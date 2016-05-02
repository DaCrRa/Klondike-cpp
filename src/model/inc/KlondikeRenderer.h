/*
 * KlondikeRenderer.h
 *
 *  Created on: 3 Apr 2016
 *      Author: dancre
 */

#ifndef SRC_INC_KLONDIKERENDERER_H_
#define SRC_INC_KLONDIKERENDERER_H_

#include <vector>
#include <Foundation.h>
#include <Stock.h>
#include <TableauPile.h>

class KlondikeRenderer {
protected:
	const Stock* stock = nullptr;
	const std::vector<TableauPile>* tableau = nullptr;
	const std::vector<Foundation>* foundations = nullptr;
public:
	void setStock(const Stock* s);
	void setTableau(const std::vector<TableauPile>* tableau);
	void setFoundations(const std::vector<Foundation>* foundations);

	virtual void render() = 0;
	virtual void renderStock() = 0;
	virtual void renderFoundations() = 0;
	virtual void renderTableau() = 0;
	virtual void renderTableauPile(const TableauPile* tp) = 0;
	virtual void renderFoundation(const Foundation* f) = 0;

	virtual ~KlondikeRenderer() { }
};

#endif /* SRC_INC_KLONDIKERENDERER_H_ */
