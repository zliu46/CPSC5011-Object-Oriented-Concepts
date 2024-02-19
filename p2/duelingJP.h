//Zhou Liu
//duelingJP.h
//Purpose: this is the h file of duelingJP class.
//This class will create a container to hold JP objects.
//User is allowed to get the number of "collisions" and "inversions".
//This program will also track the number of JP objects on the container.
//This program manage JP objects provides analysis of JPs on the dueling object.
//version 1.0
//2/6/23
/**
 * I am think this program will take jumpPrime Objects then analyze them.
 * This program will generate a report of "collide" and “inversions”.
 * This program allows to add and remove jumpPrime objects.
 */
#ifndef P2_DUELINGJP_H
#define P2_DUELINGJP_H
#include "jumpPrime.h"
class duelingJP {
private:
    jumpPrime * array;//Create an array to hold JP objects.
    int numCollisions;//To count "collisions"
    int numInversions;//To count "inversions".
    int jPCount;//Track the number of JP objects.
    int size = 10; //Set the size of array.
    void copy(const duelingJP&);//a copy sub method.
    void resize();//A resize method.

public:
    //Constructor.
    duelingJP();
    //deep copy.
    duelingJP(const duelingJP&);
    //Overloading operator
    duelingJP& operator=(const duelingJP&);
    //Move semantics
    duelingJP(duelingJP&&) noexcept;
    //Move semantics.
    duelingJP& operator=(duelingJP&&) noexcept;
    //Destructor
    ~duelingJP();
    //Add JP.
    void addJumpPrime(jumpPrime);
    //Remove.
    void removeJumpPrime(int );
    //Returns the number of jumpPrime under management.
    int jumpPrimeCount();
    //Manage jumpPrime objects and run analysis.
    void runAnalysis();
};
#endif //P2_DUELINGJP_H
