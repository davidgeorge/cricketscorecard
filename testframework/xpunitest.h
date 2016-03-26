/*****************************************************************************\
*  Copyright (c) 2012 - 2015 Tucan Software Pty Ltd. All rights reserved.
*
*  This program is free software; you can redistribute it and/or modify it
*  under the terms of the GNU Lesser General Public License as published 
*  by the Free Software Foundation; either version 3 of the License, or
*  (at your option) any later version.
*
*  This program is distributed in the hope that it will be useful, but
*  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
*  or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public 
*  License for more details.
*  
*  You should have received a copy of the GNU Lesser General Public License
*  along with this program.  If not, see http://www.gnu.org/licenses.
\*****************************************************************************/
#ifndef XPUNIT_H_INCLUDED
#define XPUNIT_H_INCLUDED

#include <string>
#include <map>
#include <iostream>
#include <iomanip>
#include <cstdint>

#define XpAssert(testCaseStr, bResult)                   Assert(__FILE__, __LINE__, testCaseStr, bResult)
#define XpAssertEqual(testCaseStr, expected, received)   AssertEqual(__FILE__, __LINE__, testCaseStr, expected, received)
#define XpAssertNotEqual(testCaseStr, expected, received) AssertNotEqual(__FILE__, __LINE__, testCaseStr, expected, received)

#define XpAssertEQ(testCaseStr, expected, received)      AssertEqual(__FILE__, __LINE__, testCaseStr, expected, received)
#define XpAssertNE(testCaseStr, expected, received)      AssertNotEqual(__FILE__, __LINE__, testCaseStr, expected, received)
#define XpAssertLT(testCaseStr, expected, received)      AssertGeneric((expected < received), __FILE__, __LINE__, testCaseStr, expected, received)
#define XpAssertLE(testCaseStr, expected, received)      AssertGeneric((expected <= received), __FILE__, __LINE__, testCaseStr, expected, received)
#define XpAssertGT(testCaseStr, expected, received)      AssertGeneric((expected > received), __FILE__, __LINE__, testCaseStr, expected, received)
#define XpAssertGE(testCaseStr, expected, received)      AssertGeneric((expected >= received), __FILE__, __LINE__, testCaseStr, expected, received)

#define XpArraySize(test_array, struct_type)             (sizeof(test_array) / sizeof(struct_type))
#define XpTestSection(b)
#define XpTestLoop(message, array_var, test_type)    for (int i = 0; i < XpArraySize(array_var, test_type); ++i)

namespace xpunit
{
   class UnitTest;

   //	TestSuite class
   class TestSuite
   {
      // constructor & destructor
      public:
         TestSuite();
         ~TestSuite();

      private:
         // prevent copying
         TestSuite(const TestSuite&);
         TestSuite& operator=(const TestSuite&);

      // methods     
      public:
         static TestSuite& get();
         void Run(const char* title);   
         void AddTest(UnitTest* test);
         unsigned int Total() const;
         unsigned int Passed() const; 
         unsigned int Failed() const;
         void Verbose(bool flag) { verbose_ = flag; }
         bool Verbose() const { return verbose_; }

      // members
      private:
         unsigned int passed_;
         unsigned int failed_;
         bool verbose_;
         std::multimap<const std::string, UnitTest*> map_;
   };

   ////////////////////////////////////////////////////////
   // UnitTest
   // Base unit test class
   class UnitTest
   {
      /////////////////////////////////////////////////////
      // constructor & destructor
      public:
         UnitTest(const std::string& testName, const std::string& testDescription);
         virtual ~UnitTest();
         
      /////////////////////////////////////////////////////
      // methods
      public:
         std::string Name() const; 
         std::string Description() const; 
         unsigned int Passed() const; 
         unsigned int Failed() const; 
         bool Verbose() const;
         void Verbose(bool flag);
         void Assert(const char* file, int line, const std::string& testCase, bool received);
         virtual void Run();

