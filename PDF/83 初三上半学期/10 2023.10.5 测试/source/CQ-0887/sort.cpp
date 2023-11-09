/*
C sort
直接手写一个快排不就知道了？
*/
#include<bits/stdc++.h>
using namespace std;
long long cmpcnt=0;
int a[700010];
int tmpl[700010],tmpr[700010];
void sort(int l,int r)
{
	if(l>=r)return;
	// printf("[%d,%d]\n",l,r);
	// for(int i=l;i<=r;i++)printf("%d ",a[i]);
	// putchar(10);
	int pivot=a[(int)(l+ceil((double)(r-l+1)/2)-1)];
	int lptr=0,rptr=0;
	for(int i=l;i<=r;i++)
	{
		cmpcnt++;
		if(a[i]<pivot)tmpl[++lptr]=a[i];
		if(a[i]>pivot)tmpr[++rptr]=a[i];
	}
	int i,j;
	for(i=l,j=1;j<=lptr;i++,j++)a[i]=tmpl[j];
	a[i]=pivot;
	for(i++,j=1;j<=rptr;i++,j++)a[i]=tmpr[j];
	sort(l,l+lptr-1),sort(r-rptr+1,r);
	return;
}
int main()
{
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	sort(1,n);
	printf("%lld",cmpcnt);
	return 0;
}