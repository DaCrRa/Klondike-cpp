/*
 * BestScoresController.h
 *
 *  Created on: 15 de ago. de 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_INC_BESTSCORESCONTROLLER_H_
#define SRC_CONTROLLERS_INC_BESTSCORESCONTROLLER_H_

#include <Controller.h>
#include <ControllerVisitor.h>
#include <Klondike.h>
#include <EventObserver.h>

#include <memory>

class BestScoresController : public Controller {
private:
    EventObserver& observer;
    std::shared_ptr<Klondike>& game;
    std::vector<int> bestScores;
    int lastRegisteredPosition;
    int insertScore(int newScore);
    void trimBestScores();
public:
    static const int MAX_BEST_SCORES = 10;

    BestScoresController(EventObserver& o, std::shared_ptr<Klondike>& g) :
        observer(o),
        game(g),
        bestScores(0),
        lastRegisteredPosition(-1) {}
    void accept(ControllerVisitor* visitor);
    int getLastRegisteredPosition() const;
    std::shared_ptr<Klondike>& getGame();
    bool gameScoreIsInRanking();
    void registerScore();
    std::vector<int>& getBestScores();
    EventObserver& getEventObserver();
};

#endif /* SRC_CONTROLLERS_INC_BESTSCORESCONTROLLER_H_ */
