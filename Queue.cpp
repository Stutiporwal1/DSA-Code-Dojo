/* 
 Implements a queue using two stacks.
 Time Complexity: push() is O(1). 
 Space Complexity: O(n) for the stacks. 
 */

#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> inputStack;
    stack<int> outputStack;

public:
    MyQueue() {
        // Constructor, no specific initialization needed.
    }
    
    // Pushes element x to the back of the queue.
    void push(int x) {
        inputStack.push(x);
    }
    
    // Removes the element from the front of the queue and returns it.
    int pop() {
        // Ensure the output stack is ready for popping.
        prepareOutputStack();
        int frontElement = outputStack.top();
        outputStack.pop();
        return frontElement;
    }
    
    // Gets the front element.
    int peek() {
        // Ensure the output stack is ready for peeking.
        prepareOutputStack();
        return outputStack.top();
    }
    
    // Returns true if the queue is empty, false otherwise.
    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }

private:
    // Helper function to transfer elements from input to output stack.
    void prepareOutputStack() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
    }
};

// --- Example Usage ---
int main() {
    MyQueue myQueue;
    
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    
    cout << "Peek: " << myQueue.peek() << endl;  // Should be 1
    cout << "Pop: " << myQueue.pop() << endl;   // Should be 1
    
    myQueue.push(4);
    
    cout << "Peek: " << myQueue.peek() << endl;  // Should be 2
    cout << "Pop: " << myQueue.pop() << endl;   // Should be 2
    
    cout << "Is empty? " << (myQueue.empty() ? "true" : "false") << endl; // Should be false
    
    myQueue.pop(); // Pop 3
    myQueue.pop(); // Pop 4
    
    cout << "Is empty? " << (myQueue.empty() ? "true" : "false") << endl; // Should be true

    return 0;

}

