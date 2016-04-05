/*
 * KlondikeConsoleRenderer.h
 *
 *  Created on: 3 Apr 2016
 *      Author: dancre
 */

#ifndef SRC_INC_KLONDIKECONSOLERENDERER_H_
#define SRC_INC_KLONDIKECONSOLERENDERER_H_

#include <KlondikeRenderer.h>


class KlondikeConsoleRenderer: public KlondikeRenderer {
public:
	void render();
	void renderStock();
	void renderFoundations();
	void renderTableau();
	void renderFoundation(Foundation* f);
	void renderTableauPile(TableauPile* tp);
};

#endif /* SRC_INC_KLONDIKECONSOLERENDERER_H_ */
