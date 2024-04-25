#include <bits/stdc++.h>
using namespace std;
int main() {
    // operasi priority queue:
    // push(e) -> masuk ke priority queue
    // pop() -> mengeluarkan nilai paling besar di priority queue
    // top() -> nilai paling besar di priority queue
    // size() -> banyak elemen di priority queue
    priority_queue<int> pq;
    // pq = {}
    pq.push(5);
    // pq = {5}
    pq.push(3);
    // pq = {5, 3}
    pq.push(2);
    // pq = {5, 3, 2}
    pq.push(7);
    // pq = {5, 3, 2, 7}
    cout << pq.top() << endl; // A -> 7
    pq.pop();
    // pq = {5, 3, 2}
    cout << pq.top() << endl; // B -> 5
    pq.push(2), pq.push(4);
    // pq = {5, 3, 2, 2, 4}
    cout << pq.top() << endl; // C -> 5
    pq.pop();
    // pq = {3, 2, 2, 4}
    pq.pop();
    // pq = {3, 2, 2}
    pq.push(1);
    // pq = {3, 2, 2, 1}
    cout << pq.top() << endl; // D -> 3
    
}