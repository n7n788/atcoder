// #include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
typedef pair<int, int> P;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, 0, n) cin >> a.at(i);
    vector<int> exist(n + k, 0);
    rep(i, 0, n) if (a.at(i) < n + k) exist.at(a.at(i)) = 1;

    // 階上の計算
    vector<mint> fact(n + k);
    fact.at(0) = 1;
    fact.at(1) = 1;
    rep(i, 2, n + k) fact.at(i) = fact.at(i - 1) * i;

    // nCrの計算
    auto binom = [&](int n, int r) -> mint{
        return fact.at(n) / fact.at(r) / fact.at(n - r);
    };

    mint res = 0;
    int need = 1, rest;
    rep(i, 0, n + k) {
        rest = k - need;
        if (rest < 0) break;
        // 0以上i以下の整数(i＋1種類)から、rest回選ぶ重複組み合わせ
        // n+i C i で表現できる
        res += binom(rest + i, i);
        if (exist.at(i) == 0) need++; 
    }
    cout << res.val() << endl;
    return 0;
}