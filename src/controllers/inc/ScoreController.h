/*
 * ScoreController.h
 *
 *  Created on: 6 de ago. de 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_SCORECONTROLLER_H_
#define SRC_CONTROLLERS_SCORECONTROLLER_H_

#include <GameAction.h>
#include <Klondike.h>
#include <GameActionScoreCalculator.h>

class ScoreController {
private:
    std::shared_ptr<Klondike>& game;
    std::shared_ptr<GameActionScoreCalculator> gameActionScoreCalculator;
public:
    ScoreController(std::shared_ptr<Klondike>& game);
    void calculateScoreDelta(ForwardGameActionPtr gameAction);
    void updateScore();
};

#endif /* SRC_CONTROLLERS_SCORECONTROLLER_H_ */
