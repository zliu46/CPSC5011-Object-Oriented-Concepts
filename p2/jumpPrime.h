//Zhou Liu
//jumpPrime.h
//This is the h file for jumpPrime object.
//version 1.0
//2/6/23
#ifndef P2_JUMPPRIME_H
#define P2_JUMPPRIME_H
#include <iostream>
using namespace std;
class jumpPrime {
private:
    int minRange;//Hold minimum range.
    int maxRange;//Hold maximum range.
    int number; //To hold the input number from the user.
    enum Status { Active, Inactive, Deactivated};//Create status.
    Status status;//To hold the status.
    int queryCount;//To count the number of queries.
    int currNum;//To hold the number after "jumping".
    bool isPrime(int);//Check if the number is a prime number.
    bool outOfRange();//Check if current number is out of range.
    void jump();//Allows current method to jump up.
    string getStatus();//A string includes obj status.
public:
    jumpPrime();//Non-argument Constructor.
    jumpPrime(int);//Argument Constructor
    int up();//An up() function to get the next prime number.
    int down();//A down() method to get the previous prime number.
    void revive();//A method to revive the obj.
    void reset();//To reset the obj.
    void getStats();//To get a result of JP object.

};

#endif //P2_JUMPPRIME_H
