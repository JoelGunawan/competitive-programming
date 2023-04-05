#include <bits/stdc++.h>
using namespace std;
int main() {
    map<string, int> nomor_telepon;
    stack<int> st;
    priority_queue<pair<int, int>> pq;
    nomor_telepon["Budi"] = 2152157;
    cout << nomor_telepon["Budi"] << endl;
    set<int> s;
    s.insert(1);
    s.insert(3);
    s.insert(2);
    s.insert(5);
    s.insert(5);
    cout << s.count(5) << endl;
    vector<int> v;
    int val;
    lower_bound(v.begin(), v.end(), val);
    if(s.lower_bound(6) == s.end()) {
        cout << -1 << endl;
    }
    else
        cout << (*s.lower_bound(6)) << endl;
    s.erase(5);
    cout << s.count(5) << endl;
    // multiset -> harus hati-hati
    // s.count() -> O(N)
    // s.erase(5) -> menghapus SEMUA elemen yang nilainya 5
    multiset<int> ms;
    ms.insert(5);
    ms.insert(5);
    ms.insert(5);
    cout << ms.count(5) << endl;
    ms.erase(ms.find(5));
    cout << ms.count(5) << endl;
}
