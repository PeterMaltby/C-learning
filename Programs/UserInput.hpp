#pragma once
#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>

namespace pmcl {
	class UserInput {
	private:/*--------------Option struct def-----------------------*/
		struct Option {
			int(*func)(int, std::string*);
			const std::string name;
			const std::string description;
		};

	public:
		UserInput(const char* _cursor = "_>") :
			cursor(_cursor) {
			addCommand(exit, "exit", "Exits current program loop.");
		};

		~UserInput() {
			//for (auto& opt : funcMap) delete opt.second; //clears Options from heap.
		}

		bool addCommand(int(*func)(int argc, std::string*),const std::string& _alias,const std::string& _desc = "No Description available.") {
			auto ret = funcMap.emplace(std::make_pair(_alias, Option{ func,_alias,_desc }));
			return ret.second;//returns true on success.
		};

		void run() {
			int status = 1;//status of 0 will exit loop.

			do {

				//takes input from cin and outputs tokened strings (argv) and count (argc) of tokens.
				std::string input;
				std::cout << cursor;
				std::getline(std::cin, input);
				std::stringstream ss(input);
				int argc = 0;
				std::string tmp;
				std::vector<std::string> argv;
				while (std::getline(ss, tmp, ' ')) {
					argc++;
					argv.push_back(tmp);
				}
				if (argc) {
					if (argv[0] == "help") {//special case handler for help command.
						status = help(argc,&argv[0]);
					}
					else {
						auto funcMap_end = funcMap.cend();
						auto tmp = funcMap.find(argv[0]);
						if(tmp == funcMap.cend())std::cout << "Command \"" << argv[0] << "\" is not recognized, use the \"help\" command to see available commands.\n";
						else status = tmp->second.func(argc, &argv[0]);
					}
				}
			} while (status);
		}

	private:
		const char* cursor;
		std::unordered_map<std::string, Option> funcMap;

		static int exit(int, std::string*) {
			std::cout << "Exiting..." << std::endl;
			return 0;
		}

		int help(int argc, std::string* argv) {
			if (argc == 1) {
				for (auto const& pair : funcMap) {
					std::cout << pair.second.name << "\n";
				}
			}
			else {
				auto funcMap_end = funcMap.cend();
				for (int i = 1; i < argc; i++) {
					auto tmp = funcMap.find(argv[i]);
					if (funcMap_end == tmp) std::cout << "Command \"" << argv[i] << "\" was NOT found!\n";
					else std::cout << tmp->second.name << " : " << tmp->second.description << "\n";
				}
			}
			std::cout << std::endl;
			return 1;
		}
	};
}