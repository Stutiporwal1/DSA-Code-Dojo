/* Postorder traversal of a binary tree (both recursive and iterative).
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

// --- Recursive Approach ---
void postorderTraversalRecursiveHelper(TreeNode* root, vector<int>& result) {
    if (root == nullptr) {
        return;
    }
    postorderTraversalRecursiveHelper(root->left, result);
    postorderTraversalRecursiveHelper(root->right, result);
    result.push_back(root->val);
}

vector<int> postorderTraversalRecursive(TreeNode* root) {
    vector<int> result;
    postorderTraversalRecursiveHelper(root, result);
    return result;
}

// --- Iterative Approach (Two Stacks) ---
vector<int> postorderTraversalIterative(TreeNode* root) {
    vector<int> result;
    if (root == nullptr) {
        return result;
    }

    stack<TreeNode*> s1;
    stack<TreeNode*> s2;
    s1.push(root);

    while (!s1.empty()) {
        TreeNode* current = s1.top();
        s1.pop();
        s2.push(current);

        if (current->left != nullptr) {
            s1.push(current->left);
        }
        if (current->right != nullptr) {
            s1.push(current->right);
        }
    }

    while (!s2.empty()) {
        result.push_back(s2.top()->val);
        s2.pop();
    }
    
    return result;
}

int main() {
    
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    cout << "Postorder Traversal (Recursive):" << endl;
    vector<int> resultRecursive = postorderTraversalRecursive(root);
    for (int val : resultRecursive) {
        cout << val << " "; 
    }
    cout << endl;

    cout << "Postorder Traversal (Iterative):" << endl;
    vector<int> resultIterative = postorderTraversalIterative(root);
    for (int val : resultIterative) {
        cout << val << " "; 
    }
    cout << endl;

    return 0;

}
