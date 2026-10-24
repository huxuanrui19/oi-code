#include<bits/stdc++.h>
using namespace std;
int a[int(1e5+10)],b[int(1e5+10)],cnt=0;
void mer(int l,int mid,int r){
	int i=l,j=mid+1,t=0;
	while(i<=mid&&j<=r){
		if(a[i]>a[j]){
			b[t++]=a[j++];
			cnt+=mid-i+1;
		}
		else{
			b[t++]=a[i++];
		}
	}
	while(i<=mid) b[t++]=a[i++];
	while(j<=r) b[t++]=a[j++];
	for(int i=0;i<t;i++){
		a[l+i]=b[i];
	}
}
void ms(int l,int r){
	if(l<r){
		int mid=(l+r)>>1;
		ms(l,mid);
		ms(mid+1,r);
		mer(l,mid,r);
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ms(1,n);
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
} 
 
