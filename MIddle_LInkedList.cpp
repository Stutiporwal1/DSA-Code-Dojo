/* Finds the middle node of a singly linked list using a fast and slow pointer approach.
Time Complexity: O(n)
Space Complexity: O(1) */


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

// This function finds the middle node of the linked list.
ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    // The fast pointer moves two steps, and the slow pointer moves one.
    // When the fast pointer reaches the end, the slow pointer will be at the middle.
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
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
  
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);
    
    cout << "Original list 1: ";
    printList(head1);
    ListNode* middle1 = middleNode(head1);
    cout << "Middle node value: " << middle1->val << endl; 
    
    cout << endl;
    
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);
    head2->next->next->next->next->next = new ListNode(6);
    
    cout << "Original list 2: ";
    printList(head2);
    ListNode* middle2 = middleNode(head2);
    cout << "Middle node value: " << middle2->val << endl;

    return 0;
}
