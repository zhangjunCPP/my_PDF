#include <bits/stdc++.h>

using namespace std;
int main(){
    freopen("dice.in","r",stdin);
    freopen("dice.out","w",stdout);
    int n,k;
    cin>>n>>k;
    if(n==1){
        puts("Yes");
        for(int i=1;i<=6;i++){
            cout<<i*k<<" ";
        }
        return 0;
    }
    if(k==2){
        puts("Yes");
        int tmp=2;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=6;j++){
                cout<<tmp<<" ";
                tmp+=2;
            }
            cout<<"\n";
        }
        return 0;
    }
    return 0;
}