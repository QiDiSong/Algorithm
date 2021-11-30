jingdong.c
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
struct node {
    int x;
    int y;
    node (int a, int b): x(a), y(b) {};
};

int main() {
    int n,m,x,y,z;
    cin >> n >> m >> x >> y >> z;   // x move y trans z click
    unordered_map<char, pair<int, int>> mmap;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            auto p = make_pair(i, j);
            mmap[c] = p;
        }
    }
    string target;
    cin >> target;
    int ans = target.size() * z;
    int ii = 0, jj = 0;
    for (int i = 0; i < target.size(); i++)
    {
        pair<int,int> pos = mmap[target[i]];
        int move = x * (abs(ii - pos.first) + abs (jj - pos.second));
        int trans = (ii == pos.first || jj == pos.second) ? 0 : y;
        ans += move + trans;
        ii = pos.first;
        jj = pos.second;
    }
    cout << ans << endl;

    return 0;
}
