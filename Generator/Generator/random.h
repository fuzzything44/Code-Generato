#pragma once
#include <random>
#include <ctime>

int randRange(int low, int high)
{
    static bool randSeeded;
    
    // Seed rand if not already.
    if (!randSeeded) { std::srand(std::time(0)); randSeeded = true; }
    
    int max = high - low;
    
    int rand;
    
    // Make sure that the rand isn't slightly biased to lower numbers.
    do {
        
        rand = std::rand();
        
    while ( RAND_MAX - max > rand)
    
    return rand % max + low;
    
}