#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
inline int cal(string tot){
	int cnt=0;
	for(int i=3;i<tot.size();i++){
		if(tot.substr(i-3,4)=="CDNL") cnt++;
	}
	return cnt;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,m,a,ans=0;
		cin>>n>>m>>a;
		string s,t;
		cin>>s>>t;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				for(int k=1;k<=n;k++){
					for(int l=1;l<=a;l++){
						string ss=s.substr(i-1,min(j,n-i+1));
						string tt=t.substr(k-1,min(l,n-k+1));
						string tot=ss+tt;
						ans=max(ans,cal(tot));
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

