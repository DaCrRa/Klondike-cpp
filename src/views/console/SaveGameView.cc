/*
 * SaveGameView.cpp
 *
 *  Created on: 5 Nov 2016
 *      Author: dancre
 */

#include <SaveGameView.h>
#include <StringInputDialog.h>

#include <iostream>

void SaveGameView::interact(SaveGameController* saveGameController) {
    StringInputDialog inputDialog("Insert game name: ");
    std::string gameName = inputDialog.getUserInput();
    if (!gameName.empty()) {

    } else {
        std::cout << "Cancelled!" << std::endl;
    }
}

