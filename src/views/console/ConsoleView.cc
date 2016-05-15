/*
 * ConsoleView.cpp
 *
 *  Created on: 15 de may. de 2016
 *      Author: dancre
 */

#include <ConsoleView.h>
#include <GameConsoleView.h>

void ConsoleView::interact(Controller* controller) {
	controller->accept(this);
}

void ConsoleView::visit(GameActionController* controller) {
	GameConsoleView view(controller->getGame());
	view.interact(controller);
}
