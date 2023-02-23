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
        bool isSameTree(TreeNode* p, TreeNode* q) {
            //若p和q都為空 則相等
            if(p == nullptr && q == nullptr){
                return true;
            }
            //若p和q都不為空 則要比較自己、左子樹和右子樹的值是否相等
            if(p && q){
                return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
            }
            return false;
        }
};