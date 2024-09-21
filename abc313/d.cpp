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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    // 質問を出力して、解答の入力を受け取る関数
    auto f = [&] (vector<int> x) {
        rep(i, 0, k) x.at(i)++;
        cout << '?';
        rep(i, 0, k) cout << ' ' << x.at(i);
        cout << endl;
        int res;
        cin >> res;
        return res;
    };

    vector<int> b(n);
    int t = 0;
    rep(i, 0, k + 1) {
        vector<int> x;
        rep(j, 0, k + 1) if (i != j) x.push_back(j);
        b[i] = f(x);
        t ^= b[i];
    }   
    rep(i, 0, k + 1) a[i] = b[i] ^ t;

    t = 0;
    rep(i, 0, k - 1) t ^= a.at(i);

    vector<int> x;
    rep(i, 0, k - 1) x.push_back(i);
    rep(i, k + 1, n) {
        x.push_back(i);
        b.at(i) = f(x);
        a.at(i) = b.at(i) ^ t;
        x.pop_back();
    }
    cout << '!';
    rep(i, 0, n) {
        cout << ' ' << a.at(i);
    }
    cout << endl;

    return 0;
}