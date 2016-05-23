/*
 * CardConsoleRenderer.cpp
 *
 *  Created on: 8 Apr 2016
 *      Author: dancre
 */

#include "CardConsoleRenderer.h"

#include <iostream>

void CardConsoleRenderer::renderCard(const Card* c) {
    std::cout << "{" << c->getRank() << "}";
}

