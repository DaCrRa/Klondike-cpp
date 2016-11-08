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
#include <EventObserver.h>

#include <KlondikeLoader.h>

class LoadGameController: public Controller {
private:
    EventObserver& eventObserver;
    KlondikeLoader& loader;
public:
    LoadGameController(EventObserver& o, KlondikeLoader& s) :
        eventObserver(o),
        loader(s) {};
    std::vector<std::string> listSavedGames();
    void accept(ControllerVisitor* v);
};

#endif /* SRC_CONTROLLERS_INC_LOADGAMECONTROLLER_H_ */
