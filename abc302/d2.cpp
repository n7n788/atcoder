//#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <atcoder/all>
#include <map>
#include <set>

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
    ll D;
    cin >> n >> m >> D;
    vector<ll> A(n), B(m);
    rep(i, 0, n) cin >> A.at(i);
    rep(i, 0, m) cin >> B.at(i);

    // 配列Bにおいて、xより大きい最小のインデックスを返す関数
    auto upper_bound = [&](ll x) -> int{
        // wcは常に条件を満たさない
        // acは常に条件を満たす
        int wc = -1, ac = m;
        while (ac - wc > 1) {
            int mid = (ac - wc) / 2 + wc;
            if (B[mid] > x) ac = mid;
            else wc = mid;
        }
        return ac;
    };

    sort(B.begin(), B.end());
    ll max = -INF_ll;
    for (ll a: A) {
        int j = upper_bound(a + D) - 1;
        if (j != -1 && B[j] >= a - D) chmax(max, a + B[j]);
    }

    if (max == -INF_ll) cout << -1 << endl;
    else cout << max << endl;
}