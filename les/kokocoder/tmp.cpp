#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;cin>>n>>m;
    long long a[300005];
    for(int i=0;i<n;i++) cin>>a[i];
    long long l=0,r=1e18,idx=0;
    while(l<=r){
        long long cnt =0,mid = (l+r)/2;
        //cout << l << " " << r << endl;
        for(int i=0;i<n;i++) {
            cnt += mid/a[i];
        }
        //cout << "TEST" << endl;
        if(cnt<=m){
            idx=mid;
            l=mid+1;
        }else r = mid-1;
    }
    long long idx2=0;
    l=0,r=1e18;
    while(l<=r){
        long long cnt =0,mid=(l+r)/2;
        for(int i=0;i<n;i++) cnt +=mid/a[i];
        if(cnt<=m-1){
            idx2=mid;
            l=mid+1;
        }else r=mid-1;
    }cout<<idx-idx2;
}