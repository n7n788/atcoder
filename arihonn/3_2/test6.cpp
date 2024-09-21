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

// nビットの集合bitの要素をプリント
void print(int bit, int n) 
{
    rep(i, 0, n) if ((bit >> i) & 1) cout << i << ' ';
    cout << endl;
    return;
}

int main()
{
    vector<int> a = {2, 3, 5, 7, 15};
    vector<int> b = {3, 6, 11, 15};

    int n = 16;
    int m = 1 << n;
    int bita = 0, bitb = 0;

    // 配列aの要素を集合に追加
    rep(i, 0, a.size()) bita |=  (1 << a.at(i));
    print(bita, n);

    // 配列bの要素を集合に追加
    rep(i, 0, b.size()) bitb |=  (1 << b.at(i));
    print(bitb, n);

    // 集合aから2を取り除く
    int x = 2;
    bita &= ~(1 << x);
    print(bita, n);

    // 集合aとbの和集合をとる
    int bitc = bita | bitb;
    print(bitc, n);

    // 集合aとbの積集合をとる
    int bitd = bita & bitb;
    print(bitd, n);

    int bite = (1 << n) - 1;
    int bitf = 1 << 15;

    print(bitc & bite, n);
    print(bitf | bitf, n);
}