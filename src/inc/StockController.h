/*
 * StockController.h
 *
 *  Created on: 8 Apr 2016
 *      Author: dancre
 */

#ifndef SRC_INC_STOCKCONTROLLER_H_
#define SRC_INC_STOCKCONTROLLER_H_

#include <Controller.h>
#include <Stock.h>

class StockController : public Controller {
private:
	Stock* stock;
public:
	StockController(Stock* s);
	void operate();
};

#endif
