/* Inorder traversal of a binary tree (both recursive and iterative).
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

//  Recursive Approach 
void inorderTraversalRecursiveHelper(TreeNode* root, vector<int>& result) {
    if (root == nullptr) {
        return;
    }
    inorderTraversalRecursiveHelper(root->left, result);
    result.push_back(root->val);
    inorderTraversalRecursiveHelper(root->right, result);
}

vector<int> inorderTraversalRecursive(TreeNode* root) {
    vector<int> result;
    inorderTraversalRecursiveHelper(root, result);
    return result;
}

// Iterative Approach 
vector<int> inorderTraversalIterative(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> s;
    TreeNode* current = root;

    while (current != nullptr || !s.empty()) {
        // Reach the leftmost node of the current subtree.
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }

        // Pop the top element and add it to the result.
        current = s.top();
        s.pop();
        result.push_back(current->val);

        // Move to the right child.
        current = current->right;
    }
    return result;
}


int main() {

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    cout << "Inorder Traversal (Recursive):" << endl;
    vector<int> resultRecursive = inorderTraversalRecursive(root);
    for (int val : resultRecursive) {
        cout << val << " "; 
    }
    cout << endl;

    cout << "Inorder Traversal (Iterative):" << endl;
    vector<int> resultIterative = inorderTraversalIterative(root);
    for (int val : resultIterative) {
        cout << val << " "; 
    }
    cout << endl;
    return 0;

}
