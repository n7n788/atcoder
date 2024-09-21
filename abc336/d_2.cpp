//#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include "atcoder/all"
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <cstdlib>

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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a.at(i);
    vector<int> dpl(n + 2, 0), dpr(n + 2, 0);
    int ans = 0;
    rep(i, 0, n) dpl.at(i + 1) = min(dpl.at(i) + 1, a.at(i));
    for (int i = n + 1; i >= 2; i--) dpr.at(i - 1) = min(dpr.at(i) + 1, a.at(i - 2));

    erep(i, 1, n) {
        chmax(ans, min(dpl.at(i), dpr.at(i)));
    }
    cout << ans << "\n";
    return 0;
}