#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define lowbit(i) i&(-i)
#define i64 __int128
const int N = 5e5+5;
ll n,a[N],V,b[N],len,ans;
ll f[N][2],g[N][2],h[N][2];
bool calc(ll l,ll r){
	f[0][0] = 1;
	for(int i=1;i<=n;i++){
		f[i][0] = (l<=a[i] && a[i]<=r)&(f[i-1][0]|f[i-1][1]);
		if(i>1) f[i][1] = (l<=a[i]+a[i-1] && a[i]+a[i-1]<=r)&(f[i-2][0]|f[i-2][1]);
	}
	return f[n][0] | f[n][1];
}
bool check1(ll mid){
	for(int id=1;id<=len;id++) if(calc(b[id],b[id]+mid)) return 1;
	return 0;
}
bool check2(ll mid){
	//g(i,0):�ֱ����0,1���㣬Ȼ��ȡ���� 
	//g(i-1,0)<=a[i]<=g(i-1,0)+mid: g(i,0) = g(i-1,0)
	//a[i]<g(i-1,0):��
	//g(i-1,0)+mid<a[i]:��a[i]-mid�Ƿ������[g,h]�������
	//g(i,1):
	//(i-1)->(i-2)
	//a[i]->(a[i]+a[i-1]) 
	//h(i,0):
	//h(i-1,0)-mid<=a[i]<=h(i-1,0): h(i,0) = h(i-1,0)
	//a[i]>h(i-1,0):��
	//����a[i]<h(i-1,0)-mid��a[i]+mid�Ƿ�����[g,h]
	g[0][0] = 0,h[0][0] = b[len]+1;
	g[0][1] = b[len]+1,h[0][1] = 0;
	for(int i=1;i<=n;i++){
		ll l1,r1,l2,r2;
		g[i][1] = g[i][0] = b[len]+1, h[i][1] = h[i][0] = 0;
		l1 = g[i-1][0],r1 = h[i-1][0],l2 = g[i-1][1],r2 = h[i-1][1];
		
		if(a[i]<l1) l1=g[0][1],r1=h[0][1];
		else if(a[i]>l1+mid){
			if(a[i]-mid<=r1) l1 = a[i]-mid;
			else l1=g[0][1],r1=h[0][1];
		}
		
		if(a[i]<l2) l2=g[0][1],r2=h[0][1];
		else if(a[i]>l2+mid){
			if(a[i]-mid<=r2) l2 = a[i]-mid;
			else l2=g[0][1],r2=h[0][1];
		}
		
		if(a[i]>r1)  l1=g[0][1],r1=h[0][1];
		else if(a[i]<r1-mid){
			if(a[i]+mid>=l1) r1 = a[i]+mid;
			else l1=g[0][1],r1=h[0][1];
		}
		
		if(a[i]>r2)  l2=g[0][1],r2=h[0][1];
		else if(a[i]<r2-mid){
			if(a[i]+mid>=l2) r2 = a[i]+mid;
			else l2=g[0][1],r2=h[0][1];
		}
		
		if(l1<=r1) g[i][0] = l1,h[i][0] = r1;
		if(l2<=r2) g[i][0] = min(g[i][0],l2),h[i][0] = max(h[i][0],r2);
		
		if(i==1) continue;
		
		l1 = g[i-2][0],r1 = h[i-2][0],l2 = g[i-2][1],r2 = h[i-2][1];
		
		if(a[i]+a[i-1]<l1) l1=g[0][1],r1=h[0][1];
		else if(a[i]+a[i-1]>l1+mid){
			if(a[i]+a[i-1]-mid<=r1) l1 = a[i]+a[i-1]-mid;
			else l1=g[0][1],r1=h[0][1];
		}
		
		if(a[i]+a[i-1]<l2) l2=g[0][1],r2=h[0][1];
		else if(a[i]+a[i-1]>l2+mid){
			if(a[i]+a[i-1]-mid<=r2) l2 = a[i]+a[i-1]-mid;
			else l2=g[0][1],r2=h[0][1];
		}
		
		if(a[i]+a[i-1]>r1)  l1=g[0][1],r1=h[0][1];
		else if(a[i]+a[i-1]<r1-mid){
			if(a[i]+a[i-1]+mid>=l1) r1 = a[i]+a[i-1]+mid;
			else l1=g[0][1],r1=h[0][1];
		}
		
		if(a[i]+a[i-1]>r2)  l2=g[0][1],r2=h[0][1];
		else if(a[i]+a[i-1]<r2-mid){
			if(a[i]+a[i-1]+mid>=l2) r2 = a[i]+a[i-1]+mid;
			else l2=g[0][1],r2=h[0][1];
		}
		if(l1<=r1) g[i][1] = l1,h[i][1] = r1;
		if(l2<=r2) g[i][1] = min(g[i][1],l2),h[i][1] = max(h[i][1],r2);
	}
	ll al = min(g[n][1],g[n][0]),ar = max(h[n][1],h[n][0]);
	if(al>ar) return 0;
	int i = lower_bound(b+1,b+1+len,al)-b,j = upper_bound(b+1,b+1+len,ar)-b-1;
	return ((1<=i && i<=len) && (1<=j && j<=len) && (i-j+1>0));
}
int main(){
	freopen("ex_segment4.in","r",stdin);
//	freopen("segment.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i],V = max(V,a[i]);
	for(int i=1;i<=n;i++) b[++len] = a[i];
	for(int i=1;i<n;i++) b[++len] = a[i]+a[i+1];
	sort(b+1,b+1+len); 
	len = unique(b+1,b+1+len)-b-1;
	if(V<=10 || n<=2000){
		ll l = 0,r = b[len];
		while(l<=r){
			ll mid = (l+r)>>1;
			if(check1(mid)) ans = mid,r = mid-1;
			else l = mid+1;
		}
	}else{
		ll l = 0,r = b[len];
		while(l<=r){
			ll mid = (l+r)>>1;
			if(check2(mid)) ans = mid,r = mid-1;
			else l = mid+1;
		}
	}
	cout << ans;
	return 0;
}
//80pts:
//���֣�Ȼ���ж���
//���ʲ�ͬ���½�����3*n�� ��ö���½磬Ȼ��f(i,0/1)�ж���
//f(i,0) = (<=a[i]<=)(f(i,0)|f(i,1));
//f(i,1) = (<=a[i]+a[i-1]<=)(f(i-2,0)); 
//O(n^2logn)
//���߿���������֣�
//��֪���dp�½硣
//�ֱ�dp�½���Сֵ�����
//Ȼ���ж��м��Ƿ���ֵ�� 
//ͨ��������ֹ�����ȷ��
 
 
