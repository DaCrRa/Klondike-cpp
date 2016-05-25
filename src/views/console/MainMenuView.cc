/*
 * MainMenuView.cpp
 *
 *  Created on: 15 de may. de 2016
 *      Author: dancre
 */

#include <MainMenuView.h>

#include <UserGameActionController.h>
#include <RandomGameActionController.h>
#include <Menu.h>

#include <assert.h>

void MainMenuView::interact(StartController* startController) {

    const std::vector<std::shared_ptr<GameActionController> >& gameActionControllers = startController->getAvailableGameActionControllers();

    size_t index = 0;
    for (auto gameActionController : gameActionControllers) {
        assignGameActionControllerIndex = [&](size_t& gameActionControllerIndexReference) {
            gameActionControllerIndexReference = index;
        };
        gameActionController->acceptGameActionControllerVisitor(this);
        ++index;
    }

    std::cout << std::endl;
    std::cout << "  ...---=== KLONDIKE ===---..." << std::endl;
    std::cout << std::endl;

    std::vector<std::pair<MenuOption, std::function<void()> > > options;

    if (startController->isGameInProgress()) {
        options.push_back(std::make_pair(MenuOption("Resume game", 0), [&] {
            startController->resumeGame();
        }));
    }

    options.push_back(std::make_pair(MenuOption("Start one-player klondike", 0), [&] {
        startGame(startController, userControllerIndex);
    }));
    options.push_back(std::make_pair(MenuOption("Demo", 0), [&] {
        startGame(startController, randomControllerIndex);
    }));

    try {
        Menu<std::function<void()>> m("Options:", std::move(options));
        (m.getUserSelection())();
    } catch (CancelledDialogException& e) {
        std::cout << "Bye!" << std::endl;
        startController->terminateApp();
    }
}

void MainMenuView::startGame(StartController* startController, size_t gameActionControllerIndex) {
    startController->setSelectedGameActionController(gameActionControllerIndex);
    startController->startGame();
}

void MainMenuView::visit(UserGameActionController* userController) {
    assert(assignGameActionControllerIndex);
    assignGameActionControllerIndex(this->userControllerIndex);
}

void MainMenuView::visit(RandomGameActionController* randomController) {
    assert(assignGameActionControllerIndex);
    assignGameActionControllerIndex(this->randomControllerIndex);
}
