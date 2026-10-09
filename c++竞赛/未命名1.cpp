#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k1,k2;
	cin>>n>>k1>>k2;
	int ans=0;
	for(int i=1;i<=n;i++){
		int a,x,y;
		cin>>a>>x>>y;
		if(x&y){
			continue;
		}
		a-=x*k1;
		a-=y*k2;
		if(a<=0) continue;
		ans+=a;
	}
	if(ans==0) cout<<"-1";
	cout<<ans;
	return 0;	
}

