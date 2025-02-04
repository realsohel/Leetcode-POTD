
// Q. Given an array of positive integers nums, return the maximum possible sum of an ascending subarray in nums.
// subarray is defined as a contiguous sequence of numbers in an array.
// A subarray [numsl, numsl+1, ..., numsr-1, numsr] is ascending if for all i where l <= i < r, numsi < numsi+1.

// Ans. We can solve this problem by using the sliding window technique.
// We will keep track of the sum of the current subarray and the maximum sum of the subarray.
// We will iterate over the array and check if the current element is greater than the previous element.
// If it is, we will add the current element to the sum of the subarray.
// If it is not, we will update the maximum sum of the subarray and reset the sum of the subarray to the current element.
// We will return the maximum sum of the subarray as the answer.
// The time complexity of this approach is O(n), where n is the size of the array, and the space complexity is O(1).


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

//  Optimal Approach
// Time = O(n)
// Space = O(1)
    int maxAscendingSum_Optimal(vector<int>& nums) {

        int n = nums.size();
        int ans = nums[0];
        int sum = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] >= nums[i - 1]) {
                sum += nums[i];
            } else {
                sum = nums[i];
            }

            ans = max(ans, sum);
        }

        return ans;
    }

// Brute Force
// Time = O(n^2)
// Space = O(1)
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int sum = nums[i];

            for (int j = i + 1; j < n; j++) {
                if (nums[j] > nums[j - 1]) { 
                    sum += nums[j];
                } else {
                    break;
                }
            }

            ans = max(ans, sum);
        }

        return ans;
    }
};
