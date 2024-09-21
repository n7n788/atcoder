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

int main()
{
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> a(n), b(m);
    rep(i, 0, n) cin >> a.at(i);
    rep(i, 0, m) cin >> b.at(i);
    vector<unordered_set<int>> st(n);
    rep(i, 0, l) {
        int c, d;
        cin >> c >> d;
        c--; d--;
        st.at(c).insert(d);
    }
    vector<int> bi(m);
    rep(i, 0, m) bi.at(i) = i;
    sort(bi.begin(), bi.end(), [&](int i, int j) {
        return b[i] > b[j];
    });
    int ans = 0;
    rep(i, 0, n) {
        for (int j: bi) {
            if (st.at(i).count(j)) continue;
            chmax(ans, a.at(i) + b.at(j));
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}
