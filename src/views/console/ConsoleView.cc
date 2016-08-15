/*
 * ConsoleView.cpp
 *
 *  Created on: 15 de may. de 2016
 *      Author: dancre
 */

#include <ConsoleView.h>
#include <GameView.h>
#include <MainMenuView.h>

void ConsoleView::interact(Controller* controller) {
    controller->accept(this);
}

void ConsoleView::visit(GameActionController* controller) {
    GameView view(controller->getGame());
    view.interact(controller);
}

void ConsoleView::visit(StartController* controller) {
    MainMenuView menu;
    menu.interact(controller);
}
