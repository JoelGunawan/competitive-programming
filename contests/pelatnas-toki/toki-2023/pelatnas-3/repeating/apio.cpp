#include <bits/stdc++.h>
using namespace std;
int main() {
    ifstream all("all_names.in"), non("non_chinese.in");
    vector<string> a, b;
    string x;
    while(getline(all, x))
        a.push_back(x);
    while(getline(non, x))
        b.push_back(x);
    sort(b.begin(), b.end());
    ofstream fout("rank.out");
    for(auto i : a) {
        if(binary_search(b.begin(), b.end(), i))
            fout << i << endl;
    }
}