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

// aとbの最大公約数を返す
ll gcd(ll a, ll b) 
{
    if (b == 0) return a;
    else return gcd(b, a % b);
}

// aとbの最大公約数を返し, ax+by=gcd(a, b)の解(x, y)を求める
ll extgcd(ll a, ll b, ll& x, ll& y) 
{
    ll d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1; y = 0;
    }
    return d;
}

int main()
{
    ll a, b;
    cin >> a >> b;
    ll x, y;
    ll g = extgcd(a, b, x, y);
    if (g != 1) cout << -1 << "\n";
    else {
        cout << max(x, 0ll) << " " << max(y, 0ll) << " ";
        cout << max(-x, 0ll) << " " << max(-y, 0ll) << "\n";
    }
    return 0;
}