//Zhou Liu
//p2.cpp
//Purpose: This is the driver that tests the duelingJP class.
//First, testing deep copying function. Second, testing using unique pointer.
//Third, testing shared pointer. Last, testing move semantics.
//version 1.0
//2/6/23
#include "jumpPrime.h"
#include "duelingJP.h"
#include <iostream>
#include <vector>
#include <memory>
using namespace std;
/*
 * A method that tests deep copying of duelingJP object.
 */
void testDeepCopying();
/*
 * A method that creates unique pointer.
 */
void testUniquePointer();
/*
 * A method that is using shared pointer.
 */
void testSharedPointer();
/*
 * A method that tests move semantics.
 */
void testMoveSemantics();

int main() {
    cout << "Test starts```" << endl;
    //Call a deep copying method.
    testDeepCopying();
    //Call a function that tests unique pointer.
    testUniquePointer();
    //Call a function that tests shared pointer.
    testSharedPointer();
    //Call a method that tests move semantics.
    testMoveSemantics();
    //Prints out an end message.
    cout << "\nTesting ends```";

    return 0;
}void testDeepCopying() {
    //Prints method title.
    cout << "Test Deep Copying```" << endl;
    //Create a JP object.
    jumpPrime jp(3519);
    //Create a JP object.
    jumpPrime jp2(3528);
    //Create a duelingJP object.
    duelingJP myObj;
    //Add JPs to duelingJP.
    myObj.addJumpPrime(jp);
    myObj.addJumpPrime(jp2);
    //Create a copy by using deep copying.
    duelingJP copy(myObj);
    duelingJP copy1;
    //Test overloading operator.
    copy1 = copy;
    //Call jumpPrimeCount() & runAnalysis() methods to prints out the result of copy objects.
    cout << "number of object: " << copy1.jumpPrimeCount() << endl;
    copy.runAnalysis();
}
/**
 * Both Unique pointer and shared pointer will be destroyed when it went out of scope.
 * Smart pointers prevent memory leaking.
 * The different between unique pointer and shared pointer:
 * shared pointer can have different object reference to the same address.
 * unique pointer can not be copied.
 * etc.
 */

void testUniquePointer()
{
    //Prints out the title.
    cout << "\nTest Unique Pointer```" << endl;
    //Create JP objects.
    jumpPrime jp(3519);
    jumpPrime jp2(3528);
    //Create duelingJP object.
    duelingJP myObj;
    //Add jp objects to duelingJP object.
    myObj.addJumpPrime(jp);
    myObj.addJumpPrime(jp2);
    //Create a unique pointer.
    unique_ptr<duelingJP> ptr (new duelingJP());
    //Call functions by using unique pointer.
    ptr->addJumpPrime(jp);
    ptr->addJumpPrime(jp2);
    ptr->runAnalysis();
}
void testSharedPointer() {
    //Prints out title.
    cout << "\nTest Shared Pointer```" << endl;
    //Create jp objects.
    jumpPrime jp(2222);
    jumpPrime jp2(2233);
    //Create a duelingJP object.
    duelingJP myObj;
    //Add JPs to duelingJP.
    myObj.addJumpPrime(jp);
    myObj.addJumpPrime(jp2);
    //Create a shared pointer.
    shared_ptr<duelingJP> ptr (new duelingJP());
    //Create a copy pointer.
    shared_ptr<duelingJP> copyPtr(new duelingJP());
    //Call methods by using smart pointer.
    ptr->addJumpPrime(jp);
    ptr->addJumpPrime(jp2);
    //Using copy pointer to reference to the ptr.
    copyPtr = ptr;
    //Call a function of copy pointer.
    copyPtr->runAnalysis();
}
void testMoveSemantics() {
    cout << "\nTest Move Semantics```" << endl;
    //Create JP objects.
    jumpPrime jp(2222);
    jumpPrime jp2(2233);
    //Create a duelingJP object.
    duelingJP myObj;
    //Add JPs to duelingJP object.
    myObj.addJumpPrime(jp);
    myObj.addJumpPrime(jp2);
    //Create a vector by using duelingJP class.
    vector<duelingJP> v;
    //Create a copy vector.
    vector<duelingJP> copy;
    //Add object to the vector.
    v.push_back(myObj);
    //Move semantics.
    copy = move(v);
    //Prints out the result by using the copy vector.
    cout << "number of object: " << copy[0].jumpPrimeCount() << endl;
    copy[0].runAnalysis();
}