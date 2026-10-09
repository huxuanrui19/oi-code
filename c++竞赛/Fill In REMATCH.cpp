#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int t;
ll p[N],s[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>p[i];
		}
		for(int i=1;i<=n;i++){
			cin>>s[i];
		}
		p[0]=s[n+1]=0;
		ll sum=0;
		for(int i=0;i<=n;i++){
			if(p[i]!=-1&&s[i+1]!=-1){
				sum=p[i]^s[i+1];
				break;
			}
		}
		for(int i=0;i<=n;i++){
			if(p[i]==-1&&s[i+1]!=-1) p[i]=sum^s[i+1];
            else if(p[i]==-1&&s[i+1]==-1) p[i]=523;
			else s[i+1]=sum^p[i];
		}
		for(int i=1;i<=n;i++){
			cout<<(p[i]^p[i-1])<<" ";
		}
		cout<<"\n";
	}
	return 0;
}

