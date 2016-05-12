/*
 * GameConsoleView.cpp
 *
 *  Created on: 8 Apr 2016
 *      Author: dancre
 */

#include <GameConsoleView.h>

#include <SelectActionView.h>
#include <StockAction.h>

#include <iostream>

GameConsoleView::GameConsoleView(Klondike* k) :
	game(k)
{
	k->configureRenderer(&renderer);
}

void GameConsoleView::interact(GameActionController* c) {
	renderer.render();
	c->acceptGameActionControllerVisitor(this);
}

void GameConsoleView::visit(UserGameActionController* c) {
	GameActionPtr action;
	SelectActionView v(c);
	try {
		v.getAction(action);
		c->doAction(action);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
