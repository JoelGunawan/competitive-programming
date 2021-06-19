#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int> graphNumber(2 * 1e5 + 1, 0);
    // we can treat this problem as kind of graph
    // for each graph we need to make the numbers the same
    // if there is a number that is not palindrome, it should be put in to a graph
    // if a graph with either of the numbers don't exist it should be added
    // else there should be a graph
    vector<set<int>> graph; set<int> invalidNumbers;
    for(int i = 0; i < n / 2; ++i)
    {
        if(a[i] != a[n - i - 1])
        {
            if(graphNumber[a[i]] == graphNumber[a[n - i - 1]] && graphNumber[a[i]] != 0)
                continue;
            if(graphNumber[a[i]] && graphNumber[a[n - i - 1]])
            {
                // merge the graphs
                invalidNumbers.insert(graphNumber[a[n - i - 1]]);
                for(auto it = graph[graphNumber[a[n - i - 1] - 1]].begin(); it != graph[graphNumber[a[n - i - 1] - 1]].end(); ++it)
                {
                    graph[graphNumber[a[i]] - 1].insert(*it);
                    graphNumber[*it] = graphNumber[a[i]];
                }
            }
            else if(graphNumber[a[i]] && !graphNumber[a[n - i - 1]])
            {
                graphNumber[a[n - i - 1]] = graphNumber[a[i]];
                graph[graphNumber[a[i]] - 1].insert(a[n - i - 1]);
            }
            else if(!graphNumber[a[i]] && graphNumber[a[n - i - 1]])
            {
                graphNumber[a[i]] = graphNumber[a[n - i - 1]];
                graph[graphNumber[a[n - i - 1]] - 1].insert(a[i]);
            }
            else
            {
                set<int> tmp;
                tmp.insert(a[i]); tmp.insert(a[n - i - 1]);
                graphNumber[a[i]] = graph.size() + 1; graphNumber[a[n - i - 1]] = graph.size() + 1;
                graph.push_back(tmp);
            }
        }
    }
    int res = 0;
    for(int i = 0; i < graph.size(); ++i)
    {
        if(invalidNumbers.find(i + 1) == invalidNumbers.end())
            res += (graph[i].size() - 1);
    }
    cout << res << endl;
    return 0;
}