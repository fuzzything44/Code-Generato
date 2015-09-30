#include "random.h"
#include "logger.h"
#include <iostream>


int64 randRange(int64 low, int64 high)
{
    ENTER_FUNC("random::randRange(int64 low, int64 high)")
    static bool randSeeded;
    
    // Seed rand if not already.
    if (!randSeeded) { LOG("Seeding rand..."); std::srand(std::time(NULL)); randSeeded = true; }
    
    int64 max = high - low;
    max++;
    
    if ( max < 0) {
        LOG("Max <= 0. Failed rand.")
        return 0;
    }
    if ( max == 0) {
        return low;
    }
    
    int64 rand;
    // Make sure that the rand isn't slightly biased to lower numbers.
    do {
        rand = std::rand();
        LOG("Random value to check: " << rand)
    } while ( ((RAND_MAX / max) * max) < rand);
    
    LOG("Found valid value!")
    
    LEAVE_FUNC("random::randRange(int64 low, int64 high)", rand % max + low)
        
}
