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

std::shared_ptr<GameActionController> MainMenuView::getSelection(Klondike* k) {
	std::shared_ptr<GameActionController> userController(new UserGameActionController(k));
	std::shared_ptr<GameActionController> randomController(new RandomGameActionController(k));

	std::cout << std::endl;
	std::cout << "  ...---=== KLONDIKE ===---..." << std::endl;
	std::cout << std::endl;

	Menu<std::shared_ptr<GameActionController> > m("Options:", std::vector<std::pair<MenuOption, std::shared_ptr<GameActionController> > >({
		{ MenuOption("Start one-player klondike", 0), userController },
		{ MenuOption("Demo", 0), randomController }
	}));

	return m.getUserSelection();
}

