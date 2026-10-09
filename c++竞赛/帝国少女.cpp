#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n,m,a[N];
int kkk(int l,int r){
	if(l==r) return 0;
	int cnt=0,cur=a[l],len=1;
	for(int i=l+1;i<=r;i++){
		if(a[i]==cur){
			len++;
		}
		else{
			cnt+=(len-1)/2;
			cur=a[i];
			len++; 
		}
	}
	cnt+=(len-1)/2;
	return cnt;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ans+=1ll*kkk(i,j);
		}
	}
	cout<<ans;
	return 0;
}

