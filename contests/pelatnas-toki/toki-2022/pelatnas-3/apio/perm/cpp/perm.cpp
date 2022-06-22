#include "perm.h"
#include <bits/stdc++.h>
using namespace std;
std::vector<int> construct_permutation(long long k)
{
	{
		// find closest 2^x - 1 to k
		// use maximum numbers for them
		// add smaller numbers from largest
		// if we add with remainder length, we add 2^remainder + 1 to the array
		long long tmp = 1, sz = 0;
		while(2 * tmp <= k)
			tmp *= 2, ++sz;
		// create an array of length tmp2 initially
		// then add new indices until fulfill
		vector<int> res(sz, -1);
		k -= tmp;
		// find largest 2^x + 1
		while(k > 0) {
			long long tmp = 1, tmp2 = 0;
			while(2 * tmp <= k) {
				tmp = 2 * tmp;
				++tmp2;
			}
			k -= tmp;
			// add at dist tmp2 from end
			// ijin ke toilet
			if(tmp2 == 0)
				res.push_back(-2);
			else if(tmp2 == sz)
				res.insert(res.begin(), -2);	
			else {
				int cnt = 0;
				for(int i = res.size() - 1; i >= 0; --i) {
					if(cnt == tmp2) {
						res.insert(res.begin() + i + 1, -2);
						break;
					}
					if(res[i] == -1)
						++cnt;	
				}
			}
		}
		int idx = 0;
		for(int i = res.size() - 1; i >= 0; --i) {
			if(res[i] == -2)
				res[i] = idx++;
		}
		for(int i = 0; i < res.size(); ++i) {
			if(res[i] == -1)
				res[i] = idx++;
		}
		return res;
	}
	return {};
}