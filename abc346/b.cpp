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
    int w, b;
    cin >> w >> b;
    string s = "wbwbwwbwbwbw";

    rep(i, 0, s.size()) {
        int wc = 0, bc = 0;
        rep(j, 0, w + b) {
            if (s.at((i + j) % s.size()) == 'w') wc++;
            else if (s.at((i + j) % s.size()) == 'b') bc++;
        }
        if (wc == w && bc == b) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}