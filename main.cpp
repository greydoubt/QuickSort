#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <ctime> 
#include <algorithm>
#include <cstdlib>  // probably dont need
#include "quicksort.h"


int main() {

    int maxint = std::numeric_limits<int>::max();
    int minint = 1;
    int numrounds = 100000;

    clock_t t1, t2;

    std::vector <int>
        samplevec1,
        samplevec2,
        samplevec3,
        samplevec4;

    // it makes no sense to sort the same vector over and over again, or populate multiple vectors so one main copy is made then it is copied into 3 others
    populateVector(samplevec1, numrounds, minint, maxint);

    samplevec2 = samplevec1;
    samplevec3 = samplevec1;
    samplevec4 = samplevec1;




    // Example of the median of the first, last and middle elements:
    //1 2 3 4 5 6 7 8 0 (median of 1, 5, 0 is 1)
    //8 0 1 2 3 4 5 6 7 (median of 8, 3, 7 is 7)
    //std::vector <int> exv1{1, 2, 3, 4, 5, 6, 7, 8, 0};
    //std::vector <int> exv2{8, 0, 1, 2, 3, 4, 5, 6, 7};

    //int med3 = parseMedian(exv1, 0, exv1.size( ) - 1 );

    //std::cout << parseMedian(exv1, 0, exv1.size( ) - 1 ) << '\n';
    //std::cout << parseMedian(exv2, 0, exv2.size( ) - 1 ) << '\n';

    //quicksort(v3);
    //insertionSort(v3);

    ///std::cout << t1 << '\n';


    // output 1: the unsorted version
    //std::cout << "Unsorted:\n";
    //printVector(samplevec1);
    //std::cout << '\n';


    
    // case 1 -- just quicksort, pivot on middle
      
    t1 = clock(); // starting time

    quicksortNormalMiddle(samplevec1);

    t2 = clock(); // ending time; run time is t2-t1

    //printVector(samplevec1);
    std::cout << "time: " << t2 - t1 << '\n';
    
  
    // case 2 -- just quicksort, pivot on median-of-three
    t1 = clock(); // starting time

    quicksortNormalMedian3(samplevec2);

    t2 = clock(); // ending time; run time is t2-t1

    //printVector(samplevec2);
    std::cout << "time: " << t2 - t1 << '\n';
    

   
    // case 3
    t1 = clock(); // starting time
    quicksortHybridMiddle(samplevec3);

    t2 = clock(); // ending time; run time is t2-t1
    //printVector(samplevec3);
    std::cout << "time: " << t2-t1 << '\n';


    // case 4
    t1 = clock(); // starting time
    quicksortHybridMedian3(samplevec4);

    t2 = clock(); // ending time; run time is t2-t1
    //printVector(samplevec4);
    std::cout << "time: " << t2-t1 << '\n';
    

}