//Zhou Liu
//duelingJP.cpp
//Purpose: this is the cpp file of duelingJP clas.
//version 1.0
//2/6/23

#include "duelingJP.h"
#include "jumpPrime.h"
/*
 * Non-argument constructor.
 */
duelingJP::duelingJP() {
    array = new jumpPrime[size];//Initialize array to hold JP objects.
    numCollisions = 0;//Set number of collisions.
    numInversions = 0;//Set number of inversions.
    jPCount = 0;//Set number of JP.
}
/*
 * DeepCopying
 * IN: const address duelingJP object.
 */
duelingJP::duelingJP(const duelingJP& obj) {
    //Call a copy sub function.
    copy(obj);
}
/*
 * copy function that copy duelingJP obj to current obj.
 * IN: duelingJP object.
 */
void duelingJP::copy(const duelingJP& obj) {
    //Reset a new array.
    array = new jumpPrime[size];
    //Copy each element on the array by using a for loop.
    for (int i = 0; i < obj.jPCount; i++) {
        array[i] = obj.array[i];
    }
    //Copy number of collisions.
    this->numCollisions = obj.numCollisions;
    //Copy number of inversions.
    this->numInversions = obj.numInversions;
    //Copy number of JP objects.
    this->jPCount = obj.jPCount;
}

/*
 * overloading operator= function.
 * IN: a duelingJP object on the right side of operand.
 */
duelingJP& duelingJP::operator=(const duelingJP & obj) {
    //Compare two duelingJP objects.
    if(this != &obj) {
        delete [] array;//Delete current array.
        array = new jumpPrime[size];//Set a new array.
        //Use a for loop to copy each element on the array.
        for (int i = 0; i < obj.jPCount; i++) {
            array[i] = obj.array[i];
        }
        //Copy number of collisions.
        this->numCollisions = obj.numCollisions;
        //Copy number of inversions.
        this->numInversions = obj.numInversions;
        //Copy number of JP objects.
        this->jPCount = obj.jPCount;
    }
    //Return curr duelingJP object.
    return *this;
}
/*
 * && move semantics.
 * efficient deep copying supported.
 * IN: reference to duelingJP object.
 */
duelingJP::duelingJP(duelingJP && obj) noexcept {
    //Copy array from obj.
    array = obj.array;
    //Copy number of collisions.
    this->numCollisions = obj.numCollisions;
    //Copy number of inversions.
    this->numInversions = obj.numInversions;
    //Copy number of JP.
    this->jPCount = obj.jPCount;
    //Reset obj to 0.
    obj.numCollisions = 0;
    //Reset obj to 0.
    obj.numInversions = 0;
    //Reset obj array to nullptr.
    obj.array = nullptr;
}
/*
 * && move semantics.
 * efficient deep copying supported.
 * IN: reference to duelingJP object.
 */
duelingJP& duelingJP::operator=(duelingJP && obj) noexcept {
    //Swap the array.
    swap(array, obj.array);
    //Swap the value of number of inversions.
    swap(numInversions, obj.numInversions);
    //Swap the number of collisions.
    swap(numCollisions, obj.numCollisions);
    //Return this.
    return *this;
}
/*
 * Destructor.
 */

duelingJP::~duelingJP() {
    //Delete the pointer.
    delete [] array;
}
/*
 * This function takes JP as param then add it to the array.
 * IN: JP object.
 */
void duelingJP::addJumpPrime(jumpPrime jp) {
    //Check if it is out of range.
    if (jPCount > size) {
        //Call a function to resize the array.
        resize();
    }
    //Initialize array by using index.
    array[jPCount] = jp;
    //Increment of number of JP.
    jPCount++;
}
/*
 * Remove JP object from the class.
 * IN:array index.
 */
void duelingJP::removeJumpPrime(int index) {
    //traverse array started from the index by using a for loop.
    if (index <= jPCount) {
        for (int i = index; i < jPCount; i++) {
            array[i] = array[i+1];
        }
        //Decrement number of JP after removing.
        jPCount--;
    }
}
/*
 * A method that returns number of JP objects.
 */
int duelingJP::jumpPrimeCount() {
    return jPCount;
}
/*
 * A method manage JP objects and prints out the analyzing result.
 */
void duelingJP::runAnalysis() {
    //Create for loops to compare prime numbers of each JP object.
    for (int i = 0; i < jPCount; i++) {
        array[i].reset();//Reset the JP after "jump".
        for (int j = i + 1; j < jPCount; j++) {
            array[i].reset();//Reset the JP after "jump".
            array[j].reset();//Reset the JP after "jump".
            //Check if two obj produce the same prime number.
            if (array[i].up() == array[j].up()) {
                array[i].reset();//Reset the JP after "jump".
                array[j].reset();//Reset the JP after "jump".
                //Increment number of collisions.
                numCollisions++;
            }
            array[i].reset();//Reset the JP after "jump".
            array[j].reset();//Reset the JP after "jump".
            //Check inversions situations.
            if (array[i].up() == array[j].down()) {
                //Increment number of inversions.
                numInversions++;
            }
        }
    }
    //Prints out the analyzing results.
    cout << "number of collisions: " << numCollisions << "\nnumber of inversions: "
    << numInversions << endl;
}
//a function that resize the array.
void duelingJP::resize() {
    //Double the size.
    size = size * 2;
    //Create a new copy array.
    jumpPrime * curr = new jumpPrime[size];
    //Copy elements to the copy array.
    for (int i = 0; i < jPCount; i++) {
        curr[i] = array[i];
    }
    //Delete current array.
    delete [] array;
    //Initialize current array.
    array = curr;
    //Delete copy array.
    delete [] curr;
}

