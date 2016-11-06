/*
 * GameActionController.cpp
 *
 *  Created on: 24 de abr. de 2016
 *      Author: dancre
 */

#include <GameActionController.h>
#include <GameActionScoreCalculator.h>
#include <Move.h>

void GameActionController::accept(ControllerVisitor* visitor) {
    visitor->visit(this);
}

std::shared_ptr<Klondike>& GameActionController::getGame() {
    return game;
}

void GameActionController::pauseGame() {
    observer.gamePauseRequested();
}

void GameActionController::doAction(GameActionPtr action) {
    action->doAction();
    GameActionScoreCalculator gameActionScoreCalculator(action);
    gameActionScoreCalculator.setActionScore();
    game->updateScore(action->getScoreDelta());
    if (game->isCompleted()) {
        observer.gameCompleted();
    }
}

void GameActionController::MoveDestFinder::visitTableauPile(TableauPile* tp) {
    if (tp->cardCanBeAdded(origin->showAvailableCard())) {
        possibleDests.push_back(tp);
    }
}

void GameActionController::MoveDestFinder::visitFoundation(Foundation* f) {
    if (f->cardCanBeAdded(origin->showAvailableCard())) {
        possibleDests.push_back(f);
    }
}

std::vector<MoveDest*> GameActionController::getPossibleMoveDests(MoveOrigin* origin) {
    if (!origin->hasCardAvailable()) {
        return std::vector<MoveDest*>();
    }
    MoveDestFinder destFinder(origin);
    game->accept(&destFinder);
    return destFinder.getPossibleDests();
}
