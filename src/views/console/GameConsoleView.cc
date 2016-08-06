/*
 * GameConsoleView.cpp
 *
 *  Created on: 8 Apr 2016
 *      Author: dancre
 */

#include <GameConsoleView.h>

#include <SelectActionView.h>
#include <ShowActionView.h>
#include <StockAction.h>
#include <RandomGameActionController.h>

#include <iostream>

GameConsoleView::GameConsoleView(Klondike* k) :
    game(k)
{
    renderer.setGame(game);
}

void GameConsoleView::interact(GameActionController* controller) {
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

void GameConsoleView::selectGameAction(GameActionController* controller) {
    controller->acceptGameActionControllerVisitor(this);
}

void GameConsoleView::visit(UserGameActionController* c) {
    SelectActionView v(c);
    v.getAction(gameAction);
}

void GameConsoleView::visit(RandomGameActionController* c) {
    gameAction = c->getAction();
    ShowActionView(gameAction).show();
}
