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
#include <stack>

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

// セグ木で使用
// 最大値を保持
int op(int a, int b) { return max(a, b); }
// 初期値
int e() { return 0; }
const int A = 500010;

int main()
{
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    // セグ木の実装
    atcoder::segtree<int, op, e> seg(A);
    rep(i, 0, n) {
        int a;
        cin >> a;
        int l = max(a - d, 0);
        int r = min(a + d, A - 1);
        int max = seg.prod(l, r + 1); // 区間[l, r+1)の最大値を返す
        seg.set(a, max + 1); // [a]にmax+1に更新
    }
    cout << seg.all_prod() << "\n"; // 全体の最大値を返す
    return 0;
}