/*
 * Stock.h
 *
 *  Created on: 3 Apr 2016
 *      Author: dancre
 */

#ifndef STOCK_H_
#define STOCK_H_

#include <Pile.h>

class Stock {
private:
	Pile covered;
	Pile waste;

	void rotate();

public:
	void move();
	bool hasCardAvailable();
	const Card* availableCard();
};

#endif
