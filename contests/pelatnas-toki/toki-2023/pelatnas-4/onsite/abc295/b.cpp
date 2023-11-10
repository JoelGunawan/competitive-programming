#include <bits/stdc++.h>
using namespace std;
int main() {
    int r, c;
    cin >> r >> c;
    char a[r][c];
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            if(a[i][j] != '#' && a[i][j] != '.') {
                for(int x = 0; x < r; ++x) {
                    for(int y = 0; y < c; ++y) {
                        if(abs(x - i) + abs(y - j) <= a[i][j] - '0' && a[x][y] == '#')
                            a[x][y] = '.';
                    }
                }
                a[i][j] = '.';
            }
        }
    }
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            cout << a[i][j];
        }
        cout << endl;
    }
}