#include "minimum.h"
#include <iostream>
using namespace std;

static int n, A[10000005];

int main() {
    cin >> n;
    for ( int i = 0; i < n; i++ ) cin >> A[i];
    cout << findMin(n, A) << endl;
    return 0;
}
