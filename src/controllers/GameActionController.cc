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

void GameActionController::MoveDestFinder::checkIfIsPossibleDestAndAddIt(MoveDest* dest) {
    if (dest->cardsCanBeAdded(origin->showAvailableCards(numberOfCards))) {
        possibleDests.push_back(dest);
    }
}

void GameActionController::MoveDestFinder::visitTableauPile(TableauPile* tp) {
    checkIfIsPossibleDestAndAddIt(tp);
}

void GameActionController::MoveDestFinder::visitFoundation(Foundation* f) {
    checkIfIsPossibleDestAndAddIt(f);
}

std::vector<MoveDest*> GameActionController::getPossibleMoveDests(MoveOrigin* origin, int numberOfCards) {
    if (origin->getNumCardsAvailableToMove() == 0) {
        return std::vector<MoveDest*>();
    }
    MoveDestFinder destFinder(origin, numberOfCards);
    game->accept(&destFinder);
    return destFinder.getPossibleDests();
}
