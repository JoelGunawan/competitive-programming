#include <iostream>

using namespace std;

void solve()
{
    string s;
    cin >> s;
    int sum = 0, zeroCount = 0; bool containEven = false;
    for(int i = 0; i < s.size(); ++i)
    {
        sum += (s[i] - '0');
        if(s[i] == '0')
        {
            ++zeroCount;
        }
        else if((s[i] - '0') % 2 == 0)
        {
            containEven = true;
        }
    }
    if(sum % 3 == 0 && ((zeroCount > 0 && containEven) || zeroCount > 1)) cout << "red" << endl;
    else cout << "cyan" << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
