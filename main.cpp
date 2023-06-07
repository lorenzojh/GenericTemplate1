//File: Main.cpp
//Author: Lorenzo Hobbs
//Description : This file contains main  testing
// Date : 3/16/23
#include <iostream>
#include <vector>
#include "PairList.hpp"


int main() {
    //create an intance of PairList class and populate it with pairs
    //adds pairs using addPair function
    PairList<int> myPairList;
    myPairList.addPair(1, 2);
    myPairList.addPair(3, 4);
    myPairList.addPair(5, 6);

    // Test getFirst and getSecond methods
    std::cout << "getFirst(2) = " << myPairList.getFirst(2) << std::endl;
    std::cout << "getSecond(5) = " << myPairList.getSecond(5) << std::endl;

    // Test deletePair method
    myPairList.deletePair(3, 4);
    std::cout << "After deleting (3,4):" << std::endl;
    myPairList.printList();  // should print "(1,2), (5,6)"

    return 0;
}
