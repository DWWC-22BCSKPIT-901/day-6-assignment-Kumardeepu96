#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& preIdx, int inStart, int inEnd) {
    if (inStart > inEnd) return NULL;
    TreeNode* root = new TreeNode(preorder[preIdx++]);
    int inIdx = inStart;
    while (inorder[inIdx] != root->val) inIdx++;
    root->left = build(preorder, inorder, preIdx, inStart, inIdx - 1);
    root->right = build(preorder, inorder, preIdx, inIdx + 1, inEnd);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int preIdx = 0;
    return build(preorder, inorder, preIdx, 0, inorder.size() - 1);
}
