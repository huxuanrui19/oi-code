#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll a[N][3];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=2;j++){
				cin>>a[i][j];
			}
		}
		priority_queue<int,vector<int>,less<int> > u;
		priority_queue<int,vector<int>,less<int> > v;
		priority_queue<int,vector<int>,less<int> > w;
		int ans=0;
		for(int i=1;i<=n;i++){
			int maxn=-1,idx=-1;
			for(int j=0;j<=2;j++){
				if(a[i][j]>maxn){
					maxn=a[i][j];
					idx=j;
				}
			}
			if(idx==0) u.push(max(a[i][1]-maxn,a[i][2]-maxn));
			if(idx==1) v.push(max(a[i][0]-maxn,a[i][2]-maxn));
			if(idx==2) w.push(max(a[i][1]-maxn,a[i][0]-maxn));
			ans+=maxn;
		}
		while(u.size()>(n/2)){
			int x=u.top();
			ans+=x;
			u.pop();
		}
		while(v.size()>(n/2)){
			int x=v.top();
			ans+=x;
			v.pop();
		}
		while(w.size()>(n/2)){
			int x=w.top();
			ans+=x;
			w.pop();
		}
		while(!u.empty()) u.pop();
		while(!v.empty()) v.pop();
		while(!w.empty()) w.pop();
		cout<<ans<<"\n";
	}
	
	return 0;
}
