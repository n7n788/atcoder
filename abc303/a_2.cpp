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
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    auto f = [&](string s) -> string {
        rep(i, 0, n) {
            if (s.at(i) == '0') s.at(i) = 'o';
            else if (s.at(i) == '1') s.at(i) = 'l';
        }
        return s;
    };
    
    if (f(s) == f(t)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}