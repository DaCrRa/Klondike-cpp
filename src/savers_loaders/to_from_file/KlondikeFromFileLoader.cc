/*
 * KlondikeFromFileLoader.cpp
 *
 *  Created on: 8 Nov 2016
 *      Author: dancre
 */

#include <KlondikeFromFileLoader.h>

std::vector<std::string> KlondikeFromFileLoader::listSavedGames() {
    std::vector<std::string> savedGames;
    for (auto& entry : std::experimental::filesystem::directory_iterator(path)) {
        if (std::experimental::filesystem::is_regular_file(entry)) {
            savedGames.push_back(entry.path().filename());
        }
    }
    return savedGames;
}
