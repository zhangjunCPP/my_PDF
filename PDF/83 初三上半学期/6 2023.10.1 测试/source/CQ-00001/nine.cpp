//the code is from chenjh
#include<bits/stdc++.h>
using namespace std;
int k,x,y;
using ci=const int;
inline int dis(ci x,ci y,ci xx,ci yy){return abs(x-xx)+abs(y-yy);}
int main(){
	freopen("nine.in","r",stdin);
	freopen("nine.out","w",stdout);
	scanf("%d%d%d",&k,&x,&y);
	int d=dis(0,0,x,y);
	if(!(d%k)){
		printf("%d\n",d/k+1);
		int nx=0,ny=0;
		if(nx>x){
			for(;nx>=x;nx-=k)printf("%d %d\n",nx,ny);
			nx+=k;
		}
		else{
			for(;nx<=x;nx+=k)printf("%d %d\n",nx,ny);
			nx-=k;
		}
		int tmp=k-abs(x-nx);
		nx=x;
		ny+=y>0?tmp:-tmp;
		if(ny>y){
			for(;ny>=y;ny-=k)printf("%d %d\n",nx,ny);
//			ny+=k;
		}
		else{
			for(;ny<=y;ny+=k)printf("%d %d\n",nx,ny);
//			ny-=k;
		}
		return 0;
	}
	if(!(k&1) && (d&1)) return puts("-1"),0;
	int t,p,q,pq;
	for(t=max((d+k-1)/k,2);;t++){
		if((((long long)k*t)&1)!=(d&1)) ++t;
		pq=((long long)k*t+d)>>1;
		p=abs(x),q=pq-p;
		if(p>=abs(x) && q>=abs(y)) break;
	}
//	printf("%d %d\n",p,q);
	p=pq>>1,q=pq-p;
	if(q<abs(y)) p-=abs(y)-q,q=abs(y);
	if(p<abs(x)) q-=abs(x)-p,p=abs(x);
	printf("%d\n",t);
	int fx,fy;
//	printf("%d %d %d %d\n",p,q,fx,fy);
	if(x>=0){
		if(y>=0){
			fx=x-p,fy=q;
			int nx=0,ny=0;
			nx-=k;
			for(;nx>=fx;nx-=k)printf("%d %d\n",nx,ny);
			nx+=k;
			int tmp=k-abs(fx-nx);
			nx=fx,ny+=tmp;
			for(;ny<=fy;ny+=k)printf("%d %d\n",nx,ny);
			ny-=k;
			tmp=k-abs(fy-ny);
			ny=fy,nx+=tmp;
			for(;nx<=x;nx+=k)printf("%d %d\n",nx,ny);
			nx-=k;
			tmp=k-abs(x-nx);
			nx=x,ny-=tmp;
			for(;ny>=y;ny-=k)printf("%d %d\n",nx,ny);
		}
		else{
			fx=x-p,fy=-q;
			int nx=0,ny=0;
			nx-=k;
			for(;nx>=fx;nx-=k)printf("%d %d\n",nx,ny);
			nx+=k;
			int tmp=k-abs(fx-nx);
			nx=fx,ny-=tmp;
			for(;ny>=fy;ny-=k)printf("%d %d\n",nx,ny);
			ny+=k;
			tmp=k-abs(fy-ny);
			ny=fy,nx+=tmp;
			for(;nx<=x;nx+=k)printf("%d %d\n",nx,ny);
			nx-=k;
			tmp=k-abs(x-nx);
			nx=x,ny+=tmp;
			for(;ny<=y;ny+=k)printf("%d %d\n",nx,ny);
		}
	}
	else{
		if(y>=0){
			fx=x+p,fy=q;
//			printf("%d %d\n",fx,fy);
			int nx=0,ny=0;
			nx+=k;
			for(;nx<=fx;nx+=k)printf("%d %d\n",nx,ny);
			nx-=k;
			int tmp=k-abs(fx-nx);
			nx=fx,ny+=tmp;
			for(;ny<=fy;ny+=k)printf("%d %d\n",nx,ny);
			ny-=k;
			tmp=k-abs(fy-ny);
			ny=fy,nx-=tmp;
			for(;nx>=x;nx-=k)printf("%d %d\n",nx,ny);
			nx-=k;
			tmp=k-abs(x-nx);
			nx=x,ny-=tmp;
			for(;ny>=y;ny-=k)printf("%d %d\n",nx,ny);
		}
		else{
			fx=x+p,fy=-q;
			int nx=0,ny=0;
			nx-=k;
			for(;nx>=fx;nx-=k)printf("%d %d\n",nx,ny);
			nx+=k;
			int tmp=k-abs(fx-nx);
			nx=fx,ny-=tmp;
			for(;ny>=fy;ny-=k)printf("%d %d\n",nx,ny);
			ny+=k;
			tmp=k-abs(fy-ny);
			ny=fy,nx+=tmp;
			for(;nx<=x;nx+=k)printf("%d %d\n",nx,ny);
			nx-=k;
			tmp=k-abs(x-nx);
			nx=x,ny+=tmp;
			for(;ny<=y;ny+=k)printf("%d %d\n",nx,ny);
		}
	}
	return 0;
}

