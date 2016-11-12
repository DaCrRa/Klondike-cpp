/*
 * DeckFactory.cpp
 *
 *  Created on: 12 Nov 2016
 *      Author: dancre
 */

#include <AbstractDeckFactory.h>



Deck& AbstractDeckFactory::getDeck() {
    return *deck;
}

