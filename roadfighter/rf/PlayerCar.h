//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_PLAYERCAR_H
#define PROJECTGP_PLAYERCAR_H

#include "Entity.h"
#include "World.h"

namespace roadfighter {
    class PlayerCar : public roadfighter::Entity {
    protected:
        pair<float, float> loc;
        float width;
        float height;

        pair<float, float> tlLoc;
        pair<float, float> brLoc;

        float speed;
        float relativeSpeed;

    public:
        // constructor
        PlayerCar();


        // functions
        void draw() override = 0;
        void update(int speed) override = 0;

        // getters and setters
        void setLoc(const pair<float, float> &loc);

        float getSpeed() override;

    };
}

#endif //PROJECTGP_PLAYERCAR_H
