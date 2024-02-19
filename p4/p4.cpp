/**
 * @author Zhou Liu
 * p4.cpp
 * Purpose: This is the test driver to test operator overloading in class
 * jumpPrime & duelingJP. This program will test mathematical operators,
 * relational operators, and shortcut operators.
 * @version 1.0
 * 3/9/23
 */
#include "jumpPrime.h"
#include "duelingJP.h"
#include <iostream>
#include <memory>
using namespace std;
/*
 * This method tests the mathematical operator overloading.
 */
void testMathematical();
/*
 * This method tests the relational operator overloading.
 */
void testRelational();
/*
 * This method tests the shortcut operator overloading.
 */
void testShortCut();
/*
 * This is main method that calls each test function.
 */
int main() {
    srand((unsigned) time(NULL));//Create a random obj.
    //Test each method multiple times by using a for loop.
    for (int i = 0; i < 3; i++) {
        cout << "\n\t\t\t\t" << "TEST" << i + 1 << endl;
        testMathematical();//Call a testMathematical function.
        testRelational();//Call a testRelational function.
        testShortCut();//Call a shortcut function.
    }
}
/**
 * This method may throw an exception due to object is out of range.
 * for example, if object a - object b is negative, the program will throw
 * an out of range exception.
 */
void testMathematical() {
    cout << "=============Test Mathematical=============" <<endl;
    int a, b, c;//To hold random numbers.
    a = 100 + (rand() % 99900);//Initialize a random number.
    b = 100 + (rand() % 99900);//Initialize a random number.
    c = 100 + (rand() % 99900);//Initialize a random number.
    cout << "... Create JumpPrime objects..." << endl;
    cout << "Encapsulate numbers: ";
    jumpPrime jp(a);//Create jumpPrime objects.
    jumpPrime jp1(b);//Create jumpPrime objects.
    jumpPrime jp2(c);//Create jumpPrime objects.
    cout << "... Testing ... " << endl;
    jp = jp + jp1 - jp2;//Initialize jp by using mathematical operators.
    cout << "... Result ... " << endl;
    jp.getStats();//Prints out the result.
    cout << "\n... Create duelingJP objects ..." << endl;
    duelingJP obj, obj1, obj2;//Create duelingJP objects.
    obj.addJumpPrime(jp);//Add jp obj to the duelingJP.
    obj1.addJumpPrime(jp1);//Add jp obj to the duelingJP.
    obj2.addJumpPrime(jp2);//Add jp obj to the duelingJP.
    cout << "... Testing ..." << endl;
    obj = obj + obj1 - obj2;//Implement mathematical operators.
    cout << "number of objects in the duelingJp: ";
    cout << obj.jumpPrimeCount() << endl;//Prints out the number of jp objects.
    obj.runAnalysis();//Run the analysis.

}
void testRelational() {
    cout << "=============Test Relational=======================" <<endl;
    int a, b, c;//To hold the random numbers.
    a = 100 + (rand() % 9900);;//Initialize a random number.
    b = 100 + (rand() % 9900);;//Initialize a random number.
    c = 100 + (rand() % 9900);//Initialize a random number.
    cout << "Encapsulate numbers: " << a << " " << b << " " << c << endl;
    cout << "... Create JumpPrime objects..." << endl;
    jumpPrime jp(a);//Create jumpPrime objects.
    jumpPrime jp1(b);//Create jumpPrime objects.
    jumpPrime jp2(c);//Create jumpPrime objects.
    cout << "... Testing ..." << endl;
    //Test relational operators.
    cout << "jp > jp1: ";
    if (jp > jp1) {
        //Test if object is larger than another object.
        cout << "true" << endl;
    }
    else
        cout << "false" << endl;
    cout << "jp < jp1: ";
    if(jp < jp1) {
        //Test if object is smaller than another object.
        cout << "true" << endl;
    }
    else
        cout << "false" << endl;
    cout << "jp1 >= jp2: ";
    if(jp >= jp2) {
        //Test if object is either larger or equal than another object.
        cout << "true" << endl;
    }
    else
        cout << "false" << endl;
    cout << "jp1 <= jp2: ";
    if (jp1 <= jp2) {
        //Test if object is either smaller or equal than another object.
        cout << "true" << endl;
    }
    else
        cout << "false" << endl;
    cout << "jp1 == jp2: ";
    if (jp1 == jp2) {
        //Test if object is equal to another object.
        cout << "true" << endl;
    }
    else
        cout << "false" << endl;
    cout << "... Create duelingJP objects ..." << endl;
    duelingJP obj, obj1;//Create duelingJP objects.
    obj.addJumpPrime(jp);//Add jp obj to the duelingJP.
    obj.addJumpPrime(jp1);//Add jp obj to the duelingJP.
    obj1.addJumpPrime(jp2);//Add jp obj to the duelingJP.
    cout << "... Testing ..." << endl;
    cout <<"obj > obj1: ";
    if(obj > obj1) {
        //test if object is larger than another.
        cout << "true" << endl;
    }
    else
        cout << "false" << endl;
    cout << "obj < obj1: ";
    if(obj < obj1) {
        //test if object is smaller than another.
        cout << "true" << endl;
    }
    else
        cout << "false" << endl;
    cout << "obj >= obj1: ";
    if(obj >= obj1) {
        //test if object is either larger or equal to another.
        cout << "true" << endl;
    }
    else
        cout << "false" <<endl;
    cout << "obj <= obj1: ";
    if(obj <= obj1) {
        //test if object is either smaller or equal to another.
        cout << "true" << endl;
    }
    else
        cout << "false" <<endl;
    cout << "obj == obj1: ";
    if(obj == obj1) {
        //test if object is equal to another.
        cout << "true" << endl;
    }
    else
        cout << "false" <<endl;
}
void testShortCut() {
    cout << "=============Test Relational=======================" <<endl;
    int a;//Hold a random number.
    a = 100 + (rand() % 9900);;//Initialize a random number.
    cout << "Encapsulate numbers: " << a << endl;
    cout << "... Create JumpPrime objects..." << endl;
    jumpPrime jp(a);//Create a jumpPrime object.
    cout << "... Testing ..." << endl;
    cout << "++object++" << endl;
    ++jp;//test Pre-increment.
    jp++;//test Post-increment.
    --jp;//test Post-decrement.
    jp--;//test Post-decrement.
    cout << "... Result ... " << endl;
    jp.getStats();//Get the result.
    cout << "\n... Create duelingJP objects ..." << endl;
    duelingJP obj;//Create a duelingJP object.
    obj.addJumpPrime(jp);//Add jp object to duelingJP object.
    obj.addJumpPrime(jp);//Add jp object to duelingJP object.
    cout << "... Testing ... " << endl;
    cout << "++object++" << endl;
    ++obj;//test pre-increment
    obj++;//test post-increment
    --obj;//test pre-decrement.
    obj--;//test post-decrement.
    obj.runAnalysis();//Run analysis.
}