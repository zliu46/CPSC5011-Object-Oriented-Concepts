//Zhou Liu
//dataFilters.cs
//Purpose: This is the dataFilters class
//This class consists of 2 functions. filter method, returns a subset of an
//encapsulated integer sequence.Scramble method, updates the encapsulated
//sequence with seq, if not null, returns a reordered integer sequence.
//2/23/23
//@version 1.0
using System;
public class dataFilter
{
    protected int primeNumber;//Holds a prime number.
    protected dataSequence seq;//Holds an interger sequence.
    protected int[] array;//Holds the result of filter.
    protected int[] scrambleArr;//Holds the last scrambled result.
    protected const int size = 10;//Set the size for the sequence.
    protected bool mode;  //true is "large" mode, false is "small" mode.
    /**
     * Constructor
     * @param int prime number, integer sequence.
     */
    public dataFilter(int p, dataSequence seq)
    {
        //Check if the number is valid.
        try
        {
            if (isPrime(p))
            {
                primeNumber = p;
            }
            else
                //Throw an exception if it is needed.
                throw new Exception("number is invalid!");

        }
        catch (Exception e)
        {
            Console.Write(e);
        }
        //Initialize the sequence.
        this.seq = seq;
        //Create a integer new array.
        array = new int[size];
        //Create an array to hold the last scrambled result.
        scrambleArr = new int[size];
        //Initialize the mode.
        mode = true;
    }
    /**
     * This is the filter method that returns a subset of an encapsulated 
     * integer sequence. when in ‘large’ mode, all integers larger than p,
     * when in ‘small’ mode, all integers smaller than p.
     * @return integer array of result.
     */
    public virtual int[] filter()
    {
        int n = 0;//Hold the index of the array.
        //Implement large mode if mode is true.
        if (mode)
        {
            //Create a new array.
            array = new int[size];
            //Store each element from the sequence to the array.
            for (int i = 0; i < size; i++)
            {
                //Check if numbers are larger than the prime number p.
                //In "large" mode, only return the sequence that is larger than
                //the prime number.
                int temp = seq.get(i);
                if (temp > primeNumber)
                {
                    array[n] = temp;//Store the number to the array.
                    n++;//Index increment.
                }
            }
            //Return the array.
            return array;
        }
        else
        {   //In "small" mode, only return numbers of sequence that are smaller
            //than the prime number p.
            array = new int[size];//Create a new object.
            n = 0;
            for (int i = 0; i < size; i++)
            {
                int curr = seq.get(i);//Holds the element.
                //Check if the number is smaller than p.
                if (curr < primeNumber)
                {
                    array[n] = curr;//Store the number to the array.
                    n++;//index increment.
                }
            }
            //Return the array.
            return array;
        }
    }
    /**
     * This is the scramble method that takes a sequence and update it when it
     * is not null. Returns a reordered integer sequence.
     * @param sequence
     * @return int array of result.
     */
    public virtual int[] scramble(dataSequence s)
    {
        //Check if the sequence is null.
        try
        {
            if (s != null)
            {
                //Update the sequence.
                this.seq = s;

            }
            else
                //Throw exception if it is necessary.
                throw new Exception("Sequence is null.");
        }
        catch (Exception e)
        {
            Console.Write(e);
        }
        //Get the size of sequence.
        int size = seq.getSize();
        //Set the pairs number.
        int n = size / 2;
        //Hold index from the beginning of sequence.
        int start = 0;
        //Hold index from the end of sequence.
        int end = size - 1;
        //Create a new array.
        array = new int[size];
        //Check mode.
        if (mode)
        {
            //In "large" mode, swap the values that are even.
            //for exmaple, 1st to last element, 2rd to the element before
            //the last element, etc.

            s = seq;//Reset the sequence.
            for (int i = 0; i < n; i++)
            {
                //Check if numbers are paired.
                if (s.get(start) % 2 == 0 && s.get(end) % 2 == 0)
                {
                    //Swap the sequence order.
                    s.swap(start, end);

                }
                //move to the next paried number.
                start++;
                end--;
            }
            //Store the sequence result to the array.
            for (int i = 0; i < size; i++)
            {
                array[i] = s.get(i);
            }
            //Set the last scrambled array.
            scrambleArr = array;
            //Return the array.
            return array;
        }
        else
        {
            //Reset the sequence.
            s = seq;
            //Check if paired numbers are odd. Swap the odd numbers.
            for (int i = 0; i < n; i++)
            {
                if (s.get(start) % 2 != 0 && s.get(end) % 2 != 0)
                {

                    s.swap(start, end);//Swap the value.

                }
                //Move to the next number indexes.
                start++;
                end--;
            }
            //Store the sequence to the array.
            for (int i = 0; i < size; i++)
            {
                array[i] = s.get(i);
            }
            //Set scrambled array.
            scrambleArr = array;
            //Return the array.
            return array;
        }
    }
    /*
     * This method check if the number is a prime number.
     */
    protected bool isPrime(int p)
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
    /*
     * Method to change the mode to "large" or "small".
     */
    public void changeMode() { mode = !mode; }
}

