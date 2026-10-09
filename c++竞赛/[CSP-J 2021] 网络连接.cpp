#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+10;
struct ip{
	int a,b,c,d,e;
	bool add(string s){
		int n=s.size();
		s=' '+s;
		for(int i=1;i<=n;i++){
			if(s[i]!='.'&&s[i]!=':'&&(s[i]>'9'||s[i]<'0')) return 0;
		}
		if(count(s.begin(),s.end(),'.')!=3||count(s.begin(),s.end(),':')!=1) return 0;
		else{
			int pos1=s.find('.');
			int pos2=s.find('.',pos1+1);
			int pos3=s.find('.',pos2+1);
			int pos4=s.find(':',pos3+1);
            if(pos1>pos4||pos2>pos4||pos3>pos4) return 0;
            if(pos1==1||pos4==n||pos1+1==pos2||pos2+1==pos3||pos3+1==pos4) return 0;
			int cnt1,cnt2,cnt3,cnt4,cnt5;
			cnt1=cnt2=cnt3=cnt4=cnt5=0;
			for(int i=1;i<pos1;i++){
				if(i==1&&s[i]=='0'&&pos1!=2){
					return 0;
				}
				cnt1=cnt1*10+s[i]-'0';
			}
			for(int i=pos1+1;i<pos2;i++){
				if(i==pos1+1&&s[i]=='0'&&pos2!=pos1+2){
					return 0;
				}
				cnt2=cnt2*10+s[i]-'0';
			}
			for(int i=pos2+1;i<pos3;i++){
				if(i==pos2+1&&s[i]=='0'&&pos3!=pos2+2){
					return 0;
				}
				cnt3=cnt3*10+s[i]-'0';
			}
			for(int i=pos3+1;i<pos4;i++){
				if(i==pos3+1&&s[i]=='0'&&pos4!=pos3+2){
					return 0;
				}
				cnt4=cnt4*10+s[i]-'0';
			}
			for(int i=pos4+1;i<=n;i++){
				if(i==pos4+1&&s[i]=='0'&&n!=pos4+1){
					return 0;
				}
				cnt5=cnt5*10+s[i]-'0';
			}
			//cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<" "<<cnt4<<" "<<cnt5<<"\n";
			if(cnt1>255||cnt2>255||cnt3>255||cnt4>255||cnt5>65535){
				return 0;
			}
            if(cnt1<0||cnt2<0||cnt3<0||cnt4<0||cnt5<0) return 0;
			a=cnt1;b=cnt2;c=cnt3;d=cnt4;e=cnt5;
			return 1;
		}
	}
	bool operator <(const ip &x)const{
		if(a!=x.a) return a<x.a;
		if(b!=x.b) return b<x.b;
		if(c!=x.c) return c<x.c;
		if(d!=x.d) return d<x.d;
		return e<x.e;
	}
};
int idx=0;
map<ip,int> mp;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	while(n--){
		string op,s;
		cin>>op>>s;
        idx++;
		if(op=="Server"){
			ip p;
			bool flag=p.add(s);
			if(flag){
				if(mp.count(p)) cout<<"FAIL\n";
				else{
					mp[p]=idx;
					cout<<"OK\n";
				}
			}
			else cout<<"ERR\n";
		}
		else{
			ip p;
			bool flag=p.add(s);
			if(flag){
				if(mp.count(p)) cout<<mp[p]<<"\n";
				else cout<<"FAIL\n";
			}
			else cout<<"ERR\n";
		}
	}
	return 0;
}
