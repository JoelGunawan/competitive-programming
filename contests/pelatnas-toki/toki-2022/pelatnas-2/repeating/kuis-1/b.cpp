#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define ins insert
#define ll long long
using namespace std;
const int lim = 200005;
int LOG[lim];
struct sparse_table_max {
    int a[18][lim];
    int merge(int a, int b) {
        return max(a, b);
    }
    void build(vector<int> arr) {
        for(int i = 0; i < arr.size(); ++i)
            a[0][i] = arr[i];
        for(int i = 1; i < 18; ++i) {
            for(int j = 0; j + (1 << i) <= lim; ++j) {
                a[i][j] = merge(a[i - 1][j], a[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    int query(int l, int r) {
        int dist = (r - l + 1);
        return merge(a[LOG[dist]][l], a[LOG[dist]][r - (1 << (LOG[dist])) + 1]);
    }
};
struct sparse_table_min {
    int a[18][lim];
    sparse_table_min() {
        for(int i = 0; i < 18; ++i)
            for(int j = 0; j < lim; ++j)
                a[i][j] = INT_MAX;
    }
    int merge(int a, int b) {
        return min(a, b);
    }
    void build(vector<int> arr) {
        for(int i = 0; i < arr.size(); ++i)
            a[0][i] = arr[i];
        for(int i = 1; i < 18; ++i) {
            for(int j = 0; j + (1 << i) <= lim; ++j) {
                a[i][j] = merge(a[i - 1][j], a[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    int query(int l, int r) {
        int dist = (r - l + 1);
        return merge(a[LOG[dist]][l], a[LOG[dist]][r - (1 << (LOG[dist])) + 1]);
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i = 2; i <= lim; ++i)
        LOG[i] = LOG[i >> 1] + 1;
    sparse_table_min minq;
    sparse_table_max maxq;
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    // binser for indeks ke i
    // prefmax previous itu berapa
    ll res = 0;
    stack<int> s;
    for(int i = 0; i < n; ++i) {
        for(int j = i; j < n; ++j) {
            if(s.size() > 0 && a[j] < s.top()) {
                while(s.size() > 0 && a[j] )
                s.pop();
                s.push(a[j]);
            }
            else if(s.size() == 0 && a[j] > a[i]) 
                s.push(a[j]);
            else if(s.size() > 0 && a[j] > s.top())
                s.push(a[j]);
        }
    }
    return 0;
}
/*
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
ll n,arr[N],letak[N];
vector<pii > mini,minichanges,maxi,p;
ll ans;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen(,r,stdin);
    //freopen(,w,stdout);
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
        letak[arr[i]] = i;
    }
    for(int i = n;i>=1;i--){
        while(mini.empty() == false && mini.back().fi > arr[i]){
            minichanges.pb({mini.back().fi,i});
            mini.pop_back();
        }
        mini.pb({arr[i],i});
    }
    // for(auto isi : minichanges) cout<<isi.fi<<" "<<isi.se<<endl;
    for(int i = 1;i<=n;i++){
        while(p.empty() == false && p.back().fi < arr[i]){
            int ki = 0,ka = mini.size() - 1;
            int pos = mini.size();
            // debug(i);
            // for(auto isi: mini) cout<<isi.fi<<endl;
            while(ki <= ka){
                int mid = (ki + ka)/2;
                if(mini[mid].fi > p.back().fi){
                    pos = mid;
                    ka = mid - 1;
                }
                else{
                    ki = mid + 1;
                }
            } 
            ll len = p.back().se;
            if(p.size() > 1) len = p.back().se - p[p.size() - 2].se; 
            ll z = 0;
            if(pos == 0){
                z = n - i + 1;
            }
            else{
                z = letak[mini[pos - 1].fi] - 1 - i + 1;
            }
            // if(pos != mini.size()-1) z = mini[pos + 1].se - mini[pos].se + 1;
            // cout<<len <<" "<<z<<endl;;
            ans += len *z;
            // cout<<"-------"<<endl;
            p.pop_back();
        }
        p.pb({arr[i],i});
        if(letak[mini.back().fi] == i){
            mini.pop_back();
        }
        vector<pii >temp;
        while(minichanges.empty() == false && minichanges.back().se == i){
            mini.pb(minichanges.back());
            minichanges.pop_back();
        } 
    }
    cout<<ans + n * (n + 1)/2<<endl;
}
*/