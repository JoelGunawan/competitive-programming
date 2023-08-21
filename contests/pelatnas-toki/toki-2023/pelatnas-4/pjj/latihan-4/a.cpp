#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    // constructive ->
    // 1111000
    // 1111000
    // 1111000 banyak row ini sesuai min 1 yg perlu brp
    // 0001111
    int grid[h][w];
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            if(i < b) {
                if(j < a)
                    grid[i][j] = 1;
                else
                    grid[i][j] = 0;    
            }
            else {
                if(j < a)
                    grid[i][j] = 0;
                else  
                    grid[i][j] = 1;
            }
            cout << grid[i][j];
        }
        cout << endl;
    }
}