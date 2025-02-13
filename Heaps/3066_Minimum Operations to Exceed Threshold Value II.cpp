// 3066. Minimum Operations to Exceed Threshold Value II
// Q. You are given a 0-indexed integer array nums, and an integer k. In one operation, you will:
//  1. Take the two smallest integers x and y in nums.
//  2. Remove x and y from nums.
    // 3. Add min(x, y) * 2 + max(x, y) anywhere in the array.
// Note that you can only apply the described operation if nums contains at least two elements.
// Return the minimum number of operations needed so that all elements of the array are greater than or equal to k.


// Answer: We can use a heap to keep track of the smallest elements in the array. We can then perform the operation described in the problem statement until the smallest element in the heap is greater than or equal to k. We can use a priority_queue to implement the heap. We can initialize the priority_queue with the elements of the array nums. We can then perform the following steps until the smallest element in the priority_queue is greater than or equal to k:
// 1. Pop the two smallest elements x and y from the priority_queue.
// 2. Calculate the new element z = min(x, y) * 2 + max(x, y).
// 3. Push the new element z into the priority_queue.
// 4. Increment the count of operations by 1.
// Finally, we can return the count of operations as the answer.
// The time complexity of this approach is O(NlogN), where N is the number of elements in the array nums. The space complexity is O(N) to store the elements in the priority_queue.


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Using Heap 
    // Time Complexity: O(NlogN)
    // Space Complexity: O(N)
    int minOperations(vector<int>& nums, int k) {
        priority_queue <long long, vector<long long>, greater<long long> > pq(nums.begin(),nums.end()); // Ye heapify - LogN leta h 

        // for(int x:nums) // Ye N*LOGN le ta h
        //     pq.push(x);
        
        int count=0;
        while(true){
            
            if(pq.top()>=k or pq.size()<2)
                break;
            
            long long smallest = pq.top();
            pq.pop();
            long long secSmallest = pq.top();
            pq.pop();

            long long ans = smallest*2 + secSmallest;
            pq.push(ans);
            count++;
        }

        return count;
    }
//  Brute Force 
// TLE + Wrong bhi hai. 561st case failedd
    // int minOperations(vector<int>& nums, int k) {
    //     int count=0;
    //     while(true){
    //         sort(nums.begin(),nums.end());

    //         if(nums[0]>=k)
    //             break;
    //         long long  mini = min(nums[0],nums[1]);
    //         long long maxi = max(nums[0],nums[1]);
    //         long long cal = mini*2 + maxi;

    //         nums.erase(nums.begin());
    //         nums[0]=cal;
    //         count++;

    //     }

    //     return count;
    // }
};