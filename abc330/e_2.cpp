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
    vector<int> a(n);
    rep(i, 0, n) cin >> a.at(i);

    set<int> st;
    map<int, int> mp;
    rep(i, 0, n) mp[a.at(i)]++;
    erep(i, 0, n) {
        if (mp.find(i) != mp.end()) continue;
        st.insert(i);
    }

    rep(qi, 0, q) {
        int i, x;
        cin >> i >> x;
        i--;
        mp[a.at(i)]--;
        if (mp[a.at(i)] == 0) st.insert(a.at(i));
        a.at(i) = x;
        mp[a.at(i)]++;
        if (mp[a.at(i)] == 1) st.erase(a.at(i));
        cout << *st.begin() << "\n";
    }
    return 0;
}