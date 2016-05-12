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

void GameConsoleView::interact(GameActionController* controller) {
	renderer.render();
	try {
		GameActionPtr gameAction = getGameAction(controller);
		controller->doAction(gameAction);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void GameConsoleView::visit(UserGameActionController* c) {
	GameActionPtr action;
	SelectActionView v(c);
	try {
		v.getAction(action);
		c->doAction(action);

}

void GameConsoleView::visit(RandomGameActionController* c) {
	/*GameActionPtr action;
	SelectActionView v(c);
	try {
		v.getAction(action);
		c->doAction(action);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}*/
}
