#include <bits/stdc++.h> 

using namespace std;

typedef long long int lli;
typedef long double ld;
typedef vector<lli> vi;
typedef pair<lli,lli> pii;

#define endl '\n'
#define fi first
#define se second
#define fore(i,a,b) for(lli i = (a), TT = (b); i < TT; ++i)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const lli INF = 1e9;
const ld EPS = -1e9;

ld n;

bool f(ld x){
    return ((x*x) + sqrt(x)) >= n;
}

int main(){ _
    cin >> n;
    ld l = 0, r = 1e6;
    fore(i,0,100){
        ld mid = (l + r) / 2;
        if(f(mid)){
            r = mid;
        }else{
            l = mid;
        }
    }
    cout << fixed << setprecision(12) << r  << endl;
    return 0;
}