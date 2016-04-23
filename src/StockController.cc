/*
 * StockController.cpp
 *
 *  Created on: 8 Apr 2016
 *      Author: dancre
 */

#include <StockController.h>

StockController::StockController(Stock* s) :
stock(s)
{ }

void StockController::operate() {
	stock->move();
}

void StockController::accept(ControllerVisitor* visitor) {
	visitor->visit(this);
}
