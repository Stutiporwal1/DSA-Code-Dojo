/* Preorder traversal of a binary tree (both recursive and iterative).
 Time Complexity: O(n) for both approaches.
 Space Complexity: O(h) or O(n) for a skewed tree.
*/
#include <iostream>
#include <vector>
#include <stack>

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

// Recursive Approach
void preorderTraversalRecursiveHelper(TreeNode* root, vector<int>& result) {
    if (root == nullptr) {
        return;
    }
    result.push_back(root->val);
    preorderTraversalRecursiveHelper(root->left, result);
    preorderTraversalRecursiveHelper(root->right, result);
}

vector<int> preorderTraversalRecursive(TreeNode* root) {
    vector<int> result;
    preorderTraversalRecursiveHelper(root, result);
    return result;
}

// --- Iterative Approach ---
vector<int> preorderTraversalIterative(TreeNode* root) {
    vector<int> result;
    if (root == nullptr) {
        return result;
    }
    stack<TreeNode*> s;
    s.push(root);

    while (!s.empty()) {
        TreeNode* current = s.top();
        s.pop();
        result.push_back(current->val);

        // Push the right child first, so the left child is processed first.
        if (current->right != nullptr) {
            s.push(current->right);
        }
        if (current->left != nullptr) {
            s.push(current->left);
        }
    }
    return result;
}

int main() {
    
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    cout << "Preorder Traversal (Recursive):" << endl;
    vector<int> resultRecursive = preorderTraversalRecursive(root);
    for (int val : resultRecursive) {
        cout << val << " "; 
    }
    cout << endl;

    cout << "Preorder Traversal (Iterative):" << endl;
    vector<int> resultIterative = preorderTraversalIterative(root);
    for (int val : resultIterative) {
        cout << val << " "; 
    }
    cout << endl;

    return 0;
}