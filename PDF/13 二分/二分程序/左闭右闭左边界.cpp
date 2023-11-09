#include <bits/stdc++.h>
using namespace std;
int a[10000001]={1,2,2,2,3};
int main()
{
	int k=2,n;
	n=5;
  	int left = 0, right = n- 1;  //左闭右闭
	while (left <= right) { // 注意<=
		int mid = left + (right - left) / 2;
		if (a[mid] < k) {
	    	left = mid + 1;
		} 
	  	else if (a[mid] > k) {
	        right = mid - 1;
	    } 
	  	else if (a[mid] == k) {
	        right = mid - 1; // 锁定左侧边界
	    }
	}
	      // 最后要检查 left 越界的情况
	if (left >= n|| a[left] != k)  {cout<<-1<<endl;return 0;}
	cout<<left;
    return 0;
}
