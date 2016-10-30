/*
 * GameActionScoreController.h
 *
 *  Created on: 13 de ago. de 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_SCORE_INC_GAMEACTIONSCORECALCULATOR_H_
#define SRC_CONTROLLERS_SCORE_INC_GAMEACTIONSCORECALCULATOR_H_

#include <MoveScoreCalculator.h>

class GameActionScoreCalculator : public GameActionVisitor, public ForwardGameActionVisitor {
private:
    std::shared_ptr<MoveScoreCalculator> moveScoreCalculator;
    int scoreDelta;
public:
    GameActionScoreCalculator() : scoreDelta(0) {}
    void visit(ForwardGameAction* fwdGameAction);
    void visit(UndoGameAction* undoGameAction);
    void visit(UserSelectedMove* userSelectedMove);
    void visit(StockAction* stockAction);
    void visit(Move* move);
    int getScoreDelta() const;
};

#endif /* SRC_CONTROLLERS_SCORE_INC_GAMEACTIONSCORECALCULATOR_H_ */
