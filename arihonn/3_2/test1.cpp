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
    int n, S;
    cin >> n >> S;
    vector<int> a(n);
    rep(i, 0, n) cin >> a.at(i);

    vector<int> s(n + 1, 0);
    rep(i, 0, n) s.at(i + 1) = s.at(i) + a.at(i);

    int ans = INF;
    rep(i, 0, n) {
        int j = lower_bound(s.begin(), s.end(), s.at(i) + S) - s.begin();
        if (j == n + 1) break;
        chmin(ans, j - i);
    }
    
    if (ans == INF) cout << 0 << "\n";
    else cout << ans << "\n";
    return 0;
}