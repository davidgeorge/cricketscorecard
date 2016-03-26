#include "../testframework/xpunitest.h"
#include "../src/player.h"
#include "../src/batsman.h"

using namespace Cricket;

XpUnitTest(BatsmanTest, "Testing the Batsman")
{
   std::string sName = "Steve Waugh";
   std::string sTeam = "Australia";
   Batsman batsman(sName, sTeam);
   
   XpAssertEqual("Test batsman's name is set", sName, batsman.Name());
   XpAssertEqual("Test batsman's team is set", sTeam, batsman.Team());
   XpAssertEqual("Test batsman has is not batting", false, batsman.Batting());
   XpAssertEqual("Test batsman's is not dismissed", false, batsman.Dismissed());
   XpAssertEqual("Test batsman has scored no runs", 0, batsman.Runs());
   
   batsman.BringToCrease();
   XpAssertEqual("Test batsman is now batting", true, batsman.Batting());
   XpAssertEqual("Test batsman's is not dismissed", false, batsman.Dismissed());

   batsman.ScoreRuns(0);
   XpAssertEqual("Test batsman has scored no runs", 0, batsman.Runs());
   batsman.ScoreRuns(2);
   XpAssertEqual("Test batsman has scored runs", 2, batsman.Runs());
   batsman.ScoreRuns(4);
   XpAssertEqual("Test batsman has scored runs", 6, batsman.Runs());
   
   batsman.Dismiss();
   XpAssertEqual("Test batsman is no longer batting", false, batsman.Batting());
   XpAssertEqual("Test batsman's has been dismissed", true, batsman.Dismissed());
}

XpUnitTest(PlayerTest, "Creating the base player class")
{
   std::string sName = "Steve Waugh";
   std::string sTeam = "Australia";
   Player player(sName, sTeam);
   
   XpAssertEqual("Test name is set", sName, player.Name());
   XpAssertEqual("Test team is set", sTeam, player.Team());
}

XPUNIT_MAIN("TestPlayer")
