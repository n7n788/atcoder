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
    string s;
    cin >> s;

    rep(i, 0, n - 1) if (s.at(i) > '1' && s.at(i + 1) > '1') {
        cout << -1 << endl;
        return 0;
    }
    mint ans = 0;
    while (s.size() > 1) {
        int c = s.back() - '0';
        ans += 1;
        ans += (c - 1) * ans;
        s.pop_back();
    }

    cout << ans.val() << endl;
    return 0;
}