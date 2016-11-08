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

#include <KlondikeLoader.h>

class LoadGameController: public Controller {
private:
    KlondikeLoader& loader;
public:
    LoadGameController(KlondikeLoader& s) :
        loader(s) {};
    void accept(ControllerVisitor* v);
};

#endif /* SRC_CONTROLLERS_INC_LOADGAMECONTROLLER_H_ */
