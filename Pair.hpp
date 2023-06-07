// File : Pair.hpp
//  Author : Lorenzo Hobbs
//  Description : pair class header file and template
// Date : 3/16/23
//  
//

#ifndef Pair_hpp
#define Pair_hpp

#include <stdio.h>
template <typename F, typename S>
class Pair
{
private:
public:
    Pair() : first(), second() {}
    Pair(F first, S second);
    F getFirst() const;
    S getSecond() const;
    void setFirst(F val);
    void setSecond(S val);
    F first;
    S second;

};
// overloaded constructor with two type parameters for each pair
//@param first and second
//@return none
template <typename F, typename S>
Pair<F,S>::Pair(F first, S second)
{
    this->first = first;
    this->second = second;
}
//accessor method that returns first of pair
//@param none
//@return first element of pair
template <typename F, typename S>
F Pair<F,S>:: getFirst() const
{
    return first;
}
//accessor method that returns second of pair
//@param none
//@return second element of pair
template <typename F, typename S>
S Pair<F,S>::getSecond() const
{
    return second;
}
//setter that sets first value of pair to given value
//@param new value to set as first element of pair
//@return none
template <typename F, typename S>
void Pair<F,S>::setFirst(F newVal)
{
    this->first = newVal;
}
//sets second value of pair to second value
//@param second value to set as second element
//@return none
template <typename F, typename S>
void Pair<F,S>::setSecond(S second)
{
    this->second = second;
}
#endif /* Pair_hpp */
