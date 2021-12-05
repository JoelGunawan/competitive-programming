#include <bits/stdc++.h>
 
using namespace std;
 
bool f(vector<int> a, vector<int> b)
{
    if(a[1] != b[1]) return a[1] < b[1];
    else return a[0] > b[0];
}
 
int main()
{
    int q, i = 0;
    cin >> q;
 
    vector<vector<int>> b;
    deque <vector<int>> a;
    vector<bool> complete;
    make_heap(b.begin(), b.end(), f);
    deque<int> results;
    while(q--)
    {
        int c;
        cin >> c;
        if(c == 1)
        {
            int d;
            cin >> d;
            vector<int> e = {i, d};
            a.push_back(e);
            b.push_back(e);
            push_heap(b.begin(), b.end(), f);
            ++i;
            complete.push_back(false);
        }
        else if(c == 2)
        {
            if(complete[a[0][0]])
            {
                while(complete[a[0][0]])
                {
                    a.pop_front();
                }
            }
            results.push_back(a[0][0] + 1);
            complete[a[0][0]] = true;
            a.pop_front();
        }
        else
        {
            if(complete[b.front()[0]])
            {
                while(complete[b.front()[0]])
                {
                    pop_heap(b.begin(), b.end(), f);
                    b.pop_back();
                }
            }
            results.push_back(b.front()[0] + 1);
            complete[b.front()[0]] = true;
            pop_heap(b.begin(), b.end(), f);
            b.pop_back();
        }
    }
    for(int i = 0; i < results.size(); ++i)
    {
        cout << results[i];
        if(i == results.size() - 1) cout << endl;
        else cout << " ";
    }
    return 0;
}