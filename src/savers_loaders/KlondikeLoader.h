/*
 * KlondikeLoader.h
 *
 *  Created on: 8 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_SAVERS_LOADERS_KLONDIKELOADER_H_
#define SRC_SAVERS_LOADERS_KLONDIKELOADER_H_

#include <Klondike.h>

#include <vector>
#include <string>
#include <memory>

class KlondikeLoader {
public:
    virtual std::vector<std::string> listSavedGames() = 0;
    virtual std::shared_ptr<Klondike> loadGame(const std::string& gameName) = 0;
    virtual ~KlondikeLoader() {}
};

#endif /* SRC_SAVERS_LOADERS_KLONDIKELOADER_H_ */
