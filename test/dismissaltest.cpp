#include "../testframework/xpunitest.h"
#include "../src/dismissal.h"

#include <sstream>

using namespace Cricket;

XpUnitTest(NotOutDismissalTest, "Testing Not Out")
{
   Dismissal oDismissal(EDismissalType::ENotOut);

   std::stringstream os;
   os << oDismissal;
   std::string sExpected = "not out";
   XpAssertEqual("Check the dismissal is printed correctly", sExpected, os.str());
}

XpUnitTest(BowledDismissalTest, "Testing Bowled")
{
   Dismissal oDismissal(EDismissalType::EBowled, "Steve Waugh");

   std::stringstream os;
   os << oDismissal;
   std::string sExpected = "b Steve Waugh";
   XpAssertEqual("Check the dismissal is printed correctly", sExpected, os.str());
}

XpUnitTest(LBWDismissalTest, "Testing LBW")
{
   Dismissal oDismissal(EDismissalType::ELBW, "Steve Waugh");

   std::stringstream os;
   os << oDismissal;
   std::string sExpected = "lbw Steve Waugh";
   XpAssertEqual("Check the dismissal is printed correctly", sExpected, os.str());
}

XpUnitTest(CaughtDismissalTest, "Testing Caught")
{
   Dismissal oDismissal(EDismissalType::ECaught, "Steve Waugh", "Mark Waugh");

   std::stringstream os;
   os << oDismissal;
   std::string sExpected = "c Mark Waugh b Steve Waugh";
   XpAssertEqual("Check the dismissal is printed correctly", sExpected, os.str());
}

XpUnitTest(RunOutDismissalTest, "Testing Run Out")
{
   Dismissal oDismissal(EDismissalType::ERunOut, "Steve Waugh", "Mark Waugh");

   std::stringstream os;
   os << oDismissal;
   std::string sExpected = "run out Mark Waugh";
   XpAssertEqual("Check the dismissal is printed correctly", sExpected, os.str());
}

XpUnitTest(ObstructingDismissalTest, "Testing Obstructing the Field")
{
   Dismissal oDismissal(EDismissalType::EObstructing, "Steve Waugh", "Mark Waugh");

   std::stringstream os;
   os << oDismissal;
   std::string sExpected = "obstructing field b Steve Waugh";
   XpAssertEqual("Check the dismissal is printed correctly", sExpected, os.str());
}

XpUnitTest(HandledBallDismissalTest, "Testing Handled Ball")
{
   Dismissal oDismissal(EDismissalType::EHandleBall, "Steve Waugh");

   std::stringstream os;
   os << oDismissal;
   std::string sExpected = "handled ball b Steve Waugh";
   XpAssertEqual("Check the dismissal is printed correctly", sExpected, os.str());
}

XPUNIT_MAIN("TestDismissal")
