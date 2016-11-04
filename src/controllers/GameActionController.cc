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

std::vector<MoveOrigin*> GameActionController::getPossibleMoveOrigins() {
    std::vector<MoveOrigin*> possibleMoveOrigins;
    if (game->getStock()->hasCardAvailable()) {
        possibleMoveOrigins.push_back(game->getStock());
    }
    for (TableauPile& tableauPile : game->getTableau()) {
        if (tableauPile.hasCardAvailable()) {
            possibleMoveOrigins.push_back(&tableauPile);
        }
    }
    for (Foundation& foundation : game->getFoundations()) {
        if (foundation.hasCardAvailable()) {
            possibleMoveOrigins.push_back(&foundation);
        }
    }
    return possibleMoveOrigins;
}

std::vector<MoveDest*> GameActionController::getPossibleMoveDests(MoveOrigin* origin) {
    std::vector<MoveDest*> possibleMoveDests;
    for (TableauPile& tableauPile : game->getTableau()) {
        if (tableauPile.cardCanBeAdded(origin->showAvailableCard())) {
            possibleMoveDests.push_back(&tableauPile);
        }
    }
    for (Foundation& foundation : game->getFoundations()) {
        if (foundation.cardCanBeAdded(origin->showAvailableCard())) {
            possibleMoveDests.push_back(&foundation);
        }
    }
    return possibleMoveDests;
}
