/*
 * SaveGameView.cpp
 *
 *  Created on: 5 Nov 2016
 *      Author: dancre
 */

#include <SaveGameView.h>

#include <iostream>

void SaveGameView::interact(SaveGameController* saveGameController) {
    std::cout << "SAVE GAME" << std::endl;
    saveGameController->save("");
}

