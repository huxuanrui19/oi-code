#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin>>s;
	int m=(s[0]-'0')*10+s[1]-'0';
	int d=(s[3]-'0')*10+s[4]-'0';
	if(d>0&&d<=28){
		if(m>0&&m<=12) cout<<"0";
		else cout<<"1";
	}
	else if(d==29||d==30){
		if(m==2||m==0||m>12) cout<<"1";
		else{
			cout<<"0";
		}
	}
	else if(d==31){
		if(m==1||m==3||m==5||m==7||m==8||m==10||m==12) cout<<"0";
		else if(m==2||m==4||m==6||m==9||m==11||(m>=13&&m<=19)) cout<<"1";
		else if(m%10==4||m%10==6||m%10==9){
			cout<<"2";
		}
		else cout<<"1";
	}
	else if(m==0||m>12) cout<<"2";
	else cout<<"1";
	return 0;
}

