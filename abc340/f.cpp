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

// 拡張gcd: a, bの最大公約数と, ai + bj = gcd(a, b)となる(i, j)を求める
ll extgcd(ll a, ll b, ll& i, ll& j) {
    if (b == 0) {i = 1; j = 0; return a;}
    ll p = a / b, g = extgcd(b, a - b * p, j, i);
    j -= p * i;
    return g;
}

int main()
{
    ll x, y;
    cin >> x >> y;
    ll a, b;
    ll g = extgcd(x, y, b, a);
    a = -a;
    if (2 % g) {
        cout << -1 << endl;
        return 0;
    }
    a *= 2 / g;
    b *= 2 / g;
    cout << a << ' ' << b << endl;
    return 0;
}
