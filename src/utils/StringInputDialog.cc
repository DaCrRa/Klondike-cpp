/*
 * StringInputDialog.cpp
 *
 *  Created on: 5 Nov 2016
 *      Author: dancre
 */

#include <StringInputDialog.h>

#include <iostream>

StringInputDialog::StringInputDialog(const std::string& prompt) :
    promptMessage(prompt) {}

std::string StringInputDialog::getUserInput() {
    std::cout << promptMessage.c_str() << std::flush;
    std::string userInput;
    std::getline(std::cin, userInput);
    return userInput;
}

