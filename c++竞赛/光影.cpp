#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
vector<int> a;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k,flag=0,cnt=0,len=0;
	cin>>n>>k>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			flag=1;
		}
		if(s[i]=='0'){
			if(flag==1){
				cnt++;
			}
			flag=0;
		}
	}
	if(flag==1){
		cnt++;
	}
	flag=0;
	for(int i=0;i<n;i++){
		if(s[i]=='1'&&flag==0){
			flag=1;
			len=0;
		}
		if(flag==1&&s[i]=='0'){
			len++;
		}
		if(flag==1&&s[i]=='1'&&len!=0){
			a.push_back(len);
			len=0;
		}
	}
	sort(a.begin(),a.end());
	for(int i=0;i<a.size();i++){
		if(k>=a[i]){
			k-=a[i];
			cnt--;
		}
		else{
			break;
		}
	}
	cout<<cnt;
	return 0;
}

