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
using mint = modint998244353;

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

ll c2(ll x) 
{
    return x * (x - 1) / 2;
}

// void solve(long long N, std::vector<std::string> S)
// {
//     unordered_map<string, ll> mp;
//     ll ans;

//     REP(i, N) {
//         REP(j, S.at(i).size()) {
//             mp[S.at(i).substr(0, j + 1)]++;
//         }
//     }
//     ans = 0;
//     for (auto [pre, cnt]: mp) {
//         printf("pre, cnt = %s, %lld\n", pre.c_str(), cnt);
//         ans += c2(cnt);
//     }
//     cout << ans << endl;
//     return;
// }

// Trie木を実装
// struct Trie {
//     struct Node {
//         map<char, int> to;
//         int cnt;
//         Node() : cnt(0) {}
//     };
//     vector<Node> d;
//     ll ans;

//     Trie() : d(1) {}
//     void add(const string& s) {
//         int v = 0;
//         for (char c: s) {
//             if (!d[v].to.count(c)) {
//                 d[v].to[c] = d.size(); // 頂点番号
//                 d.push_back(Node());
//             }
//             v = d[v].to[c];
//         }
//         d[v].cnt++;
//     }


//     ll dfs(int v) {
//         int res = d[v].cnt;
//         for (auto p: d[v].to) {
//             res += dfs(p.second);
//         }
//         if (v) ans += c2(res);
//         return res;
//     }

//     ll solve() {
//         ans = 0;
//         dfs(0);
//         return ans;
//     };
// };

class Trie {

    class Node {
        public:
            map<char, int> to;
            int cnt;
        Node() : cnt(0) {};
    };

    private:
        vector<Node> d;
        ll ans;

        // 文字列sに対応する頂点番号を返す
        int getV(const string& s)
        {
            int v = 0;
            for (char c: s) {
                if (!d.at(v).to.count(c)) return -1;
                v = d.at(v).to[c];
            }
            return v;
        }

        int dfs(int v)
        {
            int res = d.at(v).cnt;
            for (auto [c, u]: d.at(v).to) {
                res += dfs(u);
            }
            if (v) ans += c2(res);
            return res;
        }
    
    public:
        Trie() : d(1) {};

        void add(const string& s) 
        {
            int v = 0;
            for (char c: s) {
                if (!d.at(v).to.count(c)) {
                    d.at(v).to[c] = d.size();
                    d.push_back(Node());
                }
                v = d.at(v).to[c];
            }
            d[v].cnt++;
        }

        bool find(const string& s)
        {
            int v = getV(s);
            return (v != -1) && d.at(v).cnt > 0;
        }

        bool remove(const string& s) 
        {
            int v = getV(s);
            if (v != -1 && d.at(v).cnt > 0) {
                d.at(v).cnt--;
                return true;
            } else return false;
        }
            
        ll solve()
        {
            ans = 0;
            dfs(0);
            return ans;
        }
};

void solve(ll N, vs S) 
{
    Trie t;
    ll ans;
    REP(i, N) {
        t.add(S.at(i));
    }

    // vs test = {"a", "ab", "abc", "addd"};
    // for (auto s: test) {
    //     cout << s << (t.find(s) ? " is found" : " is not found") << endl;
    // }
    // t.remove("ab");
    // for (auto s: test) {
    //     cout << s << (t.find(s) ? " is found" : " is not found") << endl;
    // }
    // t.remove("a");
    // for (auto s: test) {
    //     cout << s << (t.find(s) ? " is found" : " is not found") << endl;
    // }
    // t.remove("a");
    // for (auto s: test) {
    //     cout << s << (t.find(s) ? " is found" : " is not found") << endl;
    // }
    ans = t.solve();
    cout << ans << endl;
    // t.print();
    return;
}

// Generated by 2.13.0 https://github.com/kyuridenamida/atcoder-tools  (tips: You use the default template now. You can remove this line by using your custom template)
int main()
{
        long long N;
    std::scanf("%lld", &N);
    std::vector<std::string> S(N);
    for(int i = 0 ; i < N ; i++){
        std::cin >> S[i];
    }
        solve(N, std::move(S));
        return 0;
}
