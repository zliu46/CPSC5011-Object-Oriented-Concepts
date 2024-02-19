/**
 * @author Zhou Liu
 * duelingJP.cpp
 * Purpose: this is the cpp file of duelingJP clas.
 * @version 1.0
 * 3/9/23
 */
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
/**
 * This method will add all jumpPrime objects to the current duelingJP.
 * @param obj
 * @return duelingJP
 */
duelingJP duelingJP::operator+(const duelingJP & obj) {
    //Create a for loop to add each element to the current obj.
    for (int i = 0; i < obj.jPCount; i++) {
        //Call a resize method if the array is full.
        if(jPCount > size) {
            resize();
        }
        array[jPCount++] = obj.array[i];
    }
    //Return this.
    return *this;
}
/**
 * This method will remove all jumpPrime objects exist in the passed duelingJP
 * from the current duelingJP.
 * @param obj
 * @return duelingJP
 */
duelingJP duelingJP::operator-(const duelingJP & obj) {
    jumpPrime * temp = new jumpPrime[size];//Create an array to hold jp elements.
    int count = 0;//Initialize the index of temp obj.
    bool exist = false;
    //Check if the element in the current obj exists.
    for (int i = 0; i < jPCount; i++ ) {
        for (int j = 0; j < obj.jPCount; j++) {
            if (array[i] == obj.array[j]) {
                exist = true;
            }
        }
        //Add the distinct jp obj to the array.
        if (!exist) {
            temp[count++] = array[i];
        }
    }
    //Initialize the numbers of JP.
    jPCount = count;
    //Delete current array.
    delete [] array;
    //Initialize the array that holds jps.
    array = temp;
    //Return this.
    return *this;
}
//Pre-increment operator.
duelingJP duelingJP::operator++(){
    //Increment each jp object by using a for loop.
    if (array != nullptr) {
        for (int i = 0; i < jPCount; i++) {
            array[i]++;
        }
    }
    return *this; //Return the obj.
}
//pre-decrement operator.
duelingJP duelingJP::operator--(){
    //Decrement each jp object by using a for loop.
    if (array != nullptr) {
        for (int i = 0; i < jPCount; i++) {
            array[i]--;
        }
    }
    return *this;
}
//Post-increment operator.
duelingJP duelingJP::operator++(int){
    duelingJP temp = *this;
    if (temp.array != nullptr) {
        for (int i = 0; i < jPCount; i++) {
            ++temp.array[i];//Increment the jp obj.
        }
    }
    return temp;
}
//Post-decrement operator.
duelingJP duelingJP::operator--(int){
    if (array != nullptr) {
        for (int i = 0; i < jPCount; i++) {
            --array[i];//Decrement the jp obj.
        }
    }
    return *this;
}
//Relational operator.
bool duelingJP::operator==(const duelingJP & obj) {
    if (jPCount != obj.jPCount) {//Check if they have the same number of objects.
        return false;
    }
    //Compare each element by using a for loop.
    for (int i = 0; i < jPCount; i++) {
        if(array[i] != obj.array[i]) {
            return false;
        }
    }
    return true;
}
bool duelingJP::operator!=(const duelingJP & obj) {
    if (jPCount != obj.jPCount) {//Check if they have the same number of objects.
        return true;
    }
    //Compare each element by using a for loop.
    for (int i = 0; i < jPCount; i++) {
        if(array[i] != obj.array[i]) {
            return true;
        }
    }
    return false;
}
bool duelingJP::operator>(const duelingJP &obj) {
    return jPCount > obj.jPCount;//Compare the number of elements in duelingJP.
}
bool duelingJP::operator<(const duelingJP &obj) {
    return jPCount < obj.jPCount;//Compare the number of elements in duelingJP.
}
bool duelingJP::operator>=(const duelingJP &obj) {
    return jPCount >= obj.jPCount;//Compare the number of elements in duelingJP.
}
bool duelingJP::operator<=(const duelingJP &obj) {
    return jPCount <= obj.jPCount;//Compare the number of elements in duelingJP.
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

