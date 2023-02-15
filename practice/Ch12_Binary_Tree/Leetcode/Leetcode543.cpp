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
        int diameterOfBinaryTree(TreeNode* root){
            int max = 0;
            calculate(root, max);
            return max;
        }

        //算目前樹根之左子樹和右子樹的最大高度，及目前之最大值
        int calculate(TreeNode* root, int &max){
            if(root == nullptr){
                return 0;
            }

            int max_left = calculate(root->left, max); //max_left: 左子樹的最大高度
            int max_right = calculate(root->right, max); //max_right: 右子樹的最大高度

            //比較 max 和 max_left + max_right
            max = max > max_left+max_right?max:max_left+max_right;
            int max_height = max_left>max_right?max_left:max_right;
            return max_height + 1; //回傳樹根的高度
        }
};