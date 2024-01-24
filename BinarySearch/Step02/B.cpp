#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>
#include <cmath>
#include <iomanip>
 
using namespace std;
 
typedef long double ld;
typedef long long int lli;
typedef pair<lli, lli> pii;
typedef vector<lli> vi;
 
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define sz(s) lli(s.size())
#define all(s) begin(s), end(s)
#define print(s) cout << s << endl
#define fore(i, a, b) for(lli i = (a), TT = (b); i < TT; ++i)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
 
///-------------------------------------------------------------------------
///-------------------------------------------------------------------------
 
const lli MOD = 1e9 + 7;
 
///-------------------------------------------------------------------------
 
lli mcd(lli a, lli b) {return b ? mcd (b, a % b) : a;}
lli mcm(lli a, lli b) {return (!a || !b) ? 0 : a * b / mcd(a, b);}
 
//g++-12 -std=c++17 main.cpp && ./a.out < input.txt > output.txt
 
lli n, k;
vector<int> a;
 
bool good(ld x){
    int s = 0;
    for(int i = 0; i < n; i++){
        s += floor(a[i] / x);
    }
    return s >= k;
}
 
 
int main() { _
 
    cin >> n >> k;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
 
    ld l = 0; // l is good
    ld r = 1e8; // r is bad
 
    for(int t = 0; t < 100; t++){
        ld m = (l + r) / 2;
        if(good(m)){
            l = m;
        }else{
            r = m;
        }
    }
 
    cout << setprecision(20) << l;
    return 0;
 
// ea
}