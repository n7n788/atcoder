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
    vector<int> a(n), b(n);
    fenwick_tree<int> d(2 * n + 1);
    // 区間[l, r)をxに更新する関数
    auto update = [&](int l, int r, int x) -> void {
        int dx = x - d.sum(0, l + 1);
        d.add(l, dx);
        d.add(r, -dx);
    };
    rep(i, 0, n) {
        cin >> a.at(i) >> b.at(i);
        a.at(i)--;
        b.at(i)--;
    }
    rep(i, 0, n) {
        int x = d.sum(0, a.at(i) + 1);
        int y = d.sum(0, b.at(i) + 1);
        if (x != y) {
            cout << "Yes" << "\n";
            return 0;
        }
        update(a.at(i), b.at(i) + 1, i + 1);
    }
    cout << "No" << "\n";
    return 0;
}