//Zhou Liu
//P1.cs
//This is the program that tests each function of jumpPrime class.
//1/19/23
//@verstion 1.0

using System;

namespace p1
{
    class p1
    {
        //This is the test method to test creating a new jumpPrime object.
        //I hardcode the number for each function because it would be easier
        //for me to test different numbers.
        public static void Test2488()
        {
            //Create a new jumpPrime Object.
            jumpPrime myObj = new jumpPrime(2488);

        }

        //This method tests creating a jumpPrime object by using a negative
        //number.
        public static void TestNegativeInput()
        {
            //Passing -1 to jumpPrime class.
            //It will throw an exception showing "invalid number".
            jumpPrime myObj = new jumpPrime(-1);
        }

        //This method tests the Up function of jumpPrime class.
        public static void TestUp()
        {
            //Create a new obj.
            jumpPrime myObj = new jumpPrime(2488);
            //Call a Up function.
            //Prints out the next prime number.
            Console.WriteLine("Nearest prime more than given number: " +
                myObj.up() + "\n");

        }

        //This method tests the Down function of jumpPrime class.
        public static void TestDown()
        {
            //Create a new obj.
            jumpPrime myObj = new jumpPrime(2488);

            //Call a Down function.
            //Prints out the next prime number.
            Console.WriteLine("Nearest prime less than given number: " +
                        myObj.down() + "\n");

        }

        //This is the method that tests the Reset function.
        public static void TestReset()
        {
            //Create a new object.
            jumpPrime myObj = new jumpPrime(2488);
            //Call a reset function.
            myObj.reset();
            //Prints out the number after reset.
            Console.WriteLine(myObj.getNum());
        }

        //This method tests the Revive function.
        public static void TestRevive()
        {
            //Create a new Object.
            jumpPrime myObj = new jumpPrime(2488);
            //Call a revive function..
            myObj.revive();
            //Call a getStatus function to prints out the Status.
            myObj.getStatus();
        }

        //This method tests the GetStatus function.
        public static void TestGetStatus()
        {
            //Create a new Obj.
            jumpPrime myObj = new jumpPrime(2488);
            //Call a getStatus function.
            myObj.getStatus();
        }

        //This method tests the getCurrNum function.
        public static void TestGetCurrNum()
        {
            //Create a new object.
            jumpPrime myObj = new jumpPrime(2488);
            //Call a getNum function and prints it out.

            Console.WriteLine(myObj.getNum());
        }

        //This method tests the getQuery function.
        public static void TestGetQuery()
        {
            //Create a new Object.
            jumpPrime myObj = new jumpPrime(2488);
            //Jump down the number.
            myObj.down();
            //Prints out the query count.
            Console.WriteLine(myObj.getQuery());
        }
        //This method tests ranOutOfRangeLow function.
        public static void TestRanOutOfRangeLow()
        {
            //Create a new Object.
            jumpPrime myObj = new jumpPrime(1200);

            //Jump down the number until it is out of range.
            for (int i = 0; i < 100; i++)
            {
                myObj.down();
            }
        }
        //This method tests ranOutOfRangeHigh function.
        public static void TestRanOutOfRangeHigh()
        {
            //Create a new object.
            jumpPrime myObj = new jumpPrime(9500);

            //Jump up the number until it is out of range.
            for (int i = 0; i < 100; i++)
            {
                myObj.up();
            }
        }

        //This is the main method that runs each test method.
        public static void Main(string[] args)
        {
            //Call a Test2488 method.
            Test2488();

            //call a TestUp method.
            TestUp();

            //call a TestDown method.
            TestDown();

            //Call a TestNegativeInput method.
            //TestNegativeInput();

            //Call a TestReset method.
            TestReset();

            //Call a Revive method.
            TestRevive();

            //Call a TestRanOutOfRangeHigh method.
            TestRanOutOfRangeHigh();

            //Call a TestRanOutOfRangeLow method.
            TestRanOutOfRangeLow();

            //Call a TestGetQuery method.
            TestGetQuery();

            //Call a TestGetStatus method.
            TestGetStatus();

            //Call a TestGetCurrNum method.
            TestGetCurrNum();
        }

        
    }
}