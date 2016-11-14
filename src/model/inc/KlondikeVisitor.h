/*
 * KlondikeVisitor.h
 *
 *  Created on: 6 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_INC_KLONDIKEVISITOR_H_
#define SRC_MODEL_INC_KLONDIKEVISITOR_H_

#include <Foundation.h>
#include <Stock.h>
#include <TableauPile.h>
#include <DeckTypes.h>

#include <functional>

class KlondikeVisitor {
public:
    virtual void visitDeckType(DeckType type) {}
    virtual void visitScore(int score) {}
    virtual void visitStock(Stock* s) {}
    virtual void visitTableauPile(TableauPile* tp) {}
    virtual void allTableauPilesVisited() {};
    virtual void visitFoundation(Foundation* f) {}
    virtual void allFoundationsVisited() {};
    virtual ~KlondikeVisitor() {}
};

class KlondikeLambdaVisitor : public KlondikeVisitor {
private:
    std::function<void(DeckType)> visitDeckTypeFunction;
    std::function<void(int)> visitScoreFunction;
    std::function<void(Stock*)> visitStockFunction;
    std::function<void(TableauPile*)> visitTableauPileFunction;
    std::function<void(Foundation*)> visitFoundationFunction;
    std::function<void()> allTableauPilesVisitedFunction;
    std::function<void()> allFoundationsVisitedFunction;
public:
    KlondikeLambdaVisitor() :
        visitDeckTypeFunction([&](...)->void{}),
        visitScoreFunction([&](...)->void{}),
        visitStockFunction([&](...)->void{}),
        visitTableauPileFunction([&](...)->void{}),
        visitFoundationFunction([&](...)->void{}),
        allTableauPilesVisitedFunction([&](...)->void{}),
        allFoundationsVisitedFunction([&](...)->void{}) {}
    KlondikeLambdaVisitor& setVisitDeckTypeFunction(std::function<void(DeckType)> f) {
        visitDeckTypeFunction = f;
        return *this;
    }
    KlondikeLambdaVisitor& setVisitScoreFunction(std::function<void(int)> f) {
        visitScoreFunction = f;
        return *this;
    }
    KlondikeLambdaVisitor& setVisitStockFunction(std::function<void(Stock*)> f) {
        visitStockFunction = f;
        return *this;
    }
    KlondikeLambdaVisitor& setVisitTableauPileFunction(std::function<void(TableauPile*)> f) {
        visitTableauPileFunction = f;
        return *this;
    }
    KlondikeLambdaVisitor& setVisitFoundationFunction(std::function<void(Foundation*)> f) {
        visitFoundationFunction = f;
        return *this;
    }
    KlondikeLambdaVisitor& setAllTableauPilesVisitedFunction(std::function<void()> f) {
        allTableauPilesVisitedFunction = f;
        return *this;
    }
    KlondikeLambdaVisitor& setAllFoundationsVisitedFunction(std::function<void()> f) {
        allFoundationsVisitedFunction = f;
        return *this;
    }
    void visitDeckType(DeckType type) {
        visitDeckTypeFunction(type);
    }
    void visitScore(int score) {
        visitScoreFunction(score);
    }
    void visitStock(Stock* s) {
        visitStockFunction(s);
    }
    void visitTableauPile(TableauPile* tp) {
        visitTableauPileFunction(tp);
    }
    void allTableauPilesVisited() {
        allTableauPilesVisitedFunction();
    };
    void visitFoundation(Foundation* f) {
        visitFoundationFunction(f);
    }
    void allFoundationsVisited() {
        allFoundationsVisitedFunction();
    };
};

#endif /* SRC_MODEL_INC_KLONDIKEVISITOR_H_ */
