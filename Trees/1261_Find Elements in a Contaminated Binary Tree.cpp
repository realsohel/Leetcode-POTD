// Question: https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/
// Time Complexity: O(N) where N is the number of nodes in the tree
// Space Complexity: O(N) where N is the number of nodes in the tree

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

};

// USING BFS
class FindElements {
public:
    unordered_set<int> st;

    void BFS(TreeNode* root, int val) {
        queue<TreeNode*> q;
        root->val = val;
        q.push(root);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            st.insert(temp->val);
            if(temp->left){
                temp->left->val = 2*temp->val + 1;
                q.push(temp->left);
            }
            if(temp->right){
                temp->right->val = 2*temp->val + 2;
                q.push(temp->right);
            }
        }
    }

    FindElements(TreeNode* root) {
        st.clear();
        BFS(root,0);    
    }
    
    bool find(int target) {
        if(st.count(target)) return true;
        return false;
    }
};

//  DFS
// class FindElements {
// public:
//     unordered_set<int> st;

//     void Dfs(TreeNode* root, int val, unordered_set<int>& st) {
//         if(root == NULL) return;
//         root->val = val;
//         st.insert(val);
//         Dfs(root->left, 2*val + 1, st);
//         Dfs(root->right, 2*val + 2, st);
//     }

//     FindElements(TreeNode* root) {
//         st.clear();
//         Dfs(root, 0,st);    
//     }
    
//     bool find(int target) {
//         if(st.count(target)) return true;
//         return false;
//     }
// };
    
    /**
     * Your FindElements object will be instantiated and called as such:
     * FindElements* obj = new FindElements(root);
     * bool param_1 = obj->find(target);
     */