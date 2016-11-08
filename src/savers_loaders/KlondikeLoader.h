/*
 * KlondikeLoader.h
 *
 *  Created on: 8 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_SAVERS_LOADERS_KLONDIKELOADER_H_
#define SRC_SAVERS_LOADERS_KLONDIKELOADER_H_

#include <vector>
#include <string>

class KlondikeLoader {
public:
    virtual std::vector<std::string> listSavedGames() = 0;
    virtual ~KlondikeLoader() {}
};

#endif /* SRC_SAVERS_LOADERS_KLONDIKELOADER_H_ */
