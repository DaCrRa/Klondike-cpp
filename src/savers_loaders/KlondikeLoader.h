/*
 * KlondikeLoader.h
 *
 *  Created on: 8 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_SAVERS_LOADERS_KLONDIKELOADER_H_
#define SRC_SAVERS_LOADERS_KLONDIKELOADER_H_

#include <AbstractDeckFactory.h>
#include <Klondike.h>
#include <vector>
#include <string>
#include <memory>

class KlondikeLoader {
protected:
    std::shared_ptr<AbstractDeckFactory> deckFactory;
public:
    void setDeckFactory(std::shared_ptr<AbstractDeckFactory> factory) {
        deckFactory = factory;
    }
    virtual std::vector<std::string> listSavedGames() = 0;
    virtual std::shared_ptr<Klondike> loadGame(const std::string& gameName) = 0;
    virtual ~KlondikeLoader() {}
};

#endif /* SRC_SAVERS_LOADERS_KLONDIKELOADER_H_ */
