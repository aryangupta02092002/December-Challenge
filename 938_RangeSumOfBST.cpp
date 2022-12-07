#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int a) {
        val = a;
        left = right = NULL;
    }
};

void insert(TreeNode*& root, int key)
{
    TreeNode* node = new TreeNode(key);
    if (!root) {
        root = node;
        return;
    }
    TreeNode* prev = NULL;
    TreeNode* temp = root;
    while (temp) {
        if (temp->val > key) {
            prev = temp;
            temp = temp->left;
        }
        else if (temp->val < key) {
            prev = temp;
            temp = temp->right;
        }
    }
    if (prev->val > key)
        prev->left = node;
    else
        prev->right = node;
}

class Solution {
  public:
    int sum = 0;
    // void helper(TreeNode* root, int low, int high){
    //     if(!root){
    //         return;
    //     }
    //     if(root->val >= low && root->val <= high){
    //         sum += root->val;
    //         helper(root->left, low, high);
    //         helper(root->right, low, high);
    //     }
    //     else if(root->val > low){
    //         rangeSumBST(root->left, low, high);
    //     }
    //     else if(root->val < high){
    //         rangeSumBST(root->right, low, high);
    //     }
    // }
    void helper(TreeNode* root, int low, int high){
        if(!root){
            return;
        }
        if(root->val >= low && root->val <= high){
            sum += root->val;
        }
        helper(root->left, low, high);
        helper(root->right, low, high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        helper(root, low, high);
        return sum;
    }
};

int main() {

    int t;
    cin>>t;
    while (t--) {
        TreeNode* root = NULL;
        insert(root, 30);
        insert(root, 50);
        insert(root, 15);
        insert(root, 20);
        insert(root, 10);
        insert(root, 40);
        insert(root, 60);
        int low, high;
        cin>>low>>high;

        Solution obj;
        cout << obj.rangeSumBST(root, low, high) << endl;
    }
    return 0;
}