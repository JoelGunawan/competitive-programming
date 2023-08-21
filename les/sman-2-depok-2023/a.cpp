#include <bits/stdc++.h>
using namespace std;
// fungsi -> membantu
int gcd(int a, int b) {

}

int main() {
    // gcd(a, b) = gcd(b, a % b)
    // kita stop klo b = 0
    /*
    int a, b;
    cin >> a >> b;
    int x = a, y = b;
    while(y != 0) {
        // ubah nilai x jadi y
        // ubah nilai y jadi x % y
        // variable sementara buat simpan nilai x
        int tmp = y;
        // variable sementara buat simpan nilai y
        int tmp2 = x % y;
        x = tmp;
        y = tmp2;
    }
    // kalo lupa -> __gcd(a, b)
    // builtin gcd function c++
    // mis. vector<>
    cout << __gcd(a, b) << endl; 
    cout << a * b / __gcd(a, b) << endl;   
    */
    vector<int> a;
    // push_back(x)
    // masukkan elemen ke x ke paling belakang vector
    // pop_back()
    // keluarkan elemen paling belakang
    // size()
    // output ukurannya
    // {}
    a.push_back(3);
    // {3}
    a.push_back(4);
    // {3, 4}
    a.pop_back();
    // {3}
    cout << a.size() << endl;
    cout << a[0] << endl;
    sort(a.begin(), a.end());
    // utk set, multiset, dan queue
    // tdk bs akses pakai []
    // harus pakai fungsi yg dikasih
    // T -> tipe data, bisa pair, string, int
    // set<T> 
    // insert(x)
    // erase(x)
    // lower_bound(x)
    // return iterator yg memiliki nilai >= x
    // upper_bound(x)
    // return iterator yg memiliki nilai > x
    set<int> s;
    s.insert(3);
    s.insert(5);
    // error
    // cek apakah lower_bound ada nilainya atau tidak
    if(s.lower_bound(6) != s.end()) {
        cout << *s.lower_bound(6) << endl;
    }
    // erase ada 2 cara
    s.erase(5);
    s.insert(5);
    s.erase(s.lower_bound(5));
    s.insert(7);
    // perlu akses elemen paling besar/kecil
    // paling besar
    cout << (*--s.end()) << endl;
    // paling kecil
    cout << (*s.begin()) << endl;
    // set -> tdk bs elemen duplikat
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(5);
    cout << s.size() << endl;
    for(auto i : s) {
        cout << i << " ";
    }
    cout << endl;
    // multiset<T>
    multiset<int> m;
    // di multiset
    // mis m.erase(3);
    // erase semua elemen yg bernilai 3
    // bukan hny 1
    // mau erase 1 aja?
    // a.erase(a.lower_bound(3));
    m.insert(3);
    m.insert(4);
    m.insert(4);
    m.insert(6);
    for(auto i : m)
        cout << i << " ";
    cout << endl;
    m.erase(4);
    for(auto i : m)
        cout << i << " ";
    cout << endl;
    m.insert(4);
    m.insert(4);
    m.insert(4);
    m.insert(4);
    m.erase(m.lower_bound(4));
    for(auto i : m)
        cout << i << " ";
    cout << endl;
    // map<T1, T2>
    // super array
    // b[T1] -> T2
    map<string, int> b;
    b["OSP"] = 3;
    cout << b["OSP"] << endl;
    // queue<T>
    // antrian asli
    // front .. ... .... back
    // pop() -> hilangkan yg depan
    // push() -> masukkan ke belakang
    // front() -> cari tau elemen yang ada di depan
    queue<int> q;
    q.push(3);
    q.push(4);
    q.push(7);
    q.push(2);
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    // deque<T>
    // vector tp lebih op
    // push_back()
    // pop_back()
    // push_front()
    // pop_front()
    // bisa akses pakai []
    // note: wktu ngelakuin operasi pastiin operasi valid (aplg klo erase, pop, lower_bound, [])
}