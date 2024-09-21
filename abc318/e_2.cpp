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
#include <stack>

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

ll c3(ll n) { // nC3
    return  n * (n - 1) * (n - 2) / 6; 
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) {
        cin >> a.at(i);
        a.at(i)--;
    }

    vector<int> cnt(n + 1);
    vector<ll> sum(n + 1);
    ll ans = 0;
    rep(k, 0, n) {
        ans += (ll) (k - 1) * cnt.at(a.at(k)) - sum.at(a.at(k));
        cnt.at(a.at(k))++;
        sum.at(a.at(k))+= k;
    }

    rep(i, 0, n) ans -= c3(cnt.at(i));
    cout << ans << endl;

    return 0;
}