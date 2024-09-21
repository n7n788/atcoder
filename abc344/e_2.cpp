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

// 双方向リストの実装
struct Node {
    int pre, nxt;
    Node(int pre = -1, int nxt = -1): pre(pre), nxt(nxt) {}
};

struct List {
    unordered_map<int, Node> nodes;
    int head, tail;
    List(): head(-INF), tail(INF) {
        // 先頭と末尾に番兵を用意
        nodes[head] = Node(-1, tail);
        nodes[tail] = Node(head, -1);
    }
    void erase(int x) {
        Node a = nodes[x];
        nodes.erase(x);
        nodes[a.pre].nxt = a.nxt;
        nodes[a.nxt].pre = a.pre;
        // cout << "erase: " << a.pre << ", " << x << ", " << a.nxt << "\n";
        // cout << nodes[a.pre].nxt << "\n";
    }
    void add(int x, int y ){
        int z = nodes[x].nxt;
        nodes[x].nxt = y;
        nodes[z].pre = y;
        nodes[y] = Node(x, z);
    }
    void print() {
        int i = nodes[head].nxt;
        while (i != tail) {
            cout << i << ' ';
            i = nodes[i].nxt;
            // if (i == -1) {
            //     cout << "-1 error\n";
            //     return;
            // }
        }
        cout << "\n";
    }
};

int main()
{
    int n, q;
    cin >> n;
    List d;
    {
        int now = d.head;
        rep(i, 0, n) {
            int a;
            cin >> a;
            d.add(now, a);
            now = a;
        }
    }
    cin >> q;
    rep(qi, 0, q) {
        // d.print();
        int type, x;
        cin >> type >> x;
        if (type == 1) {
            int y;
            cin >> y;
            d.add(x, y);
        } else {
            d.erase(x);
        }
    }
    d.print();
    return 0;
}