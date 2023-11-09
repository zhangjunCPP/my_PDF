#include <bits/stdc++.h>

using namespace std;

int n, k;

#define speedup() {ios::sync_with_stdio(false); cin.tie(nullptr), cout.tie(nullptr);}

int main() {
    #ifndef DEBUG
    freopen("dice.in", "r", stdin);
    freopen("dice.out", "w", stdout);
    #endif
    speedup();
    cin>>n>>k;
    if (n==1) {
        cout<<"Yes\n";
        for (int i=1; i<=6; ++i)
            cout<<k*i<<' ';
        return 0;
    }
    if (1<<int(log2(k))==k) {
        cout<<"Yes\n";
        int start=k, d=k/2;
        for (int i=1; i<=(n/2)*2; ++i) {
            for (int j=0; j<6; ++j) {
                cout<<d*(start+j*k-1)<<' ';
            }
            cout<<'\n';
            start+=k;
        }
        if (n&1) {
            for (int j=0; j<6; ++j) {
                cout<<d*(start+j*k)<<' ';
            }
        }
        return 0;
    }
    else {
        puts("No");
    }
    return 0;
}