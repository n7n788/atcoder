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
    char p, q;
    cin >> p >> q;
    int pi = p - 'A', qi = q - 'A';
    vector<int> a = {3, 1, 4, 1, 5, 9};
    int as = a.size();
    vector<int> cum(as + 1, 0);
    rep(i, 0, as) cum.at(i + 1) = cum.at(i) + a.at(i);
    cout << abs(cum.at(pi) - cum.at(qi)) << endl;
    return 0;
}