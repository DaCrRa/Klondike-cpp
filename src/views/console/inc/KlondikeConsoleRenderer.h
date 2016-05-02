/*
 * KlondikeConsoleRenderer.h
 *
 *  Created on: 3 Apr 2016
 *      Author: dancre
 */

#ifndef SRC_INC_KLONDIKECONSOLERENDERER_H_
#define SRC_INC_KLONDIKECONSOLERENDERER_H_

#include <CardConsoleRenderer.h>
#include <KlondikeRenderer.h>

class KlondikeConsoleRenderer: public KlondikeRenderer {
private:
	CardConsoleRenderer cardRenderer;
public:
	void render();
	void renderStock();
	void renderFoundations();
	void renderTableau();
	void renderFoundation(const Foundation* f);
	void renderTableauPile(const TableauPile* tp);
};

#endif /* SRC_INC_KLONDIKECONSOLERENDERER_H_ */
