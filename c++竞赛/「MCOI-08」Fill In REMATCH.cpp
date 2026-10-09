#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll cspjsak=400;
ll s[N],p[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
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
		ll sum=0;
		p[0]=s[n+1]=0;
		for(int i=0;i<=n;i++){
			if(p[i]!=-1&&s[i+1]!=-1){
				sum=s[i+1]^p[i];
				break;
			}
		}
		for(int i=0;i<=n;i++){
			if(p[i]!=-1&&s[i+1]==-1) s[i+1]=sum^p[i];
			else if(p[i]==-1&&s[i+1]!=-1) p[i]=s[i+1]^sum;
			else if(p[i]==-1&&s[i+1]==-1) p[i]=cspjsak;
		}
		for(int i=1;i<=n;i++){
			cout<<(p[i]^p[i-1])<<" ";
		}
		cout<<"\n";
	}
	return 0;
}

