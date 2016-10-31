/*
 * StartController.h
 *
 *  Created on: 16 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_STARTCONTROLLER_H_
#define SRC_CONTROLLERS_STARTCONTROLLER_H_

#include <KlondikeAppStateContext.h>
#include <Controller.h>
#include <ControllerVisitor.h>
#include <Klondike.h>

#include <memory>
#include <vector>

class StartController : public Controller {
private:
    KlondikeAppStateContext& context;
public:
    StartController(KlondikeAppStateContext& ctxt);
    void startGame();
    void startDemo();
    void resumeGame();
    void terminateApp();
    bool isGameInProgress();
    void accept(ControllerVisitor* v);
};

#endif /* SRC_CONTROLLERS_STARTCONTROLLER_H_ */
