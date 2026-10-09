#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int ans,tmp,l,r,le[N],ri[N]; 
int main()
{
	int n;
	cin>>n>>l>>r;
	for(int i=1;i<=l;i++){
		cin>>tmp;
		le[tmp]++;
	}
	for(int i=1;i<=r;i++){
		cin>>tmp;
		ri[tmp]++;
	}
	for(int i=1;i<=n;i++){
		int minl=min(le[i],ri[i]);
		le[i]-=minl;
		l-=minl;
		ri[i]-=minl;
		r-=minl;
	}
	if(l<r){
		swap(le,ri);
		swap(l,r);
	}
	for(int i=1;i<=n;i++){
		int cnt=min((l-r)/2,le[i]/2);
		ans+=cnt;
		l-=cnt*2;
	}
	ans+=(l-r)/2;
	ans+=(l+r)/2;
	cout<<ans;
	return 0;
}

