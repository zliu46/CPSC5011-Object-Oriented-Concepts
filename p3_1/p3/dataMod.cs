//Zhou Liu
//dataMod.cs
//Purpose: This is the dataMod class
//This class consists of 2 functions. filter method, increments each value
//when in ‘large’ mode; otherwise, decrements, scramble(seq) replaces all
//prime numbers with ‘2’ before scrambling.
//2/23/23
//@version 1.0
using System;
public class dataMod : dataFilter
{
    //This is a child class of dataFilter.
    /*
     * Constructor.(same to the parent class).
     * @param prime number, sequence.
     */
    public dataMod(int p, dataSequence seq) : base(p, seq) { }
    //Override the function filter.
    public override int[] filter()
    {
        int n = 0;//Set index of array.
        //Check if it is "large" mode.
        if (mode)
        {
            //Initialize the array.
            array = new int[size];
            //Increment elements on the sequence.
            for (int i = 0; i < size; i++)
            {
                int temp = seq.get(i);

                array[n] = temp + 1;//Store the values to the array.
                n++;//Increment the index.

            }
            //Return the array.
            return array;
        }
        else
        {
            array = new int[size];
            //Decrement the elements on the sequence
            for (int i = 0; i < size; i++)
            {
                int temp = seq.get(i);
                //Store the element to the array.
                array[n] = temp - 1;
                n++;//Increment the index.

            }
            //Return the array.
            return array;
        }
    }
    //Override the scramble function.
    public override int[] scramble(dataSequence s)
    {
        //Initialize the array.
        array = new int[s.getSize()];
        //Holds the size of sequence.
        int size = s.getSize();
        //replaces all prime numbers with ‘2’ 
        for (int i = 0; i < size; i++)
        {
            if (isPrime(s.get(i)))
            {
                s.set(i, 2);
            }
        }
        //Store elements on the sequence to the array.
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
