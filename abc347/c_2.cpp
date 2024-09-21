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
    int n, a, b;
    cin >> n >> a >> b;
    int w = a + b;
    vector<int> d(n);
    rep(i, 0, n) cin >> d.at(i);

    rep(i, 0, n) d.at(i) %= w;
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());

    int m = d.size();
    rep(i, 0, m) d.push_back(d.at(i) + w);

    rep(i, 0, m) {
        int l = d.at(i), r = d.at(i + m - 1);
        if (r - l + 1 <= a) {
            cout << "Yes\n";
            return 0;
        }
    } 

    cout << "No\n";
    return 0;
}