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

	std::vector<std::shared_ptr<GameActionController> > gameActionControllers = startController->getGameActionControllers();

	for (auto gameActionController : gameActionControllers) {
		assignGameActionController = [&](std::shared_ptr<GameActionController>& gameActionControllerReference){
			gameActionControllerReference = gameActionController;
		};
		gameActionController->acceptGameActionControllerVisitor(this);
	}

	assert(userController);
	assert(randomController);

	std::cout << std::endl;
	std::cout << "  ...---=== KLONDIKE ===---..." << std::endl;
	std::cout << std::endl;

	std::vector<std::pair<MenuOption, std::function<void()> > > options;

	if (startController->isGameInProgress()) {
		options.push_back(std::make_pair(MenuOption("Resume game", 0), [&]{
			startController->resumeGame();
		}));
	}

	options.push_back(std::make_pair(MenuOption("Start one-player klondike", 0), [&]{
		startGame(startController, userController);
	}));
	options.push_back(std::make_pair(MenuOption("Demo", 0), [&]{
		startGame(startController, randomController);
	}));

	try {
		Menu<std::function<void()>> m("Options:", std::move(options));
		(m.getUserSelection())();
	} catch (CancelledDialogException& e) {
		std::cout << "Bye!" << std::endl;
		startController->terminateApp();
	}
}

void MainMenuView::startGame(StartController* startController, std::shared_ptr<GameActionController> gameActionController) {
	startController->setSelectedGameActionController(gameActionController);
	startController->startGame();
}

void MainMenuView::visit(UserGameActionController* userController) {
	assert(assignGameActionController);
	assignGameActionController(this->userController);
}

void MainMenuView::visit(RandomGameActionController* randomController) {
	assert(assignGameActionController);
	assignGameActionController(this->randomController);
}
