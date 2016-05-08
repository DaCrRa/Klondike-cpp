/*
 * Klondike.cc
 *
 *  Created on: 3 Apr 2016
 *      Author: dancre
 */

#include <Klondike.h>

Klondike::Klondike() :
	tableau(7), //TODO magic number
	foundations(4) //TODO magic number
{}

void Klondike::initialize() {
	int i = 0;
	for (std::vector<TableauPile>::iterator it = tableau.begin(); it != tableau.end(); ++it, ++i) {
		for (int j = 0; j < i + 1; j++) {
			it->addToCovered(deck.removeTop());
		}
		it->turnUp();
	}
	while (deck.hasCards()) {
		stock.addToCovered(deck.removeTop());
	}
}

bool Klondike::isCompleted() {
	bool completed = true;
	for (std::vector<Foundation>::iterator it = foundations.begin(); it != foundations.end() && completed; ++it) {
		completed &= it->isCompleted();
	}
	return completed;
}

void Klondike::configureRenderer(KlondikeRenderer* renderer) {
	renderer->setStock((const Stock*)&stock);
	renderer->setFoundations((const std::vector<Foundation>*)&foundations);
	renderer->setTableau((const std::vector<TableauPile>*)&tableau);
}

Stock* Klondike::getStock() {
	return &stock;
}

std::vector<Foundation>& Klondike::getFoundations() {
	return foundations;
}
