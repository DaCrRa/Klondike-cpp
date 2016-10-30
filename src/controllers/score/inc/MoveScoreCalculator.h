/*
 * MoveScoreCalculator.h
 *
 *  Created on: 13 de ago. de 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_SCORE_INC_MOVESCORECALCULATOR_H_
#define SRC_CONTROLLERS_SCORE_INC_MOVESCORECALCULATOR_H_

#include <Move.h>
#include <TableauPile.h>
#include <TableauPileObserver.h>

#include <iostream>

class MoveScoreCalculator : public MoveVisitor, public TableauPileObserver {
private:

    static const int WASTE_TO_TABLEAU = 5;
    static const int WASTE_TO_FOUNDATION = 10;
    static const int TABLEAU_TO_FOUNDATION = 10;
    static const int TURN_UP_TABLEAU_CARD = 5;
    static const int FOUNDATION_TO_TABLEAU = -15;

    class DestScoreCalculator : public MoveDestVisitor {
    protected:
        int scoreDelta;
    public:
        int getScoreDelta() const;
        virtual ~DestScoreCalculator() {}
    };

    class FromStock : public DestScoreCalculator {
    public:
        void visit(TableauPile* tableauPile);
        void visit(Foundation* foundation);
    };

    class FromTableauPile : public DestScoreCalculator {
    public:
        void visit(TableauPile* tableauPile);
        void visit(Foundation* foundation);
    };

    class FromFoundation : public DestScoreCalculator {
    public:
        void visit(TableauPile* tableauPile);
        void visit(Foundation* foundation);
    };

    TableauPile* observedTableauPile;
    int& scoreDelta;
public:
    MoveScoreCalculator(int& scoreDelta) :
        observedTableauPile(nullptr),
        scoreDelta(scoreDelta) {}
    void onCardTurnUp();
    void tableauPileDestroyed();
    void visit(MoveFromStock* move);
    void visit(MoveFromTableauPile* move);
    void visit(MoveFromFoundation* move);
    ~MoveScoreCalculator();
};

#endif /* SRC_CONTROLLERS_SCORE_INC_MOVESCORECALCULATOR_H_ */
