#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int to_integer(char a)
{
    return a - 'A';
}
char to_char(int a)
{
    return 'A' + a;
}
int main()
{
    string s;
    int n, counter[26], prev = -1; memset(counter, 0, sizeof(counter));
    cin >> n >> s;
    for(int i = 0; i < n; ++i)
        ++counter[to_integer(s[i])];
    string res = "";
    for(int i = 0; i < n; ++i)
    {
        int max = 0, max_index;
        for(int j = 0; j < 26; ++j)
        {
            if(counter[j] > max)
                max = counter[j], max_index = j;
        }
        int remain = n - i;
        if(max > remain / 2)
            res += to_char(max_index), prev = max_index, --counter[max_index];
        else
        {
            for(int j = 0; j < 26; ++j)
                if(counter[j] > 0 && j != prev)
                {
                    --counter[j], res += to_char(j), prev = j;
                    break;
                }
        }
    }
    cout << res << endl;
    return 0;
}