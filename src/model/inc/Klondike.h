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
#include <Stock.h>
#include <TableauPile.h>
#include <KlondikeVisitor.h>
#include <KlondikeInitParameters.h>

class Klondike {
private:
    const int NUM_TABLEAU_PILES = 7;
    Deck deck;
    Stock stock;
    std::vector<Foundation> foundations;
    std::vector<TableauPile> tableau;
    int score;
public:
    Klondike();
    void initialize();
    void initialize(KlondikeInitParameters& params);
    bool isCompleted();
    Stock* getStock();
    int getScore() const;
    void updateScore(int delta);
    void accept(KlondikeVisitor* vistor);
};

#endif
