/*
 * UserSelectedMove.cpp
 *
 *  Created on: 30 Oct 2016
 *      Author: dancre
 */

#include <UserSelectedMove.h>

void UserSelectedMove::action() {
    m->doAction();
}

bool UserSelectedMove::canBeDone() {
    return m->canBeDone();
}

void UserSelectedMove::acceptGameActionVisitor(GameActionVisitor* visitor) {
    visitor->visit(this);
}

MovePtr UserSelectedMove::getMove() {
    return m;
}

void UserSelectedMove::setMove(MovePtr m) {
    this->m = m;
    this->m->setObserver(observer);
}

ForwardGameActionObserverPtr UserSelectedMove::getFwdGameActionObserver() {
    return observer;
}
