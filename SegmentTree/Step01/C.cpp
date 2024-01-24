#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef pair<lli,lli> pii;


#define fore(i,a,b) for(lli i = (a), TT = (b); i < TT; ++i)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const lli INF = 1e9;

struct Segtree {
    #define mid (l + r) / 2
    #define left(u) (u + 1)
    #define right(u) (u + ((mid - l + 1) << 1))

    struct Node {
        lli s, mx;
        pii mn;
        Node(lli s = 0, lli mx = -INF, pii mn = {INF, 1}) : s(s), mx(mx), mn(mn) {}
        Node operator +(const Node &n){
            if(mn.first > n.mn.first){
                return Node(s + n.s, max(mx, n.mx), {n.mn.first, n.mn.second});
            }else if(mn.first < n.mn.first){
                return Node(s + n.s, max(mx, n.mx), {mn.first, mn.second});
            }else{
                return Node(s + n.s, max(mx, n.mx), {mn.first, (mn.second + n.mn.second)});
            }
        }
    };

    vector<Node> st;
    Segtree(int n) : st(2 * n) {}

    void update(int u, int l, int r, int kth, lli val){ // O(logN)
        if (l == r){
            st[u].s = val;
            st[u].mx = val;
            st[u].mn = {val, 1};
            return;
        }
        if (kth <= mid)
            update(left(u), l, mid, kth, val);
        else
            update(right(u), mid + 1, r, kth, val);
        st[u] = st[left(u)] + st[right(u)];
    }

    Node query(int u, int l, int r, int ll, int rr){ // O(logN)
        if (l > r or r < ll or l > rr)
            return Node();
        if (ll <= l and r <= rr)
            return st[u];
        return query(left(u), l, mid, ll, rr) + query(right(u), mid + 1, r, ll, rr);
    }
};

int main(){ _
    lli n, q;
    cin >> n >> q;
    Segtree st(n);
    fore(i,0,n){
        lli val;
        cin >> val;
        st.update(1, 0, n - 1, i, val);
    }
    fore(i,0,q){
        lli op, x, y;
        cin >> op >> x >> y;
        if(op == 1){
            st.update(1, 0,n - 1, x, y);
        } else{
            Segtree::Node ans = st.query(1, 0, n - 1, x, y - 1);
            cout << ans.mn.first << " " << ans.mn.second << endl;
        }
    }
    return 0;
}