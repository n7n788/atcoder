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
#include <string>
#include <algorithm>
#include <cstdlib>

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
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    int ans = INF;
    rep(i, 0, h) cin >> s.at(i);

    rep(i, 0, h) {
        int cnt = INF;
        rep (j, 0, w - k + 1) {
            if (cnt == INF) {
                cnt = 0;
                rep(l, 0, k) {
                    char c = s.at(i).at(j + l);
                    if (c == '.') cnt++;
                    else if (c == 'x') {
                        cnt = INF;
                        j += l;
                        break;
                    }
                }
            } else {
                char c0 = s.at(i).at(j - 1);
                char c1 = s.at(i).at(j + k - 1);
                if (c0 == '.' && c1 == 'o') cnt--;
                else if (c0 == 'o' && c1 == '.') cnt++;
                else if (c1 == 'x') {
                    cnt = INF;
                    j += k - 1;
                }
                
            }
            chmin(ans, cnt);
        }
    }

    rep(i, 0, w) {
        int cnt = INF;
        rep (j, 0, h - k + 1) {
            if (cnt == INF) {
                cnt = 0;
                rep(l, 0, k) {
                    char c = s.at(j + l).at(i);
                    if (c == '.') cnt++;
                    else if (c == 'x') {
                        cnt = INF;
                        j += l;
                        break;
                    }
                }
            } else {
                char c0 = s.at(j - 1).at(i);
                char c1 = s.at(j + k - 1).at(i);
                if (c0 == '.' && c1 == 'o') cnt--;
                else if (c0 == 'o' && c1 == '.') cnt++;
                else if (c1 == 'x') {
                    cnt = INF;
                    j += k - 1;
                }
                
            }
            chmin(ans, cnt);
        }
    }
          

    if (ans == INF) cout << -1 << "\n";
    else cout << ans << "\n";
    return 0;
}