#include "player.h"

using namespace Cricket;

Player::Player(const std::string& sName, const std::string& sTeam)
   : sName_m(sName)
   , sTeam_m(sTeam)
{}

const std::string& Player::Name() const
{
   return sName_m;
}

const std::string& Player::Team() const
{
   return sTeam_m;
}
