#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestProject
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestAdd)
		{
			//Arrange
			int expected = 20;
			MathsComponent obj = new MathsComponent;
			//Act
			int result = obj.Add(10, 10);
			//Assert
			Assert.AreEqual(expected,result);

		}

	};
}