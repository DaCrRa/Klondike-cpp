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

void MainMenuView::interact(StartController* controller) {

	std::vector<std::shared_ptr<GameActionController> > gameActionControllers = controller->getGameActionControllers();

	for (auto controller : gameActionControllers) {
		initController = [&](std::shared_ptr<GameActionController>& c){ c = controller; };
		controller->acceptGameActionControllerVisitor(this);
	}

	assert(userController);
	assert(randomController);

	std::cout << std::endl;
	std::cout << "  ...---=== KLONDIKE ===---..." << std::endl;
	std::cout << std::endl;

	Menu<std::shared_ptr<GameActionController> > m("Options:", std::vector<std::pair<MenuOption, std::shared_ptr<GameActionController> > >({
		{ MenuOption("Start one-player klondike", 0), userController },
		{ MenuOption("Demo", 0), randomController }
	}));

	controller->setSelectedGameActionController(m.getUserSelection());
	controller->startGame();
}

void MainMenuView::visit(UserGameActionController* userController) {
	assert(initController);
	initController(this->userController);
}

void MainMenuView::visit(RandomGameActionController* randomController) {
	assert(initController);
	initController(this->randomController);
}
