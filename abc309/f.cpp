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

int main()
{
    int n;
    cin >> n;
    vector<P> a;
    rep(i, 0, n) {
        int h, w, d;
        cin >> h >> w >> d;
        a.emplace_back(h, i);
        a.emplace_back(w, i);
        a.emplace_back(d, i);
    }
    stable_sort(a.begin(), a.end());

    vector<int> cnt(n, 0);
    rep(i, 0, 3 * n) {
        cnt.at(a.at(i).second)++;
        if (cnt.at(a.at(i).second) >= 3) 
    }
    return 0;
}