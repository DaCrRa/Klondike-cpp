#ifndef TABLEAUPILE_H
#define TABLEAUPILE_H

#include <Pile.h>
#include <MoveOrigin.h>
#include <MoveDest.h>
#include <TableauPileVisitor.h>

#include <memory>
typedef std::shared_ptr<TableauPile> TableauPilePtr;

class TableauPile : virtual public MoveOrigin, virtual public MoveDest {
protected:
    const int MAX_RANK_ACCEPTED;
public:
    TableauPile(const int n) :
        MAX_RANK_ACCEPTED(n) {}
    virtual bool cardCanBeTurnUp() = 0;
    virtual void turnUpCard() = 0;
    virtual void turnDownCard() = 0;
    virtual int getNumCoveredCards() const = 0;
    virtual int getNumCardsAvailableToMove() const = 0;
    virtual bool cardMeetsFirstCardCondition(const Card* card) const = 0;
    virtual bool addCardCondition(const Card* referenceCard, const Card* cardToAdd) const = 0;
    virtual PileIterator uncoveredCardsBegin() const = 0;
    virtual PileIterator uncoveredCardsEnd() const = 0;
    virtual void accept(MoveOriginVisitor* v) = 0;
    virtual void accept(MoveDestVisitor* v) = 0;
    virtual void acceptTableauPileVisitor(TableauPileVisitor* visitor) = 0;
    virtual ~TableauPile() {}
};

#endif
