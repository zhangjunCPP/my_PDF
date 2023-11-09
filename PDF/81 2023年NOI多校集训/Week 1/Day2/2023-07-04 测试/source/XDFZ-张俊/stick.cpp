//
// Created by zhang_jun on 2023/7/4.
//
#include <bits/stdc++.h>

using namespace std;
int main(){
    freopen("stick.in","r",stdin);
    freopen("stick.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        if(n==1){
            if(m==0) cout<<"1\n";
            else cout<<"0\n";
        }
        else if(n==2){
            if(m==0||m==1) cout<<"1\n";
            else cout<<"0\n";
        }
        else if(n==3){
            if(m==0||m==2||m==3) cout<<"1\n";
            else cout<<"0\n";
        }
        else if(n==4){
            if(m==0||m==3||m==4||m==5||m==6) cout<<"1\n";
            else cout<<"0\n";
        }
        else if(n==5){
            if(m==0||m==4||m==6||m==7||m==8||m==9||m==10) cout<<"1\n";
            else cout<<"0\n";
        }
        else{
            cout<<"0\n";
        }
    }
}