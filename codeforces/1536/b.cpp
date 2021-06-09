#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
string convert(char a)
{
    string s = ""; s += a;
    return s;
}
void test_case()
{
    int n; string s;
    cin >> n >> s;
    set<string> one, two, three;
    for(int i = 0; i < n; ++i)
    {
        if(i < n - 2)
            three.insert(s.substr(i, 3));
        if(i < n - 1)
            two.insert(s.substr(i, 2));
        one.insert(s.substr(i, 1));        
    }
    /*
    cout << one.size() << " " << two.size() << " " << three.size() << endl;
    for(auto it = one.begin(); it != one.end(); ++it)
        cout << *it << " ";
    cout << endl;
    for(auto it = two.begin(); it != two.end(); ++it)
        cout << *it << " ";
    cout << endl;
    */
    if(one.size() < 26)
        for(int i = 0; i < 26; ++i)
        {
            //cout << convert('a' + i) << endl;
            if(one.find(convert('a' + i)) == one.end())
            {
                cout << (char)('a' + i) << endl;
                return;
            }
        }
    else if(two.size() < 676)
        for(int i = 0; i < 26; ++i)
            for(int j = 0; j < 26; ++j)
            {
                //cout << convert('a' + i) + convert('a' + j) << endl;
                if(two.find(convert('a' + i) + convert('a' + j)) == two.end())
                {
                    cout << convert('a' + i) + convert('a' + j) << endl;
                    return; 
                }
            }
    else
        for(int i = 0; i < 26; ++i)
            for(int j = 0; j < 26; ++j)
                for(int k = 0; k < 26; ++k)
                {
                    //cout << convert('a' + i) + convert('a' + j) + convert('a' + k) << endl;
                    if(three.find(convert('a' + i) + convert('a' + j) + convert('a' + k)) == three.end())
                    {
                        cout << convert('a' + i) + convert('a' + j) + convert('a' + k) << endl;
                        return;
                    }
                }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while(t--)
        test_case();
    return 0;
}