#ifndef TABLEAUPILE_H
#define TABLEAUPILE_H

#include <Pile.h>
#include <MoveOrigin.h>
#include <MoveDest.h>
#include <TableauPileObserver.h>

class TableauPile : public MoveOrigin, public MoveDest {
private:
    Pile coveredCards;
    Pile uncoveredCards;
    TableauPileObserver* observer;
    const int MAX_RANK_ACCEPTED;
public:
    TableauPile(const int n) :
        observer(nullptr),
        MAX_RANK_ACCEPTED(n) {}
    void setObserver(TableauPileObserver* observer);
    void unsetObserver();
    bool cardCanBeTurnUp();
    void turnUpCard();
    void addToCovered(const Card* c);
    void add(const Card* c);
    void recoverCard(const Card* c);
    bool cardCanBeAdded(const Card* c);
    bool hasCardAvailable() const;
    const Card* showAvailableCard() const;
    const Card* removeAvailableCard();
    int getNumCoveredCards() const;
    PileIterator uncoveredCardsBegin() const;
    PileIterator uncoveredCardsEnd() const;
    void accept(MoveOriginVisitor* v);
    void accept(MoveDestVisitor* v);
    ~TableauPile();
};

#endif
