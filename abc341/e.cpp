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
    string s;
    cin >> s;
    fenwick_tree<int> d(n + 1);
    rep(i, 0, n - 1) {
        if (s.at(i) != s.at(i + 1)) d.add(i, 1);
    }
    rep(qi, 0, q) {
        int t, l, r;
        cin >> t >> l >> r;
        l--;
        r--;
        switch (t)
        {
        case 1:
            if (l > 0) {
                if (d.sum(l - 1, l) == 0) d.add(l - 1, 1);
                else d.add(l - 1, -1);
            }
            if (r < n - 1) {
                if (d.sum(r, r + 1) == 0) d.add(r, 1);
                else d.add(r, -1);
            }
            break;
        case 2:
            if (d.sum(l, r) == r - l) cout << "Yes" << "\n";
            else cout << "No" << "\n";
            break;
        }
    }

    return 0;
}