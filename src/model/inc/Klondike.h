/*
 * Klondike.h
 *
 *  Created on: 3 Apr 2016
 *      Author: dancre
 */

#ifndef KLONDIKE_H_
#define KLONDIKE_H_

#include <DeckTypes.h>
#include <Stock.h>
#include <KlondikeVisitor.h>
#include <KlondikeInitParameters.h>

class Klondike {
protected:
    DeckType deckType;
    StockPtr stock;
    std::vector<FoundationPtr> foundations;
    std::vector<TableauPilePtr> tableau;
    int score = 0;
public:
    Klondike() {}
    virtual void initialize() = 0;
    virtual void initialize(KlondikeInitParameters& params) = 0;
    virtual bool isCompleted() = 0;
    Stock* getStock();
    int getScore() const;
    void updateScore(int delta);
    void accept(KlondikeVisitor* vistor);
    virtual ~Klondike() {}
};

#endif
