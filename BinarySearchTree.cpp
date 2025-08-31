#include<iostream>
#include<queue>
using namespace std;


// Insert a Node in BST
// Insert a Node in BST - T.C. - O(log n) - homework - derivation 

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }


};

void inorder(Node* root) {
    // base case
    if(root == NULL) {

        return ;
    }
        inorder(root -> left);
        cout << root -> data << " ";
        inorder(root -> right);
}

void preorder(Node* root) {

    // base case
    if(root == NULL) {

        return ;
    }

    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);

}

void postorder(Node* root) {

    // base case
    if(root == NULL) {

        return ;
    }

    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";

}

void levelOrderTraversal(Node* root) {

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        }

        else {
        cout << temp -> data << " "; 
        if(temp -> left) {
            q.push(temp -> left);
        }
        if(temp -> right) {
            q.push(temp -> right);

        }
     }
  }
}

 Node* insertIntoBST(Node* root, int d) {

    //base case
    if(root == NULL) {
        root = new Node(d);
        return root;
    }
    // root means any node
    if( d> root -> data) {
        //insert in right part
        root -> right = insertIntoBST(root -> right, d);
    }

    else{
        root -> left = insertIntoBST(root -> left, d);
    }

}

void takeInput (Node* &root){
    int data;
    cin >> data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

int main() {

    Node* root = NULL;
    cout << "enter data " << endl;
    takeInput(root);

    cout<<"printing the BST" << endl;

    levelOrderTraversal(root);

    cout << "Printing Inorder" << endl;
    inorder(root);

    cout <<  endl << "Printing Preorder" << endl;
    preorder(root);

    cout << endl << "Printing Postorder" << endl;
    postorder(root);

    cout << " min value is " << minValue(root) -> data << endl;
    cout << " max value is " << maxValue(root) -> data << endl;

    root = del(root, 30); // deletion

    cout<<"printing the BST" << endl;

    levelOrderTraversal(root);

    cout << "Printing Inorder" << endl;
    inorder(root);

    cout <<  endl << "Printing Preorder" << endl;
    preorder(root);

    cout << endl << "Printing Postorder" << endl;
    postorder(root);

    cout << " min value is " << minValue(root) -> data << endl;
    cout << " max value is " << maxValue(root) -> data << endl;

    return 0;
}

// CodeStudio
// Search a number in BST (Binary Searh Tree), if the number is present in BST or not.
// t.c. O(n) or O(h) - height homework - search t.c. and s.c.

bool searchInBST(Node* root, int x) {
    // base case
    if(root == NULL) {
        return false;
    }

    if(root -> data == x)
        return true;

    if(root -> data > x){
        // left part me
        return (root -> left, x);
    }

    else {
        //right part me
        return (root -> right, x);
    }
}

// find min / max in bst

Node* minValue(Node* root) {
    Node* temp = root;

    while(temp -> left != NULL) {
        temp = temp -> left;
    }

    return temp;
}

Node* maxValue(Node* root) {
    Node* temp = root;

    while(temp -> right != NULL) {
        temp = temp -> right;
    }

    return temp;
}

// delete a node in BST

Node* del(Node*  root, int val){
    // base case
    if(root == NULL){
        return root;
    }

    if(root -> data == val) {

        if(root -> left == NULL && root -> right == NULL) {
            delete root;
            return NULL;
        }

        // left child
        if(root -> left != NULL && root -> right == NULL) {
            Node* temp = root -> left;
            delete root;
            return temp;
        }

        // right child
        if(root -> left == NULL && root -> right != NULL) {
            Node* temp = root -> right;
            delete root;
            return temp;
        }

        if(root -> left != NULL && root -> right != NULL){
            int mini = minValue(root -> right) -> data;
            root -> data = mini;
            root -> right = del(root -> right, mini);
            return root;
        }

    }

    else if (root -> data > val) {
        //left part me gye
        root -> left = del(root ->left, val);
        return root;
    }

    else{
        // right part me gye
        root -> right = del(root ->right, val);
        return root;
    }
}
