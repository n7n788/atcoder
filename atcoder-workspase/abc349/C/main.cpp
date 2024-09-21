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

const string YES = "Yes";
const string NO = "No";

void solve(string S, string T) {
    int n = S.size();
    REP(i, n) S.at(i) = toupper(S.at(i));

    if (T.back() == 'X') T.pop_back();

    int j = 0;
    REP(i, n) {
        if (S.at(i) == T.at(j)) j++;
        if (j >= T.size()) break;
    }

    cout << (j >= T.size() ? YES : NO) << endl;
    return;
}
// bool is_subseq(string S, string T) {
//     int i = 0;
//     for (char c: S) {
//         if (c == T.at(i)) i++;
//         if (i == T.size()) return true;
//     }
//     return false;
// }

// void solve(std::string S, std::string T){
//     int n = S.size();
//     for (char& c: S) c = toupper(c);
//     if (T.back() == 'X') T.pop_back();

//     cout << (is_subseq(S, T) ? "Yes" : "No") << endl;
//     return; 
// }

// Generated by 2.13.0 https://github.com/kyuridenamida/atcoder-tools  (tips: You use the default template now. You can remove this line by using your custom template)
int main(){
        std::string S;
    std::cin >> S;
    std::string T;
    std::cin >> T;
        solve(S, T);
        return 0;
}
