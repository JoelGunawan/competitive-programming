#include <bits/stdc++.h>
using namespace std;
bool is_palindrome(string s)
{
    bool res = 1;
    for(int i = 0; i < s.size() / 2; ++i)
    {
        if(s[s.size() - i - 1] != s[i])
            res = 0;
    }
    return res;
}
int main()
{
    string s;
    vector<string> strings;
    while(cin >> s)
        strings.push_back(s);
    vector<string> res;
    for(int i = 0; i < strings.size(); ++i)
        if(is_palindrome(strings[i]))
            res.push_back(strings[i]);
    for(int i = 0; i < res.size(); ++i)
        cout << res[i] << " ";
    cout << endl;
    return 0;   
}