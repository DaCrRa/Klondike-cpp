#ifndef TABLEAUPILE_H
#define TABLEAUPILE_H

#include <Pile.h>
#include <MoveOrigin.h>
#include <MoveDest.h>
#include <TableauPileVisitor.h>

class TableauPile : public MoveOrigin, public MoveDest {
private:
    Pile coveredCards;
    const int MAX_RANK_ACCEPTED;
public:
    TableauPile(const int n) :
        MAX_RANK_ACCEPTED(n) {}
    bool cardCanBeTurnUp();
    void turnUpCard();
    void turnDownCard();
    void addToCovered(const Card* c);
    int getNumCoveredCards() const;
    int getNumCardsAvailableToMove() const;
    bool cardMeetsFirstCardCondition(const Card* card) const;
    bool addCardCondition(const Card* referenceCard, const Card* cardToAdd) const;
    PileIterator uncoveredCardsBegin() const;
    PileIterator uncoveredCardsEnd() const;
    void accept(MoveOriginVisitor* v);
    void accept(MoveDestVisitor* v);
    void acceptTableauPileVisitor(TableauPileVisitor* visitor);
};

#endif