         template <typename T>
         void AssertEqual(const char* file, int line, const std::string& testCase, const T& expected, const T& received);
         void AssertEqual(const char* file, int line, const std::string& testCase, const std::wstring& expected, const std::wstring& received);
         template <typename T>
         void AssertNotEqual(const char* file, int line, const std::string& testCase, const T& expected, const T& received);
         void AssertNotEqual(const char* file, int line, const std::string& testCase, const std::wstring& expected, const std::wstring& received);
         template <typename T>
         void AssertGeneric(bool condition, const char* file, int line, const std::string& testCase, const T& expected, const T& received);
         void AssertWide(bool condition, const char* file, int line, const std::string& testCase, const std::wstring& expected, const std::wstring& received);

      protected:
         std::string FileName(const std::string& path);

      private:
         // prevent copying
         UnitTest(const UnitTest&);
         UnitTest& operator=(const UnitTest&);

      /////////////////////////////////////////////////////
      // members
      private:
         std::string name_;
         std::string description_;
         unsigned int passed_;
         unsigned int failed_;
         bool verbose_;
   };

   ////////////////////////////////////////////////////////
   //	XpUnitTest macro
   // Use this macro to create unit tests.
   #define XpUnitTest(name, description) \
      class XpUnitTest_##name : public xpunit::UnitTest \
      {\
         public:\
         XpUnitTest_##name() : UnitTest("  " #name " ", description) {}\
            virtual void Run();\
      };\
      static XpUnitTest_##name unitTest_##name;\
      void XpUnitTest_##name::Run()

   ////////////////////////////////////////////////////////
   //	UnitTest class template methods
   template <typename T>
   void UnitTest::AssertGeneric(bool condition, const char* file, int line, const std::string& testCase, const T& expected, const T& received)
   {
      const char* resultStr = condition ? " PASS " : " FAIL ";
      if (condition) ++passed_; else ++failed_;
      if (verbose_ || !condition)
      {
         std::cout << resultStr << FileName(file) << " " << line << " " << testCase;
         if (!condition)
         {
            std::cout << " expected " << expected << " received " << received;
         }
         std::cout << std::endl;
      }
   }

   inline void UnitTest::AssertWide(bool condition, const char* file, int line, const std::string& testCase, const std::wstring& expected, const std::wstring& received)
   {
      const char* resultStr = condition ? " PASS " : " FAIL ";
      if (condition) ++passed_; else ++failed_;
      if (verbose_ || !condition)
      {
         std::cout << resultStr << FileName(file) << " " << line << " " << testCase;
         if (!condition)
         {
            std::wcout << L" expected " << expected;
            std::wcout << L" received " << received;
         }
         std::cout << std::endl;
      }      
   }

   template <typename T>
   void UnitTest::AssertEqual(const char* file, int line, const std::string& testCase, const T& expected, const T& received)
   {
      AssertGeneric((expected == received), file, line, testCase, expected, received);
   }

   template <typename T>
   void UnitTest::AssertNotEqual(const char* file, int line, const std::string& testCase, const T& expected, const T& received)
   {
      AssertGeneric((expected != received), file, line, testCase, expected, received);
   }

   inline void UnitTest::AssertEqual(const char* file, int line, const std::string& testCase, const std::wstring& expected, const std::wstring& received)
   {
      AssertWide((expected == received), file, line, testCase, expected, received);
   }

   inline void UnitTest::AssertNotEqual(const char* file, int line, const std::string& testCase, const std::wstring& expected, const std::wstring& received)
   {
      AssertWide((expected != received), file, line, testCase, expected, received);
   }

   ////////////////////////////////////////////////////////
   // UnitTest implementation
   inline UnitTest::UnitTest(const std::string& testName, const std::string& testDescription)
      : name_(testName)
      , description_(testDescription)
      , passed_(0)
      , failed_(0)
      , verbose_(false)
   {
      TestSuite::get().AddTest(this);
   }

   inline UnitTest::~UnitTest() 
   {
   }
      
   inline std::string UnitTest::Name() const 
   { 
      return name_; 
   }

   inline std::string UnitTest::Description() const 
   { 
      return description_; 
   }

   inline unsigned int UnitTest::Passed() const 
   { 
      return passed_; 
   }

   inline unsigned int UnitTest::Failed() const 
   { 
      return failed_; 
   }

   inline bool UnitTest::Verbose() const 
   { 
      return verbose_; 
   }

