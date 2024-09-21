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
    int n, m;
    cin >> n >> m;
    vector<string> c(n);
    rep(i, 0, n) cin >> c.at(i);
    vector<string> d(m);
    rep(i, 0, m) cin >> d.at(i);
    vector<int> p(m);
    int p0;
    cin >> p0;
    rep(i, 0, m) cin >> p.at(i);
    map<string, int> mp;
    rep(i, 0, m) mp[d.at(i)] = p.at(i);

    int sum = 0;
    rep(i, 0, n) {
        if (mp.find(c.at(i)) != mp.end()) sum += mp[c.at(i)];
        else sum += p0;
    }
    cout << sum << endl;
    return 0;
}