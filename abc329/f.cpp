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
// typedef pair<int, int> P;
template <typename T> bool chmin(T &a, const T& b) {if (a > b) {a = b; return true;} return false;}
template <typename T> bool chmax(T &a, const T& b) {if (a < b) {a = b; return true;} return false;}

typedef long long ll;
const int INF = 1 << 30;
const ll INF_ll = 1ll << 60;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<unordered_set<int>> s(n);
    rep(i, 0, n) {
        int c; cin >> c;
        s.at(i).insert(c);
    }

    rep(qi, 0, q) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (s.at(a).size() > s.at(b).size()) swap(s.at(a), s.at(b));
        for (int c: s.at(a)) s.at(b).insert(c);
        s[a] = {};
        cout << s.at(b).size() << "\n"; 
    }
    return 0;
}