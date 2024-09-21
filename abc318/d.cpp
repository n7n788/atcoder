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
    vector d(n, vector<ll>(n));
    rep(i, 0, n - 1) rep(j, i + 1, n) cin >> d.at(i).at(j);

    int n2 = 1 << n;
    vector<ll> dp(n2, 0);
    
    rep(i, 0, n2) {
        int cnt = 0;
        rep(j, 0, n) if ((i >> j) & 0x1) cnt++;
        if (cnt % 2 == 1) continue;

        rep(j, 0, n) {
            if ((i >> j) & 0x1) continue;
            rep(k, j, n) {
                if ((i >> k) & 0x1) continue;
                int visited = i;
                visited |= (0x1 << j);
                visited |= (0x1 << k);
                chmax(dp.at(visited), dp.at(i) + d.at(j).at(k));
            }
        }
    }

    cout << dp.at(n2 - 1) << endl;
    return 0;
}