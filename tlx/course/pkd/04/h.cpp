//Paduan Suara
#include<bits/stdc++.h>
using namespace std;

int m, n, batas[25];
vector <int> beb;
bool nemu;

void mwe (int idx, int lebih, int biasa, int x)
{
    if (nemu) return;

    if(idx==m)
    {
        nemu= true;
        return;
    }

    if(idx>0)
    {
        if(beb[idx]==beb[idx-1]) return;
        batas[x]= beb[idx];
    }

    if (lebih>0) mwe(idx+ m/n+1, lebih-1, biasa, x+1);
    if (biasa>0) mwe(idx+ m/n, lebih, biasa-1, x+1);



}

int main()
{
    int hz;

    cin>>m;

    for(int i=0; i<m; i++)
    {
        cin>>hz;
        beb.push_back(hz);

    }

    sort(beb.begin(), beb.end());

    cin>>n;

    nemu= false;
    mwe(0, m%n, n-(m%n), -1);

    for(int i=0; i<n-1; i++)
    {
        cout<<batas[i];

        if (i!= n-1) cout<<" ";
        else cout<<endl;

    }



}