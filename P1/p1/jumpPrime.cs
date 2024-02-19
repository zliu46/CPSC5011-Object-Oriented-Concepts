//Zhou Liu
//jumpPrime.cs
//This is the jumpPrime class.
//1/19/23
//@verstion 1.0

using System;
namespace p1
{
	public class jumpPrime
	//This class takes a 4 digits number.
	//This class allows the user to jump the input number to the next
	//prime number.
	//The user feels free to keep jumpping the number until the current number
	//has become out of range.
	//This class allows the user to reset the object to the original version.
	//This class allows the user to acheive stats such as status, query count,
	//and current number.
    {
		private int number;//To hold the orignial number.

		//Create a enum to store different status.
		private enum Status { Active, Inactive, Deactivated };

		//To hold the status.
		private Status status;

		//To count the queries.
		private int queryCount;

		//To hold the current number after jump.
		private int currNum;

		//argument constructor
		//@param: input number from the user.
		public jumpPrime(int num)
		{
			//Check if the input number is in range.
			//Throws an exception if the number is invalid.
			if (num > 9999 || num < 1000)
			{
				throw new ArgumentOutOfRangeException();
			}
			
			number = num;//Initialize the original number.
			currNum = num;//Initialize the current number.
			status = Status.Active;//Set status.
			queryCount = 0;//Initialize the query count.
		}

		//This function checks if the number is a prime number.
		//@param: an integer number.
		//@return: boolean if the number is a prime number.
		private static bool isPrime(int curr)
		{
			//Call a for loop to check if it is a prime number.
			for (int i = 2; i <= Math.Sqrt(curr); i++)
			{
				if (curr % i == 0)
				{
					return false;
				}
			}

			return true;
		}

		//This function checks if the current number is out of range.
		//@return: boolean if the current number is invalid.
		private bool outOfRange()
		{
			//Check if the current number is not a 4 digits number.
			if (currNum < 1000 || currNum > 9999)
			{
				return true;
			}
			return false;
		}

		//This is the up function that jump up the number to the next
		//prime number
		//@return: the next prime number.
		public int up()
		{	//Check if the current number is valid.
			//Throw an exception if the number is out of range.
			if (outOfRange())
			{
				throw new Exception("out of range");
			}
			else
			{
				//Check the next number until it is a prime number.
				int temp = currNum + 1;
				while (!isPrime(temp))
				{
					temp++;
				}
				//Computing the queries that took to jump.
				//Set queryCount.
				queryCount += temp - number;
				//Set currNum to the next prime number.
				currNum = temp;
				//Return the prime number.
				return temp;
			}
		}

        //This is the up function that jump down the number to the next
        //prime number.
		//@return: the next prime number.
        public int down()
        {
			// Check if the current number is valid.
            //Throw an exception if the number is out of range.
            if (outOfRange())
			{
				throw new Exception("out of range");
			}
			else
			{
				int temp = currNum - 1;
                //Call a while loop to check the next number until
				//it is a prime number.
                while (!isPrime(temp))
				{
					temp--;
				}
                //Computing the queries that took to jump.
                //Set queryCount.
                queryCount += number - temp;
                //Set currNum to the next prime number.
                currNum = temp;
                //Return the prime number.
                return temp;
			}
        }
		//This fuction revives the status of jumpPrime object.
		public void revive()
		{
            //Set object to be permanently deactivated when it's already active.
            if (status == Status.Active)
			{
				status = Status.Deactivated;
			}
			//Set object to be active if it was inactive.
			else if (status == Status.Inactive)
			{
				status = Status.Active;
			}
			//stay deactivated.
			else
				return;
		}

		//This function resets the object.
		public void reset()
		{
			//Resets the status to be active.
			status = Status.Active;
			//Resets the query count.
			queryCount = 0;
			//Resets the current number to the original number.
			currNum = number;
		}

        //accessor
		//This function gets the current number.
		//@return: the value of current number.
        public int getNum() { return currNum; }

		//This function gets the query count.
		//@return: query count.
		public int getQuery() { return queryCount; }

		//This functions will prints out the current status of object.
		public void getStatus()
		{
			//Call a switch statement to prints out the status of object.
			switch (status)
			{
				case Status.Active:
				
					Console.WriteLine ("Active");
					break;
                case Status.Inactive:

                    Console.WriteLine("Inactive");
                    break;
				case Status.Deactivated:
                    Console.WriteLine("Deactivated");
                    break;
            }
        }

    }
}

