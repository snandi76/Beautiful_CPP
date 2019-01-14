using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using MathClassLibrary;
namespace MathTestProject
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestAdd()
        {
            //Arrange
            int expected = 20;
            MathsComponent obj = new MathsComponent();
            //Act
            int result = obj.Add(10, 10);
            //Assert
            Assert.AreEqual(expected, result);
          
        }
    }
}
