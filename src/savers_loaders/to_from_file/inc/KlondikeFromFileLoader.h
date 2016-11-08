/*
 * KlondikeFromFileLoader.h
 *
 *  Created on: 8 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_SAVERS_LOADERS_TO_FROM_FILE_INC_KLONDIKEFROMFILELOADER_H_
#define SRC_SAVERS_LOADERS_TO_FROM_FILE_INC_KLONDIKEFROMFILELOADER_H_

#include <KlondikeLoader.h>

class KlondikeFromFileLoader: public KlondikeLoader {
public:
    KlondikeFromFileLoader();
    std::vector<std::string> listSavedGames();
};

#endif /* SRC_SAVERS_LOADERS_TO_FROM_FILE_INC_KLONDIKEFROMFILELOADER_H_ */
