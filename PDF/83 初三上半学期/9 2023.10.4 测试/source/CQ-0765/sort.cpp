#include<bits/stdc++.h>
using LL = long long;
LL p;
const int maxn = 5e6 + 10;
int n;
int a[maxn], topa;
int s1[maxn], top1;
int s2[maxn], top2;
int b[maxn], topb;
bool dfs() {
    if (topb == n) {
        for (int i = 1; i <= n; i++)
            if (b[i] != n - i + 1) return false;
        return true; 
    }
    if (topa && (! top1 || a[topa] < s1[top1])) {
        int x = a[topa];
        topa--, s1[++top1] = x;
        if (dfs()) return true;
        a[++topa] = x, top1--;
    }
    if (top1) {
        int x = s1[top1];
        top1--, s2[++top2] = x;
        if (dfs()) return true;
        s1[++top1] = x, top2--;
    }
    if (top2) {
        int x = s2[top2];
        top2--, b[++topb] = x;
        if (dfs()) return true;
        s2[++top2] = x, topb--;
    }
    return false;
}
void solve() {
    scanf("%d%lld", &n, &p);
    for (int i = 1; i <= n; i++) a[i] = i;
    int cnt = 0;
    do {
        topa = n, top1 = top2 = topb = 0;
        if (! dfs()) cnt++;
    } while (std::next_permutation(a + 1, a + n + 1));
    printf("%d\n", cnt);
}
int main() {
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (; T; T--) solve();
    return 0;
}