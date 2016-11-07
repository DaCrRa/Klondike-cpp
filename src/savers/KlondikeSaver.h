/*
 * KlondikeSaver.h
 *
 *  Created on: 7 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_SAVERS_KLONDIKESAVER_H_
#define SRC_SAVERS_KLONDIKESAVER_H_

#include <string>
#include <Klondike.h>

#include <memory>

class KlondikeSaver {
protected:
    std::shared_ptr<Klondike> game;
public:
    KlondikeSaver() {}
    void setGame(std::shared_ptr<Klondike>& g) {
        game = g;
    }
    virtual bool existsGameWithName(const std::string& name) = 0;
    virtual bool save(const std::string& name) = 0;
    virtual ~KlondikeSaver() {}
};

#endif /* SRC_SAVERS_KLONDIKESAVER_H_ */
