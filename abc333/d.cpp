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
    dsu uf(n);
    int max;
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        u--; 
        v--;
        if (u != 0) {
            if (!uf.same(u, v)) uf.merge(u, v);
        }
    }
    max = 0;
    for (auto g: uf.groups()) {
        chmax(max, (int) g.size());
    }
    cout << n - max << "\n";
    return 0;
}