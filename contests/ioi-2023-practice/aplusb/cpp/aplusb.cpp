#include "aplusb.h"
#include <bits/stdc++.h>
using namespace std;

std::vector<int> smallest_sums(int N, std::vector<int> A, std::vector<int> B) {
	vector<int> ans;
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> s;
	for(int i = 0; i < N; ++i) {
		s.push(make_pair(A[i] + B[0], make_pair(i, 0)));
	}
	while(ans.size() < N) {
		int val = s.top().first, idxa = s.top().second.first, idxb = s.top().second.second;
		s.pop();
		ans.push_back(val);
		if(ans.size() == N)
			break;
		++idxb;
		s.push(make_pair(A[idxa] + B[idxb], make_pair(idxa, idxb)));
	}
	return ans;
}
