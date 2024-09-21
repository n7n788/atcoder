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


// 配列[0, ... w-1]を
// 配列x1, x2(サイズn)の値とその前後のみになるように座標を圧縮
// x1, x2座標の値を圧縮した値に変更し、圧縮した配列のサイズを返す
int compress(vector<int>& x1, vector<int>& x2, int n, int w) 
{
    // 配列x1, x2とその前後の値を抽出
    vector<int> xs;

    rep(i, 0, n) {
        erep(d, -1, 1) {
            int tx1 = x1.at(i) + d, tx2 = x2.at(i) + d;
            if (1 <= tx1 && tx1 <= w) xs.push_back(tx1);
            if (1 <= tx2 && tx2 <= w) xs.push_back(tx2);
        }
    }

    // ソートして、複数ある値は一つだけ残して他は削除
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    // 配列x1, x2を圧縮した値を返す
    // = 抽出した配列の内、要素のインデックスを返す
    rep(i, 0, n) {
        x1.at(i) = find(xs.begin(), xs.end(), x1.at(i)) - xs.begin();
        x2.at(i) = find(xs.begin(), xs.end(), x2.at(i)) - xs.begin();
    }

    for (auto x: xs) printf("%d ", x);
    printf("\n\n");

    return xs.size();
}

int main()
{
    int W, H, N;
    cin >> W >> H >> N;
    vector<int> X1(N), X2(N), Y1(N), Y2(N);
    rep(i, 0, N) cin >> X1.at(i);
    rep(i, 0, N) cin >> X2.at(i);
    rep(i, 0, N) cin >> Y1.at(i);
    rep(i, 0, N) cin >> Y2.at(i);

    // 配列X1, X2, Y1, Y2を圧縮した座標に変換
    W = compress(X1, X2, N, W);
    H = compress(Y1, Y2, N, H);

    printf("W = %d, H = %d\n", W, H);
    printf("X1 = ");
    rep(i, 0, N) printf("%d ", X1.at(i));
    printf("\n");
    printf("X2 = ");
    rep(i, 0, N) printf("%d ", X2.at(i));
    printf("\n");
    printf("Y1 = ");
    rep(i, 0, N) printf("%d ", Y1.at(i));
    printf("\n");
    printf("Y2 = ");
    rep(i, 0, N) printf("%d ", Y2.at(i));
    printf("\n\n");

    // 座標圧縮したフィールド: H x W
    vector fld(H, vector<bool>(W, false));
    // フィールドに値を埋め込む
    rep(i, 0, N) {
        erep(x, X1.at(i), X2.at(i)) {
            erep(y, Y1.at(i), Y2.at(i)) {
                fld.at(y).at(x) = true;
            }
        }
    }

    auto print_fld = [&] () {
        rep(i, 0, H) {
            rep(j, 0, W) {
                if (fld.at(i).at(j)) printf("#");
                else printf(".");
            }
            printf("\n");
        }
        printf("\n");
    };
    // (sx, sx)を始点として幅優先探索
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    auto bfs = [&](int sx, int sy) -> void {
        queue<P> q;
        q.emplace(sx, sy);
        fld.at(sx).at(sy) = true;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            rep(i, 0, 4) {
                int nx = x + dx.at(i), ny = y + dy.at(i);
                if (nx < 0 || nx >= H || ny < 0 || ny >= W)continue;
                if (fld.at(nx).at(ny)) continue;
                q.emplace(nx, ny);
                fld.at(nx).at(ny) = true;
            }
        }
    };

    // 幅優先探索を利用して島の個数をカウント
    print_fld();
    int ans = 0;
    rep(x, 0, H) rep(y, 0, W) {
        if (fld.at(x).at(y)) continue;
        bfs(x, y);
        print_fld();
        ans++;
    }

    cout << ans << "\n";
}
