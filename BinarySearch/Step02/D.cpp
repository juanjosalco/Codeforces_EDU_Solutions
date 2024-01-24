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

int m, n;
vector<int> t, y, z, ans;

bool good(int time) {
    int res = 0;
    for(int i=0; i<n; i++) {
        int ballon = time/(t[i]*z[i] + y[i]);
        int rem = time - ballon * (t[i]*z[i] + y[i]);
        ballon *= z[i];
        if(rem >= t[i]) {
            if(rem/t[i] > z[i]) {
                ballon += z[i];
            }
            else ballon += (rem/t[i]);
        }
        ans[i] = ballon;
        res += ans[i];
    }
    return res >= m;
}

int main() {
    cin >> m >> n;
    t.resize(n); y.resize(n); z.resize(n), ans.resize(n);
    fore(i, 0, n) {
        cin >> t[i] >> z[i] >> y[i];
    }
    if(m == 0) {
        cout << 0 << endl;
        for(int i=0; i<n; i++) {
            cout << "0 ";
        }
        return 0;
    }
    int l = 0, r = 1e7, count = 0;
    while(l+1 < r) {
        count++;
        int mid = (l+r)/2;
        if(good(mid)) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    cout << r << "\n";
    int time = r;
    fore(i, 0, n) {
        int ballon = time/(t[i]*z[i] + y[i]);
        int rem = time - ballon * (t[i]*z[i] + y[i]);
        ballon *= z[i];
        if(rem >= t[i]) {
            if(rem/t[i] > z[i]) {
                ballon += z[i];
            }
            else ballon += (rem/t[i]);
        }
        ans[i] = ballon;
    }
    int blown = 0;
    fore(i,0,n) {
        if(blown + ans[i] > m) {
            if(m > 0) {
                cout << m-blown << " ";
                m = 0;
            }
            else cout << "0 ";
        }
        else cout << ans[i] << " ";
        blown += ans[i];
    }
    cout << "\n";
    return 0;
}