//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_PLAYERCARSSFML_H
#define PROJECTGP_PLAYERCARSSFML_H

#include <SFML/Graphics.hpp>
#include <rf/PlayerCar.h>

namespace roadfighterSFML {

class PlayerCar : public roadfighter::PlayerCar
{
private:
        location pixloc;
        vector<sf::Texture> textures;

        sf::Sprite sprite;
        shared_ptr<sf::RenderWindow> window;

public:
        PlayerCar(shared_ptr<sf::RenderWindow> window, shared_ptr<Observer> game);
        void draw() override;
        void update(float speed, vector<shared_ptr<Entity>> entities) override;
};
} // namespace roadfighterSFML

#endif // PROJECTGP_PLAYERCARSSFML_H
