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
const ll INF_ll = 1ll << 62;

int main()
{
    // typedef unsigned long long ll;
    // const ll INF_ll = 1ll << 63;
    ll n, m, k;
    cin >> n >> m >> k;
    auto f = [&](ll x) -> ll{
        // cout << x / n << ", " << x / m << ", " <<  x / (n * m) << ", ";
        return x / n + x / m - 2 * (x / lcm(n, m));
    };
    ll wc = 0;
    ll ac = INF_ll;
    while (ac - wc > 1) {
        // cout << ac << ", " << wc << "\n";
        ll mid = (wc + ac) / 2;
        if (f(mid) >= k) ac = mid;
        else wc = mid;
        // cout << f(mid) << "\n";
    } 
    cout << ac << "\n";
    return 0;
}