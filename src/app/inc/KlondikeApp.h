/*
 * KlondikeApp.h
 *
 *  Created on: 23 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_APP_KLONDIKEAPP_H_
#define SRC_APP_KLONDIKEAPP_H_

#include <ConsoleView.h>
#include <Logic.h>

class KlondikeApp {
private:
	ConsoleView* view;
	Logic* logic;
public:
	KlondikeApp(ConsoleView* view, Logic* logic);
	void run();
};

#endif /* SRC_APP_KLONDIKEAPP_H_ */
