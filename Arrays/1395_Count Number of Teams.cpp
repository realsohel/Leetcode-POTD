// Question: There are n soldiers standing in a line. Each soldier is assigned a unique rating value.
// You have to form a team of 3 soldiers amongst them under the following rules:
// Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
// A team is valid if:  (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
// Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).

// Answer: The algorithm is as follows:
// 1. For each soldier j, we find the number of soldiers on the left of j which have a rating less than rating[j] and the number of soldiers on the right of j which have a rating greater than rating[j].
// 2. The number of teams that can be formed with j as the middle soldier is given by the product of the number of soldiers on the left of j which have a rating less than rating[j] and the number of soldiers on the right of j which have a rating greater than rating[j].
// 3. The total number of teams that can be formed is the sum of the number of teams that can be formed with j as the middle soldier for all soldiers j.
// 4. We iterate over all soldiers j and find the number of teams that can be formed with j as the middle soldier.
// 5. The final answer is the total number of teams that can be formed.
// 6. The time complexity of the above algorithm is O(n^2) where n is the number of soldiers.
// 7. The space complexity of the above algorithm is O(1).

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int teams=0;

        for(int j=1;j<rating.size()-1;j++){
            int largerLeft = 0, smallerRight = 0;
            int largerRight = 0, smallerLeft = 0;

            for(int i=0;i<j;i++){
                if(rating[i]<rating[j])
                    smallerLeft++;
                else if(rating[i]>rating[j])
                    largerLeft++;
            }
            for(int k=j+1;k<rating.size();k++){
                if(rating[k]<rating[j])
                    smallerRight++;
                else if(rating[k]>rating[j])
                    largerRight++;
            }

            teams+= (largerLeft * smallerRight) + (smallerLeft * largerRight );
        }

        return teams;
    }
};
