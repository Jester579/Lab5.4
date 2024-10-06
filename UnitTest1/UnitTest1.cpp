#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab5.4/Source.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double i = 1;
			double c = (pow(sin(i), 2) + pow(cos(1. / i), 2)) / pow(i, 2);
			Assert::AreEqual(c, i, 0);
		}
	};
}
