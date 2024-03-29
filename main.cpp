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

    bool verboseMode = false; // leave this false unless you want a lot of stuff displayed

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

    if(verboseMode)
      printVector(samplevec1);


    // case 1 -- just quicksort, pivot on middle
    t1 = clock(); // starting time
    quicksortNormalMiddle(samplevec1);
    t2 = clock(); // ending time; run time is t2-t1

    if(verboseMode)
      printVector(samplevec1);

    std::cout << "time: " << t2 - t1 << '\n';
    
  
    // case 2 -- just quicksort, pivot on median-of-three
    t1 = clock(); // starting time
    quicksortNormalMedian3(samplevec2);
    t2 = clock(); // ending time; run time is t2-t1
    
    if(verboseMode)
      printVector(samplevec2);
    
    std::cout << "time: " << t2 - t1 << '\n';
    
    // case 3
    t1 = clock(); // starting time
    quicksortHybridMiddle(samplevec3);

    t2 = clock(); // ending time; run time is t2-t1
    
    
    if(verboseMode)
      printVector(samplevec3);

    std::cout << "time: " << t2-t1 << '\n';


    // case 4
    t1 = clock(); 
    quicksortHybridMedian3(samplevec4);

    t2 = clock(); 
    
    if(verboseMode)
      printVector(samplevec4);

    std::cout << "time: " << t2-t1 << '\n';
    

}