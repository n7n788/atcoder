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
// typedef pair<int, int> P;
template <typename T> bool chmin(T &a, const T& b) {if (a > b) {a = b; return true;} return false;}
template <typename T> bool chmax(T &a, const T& b) {if (a < b) {a = b; return true;} return false;}

typedef long long ll;
const int INF = 1 << 30;
const ll INF_ll = 1ll << 60;

// セグ木で使用
struct Freq {
    int val;
    int cnt;
    Freq(int val = 0, int cnt = 0): val(val), cnt(cnt){}
};

struct P {
    Freq first, second;
    P(Freq first = Freq(), Freq second = Freq()): first(first), second(second) {}
};

// opを複数書くとコンパイルエラー
P op1(P a, Freq b) {
    if (b.val == a.first.val) {
        a.first.cnt += b.cnt;
        return a;
    } 
    else if (b.val == a.second.val) {
        a.second.cnt += b.cnt;
        return a;
    }
    if (b.val > a.second.val) a.second = b;
    if (a.second.val > a.first.val) swap(a.first, a.second);
    return a; 
}

// 2番目の最大値の個数を保持
P op(P a, P b) {
    return op1(op1(a, b.first), b.second);
    // P c;
    // map<int, int, greater<int>> mp;
    // mp[a.first.val] += a.first.cnt;
    // mp[a.second.val] += a.second.cnt;
    // mp[b.first.val] += b.first.cnt;
    // mp[b.second.val] += b.second.cnt;
    // int i = 0;
    // for (auto [val, cnt]: mp) {
    //     if (i == 0) c.first = Freq{val, cnt};
    //     else if (i == 1) c.second = Freq{val, cnt};
    //     else break;
    //     i++;
    // }
    // return c;
}

// 単位元 A + e = Aに相当するもの
P e() 
{ 
    P a = {Freq{0, 0}, Freq{-1, 0}};
    return a;
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i, 0, n) cin >> a.at(i);
    segtree<P, op, e> seg(n + 1);
    // 右開区間[l, r)での2番目に大きい個数を返す
    auto get2 = [&](int l, int r) -> int {
        P a = seg.prod(l, r);
        // cout << a.first.val << ", " << a.first.cnt << ": " << a.second.val << ", " << a.second.cnt << "\n";
        return a.second.cnt;
    };

    // [i]を値xに更新
    auto update = [&](int i, int x) {
        P a = {Freq{x, 1}, Freq{0, 0}};
        seg.set(i, a);
        return a;
    };

    rep(i, 0, n) update(i, a.at(i));
    // rep(i, 0, n) cout << seg.prod(i, i + 1).first.val << ", " << seg.prod(i, i + 1).first.cnt << "\n";
    rep(qi, 0, q) {
        int t;
        cin >> t;
        switch (t)
        {
        case 1:
            int p, x;
            cin >> p >> x;
            p--;
            update(p, x);
            break;
        case 2:
            int l, r;
            cin >> l >> r;
            l--;
            cout << get2(l, r) << "\n";
            break;
        }
    }
    return 0;
}