#include "random.h"

int64 randRange(int64 low, int64 high)
{
    static bool randSeeded;
    
    // Seed rand if not already.
    if (!randSeeded) { std::srand(std::time(0)); randSeeded = true; }
    
    int64 max = high - low;
    
    if ( max <= 0) {
        return 0;
    }
    
    int64 rand;
    
    // Make sure that the rand isn't slightly biased to lower numbers.
    do {
        
        rand = std::rand();
        
    } while ( (RAND_MAX / max) * max > rand);
            
    return rand % max + low;
        
}
