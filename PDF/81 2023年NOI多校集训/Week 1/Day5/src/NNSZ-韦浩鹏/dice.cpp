#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("dice.in", "r", stdin);
    freopen("dice.out", "w", stdout);
    int n, k;
    cin>>n>>k;
    if(n==1){
        puts("Yes");
        for(int i=1;i<=6;++i)
            printf("%d ", i*k);
    }else if(k==2){
        puts("Yes");
        if(n%2){
            for(int i=1;i<n;++i){
                for(int j=1;j<=11;j+=2)
                    printf("%d ", j);
                puts("");
            }
            for(int i=2;i<=12;i+=2)
                printf("%d ", i);
        }else{
            for(int i=1;i<=n;++i){
                for(int j=1;j<=11;j+=2)
                    printf("%d ", j);
                puts("");
            }
        }
    }
    return 0;
}
