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
    KlondikeSerializer& serializer;
public:
    KlondikeToFileSaver(KlondikeSerializer& s);
    bool existsGameWithName(const std::string& name);
    bool save(const std::string& name);
};

#endif /* SRC_SAVERS_KLONDIKETOFILESAVER_H_ */
