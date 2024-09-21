#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
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
#include <regex>
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


void solve(long long N, std::vector<std::vector<long long>> P, std::vector<std::vector<long long>> R, std::vector<std::vector<long long>> D){

}

// Generated by 2.13.0 https://github.com/kyuridenamida/atcoder-tools  (tips: You use the default template now. You can remove this line by using your custom template)
int main(){
        long long N;
    std::scanf("%lld", &N);
    std::vector<std::vector<long long>> P(N, std::vector<long long>(N));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            std::scanf("%lld", &P[i][j]);
        }
    }
    std::vector<std::vector<long long>> R(N, std::vector<long long>(N-1));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N-1 ; j++){
            std::scanf("%lld", &R[i][j]);
        }
    }
    std::vector<std::vector<long long>> D(N-1, std::vector<long long>(N));
    for(int i = 0 ; i < N-1 ; i++){
        for(int j = 0 ; j < N ; j++){
            std::scanf("%lld", &D[i][j]);
        }
    }
        solve(N, std::move(P), std::move(R), std::move(D));
        return 0;
}
