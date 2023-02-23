#include <iostream>
#include <string>
#include <queue>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        bool root_to_leaf_sum(TreeNode* root, int targetSum, int sum){
            if(root == nullptr){
                return false;
            }
            //終止條件
            if(root->left == nullptr && root->right == nullptr){
                sum += root->val;
                if(sum == targetSum){
                    return true;
                }
            }
            return root_to_leaf_sum(root->left, targetSum, sum + root->val) || root_to_leaf_sum(root->right, targetSum, sum + root->val);
        }

        bool hasPathSum(TreeNode* root, int targetSum) {
            int sum = 0;
            return root_to_leaf_sum(root, targetSum, sum);
        }
};