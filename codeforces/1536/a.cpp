#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
void test_case()
{
    int n;
    cin >> n;
    set<int> a;
    for(int i = 0; i < n; ++i)
    {
        int num; cin >> num;
        a.insert(num);
    }
    set<int> prev;
    do
    {
        prev = a;
        for(auto it = a.begin(); it != a.end(); ++it)
        {
            auto it2 = it; ++it2;
            for(auto i = it2; i != a.end(); ++i)
            {
                a.insert(*i - *it);
                if(a.size() > 300)
                    break;
            }
        }        
    } while (prev != a && a.size() <= 300);
    if(a.size() > 300)
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        cout << a.size() << endl;
        for(auto i = a.begin(); i != a.end(); ++i)
            cout << *i << " ";
        cout << endl;
    }
    
}
int main()
{
    int t; cin >> t;
    while(t--)
        test_case();
    return 0;
}