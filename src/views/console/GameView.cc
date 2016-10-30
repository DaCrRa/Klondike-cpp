/*
 * GameConsoleView.cpp
 *
 *  Created on: 8 Apr 2016
 *      Author: dancre
 */

#include <GameView.h>
#include <SelectActionView.h>
#include <ShowActionView.h>
#include <StockAction.h>
#include <RandomGameActionController.h>

#include <iostream>

void GameView::interact(GameActionController* controller) {
    renderer.render();
    try {
        selectGameAction(controller);
        controller->doAction(gameAction);
    } catch (IncompleteMoveException& e) {
        std::cout << e.what() << std::endl;
    } catch (NoActionException& e) {
        std::cout << e.what() << std::endl;
        controller->getGame()->togglePause();
    }
}

void GameView::selectGameAction(GameActionController* controller) {
    controller->acceptGameActionControllerVisitor(this);
}

void GameView::visit(UserGameActionController* c) {
    SelectActionView v(c);
    v.getAction(gameAction);
}

void GameView::visit(RandomGameActionController* c) {
    ForwardGameActionPtr action = c->getAction();
    gameAction = action;
    ShowActionView(action).show();
}
