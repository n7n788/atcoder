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
    int n;
    cin >> n;
    vector<int> t(n), x(n);
    vector<set<int>> po(n);
    vector<bool> use(n, false);
    int cnt, ans;
    rep(i, 0, n) {
        cin >> t.at(i) >> x.at(i);
        x.at(i)--;
        if (t.at(i) == 1) po.at(x.at(i)).insert(-i);
    }
    for (int i = n - 1; i >= 0; i--) {
        if (t.at(i) == 1) continue;
        auto it = upper_bound(po.at(x.at(i)).begin(), po.at(x.at(i)).end(), -i);
        int p = *it;
        if (it != po.at(x.at(i)).end()) {
            use.at(-p) = true;
            po.at(x.at(i)).erase(p);
        } else {
            cout << -1 << "\n";
            return 0;
        }
    }
    cnt = 0;
    ans = 0;
    rep(i, 0, n) {
        if (t.at(i) == 1 && use.at(i)) cnt++;
        else if (t.at(i) == 2) cnt--;
        // cout << cnt << "\n";
        chmax(ans, cnt);
    }
    cout << ans << "\n";
    rep(i, 0, n) {
        if (t.at(i) == 1) {
            // cout << use.at(i) << "\n";
            if (use.at(i)) cout << 1 << " ";
            else cout <<  0 << " ";
        }
    }
    cout << "\n";
    return 0;
}