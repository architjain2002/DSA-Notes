// CPP program to reverse a Queue
#include <bits/stdc++.h>
using namespace std;

// Utility function to print the queue
void Print(queue<int> &Queue)
{
    while (!Queue.empty())
    {
        cout << Queue.front() << " ";
        Queue.pop();
    }
}

// Function to reverse the queue
void reverseQueue(queue<int> &q)
{
    if (q.size() == 0) // base case
        return;
    int fr = q.front(); // storing front(first element) of
                        // queue
    q.pop();            // removing front
    reverseQueue(q);    // asking recursion to reverse the
                        // leftover queue
    q.push(fr);         // placing first element at its correct
                        // position
}

// Driver code
int main()
{
    queue<int> Queue;
    Queue.push(10);
    Queue.push(20);
    Queue.push(30);
    Queue.push(40);
    Queue.push(50);
    Queue.push(60);
    Queue.push(70);
    Queue.push(80);
    Queue.push(90);
    Queue.push(100);

    reverseQueue(Queue);
    Print(Queue);
}
// This code is contributed by Nakshatra Chhillar
