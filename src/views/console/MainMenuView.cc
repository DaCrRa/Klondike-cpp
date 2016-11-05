/*
 * MainMenuView.cpp
 *
 *  Created on: 15 de may. de 2016
 *      Author: dancre
 */

#include <MainMenuView.h>

#include <Menu.h>

#include <assert.h>

void MainMenuView::interact(StartController* startController) {

    std::cout << std::endl;
    std::cout << "  ...---=== KLONDIKE ===---..." << std::endl;
    std::cout << std::endl;

    std::vector<std::pair<MenuOption, std::function<void()> > > options;

    if (startController->isGameInProgress()) {
        options.push_back(std::make_pair(MenuOption("Resume game", 0), [&] {
            startController->resumeGame();
        }));
        options.push_back(std::make_pair(MenuOption("Save game", 1), [&] {
            startController->saveGame();
        }));
    }

    options.push_back(std::make_pair(MenuOption("Start new one-player klondike", 0), [&] {
        startController->startGame();
    }));
    options.push_back(std::make_pair(MenuOption("Load saved game", 0), [&] {

    }));
    options.push_back(std::make_pair(MenuOption("Demo", 0), [&] {
        startController->startDemo();
    }));

    try {
        Menu<std::function<void()>> m("Options:", std::move(options));
        (m.getUserSelection())();
    } catch (CancelledDialogException& e) {
        std::cout << "Bye!" << std::endl;
        startController->terminateApp();
    }
}
