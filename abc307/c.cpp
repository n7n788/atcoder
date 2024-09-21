#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
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
template <typename T> bool chmin(T &a, const T& b) {if (a > b) {a = b; return true;} return false;}
template <typename T> bool chmax(T &a, const T& b) {if (a < b) {a = b; return true;} return false;}

typedef pair<int, int> P;
typedef long long ll;
const int INF = 1 << 30;
const ll INF_ll = 1ll << 60;

const int delta = 10;


int main()
{
    vector<int> h(3), w(3);
    vector a(3, vector<string>(10));

    rep(k, 0, 3) {
        cin >> h.at(k) >> w.at(k);
        rep(i, 0, h.at(k)) {
            cin >> a.at(k).at(i);
        }
    }

    vector<vector<char>> tmp(30, vector<char>(30, '.'));
    // tmpに対して、(dh0, dw0), (dh1, dw1)だけズレる
    erep(dh0, 1, 20) erep(dw0, 1, 20) erep(dh1, 1, 20) erep(dw1, 1, 20) {
        rep(i, 0, 30) rep(j, 0, 30) tmp.at(i).at(j) = '.';
        rep(i, 0, h.at(0)) rep(j, 0, w.at(0)) tmp.at(dh0 + i).at(dw0 + j) = a.at(0).at(i).at(j);
        rep(i, 0, h.at(1)) rep(j, 0, w.at(1)) tmp.at(dh1 + i).at(dw1 + j) = a.at(1).at(i).at(j);

        bool ok = true;
        rep(i, 0, 30) rep(j, 0, 30) {
            if (i - 10 >= 0 && i - 10 < h.at(2) && 
                j - 10 >= 0 && j - 10 < w.at(2)) {
                    if (tmp.at(i).at(j) != a.at(2).at(i - 10).at(j - 10)) ok = false;
                }
            else {
                if (tmp.at(i).at(j) == '#') ok = false;
            }
        }
        if (ok) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}