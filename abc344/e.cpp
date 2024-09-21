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

int main()
{
    int n, q;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a.at(i);
    unordered_map<int, P> mp;
    unordered_set<int> st;
    rep(i, 0, n) {
        st.insert(a.at(i));
        int l = -1, r = -2;
        if (i != 0) l = a.at(i - 1);
        if (i != n - 1) r = a.at(i + 1);
        mp[a.at(i)] = P{l, r};
    }
    int start = a.at(0);
    cin >> q;
    rep(qi, 0, q) {
        int type;
        cin >> type;
        // for (auto [key, val]: mp) {
        //     cout << key << " (" << val.first << " " << val.second << "), ";
        // }
        // cout << "\n";
        // for (auto x: st) cout << x << " ";
        // cout << "\n";
        switch (type)
        {
        case 1:
            {
                int x, y;
                cin >> x >> y;
                st.insert(y);
                int next = mp[x].second;
                mp[y] = P{x, next};
                mp[x] = P{mp[x].first, y};
                if (next != -2) mp[next] = P{y, mp[next].second};
            }
            break;
        case 2:
            {
                int x;
                cin >> x;
                st.erase(x);
                int prev = mp[x].first;
                int next = mp[x].second;
                if (prev != -1) mp[prev] = P{mp[prev].first, next};
                else start = next;
                if (next != -2) mp[next] = P{prev, mp[next].second};
                // mp[x] = P{0, 0};
                mp.erase(mp.find(x));
                break;
            }
        }
        // cout << "start = " << start << "\n";
    }
    int x = start;
    while (x != -2) {
        cout << x << " ";
        x = mp[x].second;
        if ( x == 0) return 0;
    }
    cout << "\n";
    return 0;
}