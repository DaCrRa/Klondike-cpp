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
#include <KlondikeRenderer.h>
#include <Stock.h>
#include <TableauPile.h>

class Klondike {
private:
	Deck deck;
	Stock stock;
	std::vector<Foundation> foundations;
	std::vector<TableauPile> tableau;
	std::vector<MoveOrigin*> moveOrigins;
	std::vector<MoveDest*> moveDests;
	bool paused;
public:
	Klondike();
	void initialize();
	bool isCompleted();
	void configureRenderer(KlondikeRenderer* renderer);
	Stock* getStock();
	std::vector<Foundation>& getFoundations();
	std::vector<TableauPile>& getTableau();
	std::vector<MoveOrigin*> getPossibleMoveOrigins();
	std::vector<MoveDest*> getPossibleMoveDests(MoveOrigin* orig);
       bool isPaused();
	void pause();
};

#endif
