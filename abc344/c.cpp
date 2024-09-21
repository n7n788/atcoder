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
    int n, m, l, q;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a.at(i);
    cin >> m;
    vector<int> b(m);
    rep(i, 0, m) cin >> b.at(i);
    cin >> l;
    vector<int> c(l);
    rep(i, 0, l) cin >> c.at(i);
    cin >> q;

    unordered_set<int> st;
    rep(i, 0, n) rep(j, 0, m) rep(k, 0, l) {
        int x = a.at(i) + b.at(j) + c.at(k);
        if (st.count(x) == 0) st.insert(x);
    }
    rep(qi, 0, q) {
        int x;
        cin >> x;
        if (st.count(x)) cout << "Yes\n";
        else cout << "No\n"; 
    }
    return 0;
}