#include <bits/stdc++.h>
using namespace std;
int m = 1e6;
bool is_bigger_than_one_million = 0;
long long fast_expo(long long a, long long b) {
    if(b == 0) {
        return 1;
    }
    else {
        long long tmp = fast_expo(a, b / 2);
        tmp = tmp * tmp;
        if(tmp >= 1e6)
            is_bigger_than_one_million = 1;
        tmp %= m;
        if(b % 2 == 1) {
            tmp = tmp * a;
            if(tmp >= 1e6)
                is_bigger_than_one_million = 1;
            tmp %= m;
            return tmp;
        }
        else {
            return tmp;
        }
    }
}
int main() {
    int a, b;
    cin >> a >> b;
    int output = fast_expo(a, b);
    if(is_bigger_than_one_million) {
        // bisa jadi harus ditambahkan 0
        string s = to_string(output);
        while(s.size() < 6)
            s.insert(s.begin(), '0');
        cout << s << endl;
    }
    else {
        cout << output << endl;
    }
}