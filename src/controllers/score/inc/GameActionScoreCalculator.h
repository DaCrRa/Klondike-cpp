/*
 * GameActionScoreController.h
 *
 *  Created on: 13 de ago. de 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_SCORE_INC_GAMEACTIONSCORECALCULATOR_H_
#define SRC_CONTROLLERS_SCORE_INC_GAMEACTIONSCORECALCULATOR_H_

#include <MoveScoreCalculator.h>

class GameActionScoreCalculator : public GameActionVisitor {
private:
    int scoreDelta;
public:
    void visit(StockAction* stockAction);
    void visit(Move* move);
    int getScoreDelta() const;
};

#endif /* SRC_CONTROLLERS_SCORE_INC_GAMEACTIONSCORECALCULATOR_H_ */
