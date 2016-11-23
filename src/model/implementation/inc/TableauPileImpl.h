/*
 * TableauPileImpl.h
 *
 *  Created on: 21 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_IMPLEMENTATION_INC_TABLEAUPILEIMPL_H_
#define SRC_MODEL_IMPLEMENTATION_INC_TABLEAUPILEIMPL_H_

#include <TableauPile.h>
#include <MoveOriginImpl.h>
#include <MoveDestImpl.h>

class TableauPileImpl : public TableauPile,
    public MoveOriginImpl,
    public MoveDestImpl {

private:
    const int MAX_RANK_ACCEPTED;
    Pile coveredCards;
public:
    TableauPileImpl(const int n) :
        MAX_RANK_ACCEPTED(n),
        TableauPile() {}

    void addToCovered(const Card* c);
    bool cardCanBeTurnUp();
    void turnUpCard();
    void turnDownCard();
    int getNumCoveredCards() const;
    int getNumCardsAvailableToMove() const;
    PileIterator uncoveredCardsBegin() const;
    PileIterator uncoveredCardsEnd() const;
    bool cardMeetsFirstCardCondition(const Card* card) const;
    bool addCardCondition(const Card* referenceCard, const Card* cardToAdd) const;
    void accept(MoveDestVisitor* v);
    void accept(MoveOriginVisitor* v);
    void acceptTableauPileVisitor(TableauPileVisitor* visitor);
};

#endif /* SRC_MODEL_IMPLEMENTATION_INC_TABLEAUPILEIMPL_H_ */
