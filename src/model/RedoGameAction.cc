/*
 * RedoGameAction.cc
 *
 *  Created on: 31 Oct 2016
 *      Author: dancre
 */

#include <RedoGameAction.h>

void RedoGameAction::action() {
    forwardGameAction->redoAction();
}

bool RedoGameAction::canBeDone() {
    return (bool)forwardGameAction;
}

void RedoGameAction::acceptGameActionVisitor(GameActionVisitor* visitor) {
    visitor->visit(this);
}

ForwardGameActionPtr RedoGameAction::getForwardGameAction() {
    return forwardGameAction;
}
