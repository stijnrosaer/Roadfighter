//
// Created by stijn on 16/11/18.
//

#include "../rf/World.h"

roadfighter::World::World() { this->speed = 0; }

const shared_ptr<roadfighter::Entity>& roadfighter::World::getPlayer() const { return player; }

void roadfighter::World::setPlayer(const shared_ptr<roadfighter::Entity>& player) { World::player = player; }

void roadfighter::World::draw()
{
        for (auto& entity : entities) {
                entity->draw();
        }
        for (auto& pc : racingCars) {
                pc->draw();
        }
        player->draw();
}

void roadfighter::World::update(float speed, vector<shared_ptr<Entity>> entities)
{
        vector<shared_ptr<Entity>> allItems;
        allItems.insert(allItems.end(), this->entities.begin(), this->entities.end());
        allItems.insert(allItems.end(), this->racingCars.begin(), this->racingCars.end());

        player->update(0, this->entities);
        this->speed = player->getSpeed();

        for (auto& entity : this->entities) {
                entity->update(this->speed, allItems);
        }

        for (auto& pc : racingCars) {
                pc->update(this->speed, allItems);
        }

        toDelete();
        remCollisions();
}

float roadfighter::World::getSpeed() { return this->speed; }

void roadfighter::World::addEntity(const shared_ptr<roadfighter::Entity>& object) { entities.push_back(object); }

bool roadfighter::World::toDelete()
{
        for (long i = entities.size() - 1; i >= 0; i--) {
                if (entities[i]->toDelete()) {
                        entities.erase(entities.begin() + i);
                }
        }
        return true;
}

void roadfighter::World::remCollisions()
{
        vector<shared_ptr<Entity>> allItems;
        allItems.insert(allItems.end(), this->entities.begin(), this->entities.end());
        allItems.insert(allItems.end(), this->racingCars.begin(), this->racingCars.end());

        for (auto& item : entities) {
                if (item->collision(allItems) != nullptr) {
                        item->setDelete(true);
                        if (item->collision(entities)) {
                                item->collision(entities)->setDelete(true);
                        }
                }
        }
}

void roadfighter::World::setDelete(bool del) {}

void roadfighter::World::addRacingCars(const shared_ptr<roadfighter::Entity>& passingCar)
{
        racingCars.push_back(passingCar);
}

bool roadfighter::World::finish()
{
        vector<shared_ptr<Entity>> allItems;
        allItems.insert(allItems.end(), this->entities.begin(), this->entities.end());
        allItems.insert(allItems.end(), this->racingCars.begin(), this->racingCars.end());

        bool ready = true;
        for (auto& entity : entities) {
                if (!entity->finish()) {
                        ready = false;
                        entity->update(speed, allItems);
                }
        }
        for (auto& racingCar : racingCars) {
                if (!racingCar->finish()) {
                        ready = false;
                }
        }
        if (!player->finish()) {
                this->speed = player->getSpeed();
                ready = false;
        }

        return ready;
}
