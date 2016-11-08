/*
 * LoadGameView.h
 *
 *  Created on: 8 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_VIEWS_CONSOLE_INC_LOADGAMEVIEW_H_
#define SRC_VIEWS_CONSOLE_INC_LOADGAMEVIEW_H_

#include <LoadGameController.h>
#include <EventObserver.h>

class LoadGameView {
private:
    EventObserver& eventObserver;
public:
    LoadGameView(EventObserver& o) :
        eventObserver(o) {}
    void interact(LoadGameController* lgc);
};

#endif /* SRC_VIEWS_CONSOLE_INC_LOADGAMEVIEW_H_ */
