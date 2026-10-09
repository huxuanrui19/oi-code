#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int a[N],sum[N];
unordered_map<int,int> m; 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) sum[i]=(sum[i-1]+a[i])%k;
	for(int i=0;i<=n;i++){
		if(!m.count(sum[i])){
			m[sum[i]]=i;
		}
	}
	int maxl=0,s=0,e=0;
	for(int i=1;i<=n;i++){
		if(m[sum[i]]==i){
			continue;
		}
		else{
			if(maxl<=(i-m[sum[i]])){
				maxl=i-m[sum[i]];
				s=m[sum[i]]+1;
				e=i;
			}
		}
	}
	if(maxl==0) cout<<"-1";
	else{
		cout<<maxl<<endl;
		for(int i=s;i<=e;i++){
			cout<<a[i]<<" ";
		}
	}
	return 0;
}

