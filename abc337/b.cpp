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
    string s;
    cin >> s;
    s += 'C';
    rep(i, 0, s.size() - 1) {
        if (s.at(i) == 'A') {
            if (s.at(i + 1) != 'A' && s.at(i + 1) != 'B' && s.at(i + 1) != 'C') break;
        } else if (s.at(i) == 'B') {
            if (s.at(i + 1) != 'B' && s.at(i + 1) != 'C') break;
        } else if (s.at(i) == 'C') {
            if (s.at(i + 1) != 'C') break;
        } else break;

        if (i == s.size() - 2) {
            cout << "Yes" << "\n";
            return 0;
        }
    }
    cout << "No" << "\n";
    return 0;
}