//Zhou Liu
//dataCut.cs
//Purpose: This is the dataCut class
//This class consists of 2 functions. filter method, iremoves the maximum
//number when in ‘large’ mode; otherwise, removes the minimum/
//scramble(seq) removes any number that occurred in the previous scramble
//request before scrambling.
//2/23/23
//@version 1.0
using System;
public class dataCut : dataFilter
{
    //This is a child class of dataFilter.
    /*
     * Constructor
     * @param prime number, sequence.
     */
    public dataCut(int p, dataSequence seq) : base(p, seq) { }
    /*
     * override the filter method.
     */
    public override int[] filter()
    {
        int index;//Holds the index of array.
        int n = 0;//Set index n.
        //Check if it is in large mode.
        if (mode)
        {
            //Initialize the array.
            array = new int[size];
            //Store sequence to the array,
            for (int i = 0; i < size; i++)
            {
                int temp = seq.get(i);

                array[n] = temp;
                n++;

            }
            //Find the index of maximum on the sequence.
            index = findMax(array);
            //Set the element to 0.
            array[index] = 0;
            //Return the array.
            return array;
        }
        else
        {   //In small mode, remove the minimum on the sequence.
            array = new int[size];//Initialize the array.
            //Add elements on the sequence to the array.
            for (int i = 0; i < size; i++)
            {
                int temp = seq.get(i);

                array[n] = temp;
                n++;

            }
            //Find the minimum.
            index = findMin(array);
            //Set the number to zero.
            array[index] = 0;
            //Return the array.
            return array;
        }
    }
    /*
     * This is the method that finds the maximum on the array.
     * @param int [] array.
     * @return index of maximum.
     */
    private int findMax(int[] arr)
    {
        int size = arr.Length;
        int max = 0;
        int index = 0;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] > max)
            {
                max = arr[i];
                index = i;
            }
        }
        return index;
    }
  /*
   * This is the method that finds the minmum on the array.
   * @param int [] array.
   * @return index of minimum.
   */
    private int findMin(int[] arr)
    {
        int size = arr.Length;
        int min = 100;
        int index = 0;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] < min)
            {
                min = arr[i];
                index = i;
            }
        }
        return index;
    }
    /*
     * Override the scramble method.
     */
    public override int[] scramble(dataSequence s)
    {

        int size = s.getSize();//Hold size of the sequence.
        array = new int[size];//Initialize the array.
        int n = scrambleArr.Length;//Hold the size of passed sequence.
        //Store the sequence to the array.
        for (int i = 0; i < size; i++)
        {
            array[i] = s.get(i);

        }
        //Remove all elements on the sequence that are same to the elements
        //on the passed sequence.
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (array[j] == scrambleArr[i])
                {
                    array[j] = 0;//Set the number to zero.
                }
            }
        }
        //Set the scrambled array.
        scrambleArr = array;
        //Return the array.
        return array;
    }
}

