#include <cstddef>  // size_t
#include <cstdint>
#include <iostream>
#include <list>
#include <vector>
#include <chrono>
#include <random>
#include "timer.h"

constexpr size_t SIZE = 16000000;

int main() {
    std::list<uint64_t> populateList; 
    std::vector<uint64_t> populateVectorReserve;
    std::vector<uint64_t> populateVectorNoReserve;
    uint64_t timeTaken;
    uint64_t timeTakenNoReserve;
    uint64_t timeTakenReserve;
    
    Timer timed{};
    
    std::mt19937_64 rng(0); // initialize with seed of 0

    for(size_t i = 0; i < SIZE; i++){
       populateList.push_back(rng());
    }
    timeTaken = timed.click<std::chrono::microseconds>();

    rng.seed(0);
    for(size_t i = 0; i < SIZE; i++){
        populateVectorNoReserve.push_back(rng());
    }//No Reserve Vector populating
    timeTakenNoReserve = timed.click<std::chrono::microseconds>();

     rng.seed(0);
    for(size_t i = 0; i < SIZE; i++){
        populateVectorReserve.push_back(rng());
    }//Reserve Vector populating
    timeTakenReserve = timed.click<std::chrono::microseconds>();

    std::cout << "List population time Taken: " << timeTaken;
    std::cout << "\nVector population time taken (no reserve): " << timeTakenNoReserve;
    std::cout << "\nVector population time taken (reserve): " << timeTakenReserve;



    return 0;
}
