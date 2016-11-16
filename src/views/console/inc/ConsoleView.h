/*
 * ConsoleView.h
 *
 *  Created on: 15 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_VIEWS_CONSOLE_CONSOLEVIEW_H_
#define SRC_VIEWS_CONSOLE_CONSOLEVIEW_H_

#include <Controller.h>
#include <ControllerVisitor.h>
#include <AbstractDeckFactory.h>
#include <EventObserver.h>

class ConsoleView : public ControllerVisitor {
private:
    AbstractDeckFactory& deckFactory;
    EventObserver& eventObserver;
public:
    ConsoleView(AbstractDeckFactory& factory, EventObserver& observer) :
        deckFactory(factory),
        eventObserver(observer) {};
    void interact(Controller* c);
    void visit(GameActionController* c);
    void visit(StartController* c);
    void visit(BestScoresController* sc);
    void visit(SaveGameController* sc);
    void visit(LoadGameController* sc);
};

#endif /* SRC_VIEWS_CONSOLE_CONSOLEVIEW_H_ */
