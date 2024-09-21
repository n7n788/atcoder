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
    string t;
    cin >> t;
    int n;
    cin >> n;
    vector<int> a(n);
    vector s(n, vector<string>());
    rep(i, 0, n) {
        cin >> a.at(i);
        rep(j, 0, a.at(i)) {
            string s1;
            cin >> s1;
            s.at(i).push_back(s1);
        }
    }
    vector dp(n + 1, vector<int>(t.size() + 1, INF));
    dp.at(0).at(0) = 0;
    rep(i, 0, n) erep(j, 0, t.size()) {
        if (dp.at(i).at(j) == INF) continue;
        chmin(dp.at(i + 1).at(j), dp.at(i).at(j));

        rep(k, 0, a.at(i)) {
            int m = s.at(i).at(k).size();
            if (j + m > t.size()) continue;
            
            bool ok = true;
            rep(l, 0, m) {
                if (t.at(j + l) != s.at(i).at(k).at(l)) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;
            chmin(dp.at(i + 1).at(j + m), dp.at(i).at(j) + 1);
        }
    }

    int ans = dp.at(n).at(t.size());
    if (ans != INF) cout <<  ans << "\n";
    else cout << -1 << "\n";
    return 0;
}