#include "pch.h"
#include "CppUnitTest.h"

#include "../Lab_5.1(F)/Triangle_Public.cpp"
#include "../Lab_5.1(F)/Triangle_Private.cpp"
#include "../Lab_5.1(F)/Triad.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab51F
{
	TEST_CLASS(UnitTestLab51F)
	{
	public:
		
		TEST_METHOD(Test_Triangle_Public)
		{
			Triangle_Public a(5, 7, 8);
			Assert::AreEqual(a.Addition(), 20.0);
		}

		TEST_METHOD(Test_Triangle_Private)
		{
			Triangle_Private a(5, 5, 6);
			Assert::AreEqual(a.Calcul_Square(), 12.0);
		}
	};
}