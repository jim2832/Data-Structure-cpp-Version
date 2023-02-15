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

class Solution {
    public:
        //回傳最左邊的節點
        TreeNode* Left_Most(TreeNode* root){
            if(root == nullptr){
                return nullptr;
            }
            while(root->left != nullptr){
                root = root->left;
            }
            return root;
        }

        TreeNode* deleteNode(TreeNode* root, int key){
            if(root == nullptr){
                return nullptr;
            }

            TreeNode* parent = root; //宣告父節點
            TreeNode* new_root = root; //宣告新的樹根

            while(root != nullptr && key != root->val){
                parent = root; //每次將root給parent更新
                //在左子樹
                if(key < root->val){
                    root = root->left;
                }
                //在右子樹
                else{
                    root = root->right;
                }
            }

            //如果最後也沒找到
            if(root == nullptr){
                return new_root;
            }

            // Case1: 刪除的節點是樹葉(degree是0)
            if(root->left == nullptr && root->right == nullptr){
                if(root == new_root){
                    new_root = nullptr;
                }
                //此節點為父節點的左子點
                if(root == parent->left){
                    parent->left = nullptr;
                }
                //此節點為父節點的右子點
                else{
                    parent->right = nullptr;
                }
            }

            // Case3: 刪除的節點degree為2
            else if(root->left != nullptr && root->right != nullptr){
                TreeNode* successor = Left_Most(root->right);
                // 用前繼者取代樹根
                int temp = successor->val;
                deleteNode(root, successor->val);
                root->val = temp;
            }

            // Case2: 刪除的節點degree為1
            else{
                TreeNode* child = root->left != nullptr?root->left:root->right;
                if(root == new_root){
                    new_root = child;
                }
                //刪除的點是父節點之左子點
                if(root == parent->left){
                    parent->left = child;
                }
                //刪除的點是父節點之右子點
                else{
                    parent->right = child;
                }
            }
            return new_root;
        }
};