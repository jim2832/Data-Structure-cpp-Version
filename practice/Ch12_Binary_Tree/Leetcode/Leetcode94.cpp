#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
    public:
        //中序：左 中 右
        vector<int> inorderTraversal(TreeNode* root){
            vector<int> result;
            inorder(root, result);
            return result;
        }

        void inorder(TreeNode* current, vector<int>& path){
            if(current == nullptr){
                return;
            }
            inorder(current->left, path);
            path.push_back(current->val);
            inorder(current->right, path);
        }
};