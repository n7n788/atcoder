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
    int n, m;
    cin >> n >> m;
    vector<int> p(n), c(n);
    vector f(n, set<int>());
    rep(i, 0, n) {
        cin >> p.at(i) >> c.at(i);
        rep(j, 0, c.at(i)) {
            int f1;
            cin >> f1;
            f.at(i).insert(f1);
        }
    }

    rep(i, 0, n) rep(j, 0, n) {
        if (p.at(i) <= p.at(j)) {
            bool flag = true;
            for (auto it = f.at(j).begin(); it != f.at(j).end(); it++) {
                if (f.at(i).count(*it) == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                if ((f.at(i).size() > f.at(j).size()) || 
                    p.at(i) < p.at(j)) {
                        cout << "Yes" << endl;
                        // cout << i << " " << j << endl;
                        return 0;
                    }  
            }
        }
    }
    cout << "No" << endl;
    return 0;
}