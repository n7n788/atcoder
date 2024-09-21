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
#include <regex>

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

bool check()
{
    string s;
    cin >> s;
    // 正規表現: <==...==> に一致するかチェック
    // + : 直前の一文字が1個以上連続する
    // * : 直前の一文字が0個以上連続する
    regex re(R"(<=+>)");
    return regex_match(s, re);
}
int main()
{
    if (check()) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}