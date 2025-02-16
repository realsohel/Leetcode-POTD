// 1718. Construct the Lexicographically Largest Valid Sequence
// Question. Given an integer n, find a sequence that satisfies all of the following: 
// The integer 1 occurs once in the sequence.
// Each integer between 2 and n occurs twice in the sequence.
// For every integer i between 2 and n, the distance between the two occurrences of i is exactly i.
// The distance between two numbers on the sequence, a[i] and a[j], is the absolute difference of their indices, |j - i|.
// Return the lexicographically largest sequence. It is guaranteed that under the given constraints, there is always a solution.
// A sequence a is lexicographically larger than a sequence b (of the same length) if in the first position where a and b differ, sequence a has a number greater than the corresponding number in b. For example, [0,1,9,0] is lexicographically larger than [0,1,5,6] because the first position they differ is at the third number, and 9 is greater than 5.

// Answer: The problem is a simple backtracking problem. We need to find a sequence of length 2*n-1 such that the sequence satisfies the given conditions. The first condition is that 1 should occur only once in the sequence. The second condition is that each integer between 2 and n should occur twice in the sequence. The third condition is that for every integer i between 2 and n, the distance between the two occurrences of i should be exactly i. The fourth condition is that the distance between two numbers on the sequence, a[i] and a[j], should be the absolute difference of their indices, |j - i|. The fifth condition is that the sequence should be lexicographically largest.
// To solve the problem, we can use a recursive backtracking approach. We can start by creating a vector ans of size 2*n-1 and initialize all elements to -1. We can also create a vector vis of size 2*n-1 and initialize all elements to false. We can then call a recursive function solve(0, n, ans, vis) to find the lexicographically largest sequence that satisfies the given conditions.
// In the recursive function solve, we can iterate over all integers from n to 1. For each integer num, we can check if it has already been visited. If it has been visited, we can continue to the next integer. Otherwise, we can try placing the integer num at the current index i in the sequence. We can then explore the next index i+1 by calling solve(i+1, n, ans, vis). If the integer num is 1, we can directly call solve(i+1, n, ans, vis) as there is only one occurrence of 1 in the sequence. If the integer num is greater than 1, we can check if the next index j = ans[i]+i is within the bounds of the sequence and if the element at index j is -1. If both conditions are satisfied, we can place the integer num at index j and call solve(i+1, n, ans, vis). If the recursive call returns true, we can return true from the current call. Otherwise, we can undo the placement of the integer num at index j by setting ans[j] = -1 and continue exploring other possibilities.
// If no valid sequence is found, we can return false from the recursive function. The recursive function will backtrack to the previous index and try other possibilities until a valid sequence is found. Once a valid sequence is found, we can return true from the recursive function and the sequence will be stored in the vector ans.
// Finally, we can return the vector ans as the lexicographically largest sequence that satisfies the given conditions.
// Time Complexity: O(2^n)
// Space Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

// Recursive Backtracking
// Time Complexity: O(2^n)
// Space Complexity: O(n)
    bool solve(int i, int n, vector<int>& ans, vector<bool>& vis) {
        if(i >= ans.size()) return true;
        if(ans[i] != -1) return solve(i+1, n, ans, vis);

        for(int num=n;num>=1;num--){
            if(vis[num]==true)
                continue;
            
            //  TRY
            vis[num]=true;
            ans[i] = num;

            // EXPLORE
            if(num==1){
                if(solve(i+1, n, ans, vis)) return true;
            }
            else{
                int j = ans[i]+i;
                if(j<ans.size() && ans[j]==-1){
                    ans[j] = num;
                    if(solve(i+1, n, ans, vis)) 
                        return true;
                    else 
                        ans[j] = -1;
                }
            }

            // UNDO

            vis[num] = false;
            ans[i] = -1;
        }

        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2*n-1, -1);
        vector<bool> vis(2*n-1,false);
        solve(0,n, ans, vis);

        return ans;
    } 
};