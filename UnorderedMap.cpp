#include<iostream>
#include<string>
#include<math.h>
#define num 1000000;
using namespace std;

void op(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif
}

class Htable {
public:
		string key;
		string value;
		 Htable *next;

		string operator [](string);
};
 Htable *tbl[692];
long long a=101;
long long b=71;
int n=691;

int noe;

int caluclatehash(string curr){
		long long valu=0;
		for(int i=0; i<int(curr.size()); ++i){
			valu += (curr[i])*a;
		}
		valu += b;
		valu= valu%n;
		return int(valu);	
}
 Htable *create(string key , string val){
	 Htable *temp = new Htable();
	temp->key = key;
	temp->value = val;
	temp->next = NULL;
	return temp;
}
void insert(string key, string val){

		int r = caluclatehash(key);

		if(tbl[r]==NULL)
		tbl[r] = create(key,val);
		else{
			 Htable *temp = tbl[r];
			while(temp->next !=NULL){
				temp=temp->next;
			}
			temp->next = create(key,val);
		}
}
void erase(string ky){
	int r = caluclatehash(ky);
	if(tbl[r]!=NULL){
		 Htable *prev = tbl[r];
		if(prev->next == NULL){
			if(prev->key == ky){
				free(prev);
				prev=NULL;
				tbl[r]=NULL;
				return;
			}
		}
		else if(prev->key == ky){
			tbl[r]=prev->next;
			free(prev);
			prev=NULL;
			return;
		}

		 Htable *nxt = prev->next;
		while(nxt){
			if(nxt->key == ky){
				prev->next = nxt->next;
				free(nxt);
				break;
			}
			else{
				prev = nxt;
				nxt = nxt->next;
			}
		}
	}
}
string Htable :: operator [] (string ky){

		int r = caluclatehash(ky);
		if(tbl[r]!=NULL){

			 Htable *temp = tbl[r];
			while(temp){
				if(temp->key == ky)
					return temp->value;
				temp =temp->next;
			}
			return "nokey";
		}
		else{
			return "nokey";
		}
}
string find(string ky){

	int r = caluclatehash(ky);
		if(tbl[r]!=NULL){

			 Htable *temp = tbl[r];
			while(temp){
				if(temp->key == ky)
					return "True";
				temp =temp->next;
			}
			return "False";
		}
		else{
			return "False";
		}

}
void printtable(){
	for(int i=0; i<691; ++i){
		if(tbl[i]!=NULL){
		 Htable *temp = tbl[i];
		while(temp!=NULL){
			cout<<temp->key<<" "<<temp->value<<endl;
			temp=temp->next;
		}
		}
	}
}
int main(){
	op();
	Htable ob;
	for(int i=0; i<691; ++i)
		tbl[i]=NULL;
	cout<<"hello";
	insert(to_string(4),to_string(4));
	insert(to_string(3),to_string(5));
	printtable();
	erase(to_string(4));
	printtable();
	cout<< (ob)[to_string(3)]<<endl;
	cout<<find(to_string(4));
	//cout<<typeid(a).name()<<endl;
	


}