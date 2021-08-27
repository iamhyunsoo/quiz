#include <numeric>
    
bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if (jug1Capacity + jug2Capacity < targetCapacity) 
          return false;
  
        if (jug1Capacity == targetCapacity || jug2Capacity == targetCapacity || jug1Capacity + jug2Capacity == targetCapacity) 
            return true;
        
        return targetCapacity % std::gcd(jug1Capacity, jug2Capacity) == 0;
    }