   inline void UnitTest::Verbose(bool flag) 
   { 
      verbose_ = flag; 
   }

   inline const char* Result(bool flag)
   {
      return flag ? " PASS " : " FAIL ";
   }

   inline void UnitTest::Assert(const char* file, int line, const std::string& testCase, bool received)
   {
      if (received) ++passed_; else ++failed_;
      if (verbose_ || !received)
      {
         std::cout << Result(received) << FileName(file) << " " << line << " " << testCase << std::endl;
      }
   }

   inline void UnitTest::Run() 
   {
   }

   #ifndef XP_PATH_SEPARATOR
      #if defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__)
         #define XP_PATH_SEPARATOR  "\\"
      #else
         #define XP_PATH_SEPARATOR  "/"
      #endif
   #endif

   inline std::string UnitTest::FileName(const std::string& path)
   {
      std::string str(path);
      size_t index = path.find_last_of(XP_PATH_SEPARATOR);
      if (index != std::string::npos)
      {
         str = path.substr(index + 1);
      }
      return str;
   }

   ////////////////////////////////////////////////////////
   // TestSuite class implementation
   inline TestSuite::TestSuite() 
      : passed_(0), failed_(0), verbose_(false), map_() 
   {
   }

   inline TestSuite::~TestSuite() 
   {
   }

   inline TestSuite& TestSuite::get()
   {
      static xpunit::TestSuite instance;
      return instance;
   }

   inline void TestSuite::Run(const char* title)
   {
      const int width = 5;
      std::multimap<const std::string, UnitTest*>::iterator it;
      std::cout << title << std::endl;
      std::cout << "--------------------------------------------------------------" << std::endl;
      for (it = map_.begin(); it != map_.end(); ++it)
      {
         it->second->Verbose(Verbose());
         time_t start = time(0);
         it->second->Run();
         unsigned total = (it->second->Passed() + it->second->Failed());
         std::cout << std::setiosflags(std::ios::left);
         std::cout << "TEST  " << std::setw(width) << total << " Passed " << std::setw(width) << it->second->Passed() << " Failed " << std::setw(width) << it->second->Failed() << " " << it->second->Name() << "(" << (time(0) - start) << "s)" << std::endl;
         std::cout << std::resetiosflags(std::ios::left);
         passed_ += it->second->Passed();
         failed_ += it->second->Failed();
      }
      std::cout << "--------------------------------------------------------------" << std::endl;
      std::cout << std::setiosflags(std::ios::left);
      std::cout << "TOTAL " << std::setw(width) << Total() << " PASSED " << std::setw(width) << Passed() << " FAILED " << std::setw(width) << Failed() << "   " << title << std::endl; 
      std::cout << std::resetiosflags(std::ios::left);
   }

   inline void TestSuite::AddTest(UnitTest* test)
   {
      if (test)
      {
         map_.insert(std::pair<const std::string,UnitTest*>(test->Name(), test));
      }
   }

   inline unsigned int TestSuite::Total() const
   { 
      return passed_ + failed_; 
   }

   inline unsigned int TestSuite::Passed() const
   { 
      return passed_; 
   }

   inline unsigned int TestSuite::Failed() const 
   { 
      return failed_; 
   }

   inline int xpunit_main(int argc, char** argv, const char* title)
   {
      bool verbose = false;
      for (int i = 1; i < argc; ++i)
      {
         char* str = argv[i];
         if (str && (*str == '-' || *str == '/'))
         {
            ++str;
            if (*str == 'v' || *str == 'V')
               verbose = true;
            else
               std::cerr << "Error: invalid or unknown argument " << argv[i] << std::endl;  
         }
         else
            std::cerr << "Error: invalid or unknown argument " << argv[i] << std::endl;  
      }
      TestSuite::get().Verbose(verbose);
      TestSuite::get().Run(title);
      return int(TestSuite::get().Failed());
   }

} // namespace xpunit

#define XPUNIT_MAIN(title) \
   int main(int argc, char** argv) \
   { \
      return xpunit::xpunit_main(argc, argv, title); \
   }

#endif /* XPUNIT_H_INCLUDED */
