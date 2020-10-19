#include<iostream>
#include<string>
#include<math.h>
using namespace std;

void op(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif
}
int prio(char a, char b){
	if(a=='(' || ((b=='*' || b=='/' || b=='%') && (a=='+' || a=='-')))
		return 0;
	else
		return 1;
}
double cali(double num1, double num2, char c){
		double r;
	switch(c)
    {
        case '+':
           r=num1+num2;break;

        case '-':
        r= num1-num2;break;

        case '*':
           r= num1*num2;break;

        case '/':
            r=num1/num2;break;

        case '%':
           r = fmod(num1,num2);break;
    }
    return r;
}
int main(){
	cout.precision(5);
	//op();
	string s;
	cin>>s;
	bool fg=0;
	double t=0,sz=s.size();
	//long long ans=0;
	double num[10000];long long pn=-1;
	char str[10000];long long ps=-1;
	while(t!=sz){
		if(fg==0){
			if(s[t]=='('){
				str[++ps]='(';
				++t;
			}
			else{
				double r=0;
				if(s[t]=='-'){
					t++;
					while(s[t]>='0' && s[t]<='9'){
						r*=10;
						r+=(s[t]-'0');
						t++;
						}
						if(s[t]=='.'){
						t++;int val=1;
						double point=0;
						while(s[t]>='0' && s[t]<='9'){
							val*=10;
						point*=10;
						point+=(s[t]-'0');
						t++;
						}
						double sf = point/val;
						r+=sf;
					}
					r = -1*r;
					num[++pn]=r;
				}
				else{
					while(s[t]>='0' && s[t]<='9'){
						r*=10;
						r+=(s[t]-'0');
						t++;
						}
						if(s[t]=='.'){
						t++;int val=1;
						double point=0;
						while(s[t]>='0' && s[t]<='9'){
							val*=10;
						point*=10;
						point+=(s[t]-'0');
						t++;
						}
						double sf = point/val;
						r+=sf;
					}
					num[++pn]=r;
				}
				fg=1;
			}
		}
		else{
			if(s[t]==')'){
				while(str[ps]!='('){
					num[pn-1] = cali(num[pn-1],num[pn],str[ps]);
					pn--;
					ps--;
				}
				--ps;
			}
			else{
				while(ps!=-1 && pn!=-1 && prio(str[ps], s[t])){
					num[pn-1] = cali(num[pn-1],num[pn],str[ps]);
					ps--;
					pn--;
				}
				str[++ps]=s[t];
				fg=0;
			}

		
		++t;
		}

	}
	while(ps!=-1){
		num[pn-1] = cali(num[pn-1],num[pn],str[ps]);
		ps--;
		pn--;
	}

	cout<<fixed<<num[0];
}
/*
234+(231/2.34-67.89+(56.789-765.678)+78.654/67.78)-567.78/2.3*67/45*211.456+765
*/
