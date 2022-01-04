/*
Sample Test Case 1 (assuming a zero index):
planer[] = [2,5,3,1]
output: 1
Explanation: N=4 and planets = [2,5,3,1]. Here, if we destory the 
second planet of mass 5, then planets = [2,3,1] and the sum of even
positioned planets is (2+1) = 3 and the sum of odd positioned planets
is (3)=3, i.e., both are equal now. Hence we destroy the planet at 
index 1.

Same Test Case 2 (assuming a zero index)
planets[]=[3,5,6,7,9,4]
output:2
Explanation: N=6 and planets = [3,5,6,7,9,4]. Here if we destroy the third
planet of mass 6 then planets = [3,5,7,9,4] and the sum of even positioned
planets is (3+7+4)=14, and the sum of odd positioned planets is (5+9)=14.
Both are equal now. Hence, we destroy the planet at index 2. Deleting the 
fourth planet with mass 9 will stabilize the planetary system, but we will 
destroy the planet with minimum index.
*/

int getPlanetToDestroy(vector<int> planets) 
{
    for (int i = 0 ; i < planets.size(); i++)
    {
        std::vector<int> sum(2, 0);
        for (int j = 0; j < i; j++)
        {
            sum[j % 2] += planets[j];
        }
        for (int j = i; j < planets.size() - 1; j++)
        {
            sum[j % 2] += planets[(j+1)];            
        }
        
        if (sum[0] == sum[1]) 
        {
            return i;
        }
    }
    return -1;
}
