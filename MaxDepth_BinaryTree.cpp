/* Finds the maximum depth of a binary tree using a recursive approach.
 Time Complexity: O(n)
 Space Complexity: O(h) or O(n) in the worst case.
*/

#include <iostream>
#include <algorithm> 

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode* root) {
    // Base case: If the tree is empty, its depth is 0.
    if (root == nullptr) {
        return 0;
    }

    // Recursively find the depth of the left and right subtrees.
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    // The maximum depth is 1 (for the current node) plus the maximum
    // of the two subtree depths.
    return (leftDepth, rightDepth);
}

int main() {
    
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    int depth = maxDepth(root);
    
    cout << "The maximum depth of the binary tree is: " << endl;
    
    cout << depth << endl;
    return 0;
}
