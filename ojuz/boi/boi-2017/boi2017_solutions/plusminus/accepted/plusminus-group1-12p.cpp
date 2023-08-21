#include<cassert>
#include<cstdio>
#include<iostream>
#include<map>

using namespace std;

char flipsign(char c, int p) {
	if(p%2==0) return c;
	return c=='+' ? '-' : '+';
}

long long pow2(int x) {
	if(x==0) return 1;
	long long a = pow2(x/2);
	a = ((a*a) * (x%2==1 ? 2 : 1)) % 1000000007;
	return a;
}

int main() {
	int n,m,k,x,y;
	scanf("%d%d%d",&n,&m,&k);
    assert(n <= 5 && m <= 5);
	map<int, char> H,V;
	bool canBeH = true, canBeV = true, canBePlusEvenMinusOdd = true, canBePlusOddMinusEven = true;
	
	for(int i = 0; i < k; ++i) {
		char c;
		scanf(" %c%d%d", &c, &y, &x);

		canBeH &= ((int)H[y] == 0) || H[y] == flipsign(c,x);
		canBeV &= ((int)V[x] == 0) || V[x] == flipsign(c,y);
		
		H[y] = flipsign(c,x);
		V[x] = flipsign(c,y);
	
		canBePlusEvenMinusOdd &= (c=='+' && (x+y)%2==0) || (c=='-' && (x+y)%2==1);
		canBePlusOddMinusEven &= (c=='+' && (x+y)%2==1) || (c=='-' && (x+y)%2==0);
	}
	
	long long ans = canBeH ? pow2(n-H.size()) : 0;
	ans += canBeV ? pow2(m-V.size()): 0;
	ans -= canBeH && canBeV && canBePlusEvenMinusOdd ? 1 : 0;
	ans -= canBeH && canBeV && canBePlusOddMinusEven ? 1 : 0;
	ans = ans % 1000000007;
	
	printf ("%lld\n", ans);
	
	return 0;
}
