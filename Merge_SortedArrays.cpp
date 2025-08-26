/* Merges two sorted linked lists into a single sorted list.
 Time Complexity: O(n + m)
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

// This function merges two sorted linked lists.
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    // Create a dummy node to act as the head of the merged list.
    ListNode dummy_node(0);
    ListNode* current = &dummy_node;

    // Iterate while both lists have nodes to compare.
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val <= list2->val) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    // Add the remaining nodes from either list.
    if (list1 != nullptr) {
        current->next = list1;
    } else {
        current->next = list2;
    }

    // Return the head of the new merged list (after the dummy node).
    return dummy_node.next;
}

// Helper function to print a linked list.
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

// --- Example Usage ---
int main() {
    // Create list 1: 1 -> 2 -> 4
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);
    
    // Create list 2: 1 -> 3 -> 4
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);
    
    cout << "List 1: ";
    printList(list1);
    
    cout << "List 2: ";
    printList(list2);
    
    ListNode* merged_list = mergeTwoLists(list1, list2);
    
    cout << "Merged List: ";
    printList(merged_list);
    
    return 0;
}