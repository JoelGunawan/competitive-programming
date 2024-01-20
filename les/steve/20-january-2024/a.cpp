#include <bits/stdc++.h>
using namespace std;
// pertama: print angka aja
// selanjutnya: x ...
void prime(int n) {
    for (int i=2; i<=sqrt(n); i++) {
        int k=0;
        while (n%i==0) {
            n/=i;
            k++;
        }
        if(k>0) {
            cout<<i;
            if (k>1){
                cout<<"^"<<k;
            }
        }
    }
    if(n > 1) {
        cout << n << endl;
    }
}
int main(){
    int n;
    cin>>n;
    prime(n);
}