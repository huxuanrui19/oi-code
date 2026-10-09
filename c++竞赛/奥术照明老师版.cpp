#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,m,nn,nm,f[2*N][2*N];
char t;
bool check(int len){
	for(int j=1;j<=nm;j++){
		int cnt=0;
		for(int i=1;i<=nn;i+=2){
			if(f[i][j]>=len) cnt++;
			else cnt=0;
			if(cnt>=len) return true;
		}
		cnt=0;
		for(int i=2;i<=nn;i+=2){
			if(f[i][j]>=len) cnt++;
			else cnt=0;
			if(cnt>=len) return true;
		}
	}
	return false;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>t;
			if(t=='0') f[i-j+m][(i+j)/2]=1;
		}
	}
	nn=n+m;
	nm=(n+m)/2;
	for(int i=1;i<=nn;i++){
		for(int j=nm;j>=1;j--){
			if(f[i][j]) f[i][j]=f[i][j+1]+1;
		}
	}
	int l=0,r=nn,mid,ans=0;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans-1;
	return 0;
}
