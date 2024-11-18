#include "testlib.h"
using namespace std;

const int max_testcount = 50000;
const int max_n = 200000;
const int max_x = 1'000'000'000;
const int min_val = -1'000'000'000;
const int max_val = 1'000'000'000;

int main(int argc, char** argv) {
    registerValidation(argc, argv);
    int testcount = inf.readInt(1, max_testcount, "test-count");
    inf.readEoln();
    int sum_n = 0;
    for (int testcase = 1; testcase <= testcount; ++testcase) {
        setTestCase(testcase);
        int n = inf.readInt(1, max_n, "n");
        inf.readSpace();
        int x = inf.readInt(1, max_x, "x");
        sum_n += n;
        ensuref(sum_n <= max_n, "sum of n over all cases should not exceed %d", max_n);
        inf.readEoln();
        inf.readInts(n, min_val, max_val, "a");
        inf.readEoln();
    }
    inf.readEof();
    return 0;
}