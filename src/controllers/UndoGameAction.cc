/*
 * UndoGameAction.cpp
 *
 *  Created on: 30 de ago. de 2016
 *      Author: dancre
 */

#include <UndoGameAction.h>

void UndoGameAction::action() {
    historyController->getLastAction()->undoAction();
}

bool UndoGameAction::canBeDone() {
    return (bool)historyController->getLastAction();
}

void UndoGameAction::acceptGameActionVisitor(GameActionVisitor* visitor) {
    visitor->visit(this);
}
