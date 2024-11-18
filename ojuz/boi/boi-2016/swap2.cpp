#include<iostream>
#include<stack>
#include<map>
#include<vector>
#include<string>
#include<unordered_map>
#include <queue>
#include<cstring>
#include<limits.h>
#include <cassert>
#include<cmath>
#include<set>
#include<algorithm>
#include <iomanip>
#include<numeric> //gcd(a,b)
#include<bitset>
using namespace std;
#define ll long long
#define f first
#define endl "\n"
#define s second
#define pii pair<int,int>
#define ppii pair<int,pii>
#define vi vector<int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define F(n) for(int i=0;i<n;i++)
#define lb lower_bound
#define ub upper_bound
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);
#pragma GCC optimize ("03,unroll-loops")
using namespace std;
#define int long long
#define double long double
const int mod=1e9+7,mxn=5e5+5,lg=20,inf=1e18,minf=-1e18;
int val[mxn+10],n,ans[mxn+10];
bool yes[mxn+10],can[mxn+10],take[mxn+10],stop[mxn+10];
int32_t main(){
    fastio
    cin>>n;
    fill(val,val+mxn+1,inf);
    fill(can,can+mxn+1,true);
    for(int i=1;i<=n;i++)cin>>val[i];
    for(int i=1;i<=n;i++){
        int above=0;
        //cout<<i<<"A\n";
        for(int j=i;j>0;j>>=1){
            if(stop[j])break;
            if(take[j^1])break;
            if(take[j]){
                if(can[j^1]&&val[above]>val[j^1])above=j^1;
                break;
            }
            if(yes[j]){
                if(val[above]>val[j]&&can[j])above=j;
                break;
            }
            if(can[j]&&val[above]>val[j])above=j;
            if(!yes[j^1]&&val[above]>val[j^1]&&can[j^1]&&!stop[j>>1])above=j^1;
            /*
            if(can[j]&&val[above]>val[j])above=j;
            if(!block[j^1]&&can[j^1]&&val[above]>val[j^1])above=j^1;
            if(block[j]||stop[j])break;
            */
        }
        int mn=min({val[above],val[i*2],val[i*2+1]});
        if(mn==val[i*2]){
            yes[i*2+1]=true;
            can[i*2]=false;
        }
        else if(mn==val[i*2+1]){
            can[i*2+1]=false;
        }
        else{
            //cout<<above<<"C\n";
            can[above]=false;
            for(int j=i;j>=above;j>>=1){
                stop[j]=true;
                if(!can[j])continue;
                if(j&1){
                    yes[j-1]=true;
                }
                else{
                    if(!yes[j+1])take[j+1]=true;
                }
            }
        }
        ans[i]=mn;
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
/*
if mn=left{
    can only travel to lefts
    so block right child->last element it can take
    yes[i*2+1]=true->take cur then break;
}
if(mn==right){
    can travel to both
}
if(mn==cur){
    stop[cur]=true;->when see break
    nothing can travel pass;
}
 
when move from above to i{
    if(move){
        if(!(cur&1))
        if(yes[cur+1]=true){->can only go left
        }
        else{
            take[cur+1]=true-> take[cur^1] then break;
        }
 
        if(cur&1){
            if(!yes[cur&1]){
                take[cur-1]=true;
            }
        }
    }
}
 
 
 
*/
 
//2 4 5 8 9 10 11 16 17 18 19 20
//6 5 6 5 2 3 15
}