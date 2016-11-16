/*
 * TestCardRenderer.cc
 *
 *  Created on: 15 Nov 2016
 *      Author: dancre
 */

#include <TestCardRenderer.h>

#include <iostream>

void TestCardRenderer::renderCard(const Card* c) {
    std::cout << "{";
    c->acceptCardVisitor(*this);
    std::cout << "}";
}

void TestCardRenderer::visitRank(int rank) const {
    std::cout << rank;
}

void TestCardRenderer::visitSuit(int suit) const {

}
