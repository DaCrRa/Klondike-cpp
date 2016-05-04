/*
 * Move.cpp
 *
 *  Created on: 4 de may. de 2016
 *      Author: dancre
 */

#include <Move.h>

void Move::setOrigin(MoveOrigin* o) {
	origin = o;
}

void Move::setDest(MoveDest* d) {
	dest = d;
}

void Move::accept(GameActionVisitor* visitor) {
	visitor->visit(this);
}
