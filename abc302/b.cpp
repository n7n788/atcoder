// #include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <atcoder/all>
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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, 0, h) cin >> s.at(i);

    // インクリメントする8方向のベクトル
    vector<int> di = {-1, -1, -1,  0, 0,  1, 1, 1};
    vector<int> dj = {-1,  0,  1, -1, 1, -1, 0, 1};
    string t = "snuke";
    
    // 始点を1つ決める
    rep(si, 0, h) rep(sj, 0, w) {
        // 8方向を探索する
        rep(v, 0, 8) {
            int i = si, j = sj;
            // 5回進む
            rep(k, 0, 5) {
                if (i < 0 || i >= h || j < 0 || j >= w) break;
                if (s.at(i).at(j) != t.at(k))  break;
                if (k == 4) {
                    i = si, j = sj;
                    rep(k2, 0, 5) {
                        printf("%d %d\n", i + 1, j + 1);
                        i += di.at(v), j += dj.at(v);
                    }
                    return 0;
                }
                i += di.at(v), j += dj.at(v);
            }
        }
    }
    return 0;
}