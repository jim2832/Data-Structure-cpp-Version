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
        bool result;

        int check_balance(TreeNode* root){
            if(root == nullptr){
                return 0;
            }
            if(!result){
                return 0;
            }
            int left_sub_tree = check_balance(root->left); //往左子樹走訪
            int right_sub_tree = check_balance(root->right); //往右子樹走訪
            if(abs(left_sub_tree - right_sub_tree) > 1){
                result = false;
            }
            return 1 + max(left_sub_tree, right_sub_tree);
        }

        bool isBalanced(TreeNode* root) {
            result = true;
            int temp = check_balance(root);
            return result;
        }
};