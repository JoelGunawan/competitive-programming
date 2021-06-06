#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> answerCount(m, vector<int>(5, 0));
    for(int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        for(int j = 0; j < m; ++j)
        {
            ++answerCount[j][(s[j] - 'A')];
        }
    }

    int result = 0;

    for(int i = 0; i < m; ++i)
    {
        int multiplier;
        cin >> multiplier;
        result += multiplier * max(max(answerCount[i][0], answerCount[i][1]), max(max(answerCount[i][2], answerCount[i][3]), answerCount[i][4]));
    }

    cout << result << endl;

    return 0;
}
