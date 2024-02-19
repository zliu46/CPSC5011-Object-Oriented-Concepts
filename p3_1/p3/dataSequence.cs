/**
 * Zhou Liu
 * dataSequence.cs
 * Purpose:
 * This is the dataSequence class that holds an integer array.
 * This class allows to swap the number on the array, and gets the value of 
 * the number by using the index.
 * 2/23/23
 * @version 1.0
 */
using System;
public class dataSequence
{
    private int[] sequence;//Hold the sequence.
    private int size;//Hold the size of sequence.

    public dataSequence(int size)
    {
        this.size = size;//Initialize the size.
        sequence = new int[size];//Initialize the sequence array.
        reset();//Call a reset function.

    }
    /**
     * This function will reset the elements on the sequence.
     */
    private void reset()
    {
        Random rand = new Random();
        for (int i = 0; i < size; i++)
        {
            sequence[i] = rand.Next(1, 100);
        }
    }
    /*
	 * A swap function that swap the value stored in the array.
	 * @param integer indexes of positions.
	 */
    public void swap(int a, int b)
    {
        int temp = sequence[a];//Hold the temp value.
        sequence[a] = sequence[b];//Swap the value.
        sequence[b] = temp;//Swap the value with temp.

    }
    /*
     * This method returns the element on the sequence.
     * @param number's index.
     * @return number on the sequence.
     */
    public int get(int i)
    {
        if (i < size && i >= 0)//Using a foor loop to find the position.
        {
            return sequence[i];//return the number.
        }
        return -1;//Return -1 when it is out of range.
    }
    public int getSize() { return size; }//Return the size of sequence.
    /*
     * This method will reset the value on the sequence by using index.
     * @param index of element, new integer value.
     */
    public void set(int i, int v) { sequence[i] = v; }

}

