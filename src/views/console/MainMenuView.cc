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
	this->userController = std::shared_ptr<GameActionController>(new UserGameActionController(*userController));
}

void MainMenuView::visit(RandomGameActionController* randomController) {
	this->randomController = std::shared_ptr<GameActionController>(new RandomGameActionController(*randomController));
}
