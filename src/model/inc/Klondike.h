/*
 * Klondike.h
 *
 *  Created on: 3 Apr 2016
 *      Author: dancre
 */

#ifndef KLONDIKE_H_
#define KLONDIKE_H_

#include <Deck.h>
#include <Stock.h>
#include <KlondikeVisitor.h>
#include <KlondikeInitParameters.h>

class Klondike {
protected:
    DeckPtr deck;
    StockPtr stock;
    std::vector<FoundationPtr> foundations;
    std::vector<TableauPilePtr> tableau;
    int score = 0;
public:
    Klondike() {}
    virtual void initialize() = 0;
    virtual void initialize(KlondikeInitParameters& params) = 0;
    virtual bool isCompleted() = 0;
    virtual Stock* getStock() = 0;
    virtual int getScore() const = 0;
    virtual void updateScore(int delta) = 0;
    void accept(KlondikeVisitor* vistor);
    virtual ~Klondike() {}
};

#endif
