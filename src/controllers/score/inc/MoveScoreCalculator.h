/*
 * MoveScoreCalculator.h
 *
 *  Created on: 13 de ago. de 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_SCORE_INC_MOVESCORECALCULATOR_H_
#define SRC_CONTROLLERS_SCORE_INC_MOVESCORECALCULATOR_H_

#include <Move.h>

#include <iostream>

class MoveScoreCalculator : public MoveOriginVisitor {
private:
    class DestScoreCalculator : public MoveDestVisitor {
    private:
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

    Move* move;
    int scoreDelta;
public:
    MoveScoreCalculator(Move* m) : move(m), scoreDelta(0) {}
    void visit(Stock* stock);
    void visit(TableauPile* tableauPile);
    void visit(Foundation* foundation);
    int getScoreDelta() const;
};

#endif /* SRC_CONTROLLERS_SCORE_INC_MOVESCORECALCULATOR_H_ */
