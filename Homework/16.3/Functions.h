#include <iostream>

template <typename T> T maximun(T numA,T numB ){
    
    if(numA > numB){return numA;}
    return numB;

}

template <typename T> T minimum(T numA,T numB ){
    
    if( numA > numB){ return numB; }
    return numA;

}