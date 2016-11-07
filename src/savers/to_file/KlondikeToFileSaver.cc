/*
 * KlondikeToFileSaver.cpp
 *
 *  Created on: 6 Nov 2016
 *      Author: dancre
 */

#include <KlondikeToFileSaver.h>

#include <assert.h>
#include <fstream>

KlondikeToFileSaver::KlondikeToFileSaver(KlondikeSerializer& s)  :
    path(std::experimental::filesystem::current_path() / "saved_klondikes"),
    serializer(s) {
    std::experimental::filesystem::create_directories(path);
    assert(std::experimental::filesystem::is_directory(path));
}

bool KlondikeToFileSaver::existsGameWithName(const std::string& name) {
    return std::experimental::filesystem::exists(path / name);
}

bool KlondikeToFileSaver::save(const std::string& name) {
    try {
        std::ofstream fileoutputStream(path / name);
        if (!fileoutputStream.good()) {
            return false;
        }
        serializer.serialize(game, fileoutputStream);
        return true;
    } catch (...) {
        return false;
    }
}
