/*
 * KlondikeRenderer.h
 *
 *  Created on: 3 Apr 2016
 *      Author: dancre
 */

#ifndef SRC_INC_KLONDIKERENDERER_H_
#define SRC_INC_KLONDIKERENDERER_H_

#include <Stock.h>
#include <TableauPile.h>
#include <Foundation.h>

#include <vector>

class KlondikeRenderer {
protected:
	Stock* stock = nullptr;
	std::vector<TableauPile>* tableau = nullptr;
	std::vector<Foundation>* foundations = nullptr;
public:
	void setStock(Stock* s);
	void setTableau(std::vector<TableauPile>* tableau);
	void setFoundations(std::vector<Foundation>* foundations);

	virtual void render() = 0;
	virtual void renderStock() = 0;
	virtual void renderFoundations() = 0;
	virtual void renderTableau() = 0;
	virtual void renderTableauPile(TableauPile* tp) = 0;
	virtual void renderFoundation(Foundation* f) = 0;

	virtual ~KlondikeRenderer() { }
};

#endif /* SRC_INC_KLONDIKERENDERER_H_ */
