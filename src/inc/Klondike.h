/*
 * Klondike.h
 *
 *  Created on: 3 Apr 2016
 *      Author: dancre
 */

#ifndef KLONDIKE_H_
#define KLONDIKE_H_

#include <Deck.h>
#include <Foundation.h>
#include <TableauPile.h>
#include <Stock.h>

class Klondike {
private:
	Deck deck;
	Stock stock;
	Foundation foundations[4]; // TODO magic number
	TableauPile tableau[7]; //TODO magic number
public:
	void initialize();
	bool isCompleted();
};

#endif
