// FowardDeclaredStorageUndefinedTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ManHandler.h"
#include "Man.h"

int main()
{
    auto man_hndlr = ManHandler();                  //<-----Notice how this doesn't cause "use of undefined type ManHandler::Impl"
    man_hndlr.AddMan();                          
    auto man_hndlrs = std::vector<ManHandler>();    // Neither does this
    man_hndlrs.push_back(std::move(man_hndlr));     // But this does

    std::cout << "Success" << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
