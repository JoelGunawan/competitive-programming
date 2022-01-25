#include <bits/stdc++.h>
using namespace std;
int memo[100][100];

int f(int a, int b) {
    return b == 0 ? a : f(b, a % b);
}

int g(int a) {
    int bebek = 0;
    for(int i = 1; i < a; ++i) {
        if(f(i, a) == 1)
            ++bebek;
    }
    return bebek;
}

int h(int x, int y) {
    if(x < y)
        return 0;
    else if(y == 0)
        return 1;
    else
        return h(x - 1, y - 1) + h(x - 1, y);
}

void peko(vector<int> x) {
    for(int i = 0; i < x.size() / 2; ++i)
        swap(x[i], x[x.size() - i - 1]);
}

bool toki(int n) {
    bool x = 1;
    for(int i = 2; i < n; ++i)
        if(n % i == 0)
            x = 0;
    return x;
}

int main() {
    memset(memo, -1, sizeof(memo));
    int cnt = 0;
    for(int i = 1; i <= 100; ++i)
        if(toki(i))
            ++cnt;
    cout << cnt << endl;
    return 0;
}