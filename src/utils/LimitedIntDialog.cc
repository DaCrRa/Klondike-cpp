/*
 * LimitedIntDialog.cc
 *
 *  Created on: 19 Nov 2016
 *      Author: dancre
 */

#include <LimitedIntDialog.h>

#include <iostream>
#include <limits>

int LimitedInputDialog::getUserInput() {
    int userSelection;
    do {
        std::cout << promptMessage.c_str() << " ";
        std::cin >> userSelection;
        bool notAnIntNumberIntroduced = std::cin.fail();
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (notAnIntNumberIntroduced) {
            throw CancelledDialogException();
        }
    } while (userSelection < lowerBound || userSelection > upperBound);
    return userSelection;
}
