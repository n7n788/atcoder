#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cassert>
#include <iomanip>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF_ll 1001001001001001001ll
#define INF 1001001001
#define fcout cout << fixed << setprecision(12)

using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<long long, long long>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;
using vvc = vector<vector<char>>;
using vvb = vector<vector<bool>>;
using vvvi = vector<vector<vector<int>>>;
using pii = pair<int, int>;

template <typename T>
inline bool chmax(T &a, T b) {
    return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b) {
    return ((a > b) ? (a = b, true) : (false));
}

struct P {
    int i, j, k;
    P(int i = 0, int j = 0, int k = 0): i(i), j(j), k(k) {}
};

vector<P> Ls = {{0, 1, 2},
          {3, 4, 5},
          {6, 7, 8},
          {0, 3, 6},
          {1, 4, 7},
          {2, 5, 8},
          {0, 4, 8},
          {2, 4, 6}};

void solve(vl A)
{
    vl s(9, -1);

    auto dfs = [&](auto dfs, int turn) -> int {
        for (auto [i, j, k]: Ls) {
            if (s.at(i) == s.at(j) && s.at(i) == s.at(k) && s.at(i) != -1) {
                return s.at(i);
            }
        }
        bool finish = true;
        REP(i, 9) if (s.at(i) == -1) finish = false;
        if (finish) {
            ll sum0 = 0, sum1 = 0;
            REP(i, 9) {
                if (s.at(i) == 0) sum0 += A.at(i);
                if (s.at(i) == 1) sum1 += A.at(i);
            }
            if (sum0 > sum1) return 0;
            else return 1;
        }

        bool win = false;
        REP(i, 9) {
            if (s.at(i) != -1) continue;
            s.at(i) = turn;
            win |= (dfs(dfs, !turn) == turn);
            s.at(i) = -1;
        }
        if (win) return turn;
        else return !turn;
    };

    cout << (dfs(dfs, 0) == 0 ? "Takahashi": "Aoki") << endl;
    return;
}
// vvi Ls = {{0, 1, 2}, 
//              {3, 4, 5},
//              {6, 7, 8},
//              {0, 3, 6},
//              {1, 4, 7},
//              {2, 5, 8},
//              {0, 4, 8},
//              {2, 4, 6}};

// void solve(vector<ll> A)
// {
//     vector<ll> state(9, -1);

//     auto dfs = [&](auto dfs, int turn) -> int {
//         // 盤面が終了状態なら、勝敗を判定して答えを返す
//         // 3つ並んだかチェック
//         REP(i, 8) {
//             if (state.at(Ls.at(i).at(0)) == -1 ||
//                 state.at(Ls.at(i).at(1)) == -1 ||
//                 state.at(Ls.at(i).at(2)) == -1) continue;
//             if (state.at(Ls.at(i).at(0)) == state.at(Ls.at(i).at(1)) && 
//                 state.at(Ls.at(i).at(0)) == state.at(Ls.at(i).at(2))) 
//                     return state.at(Ls.at(i).at(0));
//         }
//         // 盤面が全て塗られたかをチェック
//         bool finish = true;
//         REP(i, 9) if (state.at(i) == -1) finish = false;
//         if (finish) {
//             vector<ll> s(2, 0);
//             REP(i, 9) s.at(state.at(i)) += A.at(i);
//             if (s.at(0) > s.at(1)) return 0;
//             else return 1;
//         }

//         // 新しい盤面s'を考え, turnが勝利するなら、turnを返す
//         bool win = false;
//         REP(i, 9) {
//             if (state.at(i) != -1) continue;
//             state.at(i) = turn;
//             win |= (dfs(dfs, !turn) == turn);
//             state.at(i) = -1;
//         }

//         if (win) return turn;
//         else return !turn;
//     };

//     cout << (dfs(dfs, 0) == 0 ? "Takahashi" : "Aoki") << endl;
//     return;
// }

// vvi Ls = {{0, 1, 2},
//           {3, 4, 5},
//           {6, 7, 8},
//           {0, 3, 6},
//           {1, 4, 7},
//           {2, 5, 8},
//           {0, 4, 8},
//           {2, 4, 6}};

// void solve(vl A) 
// {
//     vi state(9, -1);
//     auto dfs = [&](auto dfs, int turn) -> int {
//         // 終了条件
//         for (auto l: Ls) {
//             if (state.at(l.at(0)) != -1 &&
//                 state.at(l.at(0)) == state.at(l.at(1)) &&
//                 state.at(l.at(0)) == state.at(l.at(2))) 
//                 return state.at(l.at(0));
//         }
//         bool finish = true;
//         REP(i, 9) if (state.at(i) == -1) finish = false;
//         if (finish) {
//             vector<ll> sum(2, 0);
//             REP(i, 9) sum.at(state.at(i)) += A.at(i);
//             if (sum.at(0) > sum.at(1)) return 0;
//             else return 1;
//         }

//         // 次の状態を全列挙
//         bool win = false;
//         REP(i, 9) {
//             if (state.at(i) != -1) continue;
//             state.at(i) = turn;
//             win |= (dfs(dfs, !turn) == turn);
//             state.at(i) = -1;
//         }

//         if (win) return turn;
//         else return !turn;
//     };

//     cout << ((dfs(dfs, 0) == 0) ? "Takahashi" : "Aoki") << endl;
//     return;
// }

// Generated by 2.13.0 https://github.com/kyuridenamida/atcoder-tools  (tips: You use the default template now. You can remove this line by using your custom template)
int main()
{
    vector<ll> A(9);
    REP(i, 9) cin >> A.at(i);
    solve(std::move(A));
    return 0;
}
