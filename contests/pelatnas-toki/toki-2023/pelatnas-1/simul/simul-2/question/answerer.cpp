#include "answerer.h"
#include <bits/stdc++.h>
using namespace std;

bool answer(int N, int q, int h) {
	if(h & 1) {
		// berarti if x -> 1
		int idx = h / 2 - 1;
		return (1 << idx) & q;
	}
	else {

	}
	return true;
}
