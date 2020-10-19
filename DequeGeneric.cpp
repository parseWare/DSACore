#include<iostream>
#include<string>
#include<math.h>
#define MAXE 100000
using namespace std;

void op(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif
}
template<typename T>
class deque{

	private:
		T *ar;
		int strt;
		int rear;
		int sze;
		int capacity;
	public:
	deque(){
		this->sze=0;
		strt=0;
		rear=-1;
		capacity=0;
		ar = new T[capacity];
	}
	deque(int n, T x){
		this->sze = (n);
		this->capacity=2*n;
		ar = new T[capacity];
		for(int i=0; i<sze; ++i)
			ar[i]=x;
		strt =0;
		rear = n-1;
	}


void incr(){
	if(capacity==0){
		this->capacity=2;
		this->strt=0;
		this->rear=-1;
		T *nar = new T[capacity];
		this->ar = new T[capacity];
		this->ar=nar;
	}
	else{
	this->capacity = 2*capacity;
	T *nar = new T[capacity];int r=0;
	
	for(int i=strt; i<this->sze; ++i,r++)
		nar[r]=ar[i];

	for(int i=0; i<=strt-1; ++i,++r)
			nar[r]=ar[i];

	
		delete[] ar;
		this->ar=nar;
	this->strt = 0;
	this->rear=this->sze - 1;
}
}
void hndlsize(){
	int tt = ceil(log2(this->sze));
	int cpc = pow(2,tt);
	T *nar = new T[cpc];
	
	int i=strt;int r=0;
	while(i!=rear){
		nar[r++]=this->ar[i];
		i+=1;
		if(i==capacity)
			i=0;
	}
	nar[r]=ar[rear];
	delete[] ar;
	this->capacity = cpc;
	this->ar=nar;
		
	this->strt = 0;
	this->rear=this->sze - 1;


}
void display(){
	if(sze>0){
	int i=strt;
	while(i!=-1 && i!=rear){
		cout<<ar[i]<<" ";
		i+=1;
		if(i==capacity)
			i=0;
	}
cout<<ar[rear];
	cout<<"\n";
}
else{
	cout<<endl;
}
	//cout<<strt<<" "<<rear<<" "<<this->sze<<" "<<this->capacity<<endl;

}

void push_back(T x){

	if(strt == rear-1 || strt-1==rear || (strt == 0 && rear==capacity-1)){
		incr();
	}
	this->sze +=1;
	ar[++rear]=x;
}


void pop_back(){

	//this->ar[rear]=0;
	if(strt==0 && rear==0 && sze==1){
		delete[] ar;
		capacity=0;
		ar = new T[capacity];
		strt=-1;
		rear=0;
	}
	else{
		if(this->rear==0){
		rear=capacity-1;
	}
	else{
		this->rear-=1;
	}
}
	sze-=1;
	if(strt==rear){
		ar[0]=ar[strt];
		strt=0;
		rear=0;
	}
	
	if(capacity > 2*sze)
	this->hndlsize();
}


T front(){
	return ar[strt];
}


T back(){
	return ar[rear];
}


string empty(){
	return sze>0?"true":"false";
}


int size(){
	return this->sze;
}


void clear(){
	delete[] ar;
	capacity=0;
	ar = new T[capacity];
	strt=-1;
	rear=0;
	sze=0;
}


void push_strt(T x){

		if(strt == rear-1 || strt-1==rear || (strt == 0 && rear==capacity-1)){
		incr();
	}
	
		if(strt==0 && rear!=-1)
			strt=capacity;
		if(strt==0 && rear==-1){
			strt=1;
			rear=0;
		}
		this->sze +=1;
		ar[--strt]=x;

	if(capacity > 2*sze)
	this->hndlsize();
}


void pop_strt(){

if(strt==0 && rear==0 && sze==1){
	delete[] ar;
	capacity=0;
	ar = new T[capacity];
	strt=-1;
	rear=0;
	}
	else{
	if(this->strt == capacity-1){
		this->strt=0;
	}
	else{

		this->strt+=1;
	}
}
	this->sze-=1;

	if(strt==rear){
		ar[0]=ar[strt];
		strt=0;
		rear=0;
	}

	if(capacity > 2*sze)
	this->hndlsize();
}



void resize(int x , T d){

	if(sze >=x){
		int nw = sze - x;		
			rear -= nw;
			if(rear<0)
				rear = capacity + rear;

		this->sze = x;

		if(strt==rear){
		ar[0]=ar[strt];
		strt=0;
		rear=0;
	}
	}
	else{
			while(this->sze !=x){
				this->push_back(d);
			}

	}
	if(capacity > 2*sze)
		this->hndlsize();
}

T operator [](int n){

			if((capacity-1-n)>=strt){
				return (this->ar[strt+n]);
			}
			else{
				n-= (capacity - strt);
				return this->ar[n];
			}
		
}

};

	

