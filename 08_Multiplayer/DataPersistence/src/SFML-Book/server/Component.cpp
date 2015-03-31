#include <SFML-Book/server/Component.hpp>
#include <SFML-Book/server/Entity.hpp>


/////////// CompAIMain ///////////////

REGISTER_AND_CONSTRUCT(CompAIMain,"CompAIMain",\
                       _gold_amount,"gold_amount",\
                       _deltaAsDouble,"deltaAsDouble",\
                       _elapsedAsDouble,"elapsedAsDouble")


CompAIMain::CompAIMain(int gold,const sf::Time& timeDelta) :CompAIMain()
{
    _gold_amount = gold;
    _delta = timeDelta;
    _elapsed = sf::Time::Zero;
}

void CompAIMain::after_load()
{
    _delta = sf::seconds(_deltaAsDouble);
    _elapsed = sf::seconds(_elapsedAsDouble);
}

void CompAIMain::before_save()
{
    _deltaAsDouble = _delta.asSeconds();
    _elapsedAsDouble = _elapsed.asSeconds();
}

void CompAIMain::before_update()
{
    before_save();
}

///////////////////// CompAIWarrior //////////////////////////

REGISTER_AND_CONSTRUCT(CompAIWarrior,"CompAIWarrior",\
                       _hitPoint,"hitPoint",\
                       _deltaAsDouble,"deltaAsDouble",\
                       _elapsedAsDouble,"elapsedAsDouble",\
                       _range,"range",\
                       _enemyId,"enemyId")

CompAIWarrior::CompAIWarrior(int hitPoint,const sf::Time& timeDelta,int range) : CompAIWarrior()
{
    _hitPoint = hitPoint;
    _delta = timeDelta;
    _elapsed = sf::Time::Zero;
    _range = range;
    _enemyId = -1;
}

void CompAIWarrior::after_load()
{
    _delta = sf::seconds(_deltaAsDouble);
    _elapsed = sf::seconds(_elapsedAsDouble);
}

void CompAIWarrior::before_save()
{
    _deltaAsDouble = _delta.asSeconds();
    _elapsedAsDouble = _elapsed.asSeconds();
}

void CompAIWarrior::before_update()
{
    before_save();
}

///////////////// CompAIDefender //////////////
REGISTER_AND_CONSTRUCT(CompAIDefender,"CompAIDefender",\
                       _hitPoint,"hitPoint",\
                       _deltaAsDouble,"deltaAsDouble",\
                       _elapsedAsDouble,"elapsedAsDouble",\
                       _range,"range")


CompAIDefender::CompAIDefender(int hitPoint,const sf::Time& timeDelta,int range) : CompAIDefender()
{
    _hitPoint = hitPoint;
    _delta = timeDelta;
    _elapsed = sf::Time::Zero;
    _range = range;
}

void CompAIDefender::after_load()
{
    _delta = sf::seconds(_deltaAsDouble);
    _elapsed = sf::seconds(_elapsedAsDouble);
}

void CompAIDefender::before_save()
{
    _deltaAsDouble = _delta.asSeconds();
    _elapsedAsDouble = _elapsed.asSeconds();
}

void CompAIDefender::before_update()
{
    before_save();
}

//////////////////////////// CompAISpawner /////////////////////

REGISTER_AND_CONSTRUCT(CompAISpawner,"CompAISpawner",\
                       _makeAsTypeId,"makeAsTypeId",\
                       _number,"number",\
                       _deltaAsDouble,"deltaAsDouble",\
                       _elapsedAsDouble,"elapsedAsDouble")


CompAISpawner::CompAISpawner(book::MakeAs makeAs,int number,const sf::Time& timeDelta) : CompAISpawner()
{
    _makeAs = makeAs;
    _number = number;
    _delta = timeDelta;
    _elapsed = sf::Time::Zero;
}

void CompAISpawner::after_load()
{
    _delta = sf::seconds(_deltaAsDouble);
    _elapsed = sf::seconds(_elapsedAsDouble);
    _makeAs = book::getMakeAs(_makeAsTypeId);
}

void CompAISpawner::before_save()
{
    _deltaAsDouble = _delta.asSeconds();
    _elapsedAsDouble = _elapsed.asSeconds();
    _makeAsTypeId = book::getType(_makeAs);
}

void CompAISpawner::before_update()
{
    before_save();
}

////////////////////////////// CompAIWalker ////////////////////

REGISTER_AND_CONSTRUCT(CompAIWalker,"CompAIWalker",\
                       _speed,"speed",\
                       _pathToTakeX,"pathToTakeX",
                       _pathToTakeY,"pathToTakeY")

CompAIWalker::CompAIWalker(float speed) : CompAIWalker()
{
    _speed = speed;
}

void CompAIWalker::after_load()
{
    _pathToTake.x = _pathToTakeX;
    _pathToTake.y = _pathToTakeY;
}

void CompAIWalker::before_save()
{
    _pathToTakeX = _pathToTake.x;
    _pathToTakeY = _pathToTake.y;
}

void CompAIWalker::before_update()
{
    before_save();
}


/////////////////// CompAIFlyer /////////////////////////
REGISTER_AND_CONSTRUCT(CompAIFlyer,"CompAIFlyer",\
                       _speed,"speed",\
                       _pathToTakeX,"pathToTakeX",
                       _pathToTakeY,"pathToTakeY")

CompAIFlyer::CompAIFlyer(float speed) : CompAIFlyer()
{
    _speed = speed;
}

void CompAIFlyer::after_load()
{
    _pathToTake.x = _pathToTakeX;
    _pathToTake.y = _pathToTakeY;
}

void CompAIFlyer::before_save()
{
    _pathToTakeX = _pathToTake.x;
    _pathToTakeY = _pathToTake.y;
}

void CompAIFlyer::before_update()
{
    before_save();
}

////////////// CompTeam ////////////////

REGISTER_AND_CONSTRUCT(CompTeam,"CompTeam",\
                       _team,"team")

CompTeam::CompTeam(Team::type_ptr team) : CompTeam()
{
    _team = team;
}


///////////////// CompSkin /////////////////

REGISTER_AND_CONSTRUCT(CompSkin,"CompSkin",\
                       _animationId,"animationId")

CompSkin::CompSkin(short int animation) : CompSkin()
{
    _animationId = animation;
}

/////////////////// CompHp ///////////////////////

REGISTER_AND_CONSTRUCT(CompHp,"CompHp",\
                       _hp,"hp",\
                       _maxHp,"maxHp")

CompHp::CompHp(int hp) : CompHp()
{
    _hp = hp;
    _maxHp = hp;
}
