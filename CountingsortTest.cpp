#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "Countingsort.cpp"
#include <vector>

class CountingsortTest : public CppUnit::TestCase 
{
	private:
		
	public:
		
		void testSortBasic()
		{//Basic test of the Counting Sort. Just makes sure it will sort a vector of 1 through 6.
			std::vector<unsigned int> A;
			std::vector<unsigned int> B;
			
			A.push_back(5);
			A.push_back(2);
			A.push_back(4);
			A.push_back(6);
			A.push_back(1);
			A.push_back(3);
			
			Countingsort::countingsort<unsigned int>(A, B, 6);
			
			for( unsigned int i = 0; i < B.size(); i++ )
			{//Check every element of B to make sure it has sorted values 1..n where n is the number of elements.
				CPPUNIT_ASSERT( B.at(i) == i+1 );
			}
		}
		
		//Create the test suite using CPPUnit macros.
		CPPUNIT_TEST_SUITE( CountingsortTest );
		CPPUNIT_TEST( testSortBasic );
		//CPPUNIT_TEST_EXCEPTION( testPossibleOutOfRangeLower, std::out_of_range );
		//CPPUNIT_TEST_EXCEPTION( testPossibleOutOfRangeUpper, std::out_of_range );
		CPPUNIT_TEST_SUITE_END( );
};

int main( )
{
	CPPUNIT_TEST_SUITE_REGISTRATION( CountingsortTest );
	CppUnit::TextUi::TestRunner runner;
	CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry( );
	runner.addTest( registry.makeTest( ) );
	if ( runner.run( ) )
	{//Runner had success.
		return 0;
	}
	else
	{//Runner failed.
		return 1;
	}
}
