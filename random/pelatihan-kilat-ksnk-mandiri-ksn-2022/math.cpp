#include <bits/stdc++.h>
//#define endl "\n"
using namespace std;
// implementing gcd, lcm, sieve, prime checking, faktorisasi prima,  
// FPB(A, B) = FPB(B, A mod B)
long long fpb(long long x, long long y) {
    if(y == 0)
        return x;
    else
        return fpb(y, x % y);
}
/*
long long fpb(long long x, long long y) {
    if(y == 0)
        return x;
    else if(x == 0)
        return y;
    else
        return fpb(y, x % y);
}
*/
/*
long long fpb(long long x, long long y) {
    return y == 0 ? x : fpb(y, x % y);
}
*/
// kpk(x, y) = x * y / fpb(x, y)
long long kpk(long long x, long long y) {
    return x * y / fpb(x, y);
}
vector<int> sieve(int n) {
    // 2 sampai n
    bool bool_arr[n + 1];
    for(int i = 0; i <= n; ++i)
        bool_arr[i] = 1;
    // iterasi dari 2 sampai n
    for(int i = 2; i <= n; ++i) {
        // untuk setiap iterasi, kita cek apakah bool_arr[i] true atau false
        if(bool_arr[i])
            // jika true
            for(int j = 2 * i; j <= n; j += i) {
                // ubah semua kelipatan i menjadi false
                bool_arr[j] = 0;
            }
    }
    vector<int> result;
    // result = {2}
    // result.push_back(3);
    // result = {2, 3}
    for(int i = 2; i <= n; ++i)
        if(bool_arr[i])
            result.push_back(i);
    return result;
}

bool is_prime(int n) {
    // hati-hati edge case jika N < 2
    // N = 1 -> return true
    if(n <= 1)
        return false;
    // 2 versi
    // versi 1: kita cek semua bilangan dari 2 hingga sqrt(n)
    // versi 2: kita cek semua bilangan prima dari 2 hingga sqrt(n)
    for(int i = 2; i <= sqrt(n); ++i) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
    vector<int> primes = sieve(sqrt(n));
    for(int i = 0; primes[i] <= sqrt(n) && i < primes.size(); ++i) {
        if(n % primes[i] == 0)
            return false;
    }
    return true;
}

vector<pair<int, int>> prime_factorization(int n) {
    vector<pair<int, int>> result;
    // p_1^a_1 * p_2^a_2
    // 2^3, cnt = 0
    // 2^2, cnt = 1
    // 2^1, cnt = 2
    // 2^0, cnt = 3
    // misal 7
    // 7 % 2 == 1
    for(int i = 2; i <= sqrt(n); ++i) {
        if(n % i == 0) {
            int pangkat = 0;
            while(n % i == 0) {
                n /= i;
                ++pangkat;
            }
            // pangkatnya sudah sesuai
            pair<int, int> tmp;
            tmp.first = i, tmp.second = pangkat;
            result.push_back(tmp);
        }
    }
    // jika n yang tersisa itu prima
    if(n > 1) {
        pair<int, int> tmp;
        tmp.first = n, tmp.second = 1;
        result.push_back(tmp);
    }
}

// powmod, inversemod, factmod, combinmod, fungsi phi
// mulmod, addmod, submod

// di soal programming kadang kita diminta untuk mencari bilangan yang sangat besar
// 2^(100000000000) * 2^(10000000000) * 24
// modulo dengan bilangan tertentu
// biasanya 10^9+7 atau 998244353
// intinya itu bilangan prima yang sangat besar
// 1e9 -> 10^9
int mod = 1e9 + 7;
long long modexp(long long a, long long b) {
    // x^0 = 1
    if(b == 0)
        return 1;
    else {
        // (x^b/2*x^b/2)
        // tmp menyimpan x^b/2
        long long tmp = modexp(a, b / 2);
        tmp = (tmp * tmp) % mod;
        // x^b kita kali tmp dengan tmp
        // b itu ganjil
        // b / 2 itu bakal kehilangan 1
        // 3 / 2 = 1
        // x^1*x^1 != x^3
        // b ganjil, kita kali sama a sekali aja
        if(b % 2 == 1) {
            return (tmp * a) % mod;
        }
        else {
            return tmp;
        }
        // cara coding iseng
        // return b & 1 ? (tmp * a) % mod : tmp;
    }
}

long long inversemod(long long a) {
    // a^phi(b) - 1
    return modexp(a, mod - 2);
}

const int limit = 1001;
long long fact[limit];
void generate_fact(int limit) {
    // fact[i] = fact[i - 1] * i
    // 4! = 3! * 4
    for(int i = 1; i <= limit; ++i) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}
// long long -> 9*10^18
// -9*10^18
// -> error
long long combinmod(long long a, long long b) {
    // nCr=n!/(r!*(n - r)!)
    return (fact[a] * inversemod((fact[b] * fact[a - b]) % mod)) % mod;
}

// phi(n) = n * (1-1/p1)....
// 1-(1/p1)=(p1-1)/p1
long long phi(long long n) {
    long long res = n;
    for(int i = 2; i <= sqrt(n); ++i) {
        if(n % i == 0) {
            res /= i;
            res *= (i - 1);
            while(n % i == 0)
                n /= i;
        }
    }
    if(n > 1) {
        res /= n;
        res *= (n - 1);
    }
    return res;
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    generate_fact(1000);    

    return 0;
}