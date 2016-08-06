/*
 * KlondikeRenderer.h
 *
 *  Created on: 3 Apr 2016
 *      Author: dancre
 */

#ifndef SRC_INC_KLONDIKERENDERER_H_
#define SRC_INC_KLONDIKERENDERER_H_

#include <vector>
#include <Klondike.h>

#include <memory>

class KlondikeRenderer {
protected:
    std::shared_ptr<Klondike>& game;
public:
    KlondikeRenderer(std::shared_ptr<Klondike>& g) : game(g) {};

    virtual void render() = 0;
    virtual void renderScore() = 0;
    virtual void renderStock() = 0;
    virtual void renderFoundations() = 0;
    virtual void renderTableau() = 0;
    virtual void renderTableauPile(const TableauPile* tp) = 0;
    virtual void renderFoundation(const Foundation* f) = 0;

    virtual ~KlondikeRenderer() { }
};

#endif /* SRC_INC_KLONDIKERENDERER_H_ */
