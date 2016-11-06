/*
 * SaveGameView.cpp
 *
 *  Created on: 5 Nov 2016
 *      Author: dancre
 */

#include <SaveGameView.h>
#include <StringInputDialog.h>
#include <YesNoDialog.h>

#include <iostream>

std::string SaveGameView::getGameName(SaveGameController* saveGameController) {
    StringInputDialog inputDialog("Insert game name: ");
    while (true) {
        std::string gameName = inputDialog.getUserInput();
        YesNoDialog overwriteDialog(
            std::string("A game exists with this name: \"") +
            gameName +
            "\". Overwrite? ");
        if (gameName.empty()) {
            throw CancelledSaveException();
        }
        if (!saveGameController->existsGameWithName(gameName) || overwriteDialog.userSaidYes()) {
            return gameName;
        }
    }
}

void SaveGameView::interact(SaveGameController* saveGameController) {
    try {
        std::string gameName = getGameName(saveGameController);
        saveGameController->save(gameName);
    } catch (CancelledSaveException& e) {
        std::cout << e.what() << std::endl;
    }
}
