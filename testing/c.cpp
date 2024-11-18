// #include "menari.h"
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int M=998244353;
// vector<int> menari(int n, int q, std::vector<int> a, std::vector<int> l, std::vector<int> r) {
//   vector<int> ans;
//     for(int cur=0;cur<q;cur++){
//         int ct=0;
//         for(int i=l[cur];i<=r[cur];i++)for(int j=i;j<=r[cur];j++){
//             int tmp=1;
//             for(int k=i;k<=j;k++){
//                 tmp=lcm(tmp,a[k]);ct%=M;
//             }ct+=tmp;ct%=M;
//         }ans.push_back(ct%M);
//     }return ans;
// }
#include "energi.h"

double energi(int N, int K, int L, int R, vector<int> A) {

  double ans=0.0;
  vector<double>pref(N+1);
  pref[0]=0;
  for(ll i=1;i<=N;i++) {
    pref[i]+=A[i-1]+pref[i-1];
  }

  double lt=0.0,rt=1e5;

  for(int abc=0;abc<100;abc++){

    double mid=(lt+rt)/2;
    vector<double>pref(N+1),tot(N+1,1e9);
    tot[0]=0;

    for(ll i=1;i<=N;i++)
      pref[i]=pref[i-1]+A[i-1];

    deque<int>dq;
    dq.push_front(0);

    for(ll i=0;i<=N;i++){

        if(i<L)continue;

        while(!dq.empty()&&i-R-1>=dq.front())
          dq.pop_front();

        if(pref[dq.front()]-dq.front()*mid<=pref[i]-i*mid)
          tot[i]=tot[dq.front()]+1;
        else 
          tot[i]=tot[dq.front()];

        while(!dq.empty() &&
              (tot[dq.back()]>tot[i] ||
              (tot[dq.back()]==tot[i] && pref[dq.back()]-mid*dq.back()<=pref[i]-i*mid)))
                dq.pop_back();

        dq.push_back(i-L+1);

    }if(tot[N]>=K){lt=mid;ans=mid;}

    else rt=mid;

  }return ans;

}


// int main(){
//     ios_base::sync_with_stdio(false);cin.tie(0);
//     int n,k,l,r;cin>>n>>k>>l>>r;vector<int>a(n);
//     for(ll i=0;i<n;i++)cin>>a[i];
//     cout<<energi(n,k,l,r,a);
// }