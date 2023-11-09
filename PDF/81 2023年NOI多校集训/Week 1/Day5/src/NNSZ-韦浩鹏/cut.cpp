#include<bits/stdc++.h>
using namespace std;
const int N=5e5+3;
int a[N], zero[N];
struct SegmentTree{
    int l, r, w;
} t[4*N];
void Build(int p, int l, int r){
    t[p].l=l, t[p].r=r;
    if(l==r){
        t[p].w=pow(2, a[l]);
        return ;
    }
    int mid=l+((r-l)>>1);
    Build(p<<1, l, mid), Build((p<<1)+1, mid+1, r);
    t[p].w=t[p<<1].w|t[(p<<1)+1].w;
}
int cnt;

int main(){
    freopen("cut.in", "r", stdin);
    freopen("cut.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i=1;i<=n;++i){
        scanf("%d", &a[i]);
        if(a[i]==0) zero[++cnt]=i;
    }
    Build(1, 1, n);
    cout<<cnt+1;
    return 0;
}

