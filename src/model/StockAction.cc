/*
 * StockAction.cpp
 *
 *  Created on: 24 de abr. de 2016
 *      Author: dancre
 */

#include <StockAction.h>

void StockAction::accept(GameActionVisitor* actionVisitor) {
	actionVisitor->visit(this);
}

GameActionPtr StockAction::duplicate() {
	return GameActionPtr(new StockAction(*this));
}
