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
    int p;
    cin >> p;
    vector<int> a(p);
    unordered_map<int, int> mp;
    rep(i, 0, p) {
        cin >> a.at(i);
        mp[a.at(i)]++;
    }
    int m = mp.size();
    int s = 0, t = 0;
    int res = p;
    mp = {};
    for(;;) {
        while (t < p && mp.size() < m) mp[a.at(t++)]++;
        if (mp.size() < m) break;
        chmin(res, t - s);

        mp[a.at(s)]--;
        if (mp[a.at(s)] == 0) mp.erase(a.at(s));
        s++;
    }

    cout << res << "\n";
}