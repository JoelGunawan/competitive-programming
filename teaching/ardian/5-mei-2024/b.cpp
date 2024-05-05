#include <bits/stdc++.h>
using namespace std;
int main() {
    priority_queue<int> pq;
    // kompleksitas insert/erase O(log)
    set<int> s;
    // set -> priority queue, tapi bisa akses tengahnya TAPI harus pake lower_bound/find
    // s.lower_bound(x) mengembalikan iterator elemen yg terkecil >= x
    s.insert(3);
    s.insert(5);
    s.insert(2);
    cout << *s.lower_bound(4) << endl;
    // == s.end() -> invalid
    if(s.lower_bound(6) == s.end())
        cout << *s.lower_bound(6) << endl;
    // s.begin() paling kecil
    // s.end() paling besar
    // nilai paling besar
    // --s.end()
    s.insert(7);
    cout << *--s.end() << endl;
    cout << *s.begin() << endl;
    // s.upper_bound(x) terkecil yg > x
    vector<int> v;
    // syarat: vector terurut
    // lower_bound(v.begin(), v.end(), x); x -> yg dicari
    // utk iterator vector bisa dikurangi
    v = {2, 3, 4, 7, 10};
    cout << lower_bound(v.begin(), v.end(), 6) - v.begin() << endl;
}