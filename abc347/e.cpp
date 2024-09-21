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
    int n, q;
    cin >> n >> q;
    fenwick_tree<ll> f(q + 1);
    unordered_set<int> st;
    vector<int> xs(n, -1);
    vector<ll> ans(n, 0);

    rep(qi, 0, q) {
        int x;
        cin >> x;
        x--;
        if (st.count(x)) {
            // cout << "out: " << x << "\n";
            st.erase(x);
            // cout << "add: " << f.sum(xs.at(x), qi) << "\n";
            ans.at(x) += f.sum(xs.at(x), qi);
            xs.at(x) = -1;
        } else {
            // cout << "in: " << x << "\n";
            // cout << "  xs.at():  " << qi << "\n";
            st.insert(x);
            xs.at(x) = qi;
        }
        f.add(qi, (ll)st.size());
    }

    rep(i, 0, n) {
        if (xs.at(i) != -1) {
            ans.at(i) += f.sum(xs.at(i), q);
        }
    }

    rep(i, 0, n) cout << ans.at(i) << ' ';
    cout << endl;
    return 0;
}