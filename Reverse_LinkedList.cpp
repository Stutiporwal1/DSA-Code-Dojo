//
// C++ Solution
//
// Reverses a singly linked list iteratively.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
//

#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// This function reverses a linked list.
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next_node = nullptr;
    
    // Iterate through the list.
    while (current != nullptr) {
        // Store the next node.
        next_node = current->next;
        
        // Reverse the current node's pointer.
        current->next = prev;
        
        // Move the pointers one position ahead.
        prev = current;
        current = next_node;
    }
    
    // 'prev' will be the new head of the reversed list.
    return prev;
}

// Helper function to print the linked list.
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}


int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    cout << "Original list: ";
    printList(head);
    
    // Reverse the list.
    ListNode* reversed_head = reverseList(head);
    
    cout << "Reversed list: ";
    printList(reversed_head);
    
    return 0;
}