#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
string t="520",t1="52",t2="20",t3="50";
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int q;
	cin>>q;
	while(q--){
		ll n,a,b,c;
		string s;
		cin>>n>>a>>b>>c>>s;
		ll pos=0,num0=0,num1=0,num2=0,num3=0;
		set<int> se;
		while(s.find(t,pos)!=string::npos){
			pos=s.find(t,pos);
			num0++;
			se.insert(pos);se.insert(pos+1);se.insert(pos+2);
			pos+=t.size();
		}
		set<int> s1;
		pos=0;
		while(s.find(t1,pos)!=string::npos){
			pos=s.find(t1,pos);
			if(se.find(pos)==se.end()) num1++;
			s1.insert(pos);s1.insert(pos+1);
			pos+=t1.size();
		}
		pos=0;
		while(s.find(t2,pos)!=string::npos){
			pos=s.find(t2,pos);
			if(se.find(pos)==se.end()) num2++;
			s1.insert(pos);s1.insert(pos+1);
			pos+=t2.size();
		}
		pos=0;
		while(s.find(t3,pos)!=string::npos){
			pos=s.find(t3,pos);
			if(se.find(pos)==se.end()) num3++;
			s1.insert(pos);s1.insert(pos+1);
			pos+=t3.size();
		}
		for(auto d:se){
			s1.insert(d);
		}
		ll cnt5=0,cnt2=0,cnt0=0;
		for(int i=0;i<s.size();i++){
			if(s1.find(i)==s1.end()){
				if(s[i]=='5') cnt5++;
				else if(s[i]=='2') cnt2++;
				else cnt0++;
			}
		}
		//cout<<num0<<" "<<num1<<" "<<num2<<" "<<num3<<" "<<cnt0<<" "<<cnt2<<" "<<cnt5<<"\n";
		ll ans=num0;
		ans+=min(c,num1);c=max(0ll,c-num1);
		ans+=min(a,num2);a=max(0ll,a-num2);
		ans+=min(b,num3);b=max(0ll,b-num3);
		ll ans5=min(min(b,c),cnt5);
		ans+=ans5;b-=ans5;c-=ans5;
		ll ans2=min(min(a,c),cnt2);
		ans+=ans2;a-=ans2;c-=ans2;
		ll ans0=min(min(a,b),cnt0);
		ans+=ans0;a-=ans0;b-=ans0;
		ans+=min(a,min(b,c));
		cout<<ans<<"\n";
	}
	return 0;
}

