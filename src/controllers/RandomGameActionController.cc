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

    KlondikeLambdaVisitor possibleMoveFinder;
    possibleMoveFinder.setVisitStockFunction([&](Stock* s)->void{
        for (MoveDest* dest : getPossibleMoveDests(s)) {
            MovePtr move(new MoveFromStock(s));
            move->setDest(dest);
            actions.push_back(move);
        }
    }).setVisitTableauPileFunction([&](TableauPile* tp)->void{
        for (MoveDest* dest : getPossibleMoveDests(tp)) {
            MovePtr move(new MoveFromTableauPile(tp));
            move->setDest(dest);
            actions.push_back(move);
        }
    }).setVisitFoundationFunction([&](Foundation* f)->void{
        for (MoveDest* dest : getPossibleMoveDests(f)) {
            MovePtr move(new MoveFromFoundation(f));
            move->setDest(dest);
            actions.push_back(move);
        }
    });

    game->accept(&possibleMoveFinder);

    return actions[std::rand() % actions.size()];
}

void RandomGameActionController::acceptGameActionControllerVisitor(GameActionControllerVisitor* v) {
    v->visit(this);
}
