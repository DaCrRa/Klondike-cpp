/*
 * ConsoleView.cpp
 *
 *  Created on: 15 de may. de 2016
 *      Author: dancre
 */

#include <ConsoleView.h>
#include <GameView.h>
#include <MainMenuView.h>
#include <GameFinishedView.h>
#include <SaveGameView.h>

#include <BestScoresController.h>

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

void ConsoleView::visit(BestScoresController* bsc) {
    GameFinishedView(bsc->getGame()).show(bsc);
    bsc->getEventObserver().gamePauseRequested();
}

void ConsoleView::visit(SaveGameController* controller) {
    SaveGameView().interact(controller);
}
