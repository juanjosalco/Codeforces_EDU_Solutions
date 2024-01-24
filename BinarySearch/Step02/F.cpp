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

vi a;
string s1, s2, str;

bool isGood(string s1, string s2){
    lli n = s2.size();
    lli m = s1.size();
    lli i = 0, j = 0;
    while(i < n && j < n){
        if(s1[j] == s2[i]){
            i++;
            j++;
        } else {
            i++;
        }
    } 
    return j >= m;
}

int main(){
    cin >> s1 >> s2;
    a.resize(s1.size());
    fore(i,0,a.size()){
        cin >> a[i];
    }
    lli l = 0, r = a.size();
    lli mid, ans = 0;
    while(l <= r){
        mid = (l + r) / 2;
        string str = s1;
        fore(i,0,mid){
            str[a[i]-1] = '-';
        }
        string ss = "";
        fore(i,0,a.size()){
           if(str[i] != '-') ss += str[i];
        }
        if(isGood(s2, ss)){
            ans = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}