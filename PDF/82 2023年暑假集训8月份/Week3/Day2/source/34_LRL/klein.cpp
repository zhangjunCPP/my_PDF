#include<bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
int n,q,sx,sy,ex,ey,ans;
//bool check(int sx,int sy,int ex,int ey){
//	if((sx>ex&&sy>ey)||(sx<=ex&&sy<=ey))return 1;
//	return 0;
//}
void solve(int sx,int sy,int ex,int ey,int pre){
	if(sx>=ex&&sy>=ey)swap(sx,ex),swap(sy,ey);
	/*if(sx<=ex&&sy<=ey)*/ans=std::min(ans,pre+abs(sx-ex)+abs(sy-ey));
	if(sx>ex&&sy<=ey)swap(sx,ex),swap(sy,ey);
	int cx=n,cy=n-sy;
	/*if(check(cx,cy,ex,ey))*/ans=std::min(ans,pre+sx+1+abs(cx-ex)+abs(cy-ey));
	cx=0,cy=n-ey;
	/*if(check(cx,cy,sx,sy))*/ans=std::min(ans,pre+n-ex+1+abs(cx-sx)+abs(cy-sy));
	if(sy<=ey){
		cx=sx,cy=n;
		/*if(check(cx,cy,ex,ey))*/ans=std::min(ans,pre+sy+1+abs(cx-ex)+abs(cy-ey));
		cx=ex,cy=0;
		/*if(check(cx,cy,sx,sy))*/ans=std::min(ans,pre+n-ey+1+abs(cx-sx)+abs(cy-sy));
	}else{
		cx=sx,cy=0;
		/*if(check(cx,cy,ex,ey))*/ans=std::min(ans,pre+n-sy+1+abs(cx-ex)+abs(cy-ey));
		cx=ex,cy=n;
		/*if(check(cx,cy,sx,sy))*/ans=std::min(ans,pre+ey+1+abs(cx-sx)+abs(cy-sy));
	}
}
int main(){
	freopen("klein.in","r",stdin);
	freopen("klein.out","w",stdout);
	n=read(),q=read();
	while(q--){
		sx=read(),sy=read(),ex=read(),ey=read(),ans=1e9;
		if(sx>=ex&&sy>=ey)swap(sx,ex),swap(sy,ey);
		/*if(sx<=ex&&sy<=ey)*/ans=std::min(ans,abs(sx-ex)+abs(sy-ey));
		if(sx>ex&&sy<=ey)swap(sx,ex),swap(sy,ey);
		solve(sx,sy,ex,ey,0);
		if(sy<=ey){
			int cx=sx,cy=n;
			solve(cx,cy,ex,ey,sy+1);
			cx=ex,cy=0;
			solve(sx,sy,cx,cy,n-ey+1);
		}else{
			int cx=sx,cy=0;
			solve(cx,cy,ex,ey,n-sy+1);
			cx=ex,cy=n;
			solve(sx,sy,cx,cy,ey+1);
		}
		int cx=n,cy=n-sy;
		solve(cx,cy,ex,ey,sx+1);
		cx=0,cy=n-ey;
		solve(sx,sy,cx,cy,n-ex+1);
		printf("%d\n",ans);
	}
	return 0;
}
