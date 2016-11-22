/*
 * GameElementProxy.h
 *
 *  Created on: 22 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_PROXY_INC_GAMEELEMENTPROXY_H_
#define SRC_MODEL_PROXY_INC_GAMEELEMENTPROXY_H_

#include <GameElement.h>

#include <string>
#include <iostream>
#include <vector>

class GameElementProxy : virtual public GameElement {
protected:
    std::string gameElementUrl;
    void httpRequest(const std::string& method, const std::vector<std::string>& params) const;
public:
    GameElementProxy(const std::string& h, int id, char elementId);
    virtual Pile removeCards(int n);
    virtual ~GameElementProxy() {}
};

#endif /* SRC_MODEL_PROXY_INC_GAMEELEMENTPROXY_H_ */
