// #include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <atcoder/all>
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
    int h, w;
    cin >> h >> w;
    vector a(h, vector<char>(w)), b(h, vector<char>(w));
    vector a_tmp(h, vector<char>(w));
    vector a_tmp2(h, vector<char>(w));

    rep(i, 0, h) rep(j, 0, w) cin >> a.at(i).at(j);
    rep(i, 0, h) rep(j, 0, w) cin >> b.at(i).at(j);

    rep(s, 0, h) rep(t, 0, w) {
        rep(i, 0, h) rep(j, 0, w) a_tmp.at(i).at(j) = a.at((i + s) % h).at(j);
        rep(i, 0, h) rep(j, 0, w) a_tmp2.at(i).at(j) = a_tmp.at(i).at((j + t) % w);

        bool flag = true;
        rep(i, 0, h) rep(j, 0, w) {
            if (a_tmp2.at(i).at(j) != b.at(i).at(j)) flag = false;
        } 
        if (flag) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}
    