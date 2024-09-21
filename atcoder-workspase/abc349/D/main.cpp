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

using P = pair<ll, ll>;
vector<P> Ans;

void dfs(ll l, ll r, ll L, ll R) 
{
    if (R <= l || r <= L) return;
    if (L <= l && r <= R) {
        Ans.emplace_back(l, r);
        return;
    }

    ll mid = (l + r) / 2;
    dfs(l, mid, L, R);
    dfs(mid, r, L, R);
}

void solve(ll L, ll R) 
{
    dfs(0, 1ll << 60, L, R);
    cout << Ans.size() << "\n";
    for (auto [l, r]: Ans) cout << l << " " << r << "\n";
    return;
}
// using p = pair<ll, ll>;
// vector<p> Ans;
// // [l, r): 今見ている区間
// // [L, R): 求めている区間
// void dfs(ll l, ll r, ll L, ll R) 
// {
//     // [l, r)が[L, R)に完全に含まれていれば, この区間を追加して終了
//     if (L <= l and r <= R) {
//         Ans.emplace_back(pair{l, r});
//         return;
//     }
//     // [l, r)が[L, R)に全く含まれていなければ、そのまま終了
//     else if (R <= l || r <= L) return;

//     // どちらでもない場合、区間を2つに分割して再帰
//     ll m = (l + r) / 2;
//     dfs(l, m, L, R);
//     dfs(m, r, L, R);
// }

// void solve(long long L, long long R)
// {
//     dfs(0, 1ll<<60, L, R);
//     cout << Ans.size() << "\n";
//     for (auto [l, r]: Ans) {
//         cout << l << " " << r << "\n";
//     }
// }

// using P = pair<ll, ll>;
// vector<P> Ans;

// void dfs(ll l, ll r, ll L, ll R) 
// {
//     if (R <= l || r <= L) return;
//     else if (L <= l && r <= R) {
//         Ans.emplace_back(l, r);
//         return;
//     } else {
//         ll m = (l + r) / 2;
//         dfs(l, m, L, R);
//         dfs(m, r, L, R);
//     }
// }

// void solve(ll L, ll R) 
// {
//     dfs(0, 1ll << 60, L, R);
    
//     cout << Ans.size() << "\n";
//     for (auto [l, r] : Ans) {
//         cout << l << " " << r << "\n";
//     }
//     return;
// }

// Generated by 2.13.0 https://github.com/kyuridenamida/atcoder-tools  (tips: You use the default template now. You can remove this line by using your custom template)
int main(){
        long long L;
    std::scanf("%lld", &L);
    long long R;
    std::scanf("%lld", &R);
        solve(L, R);
        return 0;
}
