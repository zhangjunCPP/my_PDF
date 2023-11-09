#include <cstdio>
#include <initializer_list>
constexpr int N=1000010;
int Ch,T,n,m,i,cnt[N],x[N],y[N],ans,to[N][2];
template<typename T>
inline void r(T&x){
	while((Ch=getchar())<48);
	x=Ch&15;
	while((Ch=getchar())>47)x=(x<<1)+(x<<3)+(Ch&15);
}
template<typename...Ar>
inline void r(Ar&&...x){std::initializer_list<int>{(r(x),0)...};}
template<typename T>
void w(T&&x){
	if(9<x)w(x/10);
	putchar(x%10|48);
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	r(T);
	while(T--){
		__builtin_memset(cnt+1,0,n<<2);
		r(n,m);
		ans=0;
		for(i=0;i<m;i++){
			r(x[i],y[i]);
			cnt[x[i]]++;
			cnt[y[i]]++;
		}
		for(i=1;i<=n;i++)if(cnt[i]>ans)ans=cnt[i];
		if(ans==2){
			__builtin_memset(cnt+1,0,n<<2);
			for(i=0;i<m;i++){
				to[x[i]][cnt[x[i]]++]=y[i];
				to[y[i]][cnt[y[i]]++]=x[i];
			}
			for(i=1;i<=n;i++)
				if(cnt[i]==2){
					Ch=to[i][0];
					if(cnt[Ch]==2){
						// printf("114:%d %d\n",i,Ch);
						if(to[Ch][0]!=i){
							if(cnt[to[Ch][0]]==2&&(to[to[Ch][0]][0]==i||to[to[Ch][0]][1]==i)){
								// printf("%d %d\n",to[Ch][0],to[Ch][1]);
								ans++;
								break;
							}
						}
						else if(cnt[to[Ch][1]]==2&&(to[to[Ch][1]][0]==i||to[to[Ch][1]][1]==i)){
							// printf("%d\n",to[Ch][1]);
							ans++;
							break;
						}
					}
				}
		}
		w(ans);
		putchar(10);
	}
	return 0;
}