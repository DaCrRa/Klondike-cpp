/*
 * GameActionScoreController.h
 *
 *  Created on: 13 de ago. de 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_SCORE_INC_GAMEACTIONSCORECALCULATOR_H_
#define SRC_CONTROLLERS_SCORE_INC_GAMEACTIONSCORECALCULATOR_H_

#include <MoveScoreCalculator.h>

#include <assert.h>

class GameActionScoreCalculator : public GameActionVisitor, public ForwardGameActionVisitor {
private:
    std::shared_ptr<MoveScoreCalculator> moveScoreCalculator;
    GameActionPtr action;
    int scoreDelta;
public:
    GameActionScoreCalculator(GameActionPtr a) :
        scoreDelta(0),
        action(a) {
        assert(action);
    }
    void setActionScore();
    void visit(ForwardGameAction* fwdGameAction);
    void visit(UndoGameAction* undoGameAction);
    void visit(RedoGameAction* undoGameAction);
    void visit(UserSelectedMove* userSelectedMove);
    void visit(StockAction* stockAction);
    void visit(Move* move);
};

#endif /* SRC_CONTROLLERS_SCORE_INC_GAMEACTIONSCORECALCULATOR_H_ */
