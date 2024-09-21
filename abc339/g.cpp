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

// マージソート木
struct segtree1 {
    int n;
    vector<vector<int>> a;
    vector<vector<ll>> s; // 累積分布
    segtree1(int mx) {
        n = 1;
        while (n < mx) n <<= 1;
        a.resize(n * 2); // ノード数はn * 2個
        s.resize(n * 2, vector<ll>(1, 0));
    }
    // インデックスiに値xを入れる
    void set(int i, int x) {
        a[n + i] = {x};
        s.at(n + i).push_back(x);
    }
    // マージソート木を初期化
    void init() {
        // 下のノードからマージして初期化
        for (int i = n - 1; i >= 1; i--) {
            int l = i << 1, r = l | 1;
            merge(a.at(l).begin(), a.at(l).end(),
                  a.at(r).begin(), a.at(r).end(),
                  back_inserter(a.at(i)));
            s.at(i) = vector<ll>(a.at(i).size() + 1);
            rep(j, 0, a.at(i).size()) 
                s.at(i).at(j + 1) = s.at(i).at(j) + a.at(i).at(j);
        }
    }
    // ノードiのx以下の値の総和を返す
    ll get(int i, int x) {
        int j = upper_bound(a.at(i).begin(), a.at(i).end(), x) - a.at(i).begin();
        return s.at(i).at(j);
    }
    // 配列の右開区間[l, r)における, x以下の値の総和を返す
    ll solve(int l, int r, int x) {
        l += n;
        r += n;
        ll res = 0;
        while (l < r) {
            if (l & 1) res += get(l++, x); // lが奇数なら足して寄せる
            if (r & 1) res += get(--r, x); // rが奇数なら足して寄せる
            l >>= 1;
            r >>= 1;
        }
        return res;
    }
};

int main()
{
    int n;
    cin >> n;
    segtree1 t(n);
    rep(i, 0, n) {
        int a;
        cin >> a;
        t.set(i, a);
    }
    t.init();

    int q;
    ll ans = 0;
    cin >> q;
    rep(qi, 0, q) {
        ll l, r, x;
        cin >> l >> r >> x;
        l ^= ans;
        r ^= ans;
        x ^= ans;
        l--;
        ans = t.solve(l, r, x);
        cout << ans << "\n";
    }
    return 0;
}