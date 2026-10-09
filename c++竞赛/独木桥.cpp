#include<bits/stdc++.h>
using namespace std;
int l,n,a,maxn=0,minn=0;
int main()
{
	cin>>l>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		minn=max(min(a,l+1-a),minn);
		maxn=max(max(a,l+1-a),maxn);
	}
	cout<<minn<<" "<<maxn;
	return 0;
}
