#include <bits/stdc++.h>
#define f first
#define s second
#define fore(i,a,b) for(int i = (a), ThxMK = (b); i < ThxMK; ++i)
#define pb push_back
#define all(s) begin(s), end(s)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(s) int(s.size())
#define ENDL '\n'
using namespace std;
typedef long double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;
#define deb(x) cout << #x": " << (x) << endl;

struct DSU{
  vector<int> pr, rank; // 2 Vectores p y r
  stack<pair<int,int>> what; // What??????
  DSU(int n): pr(n), rank(n, 1){ // O(N) Constructor
    iota(all(pr), 0); // Fore 0, n incrementos de 1
  }
  int find(int u){ // O(1)
    return pr[u] == u ? u: pr[u] = find(pr[u]);
  }
  void unite(int u, int v){ // O(1)
    u = find(u), v = find(v);
    if(u != v){
      if(rank[u] < rank[v]) swap(u, v);
      rank[u] += rank[v];
      pr[v] = u;
      what.push({u, v});
    }else what.push({-1, -1});
  }
  pair<int,int> rollback(){ // O(1)
    pair<int,int> last = what.top();
    what.pop();
    int u = last.f, v = last.s;
    if(u != -1){
      rank[u] -= rank[v];
      pr[v] = v;
    }
    return last;
  }
};

int main(){
    lli n,m;
    cin >> n >> m;
    DSU d(n+1);
    fore(i,0,m){
        string op;
        lli n1, n2;
        cin >> op >> n1 >> n2;
        if(op == "union"){
            d.unite(n1,n2);
        }else{
            if(d.find(n1) == d.find(n2)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    
    return 0;
}