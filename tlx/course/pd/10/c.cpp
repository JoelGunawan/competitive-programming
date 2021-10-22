#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end()), reverse(b.begin(), b.end());
    string res = to_string(stoi(a) + stoi(b));
    reverse(res.begin(), res.end());
    cout << stoi(res) << endl; 
    return 0;
}