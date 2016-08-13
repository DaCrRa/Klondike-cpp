/*
 * ScoreController.h
 *
 *  Created on: 6 de ago. de 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_SCORECONTROLLER_H_
#define SRC_CONTROLLERS_SCORECONTROLLER_H_

#include <Klondike.h>
#include <GameAction.h>
#include <GameActionVisitor.h>

class ScoreController : public GameActionVisitor {
private:
    std::shared_ptr<Klondike>& game;
    int calculateScoreDelta(GameActionPtr gameAction);
public:
    ScoreController(std::shared_ptr<Klondike>& game);
    void updateScore(GameActionPtr gameAction);
    void visit(StockAction* stockAction);
    void visit(Move* move);
};

#endif /* SRC_CONTROLLERS_SCORECONTROLLER_H_ */
