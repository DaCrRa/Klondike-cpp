#ifndef TABLEAUPILE_H
#define TABLEAUPILE_H

#include <Pile.h>
#include <MoveOrigin.h>
#include <MoveDest.h>
#include <TableauPileVisitor.h>

class TableauPile : public MoveOrigin, public MoveDest {
private:
    Pile coveredCards;
    Pile uncoveredCards;
    const int MAX_RANK_ACCEPTED;
public:
    TableauPile(const int n) :
        MAX_RANK_ACCEPTED(n) {}
    bool cardCanBeTurnUp();
    void turnUpCard();
    void turnDownCard();
    void addToCovered(const Card* c);
    void addCards(Pile& cards);
    void recoverCard(const Card* c);
    bool cardsCanBeAdded(const Pile& cards) const;
    bool hasCardAvailable() const;
    const Card* showAvailableCard() const;
    const Card* removeAvailableCard();
    int getNumCoveredCards() const;
    PileIterator uncoveredCardsBegin() const;
    PileIterator uncoveredCardsEnd() const;
    void accept(MoveOriginVisitor* v);
    void accept(MoveDestVisitor* v);
    void acceptTableauPileVisitor(TableauPileVisitor* visitor);
};

#endif