int main(){
	//op();
	/*	deque<char> dq;

		dq.push_back('5');
	dq.push_strt("a");
		dq.push_back("c");
		dq.clear();
		dq.push_strt("20");
		dq.pop_strt();
		dq.resize(10,"paras");*/
	/*	dq.resize(2,'4');
		dq.resize(10,'9');
	//	dq.resize(15,'7');
	//	dq.resize(1,'5');
		dq.pop_strt();
		dq.pop_strt();
	//	dq.resize(5,"4");
		
	//	dq.pop_back();
	//	dq.push_back('8');
	//	dq.pop_strt();
		dq.push_back('7');*/
		//cout<<dq.back();
		//cout<<dq.front();
	//	cout<<dq.empty();
	//	cout<<dq.size();
	//	dq.push_back(9);
	//	dq.push_back(10);
	/*	dq.push_strt('4');
		dq.push_strt('5');
		dq.push_strt('8');
		dq.push_strt('6');
		dq.push_strt('a');
		dq.push_strt('b');
		dq.push_strt('c');*/
	//	cout<<dq[14]<<"\n";
		/*dq.push_strt(78);
		dq.push_back(34);
		dq.push_back(67);
		dq.pop_back();
		dq.pop_strt();
		dq.pop_strt();
		dq.pop_strt();
		dq.pop_strt();
		//cout<<"hello";
		//deque<int>dq(10,'r');
		//deque<int>dq1();
	//	cout<<dq.ar[2];*/
	//	dq.display();	


	deque<string> *arr =NULL;
    int Q,c,n;
    string x;
    cin>>Q;
    while (Q--){      
 
 cin>>c;
 if(c==1) {cin>>x;
         arr->push_strt(x);  
         arr->display();
}
        
 else if(c==2) { arr->pop_strt();
         arr->display();
       
 }
 else if(c==3) {cin>>x;
         arr->push_back(x);
         arr->display();
        
 }
 else if(c==4)  {arr->pop_back();
         arr->display();
        
 }
 else if(c==5) {if(arr !=NULL){
         delete arr;}
         arr = new deque<string>();
    
}
else if(c==6){ cin>>n>>x;
         if(arr !=NULL)
         delete arr;
         arr = new deque<string>(n,x);
         arr->display();
       
}
else if(c==7){ cout<<arr->front()<<endl;
        
}
else if(c==8) {cout<<arr->back()<<endl;
         
 }
else if(c==9){ cout<<arr->empty()<<endl;
     
}
if(c==10){ cout<<arr->size()<<endl;
          
}
if(c==11){ cin>>n>>x;
          arr->resize(n,x);
          arr->display();
      
}
else if(c==12) {arr->clear();
        
 }
if(c==13) {cin>>n;
          cout<<(*arr)[n]<<endl;
        
      }

if(c==14){(arr->display());
         
}
} 
delete[] arr;
return 0;

}
	



