/*
 * KlondikeFromFileLoader.h
 *
 *  Created on: 8 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_SAVERS_LOADERS_TO_FROM_FILE_INC_KLONDIKEFROMFILELOADER_H_
#define SRC_SAVERS_LOADERS_TO_FROM_FILE_INC_KLONDIKEFROMFILELOADER_H_

#include <KlondikeLoader.h>
#include <KlondikeSavedGamesLocation.h>
#include <KlondikeDeserializer.h>

class KlondikeFromFileLoader: public KlondikeLoader {
private:
    std::experimental::filesystem::path path;
    KlondikeDeserializer& deserializer;
public:
    KlondikeFromFileLoader(KlondikeDeserializer &ds) :
        path(KlondikeFileSaverLoader::KLONDIKE_SAVED_GAMES_LOCATION),
        deserializer(ds) {}
    std::vector<std::string> listSavedGames();
    std::shared_ptr<Klondike> loadGame(const std::string& gameName);
};

#endif /* SRC_SAVERS_LOADERS_TO_FROM_FILE_INC_KLONDIKEFROMFILELOADER_H_ */
