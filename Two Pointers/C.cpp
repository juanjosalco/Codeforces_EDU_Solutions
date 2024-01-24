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

int main(){
    lli n, m;
    cin >> n >> m;
    vi a(n), b(m);
    fore(i,0,n){
        cin >> a[i];
    }
    fore(i,0,m){
        cin >> b[i];
    }
    lli ans = 0;
    lli i = 0, j = 0;
    while(j < m){
        lli curr = 1, currAcum = 0, nxt = j + 1;
        while(nxt < m && b[nxt] == b[j]){
            curr++;
            nxt++;
        }
        while(i < n && a[i] < b[j]){
            i++;
        }
        while(i < n && a[i] == b[j]){
            i++;
            currAcum++;
        }
        ans += curr * currAcum;
        j = nxt;
    }
    cout << ans << endl;
    return 0;
}