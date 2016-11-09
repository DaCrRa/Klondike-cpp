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
#include <GameSessionStarter.h>
#include <KlondikeLoader.h>

class LoadGameController: public Controller {
private:
    EventObserver& eventObserver;
    GameSessionStarter& gameSessionStarter;
    KlondikeLoader& loader;
public:
    LoadGameController(EventObserver& o,
                       GameSessionStarter& sessionStarter,
                       KlondikeLoader& l) :
        eventObserver(o),
        gameSessionStarter(sessionStarter),
        loader(l) {};
    std::vector<std::string> listSavedGames();
    bool loadGame(std::string& gameName);
    void accept(ControllerVisitor* v);
};

#endif /* SRC_CONTROLLERS_INC_LOADGAMECONTROLLER_H_ */
