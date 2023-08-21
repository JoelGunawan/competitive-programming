#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int inf = 1e9;

int n, d;
vector<vector<int> > children;

struct DP {
    // Dynaamilise planeerimise järgi alampuusse
    // kuuluvate margitud tippude arv
    int marked = 0;

    // near - Kaugus lahimast margitud tipust
    // far - Kaugus jargmisest lahimast tipust
    // Kui near >= D / 2, siis pole far oluline
    // ja see voib ka vale olla
    int near = -1, far = inf;

    DP() = default;
    void update(const DP & con);
    void end_node();
};


void DP::update(const DP & con)
{
    marked += con.marked;

    if (2 * (con.near + 1) >= d){
        far = min(far, con.near + 1);
        return;
    }

    if (near != -1)
        --marked;

    near = max(near, con.near + 1);
    far = min(far, con.far + 1);
}


void DP::end_node()
{
    // Kui kaks liiga lahedast tippu on margitud,
    // siis kustutame lahedasema
    if (near != -1 && near + far < d){
        --marked;
        near = far;
    }

    // Margime tipu
    else if ((near == -1 || near >= d) && far >= d){
        ++marked;
        near = 0;
    }

    // if far is only marked
    else if (near == -1)
        near = far;
}


void read_input()
{
    cin.sync_with_stdio(false);
    cin >> n >> d;
    children.resize(n);
    for (int i = 1; i < n; ++i){
        int j;
        cin >> j;
        children[j].push_back(i);
    }
}


vector<DP> do_dp()
{
    vector<DP> dp(n);
    for (int i = n - 1; i >= 0; --i){
        for (int child: children[i])
            dp[i].update(dp[child]);
        dp[i].end_node();
    }
    
    return dp;
}


int main()
{
    read_input();
    cout << do_dp()[0].marked << "\n";
    
    return 0;
}
