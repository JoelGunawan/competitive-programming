#include <bits/stdc++.h>
using namespace std;
// tipe_data nama_fungsi
int gcd(int a, int b) {
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
// bool -> true/false
bool is_prime(int n) {
    if(n <= 1)
        return false;
    for(int i = 2; i <= sqrt(n); ++i) {
        if(n % i == 0)
            return false;
    }
    return true;
}
// dikasih soal, tidak pasti
int m = 1e9+7;
long long fastexpo(long long a, long long b) {
    if(b == 0)
        return 1;
    else {
        long long tmp = fastexpo(a, b / 2);
        tmp = (tmp * tmp) % m;
        if(b % 2 == 1) {
            return (a * tmp) % m;
        }
        else
            return tmp;
    }
}
long long fact[100005], inv[100005];
// m -> 10^9+7, 10^9+9, 998244353 ga harus hafal, pasti dikasih
long long combin(long long n, long long r) {
    return (((fact[n] * inv[r]) % m) * inv[n - r]) % m;
}
int main() {
    int n = 100000;
    fact[0] = 1;
    for(int i = 1; i <= n; ++i) {
        fact[i] = (fact[i - 1] * i) % m, inv[i] = fastexpo(fact[i], m - 2);
    }
    for(int i = 1; i <= 7; ++i)
        cout << fact[i] << " ";
    cout << endl;
    cout << fastexpo(2, 120) << endl;
    // inv modulo
    // hitung pecahan
    // 3/2 mod 10^9+7
    // 3 * fastexpo(2, 10^9+7 - 2)
    // phi
    // phi(10^9+7) = 10^9+6
    // a^phi(10^9+7) mod 10^9+7 = 1
    // a^0 mod 10^9+7=1
    // a^phi(10^9+7) - 1 mod 10^9+7 = a^-1 mod 10^9+7
    // 3 / 2 mod 10^9+7
    long long x = 1ll * 3 * fastexpo(2, m - 2);
    cout << 3 * fastexpo(2, m - 2) << endl;
    cout << (x * 2) % m << endl;
    // C(n, r) = n!/(n - r)!*r!

    // __gcd() -> fungsi utk integer
    // long long tdk bs/__int128t (ga dipake di osn)
    // FPB
    // FPB(a, b) = FPB(b, a m b)
    // KPK
    // KPK(a, b) = a * b / FPB(a, b)
    // Pengecekan bilangan prima
    // faktorial
    // perpangkatan cepat
    // inverse modulo
    // inverse faktorial
    // combin modulo
    // C(100, 50);
    // Pembangkitan Bilangan prima
}