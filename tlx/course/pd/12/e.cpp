#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s; int n;
    cin >> n;
    s = bitset<32>(n).to_string();
    int start = 0;
    while(start < s.size() && s[start] == '0')
        ++start;
    for(int i = start; i < s.size(); ++i)
        cout << s[i];
    cout << endl;
    return 0;
}