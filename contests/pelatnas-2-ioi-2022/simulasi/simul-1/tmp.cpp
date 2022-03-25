#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int res = 0;
    for(int i = 1; i < n; ++i) {
        // banyak binary digit yang diperlukan buat represent number itu
        // kita bisa lakuin 2logn + 2 query
        int tmp = 0;
        for(int j = 0; j < 10; ++j) {
            if(i % (1 << j) == 0)
                tmp = j;
        }
        res += tmp + 1;
       /*
       int tmp = 0;
       for(int j = 0; j < 10; ++j) {
           if(i & (1 << j))
            tmp += j + 1;
       }
        res = max(res, tmp);
        */
    }
    cout << res << endl;
    // NICE

}