#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
bool judge(int i,int j){
    if(s[i]>='a'&&s[i]<='z'){
        if(s[j]>='a'&&s[j]<='z'){
            return 1;
        }
        return 0;
    }
    else if(s[i]>='0'&&s[i]<='9'){
        if(s[j]>='a'&&s[j]<='z'){
            return 0;
        }
        return 1;
    }
    return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int p1,p2,p3;
	cin>>p1>>p2>>p3;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='-'&&i!=0&&i!=s.size()-1&&s[i-1]!='-'&&s[i+1]!='-'){
			if(char(s[i-1]+1)==char(s[i+1])){
				continue;
			}
			else if(char(s[i-1])<char(s[i+1])&&judge(i-1,i+1)){
				if(p3==1){
					for(char j=char(s[i-1]+1);j<s[i+1];j++){
						for(int k=1;k<=p2;k++){
							if(p1==1||(s[i+1]>='0'&&s[i+1]<='9'&&p1!=3)) cout<<char(j);
							else if(p1==2&&s[i+1]>='a'&&s[i+1]<='z') cout<<char(j+('A'-'a'));
							else cout<<'*';
						}
					}
				}
				else{
					for(char j=char(s[i+1]-1);j>s[i-1];j--){
						for(int k=1;k<=p2;k++){
							if(p1==1||(s[i+1]>='0'&&s[i+1]<='9'&&p1!=3)) cout<<char(j);
							else if(p1==2&&s[i+1]>='a'&&s[i+1]<='z') cout<<char(j+('A'-'a'));
							else cout<<'*';
						}
					}
				}
			}
            else{
                cout<<'-';
            }
		}
		else{
			cout<<char(s[i]);
		}
	}
	return 0;
}

