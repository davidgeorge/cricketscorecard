#include "../testframework/xpunitest.h"
#include "../src/player.h"

using namespace Cricket;

XpUnitTest(PlayerTest, "Creating the base player class")
{
   std::string sName = "Steve Waugh";
   std::string sTeam = "Australia";
   Player player(sName, sTeam);
   
   XpAssertEqual("Teat name is set", sName, player.Name());
   XpAssertEqual("Teat team is set", sTeam, player.Team());
}

XPUNIT_MAIN("TestPlayer")