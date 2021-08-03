#pragma once
#include "Programs/UserInput.hpp"
#include "Programs/add.hpp"
#include "Programs/isPolydivisible.hpp"

int main()
{
    pmcl::UserInput ui("_>");
    ui.addCommand(_add, _addName, _addDesc);
    ui.addCommand(_isPolydivisible, _isPolydivisibleName, _isPolydivisibleDesc);

    ui.run();
}
