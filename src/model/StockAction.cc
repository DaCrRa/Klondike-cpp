/*
 * StockAction.cpp
 *
 *  Created on: 24 de abr. de 2016
 *      Author: dancre
 */

#include <StockAction.h>

void StockAction::accept(ForwardGameActionVisitor* actionVisitor) {
    actionVisitor->visit(this);
}

ForwardGameActionPtr StockAction::duplicate() {
    return ForwardGameActionPtr(new StockAction(*this));
}

bool StockAction::canBeDone() {
    return stock->hasCards();
}

void StockAction::forwardAction() {
    cardsMoved = stock->moveForward();
}

void StockAction::undoAction() {
    stock->moveBackward(cardsMoved);
}
