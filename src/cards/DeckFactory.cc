/*
 * DeckFactory.cpp
 *
 *  Created on: 12 Nov 2016
 *      Author: dancre
 */

#include <DeckFactory.h>



Deck& DeckFactory::getDeck() {
    return *deck;
}

