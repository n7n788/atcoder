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
    int n, t;
    cin >> n >> t;
    // multiset<int> mu;
    unordered_map<ll, int> mp;
    vector<ll> sc(n, 0);
    int kind = 1;
    rep(i, 0, n) {
        // mu.insert(0);
        mp[0]++;
    }
    // cout << mu.count(0) << "\n";
    rep(i, 0, t) {
        int a, b;
        cin >> a >> b;
        a--;
        // if (mu.count(sc.at(a)) == 1) kind--;
        // mu.erase(mu.find(sc.at(a)));
        // sc.at(a) += b;
        // mu.insert(sc.at(a));
        // if (mu.count(sc.at(a)) == 1) kind++;
        if (mp[sc.at(a)] == 1) kind--;
        mp[sc.at(a)]--;
        sc.at(a) += b;
        mp[sc.at(a)]++;
        if (mp[sc.at(a)] == 1) kind++;
        cout << kind << "\n";
        // cout << mu.count(0) << ", " << mu.count(10) << ", " << mu.count(20) << "\n";
    }
    return 0;
}