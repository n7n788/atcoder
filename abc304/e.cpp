//#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <atcoder/all>
#include <map>
#include <set>
#include <unordered_set>

using namespace std;
using namespace atcoder;
using mint = modint998244353;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define erep(i, a, b) for (int i = (a); i <= (b); i++)
typedef pair<int, int> P;
template <typename T> bool chmin(T &a, const T& b) {if (a > b) {a = b; return true;} return false;}
template <typename T> bool chmax(T &a, const T& b) {if (a < b) {a = b; return true;} return false;}

typedef long long ll;
const int INF = 1 << 30;
const ll INF_ll = 1ll << 60;

int main()
{
    int n, m;
    cin >> n >> m;
    dsu uf(n);
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        uf.merge(u, v);
    }
    int k;
    cin >> k;
    set<P> st;
    rep(i, 0, k) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        int xl = uf.leader(x), yl = uf.leader(y);
        if (xl > yl) swap(xl, yl);
        st.emplace(xl, yl);
    }
    int Q;
    cin >> Q;
    rep(Qi, 0, Q) {
        int p, q;
        cin >> p >> q;
        p--; q--;

        int pl = uf.leader(p), ql = uf.leader(q);
        if (pl > ql) swap(pl, ql);
        if (st.find({pl, ql}) != st.end()) cout << "No" << '\n';
        else cout << "Yes" << '\n';
    }

    return 0;
}