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

class ConsoleView : public ControllerVisitor {
public:
	void interact(Controller* c);
	void visit(GameActionController* c);
};

#endif /* SRC_VIEWS_CONSOLE_CONSOLEVIEW_H_ */
