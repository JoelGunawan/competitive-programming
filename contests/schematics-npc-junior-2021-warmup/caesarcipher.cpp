#include <bits/stdc++.h>
using namespace std;
int minuschar(char a, char b)
{
    return a < b ? a + 26 - b : a - b;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string a, b;
        cin >> a >> b;
        bool ans = 0; int distance;
        for(int i = 0; i <= a.size() - b.size(); ++i)
        {
            string cur = a.substr(i, b.size());
            distance = minuschar(a[i], b[0]); ans = 1;
            for(int j = 0; j < b.size(); ++j)
                if(minuschar(a[i + j], b[j]) != distance)
                    ans = 0;
            if(ans)
                break;
        }
        if(ans)
            cout << "YA" << " " << (char)('A' + distance) << endl;
        else
            cout << "TIDAK" << endl;
    }
}