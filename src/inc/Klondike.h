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
#include <KlondikeRenderer.h>

class Klondike {
private:
	Deck deck;
	Stock stock;
	std::vector<Foundation> foundations;
	std::vector<TableauPile> tableau;
public:
	Klondike();
	void initialize();
	bool isCompleted();
	void configureRenderer(KlondikeRenderer* renderer);
	Stock* getStock();
};

#endif
