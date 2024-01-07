#include <bits/stdc++.h>
using namespace std;
int main() {
    // array -> sekumpulan sebuah tipe data
    // hard code -> ga perlu array
    // 5 angka, buat 5 variable
    // handle input?
    // misal soal sum
    // diberi angka n, habis itu ada n input
    // array -> banyak kemunculan dari sebuah tipe data
    // tipe_data nama_variable[ukuran];
    // ukuran 5 -> 0...4
    // int n;
    // cin >> n;
    // int a[n];
    // for(int i = 0; i < n; ++i)
    //     cin >> a[i];
    // int sum = 0;
    // for(int i = 0; i < n; ++i)
    //     sum += a[i];
    // cout << sum << endl;
    // for(int i = n - 1; i >= 0; --i) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    // int b[] = {72, 20351, 5123958, 9182, 283};
    // int c[n][n];
    // // c[0][0] c[0][1] c[0][2]
    // // c[1][0] c[1][1] c[1][2]
    // // c[2][0] c[2][1] c[2][2]
    // for(int i = 0; i < n; ++i) {
    //     for(int j = 0; j < n; ++j) {
    //         cin >> c[i][j];
    //     }
    // }
    // for(int i = 0; i < n; ++i) {
    //     for(int j = 0; j < n; ++j) {
    //         cout << c[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    vector<int> v(5); // 0...4
    vector<int> t;
    v.size(); // -> ukuran array
    cout << v.size() << endl;
    v[0] = 3;
    cout << v[0] << endl;
    // masukkin nilai ke belakang array 
    v.push_back(7);
    cout << v[5] << endl;
    cout << v.size() << endl;
    v.pop_back();
    cout << v.size() << endl;
    v.insert(v.begin() + 1, 10);
    cout << v[1] << endl;
    v.erase(v.begin());
    cout << v[0] << endl;
    //v.insert(); // jarang dipakai klo sudah advanced
    //v.erase(); // jarang dipakai klo sudah advancded
}