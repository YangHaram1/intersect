#include "CppUnitTest.h"
#include "../intersect/intersect.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Point P[100];
			int n = 3;
			Point p("L",0, 0, 1, 1);
			Point p1("L",1, 0, 0, 1);
			Point p2("L",1, 2, 2, 0);
			P[0] = p;
			P[1] = p1;
			P[2] = p2;

			Assert::AreEqual(3.0,solve(P,n));
		}
		TEST_METHOD(TestMethod2)
		{
			Point P[100];
			int n = 4;
			Point p("L", 0, 0, 1, 1); //1
			Point p1("L", 1, 0, 0, 1);// -1
			Point p2("L", 1, 2, 2, 0);//-2
			Point p3("L", 0, 0, 2, 1);//0.5
			P[0] = p;
			P[1] = p1;
			P[2] = p2;
			P[3] = p3;
			Assert::AreEqual(6.0, solve(P, n));
		}
		TEST_METHOD(TestMethod3)
		{
			Point P[100];
			int n = 5;
			Point p("L", 0, 0, 1, 1);
			Point p1("L", 1, 0, 0, 1);
			Point p2("L", 1, 2, 2, 0);
			Point p3("L", 0, 0, 2, 1);//-0.5
			Point p4("L", 1, 1, 2,2);//1
			P[0] = p;
			P[1] = p1;
			P[2] = p2;
			P[3] = p3;
			P[4] = p4;
			Assert::AreEqual(9.0, solve(P, n));
		}
		TEST_METHOD(TestMethod4)
		{
			Point P[100];
			int n = 4;
			Point p("L", 0, 0, 1, 1);//1
			Point p1("L", 1, 0, 0, 1);//-1
			Point p2("L", 1, 2, 2, 0);//-2
			Point p3("L", 1, 1, 2, 2);//1
			P[0] = p;
			P[1] = p1;
			P[2] = p2;
			P[3] = p3;
			Assert::AreEqual(5.0, solve(P, n));
		}
		TEST_METHOD(TestMethod5)
		{
			Point P[100];
			int n = 3;
			Point p("L", 0, 0, 1, 1);
			Point p1("L", 1, 2, 2, 4);
			Point p2("L", 1, 2, 2, 0);
			P[0] = p;
			P[1] = p1;
			P[2] = p2;

			Assert::AreEqual(3.0, solve(P, n));
		}
		TEST_METHOD(TestMethod6)
		{
			Point P[100];
			int n = 3;
			Point p("L", 0, 0, 1, 1);
			Point p1("L", 1, 3, 2, 6);
			Point p2("L", 1, 2, 2, 0);
			P[0] = p;
			P[1] = p1;
			P[2] = p2;

			Assert::AreEqual(3.0, solve(P, n));
		}
		TEST_METHOD(TestMethod7)
		{
			Point P[100];
			int n = 3;
			Point p("L", 0, 0, 1, 1);//1
			Point p1("L", 0, 0, 2, 2);//1
			Point p2("L", 3, 3, 0, 0);//1
			P[0] = p;
			P[1] = p1;
			P[2] = p2;

			Assert::AreEqual(0.0, solve(P, n));
		}
		TEST_METHOD(TestMethod8)
		{
			Point P[100];
			int n = 4;
			Point p("L", 0, 0, 1, 1);
			Point p1("L", 0, 0, 3, 3);
			Point p2("L", 1, 1, 2, 2);
			Point p3("L", 1, 1, 4, 4);//1
			P[0] = p;
			P[1] = p1;
			P[2] = p2;
			P[3] = p3;

			Assert::AreEqual(0.0, solve(P, n));
		}
		TEST_METHOD(TestMethod9)
		{
			Point P[100];
			int n = 3;
			Point p("L", 0, 0, 1, 1);
			Point p1("L", 1, 2, 2, 4);
			Point p2("L", 0, 0, 1, 4);

			P[0] = p;
			P[1] = p1;
			P[2] = p2;

			Assert::AreEqual(1.0, solve(P, n));
		}
		TEST_METHOD(TestMethod10)
		{
			Point P[100];
			int n = 3;
			Point p("L", 0, 0, 1, 1);
			Point p1("L", 0, 1, 1, 3);
			Point p2("L", -1, -1, 1, 4);

			P[0] = p;
			P[1] = p1;
			P[2] = p2;

			Assert::AreEqual(1.0, solve(P, n));
		}
	

	};
}
