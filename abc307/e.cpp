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
    vector dp(n + 1, vector<mint>(2, 0));
    dp.at(1).at(1) = m;
    rep(i, 1, n) {
        dp.at(i + 1).at(0) += dp.at(i).at(0) * (m - 2);
        dp.at(i + 1).at(1) += dp.at(i).at(0);
        dp.at(i + 1).at(0) += dp.at(i).at(1) * (m - 1);
    }
    cout << dp.at(n).at(0).val() << endl;
    return 0;
}