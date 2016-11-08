/*
 * LoadGameController.h
 *
 *  Created on: 8 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_INC_LOADGAMECONTROLLER_H_
#define SRC_CONTROLLERS_INC_LOADGAMECONTROLLER_H_

#include <Controller.h>
#include <ControllerVisitor.h>

class LoadGameController: public Controller {
public:
    LoadGameController();
    void accept(ControllerVisitor* v);
};

#endif /* SRC_CONTROLLERS_INC_LOADGAMECONTROLLER_H_ */
