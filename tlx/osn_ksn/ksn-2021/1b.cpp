#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
// subtask 2
/*
bool vis[201][201], arr[201][201];
void dfs(int x, int y) {
    vis[x][y] = 1;
    if(x + 1 < 201 && !vis[x + 1][y] && !arr[x + 1][y])
        dfs(x + 1, y);
    if(x - 1 >= 0 && !vis[x - 1][y] && !arr[x - 1][y])
        dfs(x - 1, y);
    if(y + 1 < 201 && !vis[x][y + 1] && !arr[x][y + 1])
        dfs(x, y + 1);
    if(y - 1 >= 0 && !vis[x][y - 1] && !arr[x][y - 1])
        dfs(x, y - 1);
}
int main() {
    int n, m, q, a, b, c, d;
    cin >> n >> m >> q;
    for(int i = 0; i < 201; ++i)
        for(int j = 0; j < 201; ++j)
            arr[i][j] = i & j;
    while(q--) {
        memset(vis, 0, sizeof(vis));
        cin >> a >> b >> c >> d;
        int res = 0;
        for(int i = 0; i < 201; ++i)
            for(int j = 0; j < 201; ++j)
                if(i < a || i > c || j < b || j > d)
                    vis[i][j] = 1;
        for(int i = a; i <= c; ++i)
            for(int j = b; j <= d; ++j)
                if(!vis[i][j] && !arr[i][j])
                    dfs(i, j), ++res;
        cout << res << endl;
    }
}
*/
// subtask 3
/*
int main() {
    int n, m, q, a, b, c, d;
    cin >> n >> m >> q;
    while(q--) {
        cin >> a >> b >> c >> d;
        bool active = 0;
        int res = 0;
        for(int i = b; i <= d; ++i) {
            if(!(i & a) && !active) {
                active = 1;
                ++res;
            }
            active = !(i & a);
        }
        cout << res << endl;
    }
}
*/
// subtask 4
/*
int main() {
    int n, m, q, a, b, c, d;
    cin >> n >> m >> q;
    while(q--) {
        cin >> a >> b >> c >> d;
        bool active = 0;
        int res = 0;
        for(int i = b; i <= d; ++i) {
            if(!(i & a) && !active) {
                active = 1;
                ++res;
            }
            active = !(i & a);
        }
        active = 0;
        for(int i = a; i <= c; ++i) {
            if(!(i & b) && !active) {
                active = 1;
                ++res;
            }
            active = !(i & b);
        }
        cout << res - !(a & b) << endl;
    }
}
*/
// subtask 5
/*
int main() {
    int n, m, q;
    cin >> n >> m >> q;
    while(q--)
        cout << 1 << endl;
}
*/
// subtask 6
/*
int main() {
    int n, m, q, a, b, c, d;
    cin >> n >> m >> q;
    while(q--) {
        cin >> a >> b >> c >> d;
        if(b == 0)
            cout << d / (2 * c) + 1 << endl;
        else
            cout << d / (2 * c) - (b - 1) / (2 * c) + ((!(a & b)) && (!(a & (b - 1)))) << endl;
    }
}
*/
// subtask 7
/*
int f(int a, int b) {
    if(a == 0 || b == 0)
        return 1;
    short lsb; ++b;
    for(short i = 30; i >= 0; --i)
        if(a & (1 << i))
            b = b / (1 << (i + 1)) * (1 << i) + min(b % (1 << (i + 1)), 1 << i), lsb = i;
    return ceil(b  / (double)(1 << lsb));
}
int find(int a, int b, int d) {
    if(b == 0)
        return f(a, d);
    return f(a, d) - f(a, b - 1) + (!(bool)(a & b) && !(bool)(a & (b - 1)));
}
int main() {
    int n, m, q, a, b, c, d;
    cin >> n >> m >> q;
    while(q--) {
        cin >> a >> b >> c >> d;
        cout << find(a, b, d) << endl;
    }
}
*/
// full solution
int f(int a, int b) {
    if(a == 0 || b == 0)
        return 1;
    short lsb; ++b;
    for(short i = 30; i >= 0; --i)
        if(a & (1 << i))
            b = b / (1 << (i + 1)) * (1 << i) + min(b % (1 << (i + 1)), 1 << i), lsb = i;
    return ceil(b  / (double)(1 << lsb));
}
int find(int a, int b, int d) {
    if(b == 0)
        return f(a, d);
    return f(a, d) - f(a, b - 1) + (!(bool)(a & b) && !(bool)(a & (b - 1)));
}
int main() {
    int n, m, q, a, b, c, d;
    cin >> n >> m >> q;
    while(q--) {
        cin >> a >> b >> c >> d;
        cout << find(b, a, c) + find(a, b, d) - !(bool)(a & b) << endl;
    }
    return 0;
}