#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
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
template <typename T> bool chmin(T &a, const T& b) {if (a > b) {a = b; return true;} return false;}
template <typename T> bool chmax(T &a, const T& b) {if (a < b) {a = b; return true;} return false;}

typedef pair<int, int> P;
typedef long long ll;
const int INF = 1 << 30;
const ll INF_ll = 1ll << 60;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    // ランレングス圧縮
    unordered_map<char, int> mp;
    int l = 0;
    while (l < n) {
        int r = l + 1;
        while (r < n && s.at(l) == s.at(r)) r++;
        chmax(mp[s.at(l)], r - l);
        l = r;
    }
    int ans = 0;
    for (auto [key, val]: mp) {
        ans += val;
    }
    cout << ans << "\n";
    return 0;
}