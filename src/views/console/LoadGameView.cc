/*
 * LoadGameView.cpp
 *
 *  Created on: 8 Nov 2016
 *      Author: dancre
 */

#include <LoadGameView.h>
#include <Menu.h>

#include <iostream>

void LoadGameView::interact(LoadGameController* lgc) {
    std::cout << "" << std::endl;
    std::vector<std::string> savedGames = lgc->listSavedGames();
    if (savedGames.empty()) {
        std::cout << "No saved games to load!" << std::endl;
        eventObserver.gamePauseRequested();
    } else {
        std::cout << "Available games for loading:" << std::endl;
        std::cout << std::endl;
        std::vector<std::pair<MenuOption, std::string> > options;
        char optionTag = '1';
        for (std::string& gameName : savedGames) {
            options.push_back(std::make_pair(MenuOption(std::string(1, optionTag++) +
                                             " " +
                                             gameName, 0), gameName));
        }
        Menu<std::string> m("Select game:", std::move(options));
        try {
            std::string selectedGameName = m.getUserSelection();
            std::cout << "Loading " << selectedGameName << std::endl;
            lgc->loadGame(selectedGameName);
        } catch (CancelledDialogException& e) {
            std::cout << "Cancelled load game!" << std::endl;
            eventObserver.gamePauseRequested();
        }
    }
}

