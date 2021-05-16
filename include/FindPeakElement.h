/*

LeetCode 162.

I do not think this one makes sense.

Using Binary Search for an unsorted array with the only

condition that "nums[i] != nums[i + 1] for all valid i"

won't be working.

In this array [1,2,9,5,7,6,3], the peak will be 9 in the

common sense, but when applying Binary Search, it will 

not care the left side right away so I won't be able to

find the "9", which should've been the answer.

-------------------------------------------------------
[SOLUTION]

If the constraint of this quiz wouldn't be O(LogN) time,

I'd just simply iterate all elements and store the highest

number ans the index of it. Each iteration I'd compare 

the current max number and number[i] and change the index

if number[i] is greater.


*/