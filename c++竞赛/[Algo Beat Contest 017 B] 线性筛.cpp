#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int n,a[N],flag[N];
vector<int> pos[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i*i*i<=n;i++){
		pos[1].push_back(i*i*i);
		flag[i*i*i]=1;
	}
	ll ans=1;
	for(int i=1;i<=pos[1].size();i++){
		ll tmp=i;
		for(ll j=2;j<=n;j++){
			int num=pos[j-1][i-1]+tmp;
			if(flag[num]){
				tmp++;
				num++;
			}
			if(num>n) break;
			pos[j].push_back(num);
			flag[num]=1;
			ans=max(ans,j);
		}
	}
	cout<<ans<<"\n";
	for(int i=1;i<=ans;i++){
		for(auto d:pos[i]) cout<<a[d]<<" ";
		cout<<"\n";
	} 
	return 0;
}

