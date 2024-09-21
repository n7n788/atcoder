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

const int S = 10;
const int M = 1e9;

// 素数判定
bool isPrime(int x)
{
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int mult(int a, int b, int p) {
    return (ll) a * b % p;
}

int main()
{
    vector<int> ps;
    while (ps.size() < S) {
        int p = rand() % M + M; // 10^9~2*10^9の素数を求める
        if (!isPrime(p)) continue;
        ps.push_back(p);
    }

    int n;
    cin >> n;
    vector xs(n, vector<int>()); // a[i]の各素数でのmodを保持
    rep(i, 0, n) {
        // 1000桁の数字を文字列で入力
        string s;
        cin >> s;
        // 各素数でmodをとる
        for (int p: ps) {
            ll x = 0;
            for (char c : s) {
                x = (x * 10 + (c - '0')) % p;
            }
            xs.at(i).push_back(x);
        }   
    }

    map<vector<int>, int> cnt; // 各素数のmod値をキーとして個数を保持
    rep(i, 0, n) cnt[xs.at(i)]++;

    ll ans = 0;
    rep(i, 0, n) rep(j, 0, n) {
        vector<int> cs;
        rep(k, 0, S) {
            cs.push_back(mult(xs.at(i).at(k), xs.at(j).at(k), ps.at(k)));
        }
        ans += cnt[cs];
    }
    cout << ans << "\n";
    return 0;
}
