// Implementation using STL 

/*

#include<iostream>
#include<queue>

using namespace std;

int main() {
    deque<int> d;

    d.push_front(12);
    d.push_back(5);

    cout << d.front() << endl;
    cout << d.back() << endl;

    d.pop_front();

    cout << d.front() << endl;
    cout << d.back() << endl;

    d.pop_back();

    if(d.empty()){
        cout << "Queue is empty" << endl;
    }
    else {
        cout << " queue is full" << endl;
    }
}

*/

// Implementation using Class

class Deque {
    int *arr;
    int front;
    int rear;
    int size;

    public:
    Deque(int n){
        size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    bool enqueue(int x) {
        if((front == 0 && rear == size - 1) || (rear == (front - 1) % (size -1) ) ) {
            return false;
        }
        else if(front == -1) {
            front = rear = 0;
        }
        else if(rear == size -1 && front != 0) {
            rear = 0;
        }

        else {
            rear++;
        }
        arr[front] = x;
        return true;
    }

    bool pushRear (int x) {
        if((front == 0 && rear == size -1) || (rear == (front - 1) % (size - 1) ) ) {
            return false;
    }
    else if(front == -1) {
        front = rear = 0;
    }
    else if (rear == size -1 && front != 0) {
        rear = 0;
    }
    else{
        rear++;
    }
    arr[rear] = x;
    return true;
    }
int dequeue () {
        if(front == -1){
            cout << "Queue is Empty" << endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear) {
            //single element is present
            front = rear = -1;
        }
        else if(front == size -1){
            front = 0; // to maintain cyclic nature
        }

        else {
            front++;
        }

        return ans;
    }

};




