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
    int n, t, m;
    cin >> n >> t >> m;
    map<int, vector<int>> mp;
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }

    int res = 0;
    vector<set<int>> teams;
    auto dfs = [&](int v, auto dfs) -> void {
        if (v == n) {
            if (teams.size() == t) res++; 
            return;
        } 

        rep(i, 0, teams.size()) {
            bool flag = true;
            for (auto x : mp[v]) {
                if (teams.at(i).count(x)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                teams.at(i).insert(v); 
                dfs(v + 1, dfs);
                teams.at(i).erase(v); //dfsを抜けたら変数を元に戻す
            }
        }
        // setの初期化方法set<int>({1, 2, 3, ...})
        teams.push_back(set<int>({v}));
        dfs(v + 1, dfs);
        teams.pop_back();
    };

    dfs(0, dfs);
    cout << res << endl;
    return 0;
}