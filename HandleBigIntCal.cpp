#include<iostream>
#include<string>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

void op(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif
}
string removezero(string str) 
{ 
    int i = 0; 
    while (str[i] == '0') 
       i++; 
    str.erase(0, i);   
    if(str.size()==0)
    	str="0";
    return str; 
}
string into(string s1, string s2){
	s1=removezero(s1);
	s2=removezero(s2);
	int res[100000];int cry=0;
	for(int i=0; i<100000; ++i)
		res[i]=0;
	string ans="";
		int ifs=0,inx=0;int a;
		for(int i=s2.size()-1; i>=0; --i){
				cry=0;inx=0;
			for(int j=s1.size()-1; j>=0; --j){
				a=(s1[j]-'0')*(s2[i]-'0');
				a+=(cry + res[ifs + inx]);
				res[ifs+inx] =  a%10;
				cry = a/10;			
				inx++;
			}
		int nw=0;
		while(cry){
			res[ifs+inx+nw]=cry%10;
			cry/=10;
			nw++;
		}
			ifs++;
		}
		
		if(res[ifs+inx-1]==0)ifs--;
		for(int i=(ifs+inx-1); i>=0; --i)
				ans = ans + to_string(res[i]);
		return ans;
	
}

string fac(int n){

	int res[100000];
	res[0]=1;int sz=1;int a;
	string ans="";int cry=0;
	for(int i=1; i<=n; ++i){
		cry=0;
		for(int j=0; j<sz; ++j){
			a = res[j]*i + cry;
			res[j]=a%10;
			cry = a/10;
		}
		int nw=0;
		while(cry){
			res[sz+nw]=cry%10;
			cry/=10;
			nw++;
		}
		sz+=nw;
	}
	for(int i=sz-1; i>=0; --i)
				ans = ans + to_string(res[i]);
		return ans;
}

string fexp(string a, int b){
	string rel="1";
	while(b){
		if(b&1)
			rel = into(rel,a);
		a = into(a,a);
		b>>=1;
	}
	return rel;
}

string subt(string s1, string s2){
	s1=removezero(s1);
	s2=removezero(s2);
		int sz2 = s2.size()-1;
		string res="";
		for(int i=s1.size()-1; i>=0; --i){
			if(sz2>=0){
				if(s1[i]<s2[sz2]){
					res = to_string(s1[i]-s2[sz2]+10) + res;
					s1[i-1]=(s1[i-1]-1);
				}
				else{
					res = to_string(s1[i]-s2[sz2]) + res;
				}
			}
			else{
			if((s1[i]-'0')<0){
				res = to_string(s1[i]-'0'+10) + res;
				s1[i-1]-=1;
			}
			else{
				res= to_string(s1[i]-'0') + res;
			}
		}
			sz2--;		
		}
		int i=0;
		while(i<int(res.size()) && res[i]=='0')
				++i;
		if(i==int(res.size()))
			res = to_string(0);
		else
			res = res.substr(i);
		return res;
}

string addn(string s1, string s2){
	s1=removezero(s1);
	s2=removezero(s2);
	string res= "";
	int sz2 = s2.size()-1;int cry = 0;int a;
	for(int i=s1.size()-1; i>=0; --i){
		if(sz2>=0){
		a = s1[i]-'0'+s2[sz2]-'0'+cry;
		res = to_string(a%10) + res;
		cry = a/10;
		}
		else{
		a = s1[i]-'0'+cry;
		res = to_string(a%10) + res;
		cry = a/10;
		}
		sz2--;  
	}
	if(s2.size()>s1.size()){
		for(int i=s2.size()-s1.size()-1; i>=0; --i){
		 	a = cry + s2[i]-'0';
		 	res = to_string(a%10) + res;
		 	cry = a/10;
	}
	}
	while(cry){
		res = to_string(cry%10) + res;
		cry/=10;
	}
	return res;
}

bool greaterv(string s1, string s2){
		
		if(s1.size()>s2.size())
			return 1;
		else if(s1.size()<s2.size())
			return 0;
		else{
			int i=0;
			while(i<int(s1.size()) && s1[i]==s2[i])++i;
			return s1[i]>=s2[i];
		}
}

string mode(string s1, string s2){
	s1=removezero(s1);
	s2=removezero(s2);
	string ar[11];ar[0]=to_string(1-'0');ar[1]=s2;
	for(int i=2; i<=10; ++i){
		ar[i] = addn(ar[i-1],s2);
	}

	int sz2=s2.size();
	string newform = s1; string temp;
	while(greaterv(newform,s2)){
			
		//	cout<<newform<<" ";
			temp = newform.substr(0,s2.size());
			if(!greaterv(temp,s2)){
				temp = temp + to_string(newform[sz2]-'0');
			}
			//cout<<temp<<"t ";
				int i=1;
				while(greaterv(temp,ar[i]))++i;
					--i;
			//	cout<<ar[i]<<"i ";
				if(newform.size()>ar[i].size())
					newform = subt(temp, ar[i])+newform.substr(temp.size());
				else
					newform = subt(temp, ar[i]);

			//cout<<newform<<"n ";
			newform=removezero(newform);
		
	}
	if(newform.size()>1 && newform[0]=='0')
		newform = newform.substr(1);
	return newform;
}

string gcd(string s1, string s2){
	string temp;
	while(s2[0]!='0'){
		temp = s2;
		s2 = mode(s1,s2);
		//cout<<s2<<"\n";
		s1 = temp;
	}
	return s1;
}
int main(){
	//op();
	fast;
	string s1 , s2;
	int n;
	cin>>n;int a;
	while(n--){
		cin>>a;
		if(a==1){

			int b;
			cin>>s1>>b;
	if(s1[0]=='-'){
		s1=s1.substr(1);
		if(b%2)
		cout<<"-"<<fexp(s1,b)<<"\n";
		else
		cout<<fexp(s1,b)<<"\n";
	}
	else
		cout<<fexp(s1,b)<<"\n";

		}
		else if(a==2){

	cin>>s1>>s2;
	cout<<gcd(s1,s2)<<"\n";

		}
		else{
			
			int r;
			cin>>r;
			cout<<fac(r)<<"\n";
		}

	}

	}


