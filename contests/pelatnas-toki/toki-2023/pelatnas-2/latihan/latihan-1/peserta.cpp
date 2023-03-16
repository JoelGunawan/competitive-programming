#include <bits/stdc++.h>
using namespace std;

int main(){
    // N merupakan jumlah stage
    
    // C[i][j] merupakan tenaga yang diperlukan untuk memindahkan
    // pemain dari stage i ke stage j dengan i < j
    int N;
    cin >> N;
    int C[101][101];
    for(int i = 1; i <= N; ++i) {
        for(int j = i + 1; j <= N; ++j) {
            cin >> C[i][j];
        }
    }
    int x = 1;
    int y = 1;
    int suma = 0;
    int sumb = 0;
    for(int pos = 2; pos <= N; ++pos){
        if(suma + C[x][pos] < sumb + C[y][pos]){
            suma += C[x][pos];
            x = pos;
        } else {
            sumb += C[y][pos];
            y = pos;
        }
        cout << pos << " " << suma << " " << sumb << " " << x << " " << y << endl;
    }
    
    cout << suma + sumb << endl;
}