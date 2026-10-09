#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	swap(s[0],s[s.size()-1]);
	int flag=0;
	for(int i=0;i<s.size();i++){
		if(s[i]!='0'){
			flag=1;
		}
		if(flag){
			cout<<s[i];
		}
	}
	return 0;
} 
