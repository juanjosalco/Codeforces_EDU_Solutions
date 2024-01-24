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
    vi a(n), b(m), c;
    fore(i,0,n){
        cin >> a[i];
    }
    fore(i,0,m){
        cin >> b[i];
    }
    lli i = 0, j = 0; // Mis Two Pointers
    while(i < n && j < m){
        if(a[i] < b[j]){
            c.push_back(a[i]);
            i++;
        }else{
            c.push_back(b[j]);
            j++;
        }
    }
    while(i < n){
        c.push_back(a[i]);
        i++;
    }
    while(j < m){
        c.push_back(b[j]);
        j++;
    }
    fore(z,0,c.size()){
        cout << c[z] << " ";
    }
    cout << endl;
    return 0;
}