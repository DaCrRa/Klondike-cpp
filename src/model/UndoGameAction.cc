/*
 * UndoGameAction.cpp
 *
 *  Created on: 30 de ago. de 2016
 *      Author: dancre
 */

#include <UndoGameAction.h>

void UndoGameAction::action() {
    forwardGameAction->undoAction();
}

bool UndoGameAction::canBeDone() {
    return (bool)forwardGameAction;
}

void UndoGameAction::acceptGameActionVisitor(GameActionVisitor* visitor) {
    visitor->visit(this);
}

ForwardGameActionPtr UndoGameAction::getForwardGameAction() {
    return forwardGameAction;
}
