#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
#pragma GCC optimize("Ofast")
using namespace std;
struct node
{
    int count;
    int child[26];
    node()
    {
        count = 0, memset(child, -1, sizeof(child));
    }
};
struct trie
{
    int last = 1;
    node arr[1000005];
    string s;
    void add(int idx, int cur_node)
    {
        ++arr[cur_node].count;
        if(idx == s.size())
            return;
        if(arr[cur_node].child[s[idx] - 'a'] == -1)
            arr[cur_node].child[s[idx] - 'a'] = last++;
        add(idx + 1, arr[cur_node].child[s[idx] - 'a']);
    }
    int count(int idx, int cur_node)
    {
        if(idx == s.size())
            return arr[cur_node].count;
        else if(arr[cur_node].child[s[idx] - 'a'] == -1)
            return 0;
        else
            return count(idx + 1, arr[cur_node].child[s[idx] - 'a']);
    }
};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    trie trie;
    for(int i = 0; i < n; ++i)
    {
        cin >> trie.s;
        trie.add(0, 0);
    }
    for(int i = 0; i < q; ++i)
    {
        cin >> trie.s;
        cout << trie.count(0, 0) << endl;
    }
    return 0;
}