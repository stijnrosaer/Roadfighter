//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_GAME_H
#define PROJECTGP_GAME_H

#include "Background.h"
#include "Random.h"
#include "json.hpp"
#include "rf/Factory.h"
#include "rf/World.h"
#include "roadfighterSFML/include/PlayerCarSFML.h"
#include <rf/Observer.h>

using json = nlohmann::json;

class Game : public Observer
{
private:
        shared_ptr<roadfighter::Factory> fac;
        shared_ptr<sf::RenderWindow> window;
        shared_ptr<roadfighter::World> world;
        shared_ptr<Background> background;

        float distance;
        float prevLoadDist;
        float finishDistance;

        double score;
        json scoreboard;
        vector<pair<string, int>> scoreboardMap;

        int highscore;

public:
        Game();

        virtual ~Game();

        void initialize();

        void run();
        void update();
        void finish();
        void printDisplayElements();
        void endGame();

        void react(action act) override;
};

#endif // PROJECTGP_GAME_H
