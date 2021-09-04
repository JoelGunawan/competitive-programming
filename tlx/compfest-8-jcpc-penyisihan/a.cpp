#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    getline(cin >> ws, s);
    int firstvocal = -1, lastvocal;
    for(int i = 0; i < n; ++i)
        if(s[i] == 'a' || s[i] == 'A' || s[i] == 'i' || s[i] == 'I' || s[i] == 'u' || s[i] == 'U' 
        || s[i] == 'e' || s[i] == 'E' || s[i] == 'o' || s[i] == 'O')
        {
            if(firstvocal == -1)
                firstvocal = i;
            lastvocal = i;
        }
    for(int i = firstvocal; i <= lastvocal; ++i)
        cout << s[i];
    cout << endl;
    return 0;
}