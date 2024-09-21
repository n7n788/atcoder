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


// ユークリッドの互除法 a,bの最大公約数を返す
ll gcd (ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main()
{
    typedef pair<ll, ll> P;
    P p1, p2;
    cin >> p1.first >> p1.second >> p2.first >> p2.second;
    ll dx = abs(p1.first - p2.first);
    ll dy = abs(p1.second - p2.second);
    if (dx == 0 && dy == 0) cout << 0 << "\n";
    else cout << gcd(dx, dy) - 1 << "\n";
    return 0;
}