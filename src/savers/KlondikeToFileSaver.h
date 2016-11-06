/*
 * KlondikeToFileSaver.h
 *
 *  Created on: 6 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_SAVERS_KLONDIKETOFILESAVER_H_
#define SRC_SAVERS_KLONDIKETOFILESAVER_H_

#include <KlondikeSerializer.h>

#include <experimental/filesystem>
#include <memory>


class KlondikeToFileSaver {
private:
    std::experimental::filesystem::path path;

public:
    KlondikeToFileSaver() :
        path(std::experimental::filesystem::current_path() / "saved_klondikes") {
        std::experimental::filesystem::create_directories(path);
    };

};

#endif /* SRC_SAVERS_KLONDIKETOFILESAVER_H_ */
