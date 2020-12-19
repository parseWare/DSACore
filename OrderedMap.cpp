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
int sze=0;
template<typename T, typename P>
class Node {
		public:
		T key;
		P value;
		Node * left;
		Node * right;
		int height;
		int eler;
		int elel;
		Node <T,P> *root = NULL;
int maxm(Node *r1,Node *r2){
	if(r1==NULL && r2 == NULL)
		return 0;
	else if(r1 == NULL)
		return r2->height;
	else if(r2 == NULL)
		return r1->height;
	else
	return r2->height>r1->height?r2->height:r1->height;
}
int hgt(Node *r){
	if(r == NULL)
		return 0;
	else
		return r->height;
}
Node* mknode(Node *root, T valk, P vlu){
	Node *temp = new Node();
	temp->key = valk;
	temp->value = vlu;
	temp->right= NULL;
	temp->left = NULL;
	temp->height = 1;
	temp->eler = 0;
	temp->elel = 0;
	sze++;
	return temp;
}

Node * rgtrt(Node *root){

	Node * temp = root;
	 Node * temp1 = root->left;
	 int n1 = root->eler;
	 int n2 = temp1->eler;
	temp->left = temp1->right;
	temp1->right = root;

	root->elel = n2;
	temp1->eler = n2 + n1+1;
	root->height = maxm(root->left, root->right)+1;
	temp1->height = maxm(temp1->left,temp1->right)+1;
	return temp1;
}
Node* lftrt(Node *root){

	Node * temp = root;
	Node * temp1 = temp->right;

	int n1 = root->elel;
	int n2 = temp1->elel;
	root->right = temp1->left;	
	temp1->left = root;

	root->eler = n2;
	temp1->elel = n1 + n2+1;
	root->height = maxm(root->left, root->right)+1;
	temp1->height = maxm(temp1->left,temp1->right)+1;
	return temp1;

}
Node* insert(Node *root, T val, P vlu){

	if(root == NULL){
		Node* croot = mknode(root, val, vlu);
		return croot;
	}

	if(root->key > val){
		root->elel++;
		root->left = insert(root->left, val,vlu);
	}
	else{
		root->eler++;
		root->right = insert(root->right,val,vlu);
	}

	root->height = maxm(root->left, root->right)+1;

	int blnc = hgt(root->left) - hgt(root->right);

	if(blnc >1 && root->left->key < val){
		root->left = lftrt(root->left);
		return	rgtrt(root);
	}
	if(blnc >1 && root->left->key > val){
		return rgtrt(root);
	}
	if(blnc <-1 && root->right->key < val){
		return lftrt(root);
	}
	if(blnc <-1 && root->right->key > val){
		root->right = rgtrt(root->right);
		return	lftrt(root);
	}

	return root;
}
void preo(Node *root){
	if(root == NULL)
		return;
	else{
		preo(root->left);
		cout<<root->key<<" "<<root->value<<" "<<root->height<<endl;
		preo(root->right);
	}
}
bool find(Node *root, T val){
	if(root == NULL)
		return 0;
	if(root->key == val)
		return 1;
	return (root->key > val)?find(root->left ,val) : find(root->right,val);
}

Node *fndpresucc(Node *root){
	Node *currn = root;
	while(currn->left != NULL)
		  	currn = currn->left;
	
		return currn;
}
Node *erase(Node *root, T val){

		if(root == NULL)
			return root;

		else if(root->key > val){
			root->elel--;
			root->left = erase(root->left, val);
		}

		else if(root->key < val){
			root->eler--;
			root->right = erase(root->right, val);
		}

		else{

			if(root->left == NULL || root->right == NULL){
				Node *temp =   root->right?root->right:root->left;

				if(temp == NULL){
					temp = root;
					root = NULL;
				}
				else{
					*root = *temp;
				}
				sze--;
				free(temp);
				
			}
			else{

				Node *temp = fndpresucc(root->right);
				root->key = temp->key;


				root->eler--;
				root->right = erase(root->right, temp->key);
			}
		}

		if(root == NULL)
			return root;

	root->height = maxm(root->left, root->right)+1;

	int blnc = hgt(root->left) - hgt(root->right);

	if(blnc >1 && root->left->key < val){
		root->left = lftrt(root->left);
		return	rgtrt(root);
	}
	if(blnc >1 && root->left->key > val){
		return rgtrt(root);
	}
	if(blnc <-1 && root->right->key < val){
		return lftrt(root);
	}
	if(blnc <-1 && root->right->key > val){
		root->right = rgtrt(root->right);
		return	lftrt(root);
	}

	return root;

}
Node * findkey(Node *root, T ky){
	if(root==NULL)
		return root;
	
	else if(root->key == ky){
		return root;
	}
	else{
		if(root->key > ky)
		return	findkey(root->left, ky);
		else
		return	findkey(root->right,ky);
	}
}
P& operator [] (T ky){

		Node *currval = findkey(root,ky);
		if(currval == NULL){
			P val = {};
			root = this->insert(root,ky,val);
			Node *fndcur = findkey(root,ky);
			return fndcur->value;
		}        
		else{
			return currval->value;
		}
}

Node *clear(Node *root){
	if(root == NULL)
		return root;
	sze=0;
	clear(root->right);
	clear(root->left);
	root->left=NULL;
	free(root->left);
	root->right=NULL;
	free(root->right);
	root=NULL;
	free(root);
	return root;
}



};
int main(){
	op();
	Node <double,double> ob;
	//Node<double,double>*root = NULL;
	int n;
		double a,b;
	cin>>n;
	for(int i=0; i<n; ++i){
		cin>>a>>b;
	ob.root = ob.insert(ob.root, a,b);
}
	cout<<sze<<endl;
	cout<<ob.find(ob.root,30)<<endl;
	ob.root=ob.erase(ob.root, 30);
	cout<<endl<<sze<<endl;
	cout<<ob.find(ob.root,30)<<endl;
	//ob.preo(ob.root);
	//ob.root=ob.clear(ob.root);
	//ob.preo(ob.root);
	double val = ob[7];
	if(val == 0){
		ob.erase(ob.root,7);
	}
	ob.preo(ob.root);
	ob[30] = 4.54;
	ob.preo(ob.root);
	cout<<sze;
	//ob[30]=500;

}
/*
11
30 100
10 121
25 233
60 432
5 1000
6 678
8 987
2 3.43
45 543
35 100
15 234*/