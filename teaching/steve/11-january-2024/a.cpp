#include <bits/stdc++.h>
using namespace std;
int main() {
    int A[101][101], B[101][101], M, N, P;
    cin>>N>>M>>P;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>A[i][j]; //matriks A
        }
    }
    for(int k=0; k<M; k++){
        for(int m=0; m<P; m++){
            cin>>B[k][m]; //matriks B
        }
    }
    for(int n=0; n<N; n++){
        for(int l=0; l<P; l++){
            int C=0;
            for(int k=0; k<M; k++){
                C = C + A[n][k]*B[k][l];
                cout << "DEBUG " << C << " " << k << " " << M << endl;
            }
            cout<<C<<" ";
        }
        cout<<endl;
    }
}