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

	std::vector<std::pair<MenuOption, std::shared_ptr<GameActionController> > > options;

	if (startController->isGameInProgress()) {
		options.push_back(std::make_pair(MenuOption("Resume game", 0), std::shared_ptr<GameActionController>()));
	}

	options.push_back(std::make_pair(MenuOption("Start one-player klondike", 0), userController));
	options.push_back(std::make_pair(MenuOption("Demo", 0), randomController));

	Menu<std::shared_ptr<GameActionController> > m("Options:", std::move(options));

	startController->setSelectedGameActionController(m.getUserSelection());
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
