#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int N=1e5+10;
ll n,p=1732073999;
vector<int> div(ll n){
	vector<int> tmp;
	while(n){
		tmp.push_back(n%3);
		n/=3;
	}
	reverse(tmp.begin(),tmp.end());
	return tmp;
} 
ll kkk(ll n){
	vector<int> dig=div(n);
	int m=dig.size();
	ll cur[2]={0};
	cur[1]=1;
	for(int i=0;i<m;i++){
		ll next[2]={0};
		for(int j=0;j<=1;j++){
			if(cur[j]==0) continue;
			ll max_d=(j) ? dig[i] : 2;
			for(int d=0;d<=max_d;d++){
				ll gx=(d==1)?2:1; //¹±Ï×;
				ll new_next= (j&&(d==max_d)) ? 1 : 0;
				next[new_next]=(next[new_next]%p+cur[j]*gx%p)%p;
			}
		}
		memcpy(cur,next,sizeof(next));
	} 
	return (cur[0]+cur[1])%p;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t,maxn;
	cin>>t>>maxn;
	while(t--){
		cin>>n;
		cout<<kkk(n)<<endl;
	}
}

