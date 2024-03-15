#include <bits/stdc++.h>
using namespace std;
int main() {
    string input;
    getline(cin, input);
    int t = stoi(input);
    while(t--) {
        getline(cin, input);
        stringstream ss(input);
        vector<string> s;
        while(ss >> input) {
            s.push_back(input);
        }
        // 2 kemungkinan
        // 1 -> ubah dari angka jd pangkat
        // 2 -> ubah dari pangkat jd angka (cari '^')
        bool adaPangkat = 0;
        /*
        for(int i = 0; i < s.size(); ++i) {
            for(int j = 0; j < s[i].size(); ++j) {
                if(s[i][j] == '^')
                    adaPangkat = 1;
            }
        }
        */
        for(string i : s) {
            for(char j : i) {
                if(j == '^')
                    adaPangkat = 1;
            }
        }
        if(adaPangkat) {
            string res = "";
            for(auto i : s) {
                adaPangkat = 0;
                for(auto j : i) {
                    if(j == '^')
                        adaPangkat = 1;
                }
                if(adaPangkat) {
                    int pangkat_index;
                    for(int j = 0; j < i.size(); ++j) {
                        if(i[j] == '^') {
                            pangkat_index = j;
                            break;
                        }
                    }
                    string left = "", right = "";
                    for(int j = 0; j <= pangkat_index - 1; ++j)
                        left += i[j];
                    for(int j = pangkat_index + 1; j < i.size(); ++j)
                        right += i[j];
                    int r = stoi(right);
                    for(int j = 0; j < r; ++j)
                        res += left;
                }
                else {
                    res += i;
                }
            }
            cout << res << endl;
        }
        else {
            string t = s[0];
            bool perubahan[t.size()];
            memset(perubahan, 0, sizeof(perubahan));
            for(int i = 1; i < t.size(); ++i) {
                if(t[i] != t[i - 1])
                    perubahan[i] = 1;
            }
            string hasil = "";
            int cnt = 0;
            for(int i = 0; i < t.size(); ++i) {
                if(perubahan[i]) {
                    // reset cnt
                    if(cnt >= 4) {
                        if(hasil.size() && hasil[hasil.size() - 1] != ' ')
                            hasil += " ";
                        hasil += t[i - 1];
                        hasil += "^" + to_string(cnt) + " ";
                    }
                    else {
                        for(int j = 0; j < cnt; ++j) {
                            hasil += t[i - 1];
                        }
                    }
                    cnt = 0;
                }
                ++cnt;
            }
            if(cnt >= 4) {
                if(hasil.size() && hasil[hasil.size() - 1] != ' ')
                    hasil += " ";
                hasil += t[t.size() - 1];
                hasil += "^" + to_string(cnt);
            }
            else {
                for(int j = 0; j < cnt; ++j) {
                    hasil += t[t.size() - 1];
                }
            }
            cout << hasil << endl;
        }
    }
}