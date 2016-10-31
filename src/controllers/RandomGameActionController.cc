/*
 * RandomGameActionController.cpp
 *
 *  Created on: 11 de may. de 2016
 *      Author: dancre
 */

#include <RandomGameActionController.h>
#include <StockAction.h>
#include <MoveFromStock.h>
#include <MoveFromTableauPile.h>
#include <MoveFromFoundation.h>

#include <vector>
#include <cstdlib>

ForwardGameActionPtr RandomGameActionController::getAction() {
    std::vector<ForwardGameActionPtr> actions;
    ForwardGameActionPtr stockAction(new StockAction(game->getStock()));
    if(stockAction->canBeDone()) {
        actions.push_back(stockAction);
    }
    if( isAPossibleMoveOrigin(game->getStock()) ) {
        for (MoveDest* dest : getPossibleMoveDests(game->getStock())) {
            MovePtr move(new MoveFromStock(game->getStock()));
            move->setDest(dest);
            actions.push_back(move);
        }
    }
    for(Foundation& foundation : game->getFoundations()) {
        if( isAPossibleMoveOrigin(&foundation) ) {
            for (MoveDest* dest : getPossibleMoveDests(&foundation)) {
                MovePtr move(new MoveFromFoundation(&foundation));
                move->setDest(dest);
                actions.push_back(move);
            }
        }
    }
    for(TableauPile& tableauPile : game->getTableau()) {
        if( isAPossibleMoveOrigin(&tableauPile) ) {
            for (MoveDest* dest : getPossibleMoveDests(&tableauPile)) {
                MovePtr move(new MoveFromTableauPile(&tableauPile));
                move->setDest(dest);
                actions.push_back(move);
            }
        }
    }
    return actions[std::rand() % actions.size()];
}

bool RandomGameActionController::isAPossibleMoveOrigin(MoveOrigin* origin) {
    return origin->hasCardAvailable();
}

void RandomGameActionController::acceptGameActionControllerVisitor(GameActionControllerVisitor* v) {
    v->visit(this);
}
