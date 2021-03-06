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
#include <LoadGameView.h>

#include <BestScoresController.h>

void ConsoleView::interact(Controller* controller) {
    controller->accept(this);
}

void ConsoleView::visit(GameActionController* controller) {
    GameView view(controller->getGame(), deckFactory.getDeckType());
    view.interact(controller);
}

void ConsoleView::visit(StartController* controller) {
    MainMenuView menu(eventObserver);
    menu.interact(controller);
}

void ConsoleView::visit(BestScoresController* bsc) {
    GameFinishedView(bsc->getGame(), deckFactory.getDeckType()).show(bsc);
    eventObserver.gamePauseRequested();
}

void ConsoleView::visit(SaveGameController* controller) {
    SaveGameView().interact(controller);
    eventObserver.gamePauseRequested();
}

void ConsoleView::visit(LoadGameController* controller) {
    LoadGameView(eventObserver).interact(controller);
}
