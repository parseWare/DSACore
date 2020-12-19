#include<iostream>
#include<string>
#include<math.h>
#define mnum 10e9
using namespace std;

void op(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif
}
int sze=0;
template<typename T>
class Node {
		public:
		T key;
		T cle;
		Node * left;
		Node * right;
		int count;
		int height;
		int eler;
		int elel;

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
Node* mknode(Node *root, T val){
	Node *temp = new Node();
	temp->key = val;
	temp->right= NULL;
	temp->left = NULL;
	temp->height = 1;
	temp->count = 1;
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
	temp1->eler = n2 + root->count + n1;
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
	temp1->elel = n1 + root->count + n2;
	root->height = maxm(root->left, root->right)+1;
	temp1->height = maxm(temp1->left,temp1->right)+1;
	return temp1;

}
Node* insert(Node *root, T val){

	if(root == NULL){
		Node* croot = mknode(root, val);
		return croot;
	}

	if(root->key == val){
		(root->count)++;
		sze++;
		return root;
	}
	if(root->key > val){
		root->elel++;
		root->left = insert(root->left, val);
	}
	else{
		root->eler++;
		root->right = insert(root->right,val);
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
		cout<<root->key<<" "<<root->height<<endl;
		preo(root->right);
	}
}
bool search(Node *root, T val){
	if(root == NULL)
		return 0;
	if(root->key == val)
		return 1;
	return (root->key > val)?search(root->left ,val) : search(root->right,val);
}
int cntor(Node *root, T val){
	if(root == NULL)
		return 0;
	if(root->key == val)
		return root->count;
	return (root->key > val)?cntor(root->left,val):cntor(root->right,val);
}
T lwrbnd(Node *root, T val){

	if(root == NULL)
		return 9e9;
	if(root->key >= val)
		return min(root->key,lwrbnd(root->left, val));
	else
	return lwrbnd(root->right, val);

}
T uprbnd(Node *root, T val){
	
	if(root == NULL)
		return 9e9;

	if(root->key > val)
			return min(root->key,uprbnd(root->left,val));
	else
		return uprbnd(root->right, val);
	
}
T klar(Node *root, int k){
		//cout<<root->key<<" "<<root->elel<<" "<<root->eler<<endl;
		if(root->elel >= k){
			return klar(root->left,k);
		}
		else if(root->elel + root->count < k)
			return klar(root->right, k - (root->elel + root->count));
		else
			return root->key;
}
T kthlar(Node *root, int k){
	k = (sze - (k-1));
	T val = klar(root,k);
	return val;
}
int rangee(Node *root, T a, T b){
	
	if(root == NULL)
		return 0;

	if(root->key == a && root->key == b)
		return root->count;

	if(root->key >= a && root->key <=b)
		return root->count + rangee(root->left, a ,b) + rangee(root->right, a, b);

	else if(root->key < a)
		return rangee(root->right, a, b); 

	else
		return rangee(root->left ,a ,b);

}
Node *fndpresucc(Node *root){
	Node *currn = root;
	while(currn->left != NULL)
			currn = currn->left;
	
		return currn;
}
Node *del(Node *root, T val){

		if(root == NULL)
			return root;

		else if(root->key > val){
			root->elel--;
			root->left = del(root->left, val);
		}

		else if(root->key < val){
			root->eler--;
			root->right = del(root->right, val);
		}

		else{

			if(root->count > 1){
				sze--;
				root->count--;
				return root;
			}
			else if(root->left == NULL || root->right == NULL){
				Node *temp =   root->right?root->right:root->left;

				if(temp == NULL){
					temp = root;
					root = NULL;
				}
				else{
					*root = *temp;
				}
				free(temp);
				sze--;
			}
			else{

				Node *temp = fndpresucc(root->right);
				root->key= temp->key;
				root->count=temp->count;
				temp->count = 1;

				root->eler--;
				root->right = del(root->right, temp->key);
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

T closestele(Node *root, T res, T maxm){

	if(root == NULL)
		return cle;
	if(abs(root->key - res)<=maxm){
		if(root->key != res){
		maxm=abs(root->key - res);
		cle=root->key;
	}
	else{
		if(root->count > 1)
			return root->key;
	}
	}
	if(root->key > res)
		return closestele(root->left, res, maxm);
	else if(root->key < res)
		return closestele(root->right,res,maxm);
	
	else{
		if(root->count == 1){
			return cle = min(closestele(root->left,res,maxm),closestele(root->right,res,maxm));
		}
		else
			return cle;	
	}
}

};
int main(){
	op();
	Node <double> ob;
	Node <double>*root = NULL;
	int n;
		double a;
	cin>>n;
	for(int i=0; i<n; ++i){
		cin>>a;
	root = ob.insert(root, a);
}

	ob.preo(root);
	//cout<<ob.search(root,"60")<<endl;
	//cout<<ob.cntor(root,"60")<<endl;
	cout<<ob.lwrbnd(root,1)<<endl;
	//cout<<ob.uprbnd(root,"5")<<endl;
	cout<<ob.kthlar(root,2)<<endl;
	//cout<<ob.rangee(root,"1","45");
	//root=ob.del(root,5);cout<<endl;
	ob.preo(root);
	cout<<ob.closestele(root,4,root->key);
	//cout<<ob.klar(root,6)<<endl;
	//cout<<endl<<"hello world";

}