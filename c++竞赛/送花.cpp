#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10,M=1e6+10;
set<pair<ll,ll> > s;
int val[M];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int opt;
	cin>>opt;
	while(opt!=-1){
		if(opt==1){
			ll w,c;
			cin>>w>>c;
			if(!val[c]){
    	        val[c]++;
				s.insert(make_pair(c,w));
			}
		}
		else if(opt==3){
			if(!s.empty()){
				val[(*s.begin()).first]--;
				s.erase(s.begin());
			}
		}
		else if(opt==2){
			if(!s.empty()){
				val[(*prev(s.end())).first]--;
				s.erase(prev(s.end()));
			}
		}
		cin>>opt;
	}
	ll ans1=0,ans2=0;
	for(auto d:s){
		ans1+=d.second;
		ans2+=d.first;
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}

