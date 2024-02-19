//Zhou Liu
//p3.cs
//Purpose: This is the test driver to test dataFilters, dataMod, and dataCut.
//2/23/23
//@version 1.0

using System;
class p3 {
   public static void Main(string[] args)
    {
        testDataFilter();//Call a function to test dataFilter.
        testDataMod();//Call a funtion to test dataMod.
        testDataCut();//Call a funtion to test dataCut.
    }
    /**
     * This is the function that tests dataFilter.
     * The method will create a sequence object then pass it to a dataFilter
     * object.Test filter() and scramble() fucntions.
     */
    public static void testDataFilter()
    {
        const int SIZE = 10;//Set the size for the sequence.
        int p = 4;//Initialize a variable that holds a prime number.
        Random rand = new Random();//Create a random object.
        while (!isPrime(p))//Create a while loop to get a prime number.
        {
            p = rand.Next(1, 100);//Get a prime number range from 1 to 100.
        }
        Console.Write("===============Test DataFilter ==============\n");
        dataSequence seq = new dataSequence(SIZE);//Create a sequence.
        Console.Write("Sequence: ");
        for (int i = 0; i < SIZE; i++)//Using a foor loop to print out the
                                        //Sequence.
        {
            Console.Write(seq.get(i) + " ");
        }
        Console.Write("\nPrime: " + p + "\n" + "Mode: Large\n");

        Console.Write("Create a dataFilter ...\n");
        dataFilter ftr = new dataFilter(p, seq);//Create a dataFilter object.
        //Call filter() method. Store the array that is returned from
        //the method to an array.
        int[] fArr = ftr.filter();
        Console.Write("Filter: ");
        //Prints out the sequence after filter function.
        for (int i = 0; i < fArr.Length; i++)
        {
            if (fArr[i] != 0)
            {
                Console.Write(fArr[i] + " ");
            }
        }
        //Get an array from scramble method.
        int[] sArr = ftr.scramble(seq);
        Console.Write("\nScramble: ");
        //Prints out the result of scramble array.
        for (int i = 0; i < sArr.Length; i++)
        {
            if (sArr[i] != 0)
            {
                Console.Write(sArr[i] + " ");
            }
        }

        /*
         * Test functions in "small" mode.
         */
        Console.Write("\nChange Mode..." + "\n" + "Mode: Small\n");
        ftr.changeMode();//Change mode.
        int[] arr = ftr.filter();//Get the sequence from filter method.
        Console.Write("Filter: ");
        //Prints out the result of filter function.
        for (int i = 0; i < arr.Length;i++)
        {
            if (arr[i] != 0)
            {
                Console.Write(arr[i] + " ");
            }
        }
        //Gets the array from the scramble method.
        sArr = ftr.scramble(seq);
        Console.Write("\nScramble: ");
        //Prints out the result of array.
        for (int i = 0; i < sArr.Length; i++)
        {
            if (sArr[i] != 0)
            {
                Console.Write(sArr[i] + " ");
            }
        }
        
    }
    /*
     * This method tests dataMod class.
     * Testing filter() and scramble() methods.
     */

    public static void testDataMod()
    {
        const int SIZE = 10;//Set a size for integer seqence.
        int p = 4;//Holds a prime number.
        Random rand = new Random();//Create a random object.
        while (!isPrime(p))//Get a prime number.
        {
            p = rand.Next(1, 100);
        }
        Console.Write("\n===============Test DataMod ==============\n");
        dataSequence seq = new dataSequence(SIZE);//Create a sequence object.
        Console.Write("Sequence: ");
        //Prints out the sequence.
        for (int i = 0; i < SIZE; i++)
        {
            Console.Write(seq.get(i) + " ");
        }
        Console.Write("\nPrime: " + p + "\n" + "Mode: Large\n");

        Console.Write("Create a dataFilter ...\n");
        //Create a dataMod object.
        dataMod ftr = new dataMod(p, seq);
        //Get the array from the filter method.
        int[] fArr = ftr.filter();
        Console.Write("Filter: ");
        //Prints out the result of the array.
        for (int i = 0; i < fArr.Length; i++)
        {
            if (fArr[i] != 0)
            {
                Console.Write(fArr[i] + " ");
            }
        }
        //Get an array from the scramble method.
        int[] sArr = ftr.scramble(seq);
        Console.Write("\nScramble: ");
        //Prints out result of the array.
        for (int i = 0; i < sArr.Length; i++)
        {
            if (sArr[i] != 0)
            {
                Console.Write(sArr[i] + " ");
            }
        }
        //Change to "small" mode.
        Console.Write("\nChange Mode..." + "\n" + "Mode: Small\n");
        ftr.changeMode();
        int[] arr = ftr.filter();//Get the array.
        Console.Write("Filter: ");
        //Prints out the result.
        for (int i = 0; i < arr.Length; i++)
        {
            if (arr[i] != 0)
            {
                Console.Write(arr[i] + " ");
            }
        }
      
    }
    /**
     * This method tests dataCut class.
     * Testing filter and scramble methods.
     */
    public static void testDataCut()
    {
        const int SIZE = 10;//Set size for sequence.
        int p = 4;//Hold a prime number.
        Random rand = new Random();//Create a random object.
        while (!isPrime(p))//Get a prime number.
        {
            p = rand.Next(1, 100);
        }
        Console.Write("\n===============Test DataCut ==============\n");
        dataSequence seq = new dataSequence(SIZE);//Create a sequence object.
        Console.Write("Sequence: ");
        //Prints out the sequence.
        for (int i = 0; i < SIZE; i++)
        {
            Console.Write(seq.get(i) + " ");
        }
        Console.Write("\nPrime: " + p + "\n" + "Mode: Large\n");
        //Create a data filter.
        Console.Write("Create a dataFilter ...\n");
        dataCut ftr = new dataCut(p, seq);
        //Get the result from the filer method.
        int[] fArr = ftr.filter();

        Console.Write("Filter: ");
        //Prints out the result.
        for (int i = 0; i < fArr.Length; i++)
        {
            if (fArr[i] != 0)
            {
                Console.Write(fArr[i] + " ");
            }
        }
        //Get the result from the scramble method.
        int[] sArr = ftr.scramble(seq);
        Console.Write("\nScramble: ");
        //Prints out the result.
        for (int i = 0; i < sArr.Length; i++)
        {
            if (sArr[i] != 0)
            {
                Console.Write(sArr[i] + " ");
            }
        }
        //Change to "small" mode.
        Console.Write("\nChange Mode..." + "\n" + "Mode: Small\n");
        ftr.changeMode();//Call a change mode method.
        //Get the result from the filter.
        int[] arr = ftr.filter();
        //Prints out the result by using a for loop.
        Console.Write("Filter: ");
        for (int i = 0; i < arr.Length; i++)
        {
            if (arr[i] != 0)
            {
                Console.Write(arr[i] + " ");
            }
        }
    }
    /*
     * This is the method that checks if the number is a prime number.
     * @param int number
     * @return boolean number is a prime number.
     */
    public static bool isPrime(int p)
    {
        for (int i = 2; i <= Math.Sqrt(p); i++)
        {
            if (p % i == 0)
            {
                return false;
            }
        }
        return true;
    }
}
