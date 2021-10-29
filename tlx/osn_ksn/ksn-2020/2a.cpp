#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
int dp[102][21][21][21][21];
bool skill_subset[21][21][21][21][21];
int main()
{
    int n, k;
    cin >> n >> k;
    int s[4];
    for(int i = 0; i < 4; ++i)
        cin >> s[i];
    sort(s, s + 4);
    bool m[k + 1][k + 1]; char in;
    for(int i = 1; i <= k; ++i)
        for(int j = 1; j <= k; ++j)
            cin >> in, m[i][j] = (bool)(in - '0');
    // ruangan
    // memo nyimpen state yang mungkin dari sebelume
    // kalo misale bisa progres langsung ae, lek ga cek setiap subset yang ada di perpustakaan itu
    // contains the magic that would be defeated by the skill subset
    
    // O(k^5)
    memset(dp, -1, sizeof(dp));
    for(int a = 1; a <= k; ++a)
        for(int b = a + 1; b <= k; ++b)
            for(int c = b + 1; c <= k; ++c)
                for(int d = c + 1; d <= k; ++d)
                {
                    // cek skill subset ini
                    for(int i = 1; i <= k; ++i)
                        if(m[a][i] || m[b][i] || m[c][i] || m[d][i])
                            skill_subset[a][b][c][d][i] = 1;
                }
    pair<int, int> input[n];
    for(int i = 0; i < n; ++i)
    {
        int type;
        cin >> type;
        // musuh
        if(type == 1)
        {
            int magic_type;
            cin >> magic_type;
            input[i] = {type, magic_type};
        }
        // perpustakaan
        else
            input[i] = {type, 0};
    }
    // get battle sets between perpustakaan
    vector<vector<int>> battle_set;
    vector<int> cur(k + 1, 0);
    for(int i = 0; i < n; ++i)
    {
        if(input[i].first == 1)
            ++cur[input[i].second];
        else
            battle_set.push_back(cur), cur = vector<int>(k + 1, 0);
    }
    if(input[n - 1].first != 2)
        battle_set.push_back(cur), cur.clear();
    
    dp[0][s[0]][s[1]][s[2]][s[3]] = 0;
    int idx = 1;
    // between each battle set we find the maximum for each subset
    // O(100 * k * C(k, 4))
    for(auto it = battle_set.begin(); it != battle_set.end(); ++it)
    {
        cur = *it;
        // iterate through each subset
        for(int i = 1; i <= k; ++i)
            for(int j = i + 1; j <= k; ++j)
                for(int x = j + 1; x <= k; ++x)
                    for(int y = x + 1; y <= k; ++y)
                    {
                        int cur_max = 0;
                        for(int it_2 = 1; it_2 <= k; ++it_2)
                            if(skill_subset[i][j][x][y][it_2])
                                cur_max += cur[it_2];
                        int prev_max = -1;
                        // cari semua neighboring node dari sebelumnya
                        vector<int> tmp_2 = {i, j, x, y};
                        if(it != battle_set.begin())
                        {
                            for(int a = 1; a <= k; ++a)
                            {
                                if(i != a && j != a && x != a && y != a)
                                {
                                    int tmp_2[] = {i, j, a, y};
                                    sort(tmp_2, tmp_2 + 4);
                                    prev_max = max(prev_max, dp[idx - 1][tmp_2[0]][tmp_2[1]][tmp_2[2]][tmp_2[3]]);
                                    //cout << tmp_2[0] << " " << tmp_2[1] << " " << tmp_2[2] << " " << tmp_2[3] << " " << prev_max << endl;
                                    tmp_2[0] = i, tmp_2[1] = j, tmp_2[2] = x, tmp_2[3] = a;
                                    sort(tmp_2, tmp_2 + 4);
                                    prev_max = max(prev_max, dp[idx - 1][tmp_2[0]][tmp_2[1]][tmp_2[2]][tmp_2[3]]);
                                    //cout << tmp_2[0] << " " << tmp_2[1] << " " << tmp_2[2] << " " << tmp_2[3] << " " << prev_max << endl;
                                    tmp_2[0] = i, tmp_2[2] = x, tmp_2[3] = y;
                                    tmp_2[1] = a;
                                    sort(tmp_2, tmp_2 + 4);
                                    prev_max = max(prev_max, dp[idx - 1][tmp_2[0]][tmp_2[1]][tmp_2[2]][tmp_2[3]]);
                                    //cout << tmp_2[0] << " " << tmp_2[1] << " " << tmp_2[2] << " " << tmp_2[3] << " " << prev_max << endl;
                                    tmp_2[2] = x, tmp_2[1] = j, tmp_2[3] = y;
                                    tmp_2[0] = a;
                                    sort(tmp_2, tmp_2 + 4);
                                    prev_max = max(prev_max, dp[idx - 1][tmp_2[0]][tmp_2[1]][tmp_2[2]][tmp_2[3]]);
                                    //cout << tmp_2[0] << " " << tmp_2[1] << " " << tmp_2[2] << " " << tmp_2[3] << " " << prev_max << endl;
                                }
                            }
                        }
                        prev_max = max(prev_max, dp[idx - 1][i][j][x][y]);
                        if(prev_max != -1)
                            //cout << i << " " << j << " " << x << " " << y << " " << idx << " " << prev_max << " " << cur_max << endl,
                            dp[idx][i][j][x][y] = prev_max + cur_max;
                    }
        ++idx;
    }
    int res = 0;
    for(int i = 1; i <= k; ++i)
        for(int j = i + 1; j <= k; ++j)
            for(int x = j + 1; x <= k; ++x)
                for(int y = x + 1; y <= k; ++y)
                    res = max(res, dp[battle_set.size()][i][j][x][y]);
    cout << res << endl;
    return 0;
}   