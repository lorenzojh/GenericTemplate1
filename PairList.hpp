// File : PairList.hpp
// Author: Lorenzo Hobbs
//  Description : This file contains PairList class header and template
//  Date : 3/16/23
//
//  
//

#ifndef PairList_hpp
#define PairList_hpp
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdexcept>
#include "Pair.hpp"
#include "LinkedList.hpp"
using namespace std;
// a template class for storing a list of pairs of type T
// class derived from vector class and provides methods for managing list of pairs
//@param T type of elements in pairs
template <typename T>
class PairList {
public:
    void addPair(T first, T second);
    T getFirst(T second);
    T getSecond(T first);
    void deletePair(T first, T second);
    void printList();
private:
    LinkedList<Pair<T,T>> list;
};
// add a pair to the list
// @param first - first element of pair
// @param second- second element of pair

template <typename T>
void PairList<T>:: addPair(T first, T second)
{
    list.addToEnd(Pair<T,T>(first, second));
}

//loops through for loop, for each pair checks whether second value of pair matches second
//@param second, second element of pair
//@return first element
template <typename T>
T PairList<T>::getFirst(T second)
{
    Node <Pair<T,T>>* p = list.getHead();
    while( p != nullptr){
        if(p->Data.second == second){
            // Make sure the pair has a valid first element
            if (p->Data.first) {
                return p->Data.first;
            } else {
                throw std::invalid_argument("Invalid pair: first element is null");
            }
        }
        p = p->Next;
    }
    throw std::invalid_argument("Pair not found");
}

//loop through for loop, for each pair checks whether first value of pair matches first
//@param first- first element of pair
//@return second element of pair
template <typename T>
T PairList<T>::getSecond(T first)
{
    Node<Pair<T, T>>* p = list.getHead();
    while (p != nullptr) {
        if (p->Data.first == first) {
            return p->Data.second;
        }
        p = p->Next;
    }
    //if not throw exception
    throw std::invalid_argument("Pair not found with specified first value.");
}

//@param two parameters of type T, first and second values of pairs to be deleted
//@return one pair
template <typename T>
void PairList<T>::deletePair(T first, T second)
{
    Node <Pair<T,T>>* p = list.getHead();
    Node <Pair<T,T>>* prev = nullptr;
    while( p != nullptr){
        if( p->Data.first == first && p->Data.second == second){
            if(prev == nullptr){
                list.setHead(p->Next);
            }else{
                    prev->Next= p->Next;
                }
                delete p;
                return;
            }
            prev = p;
            p = p->Next;
        
    }
    //if completes without finding a pair to delete throw exception
    throw std::invalid_argument("Pair not Found");
}
// print list of pairs
//@param none
template <typename T>
void PairList<T>::printList()
{
    Node <Pair<T,T>>* p = list.getHead();
    while(p!= nullptr){
        cout << p->Data.first << "," << p->Data.second << endl;
        p = p->Next;
    }
}

#endif /* PairList_hpp */

