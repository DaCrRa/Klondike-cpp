/*
 * KlondikeProxy.h
 *
 *  Created on: 22 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_PROXY_INC_KLONDIKEPROXY_H_
#define SRC_MODEL_PROXY_INC_KLONDIKEPROXY_H_

#include <Klondike.h>

#include <string>

class KlondikeProxy : public Klondike {
private:
    std::string host;
    int gameId;
public:
    KlondikeProxy(std::string h, DeckType dt);
    void initialize();
    void initialize(KlondikeInitParameters& params);
    bool isCompleted();
};

#endif /* SRC_MODEL_PROXY_INC_KLONDIKEPROXY_H_ */
