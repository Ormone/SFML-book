#include <SFML-Book/World.hpp>
#include <SFML-Book/Entity.hpp>

namespace book
{
    World::World(float x,float y): _x(x),
    _y(y)
    {
    }

    World::~World()
    {
        for(Entity* entity :_entities)
            delete entity;
        _entities.clear();

        for(Entity* entity :_entities_tmp)
            delete entity;
        _entities_tmp.clear();
    }

    void World::add(Entity* entity)
    {
        _entities_tmp.push_back(entity);
    }

    void World::remove(Entity* entity)
    {
        _entities.remove(entity);
    }

    void World::add(Configuration::Sounds sound_id)
    {
        std::unique_ptr<sf::Sound> sound(new sf::Sound(Configuration::sounds.get(sound_id)));
        sound->setAttenuation(0);
        sound->play();
        _sounds.emplace_back(std::move(sound));
    }

    int World::getX()const
    {
        return _x;
    }

    int World::getY()const
    {
        return _y;
    }

    void World::update(sf::Time deltaTime)
    {
        if(_entities_tmp.size() > 0)
            _entities.merge(_entities_tmp);

        for(Entity* entity_ptr : _entities)
        {
            Entity& entity = *entity_ptr;

            entity.update(deltaTime);

            sf::Vector2f pos = entity.getPosition();

            if(pos.x < 0)
            {
                pos.x = _x;
                pos.y = _y - pos.y;
            }
            else if (pos.x > _x)
            {
                pos.x = 0;
                pos.y = _y - pos.y;
            }

            if(pos.y < 0)
                pos.y = _y;
            else if(pos.y > _y)
                pos.y = 0;

            entity.setPosition(pos);
        }


        const auto end = _entities.end();
        for(auto it_i = _entities.begin(); it_i != end; ++it_i)
        {
            Entity& entity_i = **it_i;
            auto it_j = it_i;
            it_j++;
            for(; it_j != end;++it_j)
            {
                Entity& entity_j = **it_j;

                if(entity_i.isAlive() and entity_i.isCollide(entity_j))
                    entity_i.onDestroy();

                if(entity_j.isAlive() and entity_j.isCollide(entity_i))
                    entity_j.onDestroy();
            }
        }

        for(auto it = _entities.begin(); it != _entities.end();)
        {
            if(not (*it)->isAlive())
            {
                delete *it;
                it = _entities.erase(it);
            }
            else
                ++it;
        }

        _sounds.remove_if([](const std::unique_ptr<sf::Sound>& sound) -> bool {
                return sound->getStatus() != sf::SoundSource::Status::Playing;
            });
    }

    void World::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        for(Entity* entity : _entities)
            target.draw(*entity,states);
    }
}
