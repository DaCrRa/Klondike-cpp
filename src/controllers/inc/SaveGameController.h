/*
 * SaveGameController.h
 *
 *  Created on: 5 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_INC_SAVEGAMECONTROLLER_H_
#define SRC_CONTROLLERS_INC_SAVEGAMECONTROLLER_H_

#include <Controller.h>
#include <ControllerVisitor.h>
#include <EventObserver.h>
#include <Klondike.h>
#include <KlondikeToFileSaver.h>
#include <KlondikePlainTextSerializer.h>

#include <memory>

class SaveGameController: public Controller {
private:
    EventObserver& eventObserver;
    std::shared_ptr<Klondike>& game;
    KlondikePlainTextSerializer serializer;
    KlondikeToFileSaver saver;
public:
    SaveGameController(EventObserver& observer, std::shared_ptr<Klondike>& g) :
        eventObserver(observer),
        game(g),
        serializer(game),
        saver(serializer) {};
    bool existsGameWithName(const std::string& name);
    void save(const std::string& name);
    void accept(ControllerVisitor* v);
};

#endif /* SRC_CONTROLLERS_INC_SAVEGAMECONTROLLER_H_ */
