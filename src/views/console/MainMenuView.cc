/*
 * MainMenuView.cpp
 *
 *  Created on: 15 de may. de 2016
 *      Author: dancre
 */

#include <MainMenuView.h>
#include <SelectDeckView.h>

#include <Menu.h>

#include <assert.h>

void MainMenuView::interact(StartController* startController) {

    std::cout << std::endl;
    std::cout << "  ...---=== KLONDIKE ===---..." << std::endl;
    std::cout << std::endl;

    std::vector<std::pair<MenuOption, std::function<void()> > > options;

    if (startController->isGameInProgress()) {
        options.push_back(std::make_pair(MenuOption("Resume game", 0), [&] {
            eventObserver.gameResumeRequested();
        }));
        options.push_back(std::make_pair(MenuOption("Save game", 1), [&] {
            eventObserver.saveGameRequested();
        }));
    }

    options.push_back(std::make_pair(MenuOption("Start new one-player klondike", 0), [&] {
        selectDeckAndStart(startController->getDeckFactory(), [&]()->void {startController->startGame();});
    }));
    options.push_back(std::make_pair(MenuOption("Load saved game", 0), [&] {
        eventObserver.loadGameRequested();
    }));
    options.push_back(std::make_pair(MenuOption("Demo", 0), [&] {
        selectDeckAndStart(startController->getDeckFactory(), [&]()->void {startController->startDemo();});
    }));

    try {
        Menu<std::function<void()>> m("Options:", std::move(options));
        (m.getUserSelection())();
    } catch (CancelledDialogException& e) {
        std::cout << "Bye!" << std::endl;
        eventObserver.exitRequested();
    }
}

void MainMenuView::selectDeckAndStart(AbstractDeckFactory& factory, std::function<void()> startFunction) {
    try {
        SelectDeckView(factory).selectDeck();
        startFunction();
    } catch (CancelledDialogException& e) {}
}

