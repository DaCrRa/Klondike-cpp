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

#include <memory>

class BestScoresController : public Controller {
private:
    std::shared_ptr<Klondike>& game;
public:
    BestScoresController(std::shared_ptr<Klondike>& g) :
        game(g) {}
    void accept(ControllerVisitor* visitor);
    std::shared_ptr<Klondike>& getGame();
};

#endif /* SRC_CONTROLLERS_INC_BESTSCORESCONTROLLER_H_ */
