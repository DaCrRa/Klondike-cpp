/*
 * RandomGameActionController.cpp
 *
 *  Created on: 11 de may. de 2016
 *      Author: dancre
 */

#include <RandomGameActionController.h>
#include <StockAction.h>
#include <Move.h>

#include <vector>
#include <cstdlib>

ForwardGameActionPtr RandomGameActionController::getAction() {
    std::vector<ForwardGameActionPtr> actions;
    if(game->getStock()->hasCards()) {
        actions.push_back(ForwardGameActionPtr(new StockAction(game->getStock())));
    }
    std::vector<MoveOrigin*> possibleMoveOrigins = game->getPossibleMoveOrigins();
    for (std::vector<MoveOrigin*>::iterator it = possibleMoveOrigins.begin(); it != possibleMoveOrigins.end(); ++it) {
        std::vector<MoveDest*> moveDests = game->getPossibleMoveDests(*it);
        for (std::vector<MoveDest*>::iterator destIt = moveDests.begin(); destIt != moveDests.end(); ++destIt) {
            Move m;
            m.setOrigin(*it);
            m.setDest(*destIt);
            actions.push_back(ForwardGameActionPtr(m.duplicate()));
        }
    }
    return actions[std::rand() % actions.size()];
}

void RandomGameActionController::acceptGameActionControllerVisitor(GameActionControllerVisitor* v) {
    v->visit(this);
}

