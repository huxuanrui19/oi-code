#include<bits/stdc++.h>
using namespace std;
int a[int(1e5+10)];
void qs(int l,int r){
	if(l>=r) return; 
	int mid=a[l+(r-l)/2];
	int i=l,j=r;
	while(i<=j){
		while(a[i]<mid) ++i;
		while(a[j]>mid) --j;
		if(i<=j){
			swap(a[i],a[j]);
			++i;--j;
		}
	}
	qs(l,j);
	qs(i,r);
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	qs(1,n);
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
} 
