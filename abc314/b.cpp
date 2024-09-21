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
    int n;
    cin >> n;
    vector<int> c(n);
    vector a(n, vector<int>());
    rep(i, 0, n) {
        cin >> c.at(i);
        rep(j, 0, c.at(i)) {
            int t;
            cin >> t;
            a.at(i).push_back(t);
        }
    }

    int x;
    cin >> x;

    vector<int> mins;

    rep(i, 0, n) {
        rep(j, 0, c.at(i)) {
            if (a.at(i).at(j) == x) {
                if (mins.size() == 0) {
                    mins.push_back(i);
                } else {
                    if (c.at(mins.at(0)) > c.at(i)) {
                        mins = vector<int>();
                        mins.push_back(i);
                    } else if(c.at(mins.at(0)) == c.at(i)) {
                        mins.push_back(i);
                        // cout << i << ' ' << c.at(mins.at(0)) << ',' << c.at(i) << endl;
                    }
                } 
            }
        }
    }
    sort(mins.begin(), mins.end());
    cout << mins.size() << endl;
    rep(i, 0, mins.size()){
        cout << mins.at(i) + 1 << ' ';
    }
    cout << endl;
    return 0;
}