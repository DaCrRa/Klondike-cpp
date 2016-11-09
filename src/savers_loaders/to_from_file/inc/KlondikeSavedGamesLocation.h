/*
 * KlondikeSavedGamesLocation.h
 *
 *  Created on: 9 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_SAVERS_LOADERS_TO_FROM_FILE_INC_KLONDIKESAVEDGAMESLOCATION_H_
#define SRC_SAVERS_LOADERS_TO_FROM_FILE_INC_KLONDIKESAVEDGAMESLOCATION_H_

#include <experimental/filesystem>

namespace KlondikeFileSaverLoader  {
const std::experimental::filesystem::path KLONDIKE_SAVED_GAMES_LOCATION =
    std::experimental::filesystem::current_path() / "saved_klondikes";
}

#endif /* SRC_SAVERS_LOADERS_TO_FROM_FILE_INC_KLONDIKESAVEDGAMESLOCATION_H_ */
