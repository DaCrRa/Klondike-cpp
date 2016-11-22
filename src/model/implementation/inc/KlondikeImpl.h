/*
 * KlondikeImpl.h
 *
 *  Created on: 17 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_IMPLEMENTATION_INC_KLONDIKEIMPL_H_
#define SRC_MODEL_IMPLEMENTATION_INC_KLONDIKEIMPL_H_

#include <Klondike.h>
#include <TableauPileImpl.h>
#include <StockImpl.h>

class KlondikeImpl: public Klondike {
private:
    std::shared_ptr<StockImpl> stockImpl;
    std::vector<std::shared_ptr<TableauPileImpl> > tableauImpl;
    const int NUM_TABLEAU_PILES = 7;
public:
    KlondikeImpl(DeckPtr d);
    void initialize();
    void initialize(KlondikeInitParameters& params);
    bool isCompleted();
    int getScore() const;
    void updateScore(int delta);
};

#endif /* SRC_MODEL_IMPLEMENTATION_INC_KLONDIKEIMPL_H_ */
