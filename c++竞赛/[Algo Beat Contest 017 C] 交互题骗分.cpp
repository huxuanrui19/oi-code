#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,ans,a[N],b[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) b[a[i]]++;
	bool flag=1;
	for(int i=0;i<n;i++){
		if(b[i]==0) flag=0;
	}
	if(flag==1){
		cout<<n*(n+1)/2-1;
		return 0;
	}
	else if(b[0]==0){
		cout<<0;return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			vector<int> v;
			for(int k=i;k<=j;k++){
				v.push_back(a[k]);
			}
			sort(v.begin(),v.end());
            int m=unique(v.begin(),v.end())-v.begin();
            v.resize(m);
			int mex=-1;
			if(v[0]!=0) mex=0;
			else{
				for(int k=1;k<v.size();k++){
					if(v[k]!=v[k-1]+1){
						mex=v[k-1]+1;
						break;
					}
				}
				if(mex==-1) mex=v[v.size()-1]+1;
			}
			if(i==1&&j==n) continue;
			else{
				ll minn=1e18;
				for(int k=1;k<i;k++) minn=min(minn,a[k]);
				for(int k=j+1;k<=n;k++) minn=min(minn,a[k]);
				if(minn==mex){
                    ans++;
                }
			}
		}
	}
	cout<<ans;
	return 0;
}
