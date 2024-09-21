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
    int n;
    cin >> n;
    vector<int> event;
    vector<int> cnts(n + 1);
    vector<bool> ans;
    int now, max;
    rep(i, 0, n) {
        int t, x;
        cin >> t >> x;
        if (t == 1)  event.push_back(x);
        else event.push_back(-x);
    }
    reverse(event.begin(), event.end());
    now = 0;
    max = 0;
    for (int x: event) {
        if (x > 0) {
            if (cnts[x]) {
                cnts[x]--;
                now--;
                ans.push_back(1);
            } else {
                ans.push_back(0);
            }
        } else {
            cnts[-x]++;
            now++;
        }
        chmax(max, now);
    }
    if (now > 0) cout << -1 << "\n";
    else {
        cout << max << "\n";
        reverse(ans.begin(), ans.end());
        for (int x: ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
