#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10;
ll nxt[N],a[N]; 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	cin>>q;
	for(int t=1;t<=q;t++){
		ll e,r,n;
		cin>>e>>r>>n;
		memset(nxt,0,sizeof(nxt));
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		
		ll ans=0,cur=e;
		if(r>=e){
			for(int i=1;i<=n;i++){
				ans+=a[i]*e;
			}
			cout<<"Case #"<<t<<": "<<ans<<"\n";
			continue;
		}
		
		stack<int> st; 
		for(int i=n;i>=1;i--){
			while(!st.empty()&&a[st.top()]<=a[i]){
				st.pop();
			}
			nxt[i]=(st.empty())?(n+1):st.top();
			st.push(i);
		}
		
		for(int i=1;i<=n;i++){
			if(nxt[i]==n+1){
				ans+=cur*a[i];
				cur=r;
			}
			else{
				ll tmp=min(cur,cur+(nxt[i]-i)*r-e);
				if(tmp>0){
					ans+=tmp*a[i];
					cur-=tmp;
				}
				cur+=r;
				if(cur>e) cur=e; 
			}
		}
		cout<<"Case #"<<t<<": "<<ans<<"\n";
	}
	return 0;
}

