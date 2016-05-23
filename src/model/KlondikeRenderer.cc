/*
 * KlondikeRenderer.cc
 *
 *  Created on: 4 Apr 2016
 *      Author: dancre
 */

#include <KlondikeRenderer.h>

void KlondikeRenderer::setStock(const Stock* s) {
    stock = s;
}

void KlondikeRenderer::setFoundations(const std::vector<Foundation>* foundations) {
    this->foundations = foundations;
}

void KlondikeRenderer::setTableau(const std::vector<TableauPile>* tableau) {
    this->tableau = tableau;
}


