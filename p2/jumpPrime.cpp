//Zhou Liu
//jumpPrime.cpp
//Purpose: this is the cpp file of jumpPrime class from P1.
//version 1.0
//2/6/23

#include "jumpPrime.h"
#include <iostream>
#include <cmath>
using namespace std;
//Constructor.
jumpPrime::jumpPrime() {
}
//Constructor
//IN: integer 4 digits.
jumpPrime::jumpPrime(int val) {
    minRange = 999;//Set minimum range.
    maxRange = 9999;//Set maximum range.
    try {
        //Check if the input from the user is in the range.
        if (val <= maxRange && val > minRange ) {
            number = val;//Set number.
            currNum = number;//Set current number.
            status = Active;//Set status.
            queryCount = 0;//Set number of queries.
        }
        else
            throw val;//Throw an exception if the number is out of range.
    }
    catch (int num){
        //Prints out the exception.
        cout << "You must enter a 4 digits number." << endl;
    }
}

/*
 * A method that checks if the number is a prime number.
 * IN:value of number.
 * OUT:boolean if the number is prime.
 */
bool jumpPrime::isPrime(int val) {
    //Create a for loop to calculate the factors.
    for (int i = 2; i <= sqrt(val); i++) {
        if (val % i == 0) {
            return false;
        }
    }
    return true;
}
/*
 * outOfRange function could be a part of jump() method?
 * OUT: boolean if the current number is out of range,
 */
bool jumpPrime::outOfRange() {
    //Check if current number is larger than the maximum range.
    if (currNum > maxRange) {
        return true;
    }
    else
        return false;
}
//A method that allows the current number to "jump" up after certain queries.
void jumpPrime::jump() {
    //number is going to jump up the number of  queries.
    currNum = number + queryCount;
}
//A method to find the next prime number of current number.
//OUT: next prime number, integer.
int jumpPrime::up() {
    try {
        //int curr = currNum;
        int temp = currNum + 1;
        //Find the next prime number by using a while loop.
        while (!isPrime(temp)) {
            temp++;
        }
        //Compute the number of queries.
        queryCount += temp - number;
        //Jump the number.
        jump();
        //Check if it is possible to jump the number.
        if (!outOfRange()) {
            return temp;
        }
        else
            throw temp;
    }
    //Throw a out of range exception.
    catch (int num) {
        cout << num << "is out of range." << endl;
    }
    //Return the number after jumping.
    return currNum;
}
//A method to find the previous prime number.
int jumpPrime::down() {
    try {
        //int curr = currNum;
        int temp = currNum - 1;
        while (!isPrime(temp)) {
            temp--;
        }
        queryCount += currNum - temp;
        jump();
        if (!outOfRange()) {
            return temp;
        }
        else
            throw temp;
    }
    catch (int num) {
        cout << num << " is out of range." << endl;
    }
    return currNum;
}

//A method to reset the class.
void jumpPrime::reset() {
    status = Active;
    queryCount = 0;
    currNum = number;
}
//A method to revive the status of JP obj.
void jumpPrime::revive() {
    if (status == Active)
        status = Deactivated;
    else if (status == Inactive)
        status = Active;
    else
        return;
}
/**
 * I was thinking to have getter functions such as getNum(), getStatus(),
 * get Queries(), etc.
 * Now I decided to use a function that returns a string about all the information.
 */
//int jumpPrime::getNum() { return currNum;}//Change to getStats()?
void jumpPrime::getStats() {
    cout << "Number: " << currNum << "\nStatus: " << getStatus() << "\nQueries: "
    << queryCount;
}
//A method that returns a string of current status.
string jumpPrime::getStatus() {
    switch (status) {
        case Active:
            return "Active";
        case Inactive:
            return "Inactive";
        case Deactivated:
            return "Deactivated";
    }
    return"";
}
