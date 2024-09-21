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
    vector<int> a(n);
    rep(i, 0, n) {
        cin >> a.at(i);
        a.at(i)--;
    }

    vector ps(n, vector<ll>());
    rep(i, 0, n) {
        ps.at(a.at(i)).push_back(i);
    }

    ll sum = 0;
    rep(i, 0, n) {
        vector<ll> vals(ps.at(i).size(), 0);
        rep(j, 1, ps.at(i).size()) {
            vals.at(j) += vals.at(j - 1);
            vals.at(j) += (ps.at(i).at(j) - ps.at(i).at(j - 1) - 1) * j;
        }
        rep(j, 1, ps.at(i).size()) {
            sum += vals.at(j);
        }
    }
    cout << sum << endl;
    
    return 0;
}