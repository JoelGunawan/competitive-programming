#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    // ; -> mengakhiri
    //cout << "Hello World" << endl;
    //cout << "Hello " << "World";
    //cout << "!" << endl;
    // tipe data "primitif" (built in ke bahasa c++)
    // variable -> menyimpan nilai
    // bool (boolean) -> true/false. 0 -> false, selain 0 -> true
    // short -> integer -2^15...2^15-1 -32768...32767 (perf. mirip int, jadi gaperna dipake) memory pake 1/2 dari memory int, gaperna dipake)
    // int -> integer -2^31...2^31-1  -2e9...2e9 (perf. masih cepet, paling sering dipake) 
    // long long -> integer -2^63...2^63-1 -9e18...9e18 (perf. agak lebih lambat, tapi ga separah long double, kalo mau pake long" terus boleh)
    // char -> hanya 1 karakter 'a', 'z', ' '
    // float -> 16 bit float number (desimal) 23.9342872942 (gapernah dipake)
    // double -> 32 bit float number (desimal) (paling sering dipake)
    // long double -> 48 bit float number (desimal) (butuh precision sangat tinggi, jarang)
    // tipe data non primitif
    // string -> kumpulan karakter "az"
    // tipe_data nama_variable;
    // huruf depan harus a-z, A-Z, _
    // sisanya harus a-Z, A-Z, _, 0-9
    //int x; // deklarasi variable
    //string s = "Hello World!"; // deklarasi dan initialisasi
    //int y = 2024;
    //char e = 'e';
    //cout << s << endl;
    //cout << y << endl;
    //cout << e << endl;
    //double dbl = 3974519237591875619257.34951755107;
    // fixed -> outputnya jangan scientific notation, output biasa
    // setprecision(n) -> output n angka di belakang decimal
    //cout << fixed << setprecision(2); 
    //cout << dbl << endl;
    //int a, b;
    //cin >> a >> b;
    //cout << a << " " << b << endl;
    //string t;
    //cin >> t;
    //cout << t << endl;
    //char f;
    //cin >> f;
    //cout << f << endl;
    //string u;
    //cin >> u;
    //cout << u << endl;
    //int x = 5, y = 4;
    //cout << x + y << endl;
    //cout << x - y << endl;
    //cout << x * y << endl;
    //cout << (double)x / y << endl;
    //cout << x % y << endl; // modulo
    //double a = 5, b = 4;
    //cout << a / b << endl;
    // operator bit
    // AND XOR OR (nanti)
    // Judge Verdict
    // AC/Accepted (benar)
    // WA/Wrong Answer (salah)
    // TLE/Time Limit Exceeded (terlalu lambat)
    // MLE/Memory Limit Exceeded (memory ga cukup)
    // RTE/Runtime Error (error, di beberapa online judge MLE itu bakal keluar verdictnya RTE)
    // OK (jarang, muncul di soal-soal yang level OSN)
    // kapan ada verdict OK?
    // creative scoring
    // tebak 1 kali -> 100
    // tebak 2 kali -> 90
    // tebak 3 kali -> ..
    // 1...1000
    // jumlah_tebakan/10
    //cout << 8 << endl;
    //cout<<8<<endl;
    // compile command
    // g++-13 nama_file -o nama_program
    // ./nama_program
    int a, b;
    cin >> a >> b;
    cout << "masing masing " << a / b << endl;
    cout << "bersisa " << a % b << endl;
    return 0;
}