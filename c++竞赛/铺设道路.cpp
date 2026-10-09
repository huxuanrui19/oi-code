#include<bits/stdc++.h>
using namespace std;
long long ans=-0,a[100005];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	ans+=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]>a[i-1]){
			ans+=a[i]-a[i-1];
		}
	}
	cout<<ans;
	return 0;
} 
