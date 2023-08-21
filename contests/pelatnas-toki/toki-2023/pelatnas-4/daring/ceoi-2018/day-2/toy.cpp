#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> nums;
    for(int i = 1; i <= sqrt(n); ++i) {
        if(n % i == 0) {
            nums.push_back(i);
            if(n / i != i)
                nums.push_back(n / i);
        }
    }
    //cout << nums.size() << endl;
    //cout.flush();
    sort(nums.begin(), nums.end());
    vector<int> factors[nums.size()];
    // generate factors of every number in O(log) or O(log^2)
    for(int i = 0; i < nums.size(); ++i) {
        for(int j = 1; j <= sqrt(nums[i]); ++j) {
            if(nums[i] % j == 0) {
                factors[i].push_back(j);
                if(nums[i] / j != j)
                    factors[i].push_back(nums[i] / j);
            }
        }
        sort(factors[i].begin(), factors[i].end());
    }
    //cout << "TEST" << endl;
    // dp all possibilities?
    vector<int> possible[nums.size()];
    possible[0].push_back(0);
    for(int i = 1; i < nums.size(); ++i) {
        // get dr semua faktornya
        for(auto j : factors[i]) {
            if(nums[i] != j) {
                for(auto k : possible[lower_bound(nums.begin(), nums.end(), j) - nums.begin()]) {
                    if(nums[i] == n || nums[i] == 18 || nums[i] == 9) {
                        //cout << k << " " << nums[i] << " " << j << " " << k + nums[i] / j - 1 << endl;
                    }
                    possible[i].push_back(k + nums[i] / j - 1);
                }
                //cout << endl;
            }
        }
        sort(possible[i].begin(), possible[i].end());
        possible[i].resize(unique(possible[i].begin(), possible[i].end()) - possible[i].begin());
        //cout << nums[i] << " " << possible[i].size() << endl;
        //for(auto j : possible[i])
        //    cout << j << " ";
        //cout << endl;
    }
    sort(possible[nums.size() - 1].begin(), possible[nums.size() - 1].end());
    cout << possible[nums.size() - 1].size() << endl;
    for(auto i : possible[nums.size() - 1])
        cout << i << " ";
    cout << endl;
}