/*
 * KlondikeRenderer.cc
 *
 *  Created on: 4 Apr 2016
 *      Author: dancre
 */

#include <KlondikeRenderer.h>

void KlondikeRenderer::setStock(Stock* s) {
	stock = s;
}

void KlondikeRenderer::setFoundations(std::vector<Foundation>* foundations) {
	this->foundations = foundations;
}

void KlondikeRenderer::setTableau(std::vector<TableauPile>* tableau) {
	this->tableau = tableau;
}


