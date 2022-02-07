# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
#define pii pair<int,int>
#define debug(x) cout << #x << '=' << x << endl;
const int N = 2e5 + 5;
const int INF = 1e9;
const ll mod = 1e9+7;
// solution by edbert h
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen(,r,stdin);
    //freopen(,w,stdout);
    string a,b;
    cin>>a>>b;
    bool x = 1,y = 1;
    for(auto isi : a){
        if(!(isi >= '0' && isi <= '9')) x = 0;
    }
    for(auto isi : b){
        if(!(isi >= '0' && isi <= '9')) y = 0;
    }
    if(x == 0 || y == 0) cout<<"NaN"<<endl;
    else{
        int c = 0,d = 0;
        for(auto isi : a){
            c = c * 10 + (isi - '0');
        }
        for(auto isi : b){
            d = d * 10 + (isi - '0');
        }
        cout<<c - d<<endl;
    }
}