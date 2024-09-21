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
    vector<string> s(n);
    rep(i, 0, n) cin >> s.at(i);

    vector<int> ls(n);
    rep(i, 0, n) {
        int l = -1;
        rep(j, 0, n) if (s.at(i).at(j) == '1') l = j;
        ls.at(i) = l;
    }
    // rep(i, 0, n) cout << ls.at(i) << " ";

    auto move = [&](int i, int ni) -> int {
        for (int j = ni - 1; j >= 0; j--) {
            // swap(s.at(j), s.at(j + 1));
            swap(ls.at(j), ls.at(j + 1));
        }
        return ni - i;
    };

    int ans = 0;
    rep(i, 0, n - 1) {
        int ni = -1;
        rep(j, i, n) {
            if (ls.at(j) <= i) {
                ni = j;
                break;
            }
        }
        if (ni == -1) {
            cout << -1 << "\n";
            return 0;
        }
        ans += move(i, ni);
        // cout << ni << "\n";
    }
    cout << ans << "\n";
}