// #include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <atcoder/all>
#include <set>
#include <map>
#include <atcoder/all>
#include <unordered_map>
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
    int m, x;
    double p;
    cin >> m >> p >> x;

    int n = 1 << m;
    vector dp(2, vector<double>(n + 1, 0.0));
    dp.at(0).at(n) = 1.0;
    vector<double>& prv = dp.at(0), nxt = dp.at(1);

    rep(r, 0, m) {
        erep(i, 0, n) {
            int jubs = min(i, n - i);
            double t = 0.0;
            for (int j = 0; j <= jubs; j++) {
                chmax(t, p * prv.at(i + j) + (1 - p) * prv.at(i - j));
            }
            nxt.at(i) = t;
        }
        swap(nxt, prv);
    }

    int i = (ll) x * n / 1e6;
    printf("%.6f\n", prv.at(i));
    return 0;
}