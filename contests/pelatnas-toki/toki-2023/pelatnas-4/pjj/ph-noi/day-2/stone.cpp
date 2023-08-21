#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
using namespace std;
int main() {
    int h, w;
    cin >> h >> w;
    char grid[h + 5][w + 5];
    for(int i = 1; i <= h; ++i) {
        for(int j = 1; j <= w; ++j)
            grid[i][j] = '.';
    }
    if(h & 1) {
        for(int i = 1; i <= w; i += 2) {
            if((i / 2) & 1) {
                for(int j = 1; j <= h; j += 2)
                    grid[j][i] = '#';
            }
            else {
                for(int j = 1; j <= h; j += 4)
                    grid[j][i] = '#';
            }
        }
    }
    else if(h == 2) {

    }
    else if(h == 4) {
        for(int i = 1; i <= w; ++i) {
            if(i % 6 == 1) {
                grid[1][i] = '#';
                grid[3][i] = '#';
            }
            else if(i % 6 == 4) {
                grid[2][i] = '#';
                grid[4][i] = '#';
            }
            else if(i % 6 == 2 || i % 6 == 0) {
                grid[4][i] = '#';
            }
            else {
                grid[1][i] = '#';
            }
        }
    }
    else if(h == 6) {
        for(int i = 1; i <= w; ++i) {
            if(i % 10 == 1) {
                grid[3][i] = grid[5][i] = '#';
            }
            else if(i % 10 == 2 || i % 10 == 0) {
                grid[6][i] = '#';
            }
            else if(i % 10 == 3 || i % 10 == 9) {
                grid[1][i] = grid[3][i] = '#';
            }
            else if(i % 10 == 4 || i % 10 == 8) {
                grid[4][i] = grid[6][i] = '#';
            }
            else if(i % 10 == 5 || i % 10 == 7) {
                grid[1][i] = '#';   
            }
            else {
                grid[2][i] = grid[4][i] = '#';
            }
        }
        if(w % 10 == 2) {
            swap(grid[4][w - 2], grid[6][w - 2]);
            grid[3][w - 1] = grid[5][w - 1] = '.';
            grid[1][w - 1] = '#';
            grid[2][w] = grid[4][w] = '#';
        }
        else if(w % 10 == 7) {
            swap(grid[1][w - 2], grid[3][w - 2]);
            grid[2][w - 1] = grid[4][w - 1] = '.';
            grid[6][w - 1] = '#';
            grid[3][w] = grid[5][w] = '#';
        }
    }
    for(int i = 1; i <= h; ++i) {
        for(int j = 1; j <= w; ++j)
            cout << grid[i][j];
        cout << endl;
    }
    // buat bitmask, kita checking dr previous bitmask, transisi ke bitmask sekarang dapet berapa?
    // butuh 2 bitmask terakhir tapi
    // 2^(3h*w)
}