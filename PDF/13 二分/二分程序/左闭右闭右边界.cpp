#include <bits/stdc++.h>
using namespace std;
int a[10000001]={1,2,2,2,3};
int main()
{
	int k=2,n;
	n=5;
  	int left = 0, right = n - 1;
	while (left <= right) {
	    int mid = left + (right - left) / 2;
	    if (a[mid] < k) {
	        left = mid + 1;
	    } 
	  	else if (a[mid] > k) {
	        right = mid - 1;
	    } 
	  	else if (a[mid] == k) {
	  	     left = mid + 1; // �����Ҳ�߽�
	        }
	    }
	      // ���Ҫ��� right Խ������
	if (right < 0 || a[right] != k) {cout<<-1<<endl;return 0;}
	cout<<right;
    return 0;
}
