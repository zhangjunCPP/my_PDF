#include <cstdio>
int Ch;
template<typename T>
inline void r(T&x){
	while((Ch=getchar())<48);
	x=Ch&15;
	while((Ch=getchar())>47)x=(x<<1)+(x<<3)+(Ch&15);
}
inline int r(char*x){
    char*st=x;
    while((*x=getchar())<33);
    while((*++x=getchar())>32);
    *x=0;
    return x-st;
}
template<typename T>
void w(T&&x){
	if(9<x)w(x/10);
	putchar(x%10|48);
}
using ll=unsigned long long;
constexpr int N=200010,P1=131,P2=29;
int k,n,T,m,L,R,mid,ans,i;
ll H1_[N],H2_[N],*H1=H1_+1,*H2=H2_+1,p1[N],p2[N],H3_[N],H4_[N],*H3=H3_+1,*H4=H4_+1;
char s[N],t[N];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	r(k);
    n=r(s);
    *H1=*H2=*s^96;
    *p1=*p2=1;
    for(i=1;i<n;i++){
        H1[i]=H1[i-1]+(p1[i]=p1[i-1]*P1)*(s[i]^96);
        H2[i]=H2[i-1]+(p2[i]=p2[i-1]*P2)*(s[i]^96);
    }
    r(T);
    while(T--){
        m=r(t);
        ans=0;
        if(m>n){
            w(0);
            putchar(10);
            continue;
        }
        *H3=*H3=*t^96;
        for(i=1;i<m;i++){
            H3[i]=H3[i-1]+p1[i]*(t[i]^96);
            H4[i]=H4[i-1]+p2[i]*(t[i]^96);
        }
        for(i=0;i+m<=n;i++){
            L=0;R=m;
            while(L<R){
                mid=L+R>>1;
                if(H3[mid]*p1[i]==H1[i+mid]-H1[i-1]&&H4[mid]*p2[i]==H2[i+mid]-H2[i-1])L=mid+1;
                else R=mid;
            }
            if(L+k>=m||(H3[m-1]-H3[L+k-1])*p1[i]==H1[i+m-1]-H1[i+L+k-1]&&(H4[m-1]-H4[L+k-1])*p2[i]==H2[i+m-1]-H2[i+L+k-1])ans++;
        }
        w(ans);
        putchar(10);
    }
	return 0;
}