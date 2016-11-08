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
#include <KlondikeSaver.h>

#include <memory>

class SaveGameController: public Controller {
private:
    std::shared_ptr<Klondike>& game;
    KlondikeSaver& saver;
public:
    SaveGameController(std::shared_ptr<Klondike>& g,
                       KlondikeSaver& s) :
        game(g),
        saver(s) {};
    bool existsGameWithName(const std::string& name);
    bool save(const std::string& name);
    void accept(ControllerVisitor* v);
};

#endif /* SRC_CONTROLLERS_INC_SAVEGAMECONTROLLER_H_ */
