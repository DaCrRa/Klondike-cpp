/*
 * CardConsoleRenderer.cpp
 *
 *  Created on: 8 Apr 2016
 *      Author: dancre
 */

#include <CardConsoleRenderer.h>

#include <iostream>

void CardConsoleRenderer::renderCard(const Card* c) {
    std::cout << "{";
    c->acceptCardVisitor(*this);
    std::cout << "}";
}

void CardConsoleRenderer::visitRank(int rank) const {
    std::cout << rank;
}

void CardConsoleRenderer::visitSuit(int suit) const {

}
