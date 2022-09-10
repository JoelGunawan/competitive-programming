#include <bits/stdc++.h>
using namespace std;
int main() {
    // priority_queue, queue, deque, vector, set, multiset, unordered_map, map, stack
    // priority queue
    // biasanya dipakai untuk dijkstra/prim (algoritma mst)
    priority_queue<int> x;
    x.push(5);
    x.push(3);
    x.push(7); // masukkan elemen ke x
    cout << x.top() << endl; // cek elemen terbesar di x
    x.empty(); // buat cek elemen x kosong atau bukan
    x.size(); // banyak elemen di x
    x.pop(); // keluarkan elemen terbesar di x
    // kompleksitas operasi O(logn)
    // push o(logn) pop o(logn) query o(1 ataulogn)
    // pertama -> jarak, kedua -> node
    priority_queue<pair<int, int>> dijkstra;
    vector<pair<int, int>> edges[10005];
    bool vis[10005];
    int ans[10005];
    dijkstra.push({-0, 1});
    while(!dijkstra.empty()) {
        int node = dijkstra.top().second, distance = -dijkstra.top().first;
        dijkstra.pop();
        // di dijkstra kita mau access elemen yang nilainya paling kecil
        if(vis[node])
            continue;
        vis[node] = 1;
        ans[node] = distance;
        for(auto i : edges[node]) {
            if(!vis[i.first])
                dijkstra.push({distance + i.second, i.first});
        }
    }
    // queue
    // mirip baris antrian
    queue<int> q;
    q.push(5);
    q.pop();
    q.size();
    q.empty();
    
    // deque
    // semacam super vektor
    deque<int> dq;
    dq.push_back(0);
    dq.push_front(2);
    dq.pop_front();
    dq.pop_back();
    dq.size();
    dq.push_back(4);
    cout << dq[0] << endl;

    stack<int> st;
    st.push(5);
    st.pop();
    st.size();
    st.empty();

    set<int> s; // balanced binary search tree/red black tree
    // fungi set: kita punya beberapa elemen, akan diurutkan menaik otomatis
    // buat akses: pake lower_bound aja sama upper_bound O(logn), kalo tidak O(n)
    // fungsi find, periksa apakah elemen ada di set atau tidak
    // jika ada elemen duplikat, dia akan hanya pakai 1
    int cari = 0;
    // mengembalikkan iterator (bukan angkanya)
    s.lower_bound(cari);
    s.upper_bound(cari);
    s.find(cari);
    
    s.begin();
    s.end()++;
    s.begin()--;
    
    s.insert(5);
    s.erase(s.find(5)); // erase element jika tidak ada elementnya, maka tidak akan erase

    multiset<int> ms;
    ms.count(5);
    s.count(5);
    // bisa buat gantikan binser
    // pair<int, int> di dalam set/multiset -> merging dsu (yang akan dipelajari)
    // dynamic array yang butuh sorting
    // kita keluar/masukkan elemen tapi butuh binser
    // iterasi nilai set
    for(auto i : s) {

    }
    // iterasi iterator multiset
    for(auto it = ms.begin(); it != ms.end(); ++it) {
        
    }


}