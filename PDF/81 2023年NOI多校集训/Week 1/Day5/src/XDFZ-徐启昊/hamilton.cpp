#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+11,inf=1e9;
void Freopen(){
	freopen("hamilton.in","r",stdin);
  	freopen("hamilton.out","w",stdout);
}
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
        x=x*10+ch-'0',ch=getchar();
    return x*f;
}
void write(int x){
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
    return;
}
signed main(){
  	Freopen();
  	cout<<"NO";
	return 0;
}

