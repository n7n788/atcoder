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
    int max = 0;
    int max_index = -1;
    int n = 'z' - 'a' + 1;
    vector<int> count(n, 0);
    rep(i, 0, s.size()) count.at(s.at(i) - 'a')++;
    rep(i, 0, n) {
        if (count.at(i) > max) {
            max = count.at(i);
            max_index = i;
        }
    }
    printf("%c\n", 'a' + max_index);
}