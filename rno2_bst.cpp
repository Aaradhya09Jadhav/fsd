/*#include<iostream>
using namespace std;
#include<string>

class node{
	string word;
	string mean;
	node *left, *right;
	friend class BST;
	
	};

class BST{
	
	public:
		node* root;
		void create_BST();
		void  inorder_BST();
		void  inorder_BST(node *root);
		void preorder();
    	void preorder(node *root);
    	void postorder();
    	void postorder(node *root);
  		node* copy_rec();
  		node* copy_rec(node *root);
		void mirror_rec(node *root);
		};
		
void BST::create_BST(){
	root=new node();
	char choice='Y';
	int flag;
	cout<<"Enter root word : ";
	cin>>root->word;
	root->left=root->right=NULL;
	do{
		node* curr=new node();
		cout<<"ENTER DATA : ";
		cin>>curr->word;
		cout<<"ENTER MEANING : ";
		cin>>curr->mean;
		node* temp=root;
		flag=0;
		
		curr->left=curr->right=NULL;
		while(flag==0){
			 if(curr->word<=temp->word){
				if(temp->left==NULL){
					temp->left=curr;
					flag=1;
					break;
					}
				else{
					temp=temp->left;
					flag=0;
					}
				}
			else{
				if (temp->right==NULL){
					temp->right=curr;
					flag=1;
					break;
					}
				else{
					temp=temp->right;
					flag=0;
					}
			}
	}
	cout<<"ENTER CHOICE : ";
	cin>>choice; 
}		
	while(choice=='Y');

}

void BST::inorder_BST(){
	inorder_BST(root);
	}

void BST::inorder_BST(node *root){
	if(root!=NULL){
		inorder_BST(root->left);
		cout<<root->word<<" ";
		inorder_BST(root->right);
		}
	}
	
void BST :: preorder(){
	preorder(root);
	}
	
void BST :: preorder(node *root){
	if(root!=NULL){
		cout<<root->word<< " ";
		preorder(root->left);
		preorder(root->right);
		}
	}

void BST :: postorder(){
	postorder(root);
	}
	
	
void BST :: postorder(node *root){
	if(root!=NULL){
		
		postorder(root->left);
		postorder(root->right);
		cout<<root->word<<" ";
		}
	}
	

node* BST::copy_rec(node *root){
	node* temp=NULL;
	if(root!=NULL){
		temp=new node();
		temp->word=root->word;
		temp->left=copy_rec(root->left);
		temp->right=copy_rec(root->right);
		}
	return temp;
	}


			

int main(){
	BST b1;
	b1.create_BST();
	cout<<"INORDER"<<endl;
	b1.inorder_BST();
	/*cout<<"PREORDER"<<endl;
	b1.preorder();
	cout<<"POSTORDER"<<endl;
	b1.postorder();
	
	BST b2;
	b2.copy_rec(b1.root);
	b2.inorder_BST();
	
	return 0; 
	}
		
		
*/	
		
		
#include <iostream>
#include <string>
using namespace std;

class node
{
    string word;
    string mean;

    node *left, *right;

    friend class BST;
};

class BST
{
    public:
    node *root;
    void create_BST();
    void inorder();
    void inorder(node *root);
    void preorder();
    void preorder(node *root);
    void postorder();
    void postorder(node *root);
    void mirror_rec();
    void mirror_rec(node *root);
    void copy_rec();
    node *copy_rec(node *root);
};

void BST::create_BST()
{
    root = new node();
    int flag;
    char choice;

    cout << "Enter root Word";
    cin >> root->word;
    cout << "Enter Mean:";
    cin >> root->mean;

    root->left = root->right = NULL;

    do
    {

        node *curr = new node();
        cout << "Enter word:";
        cin >> curr->word;
        cout << "Enter Mean:";
        cin >> curr->mean;
        curr->left = curr->right = NULL;
        node *temp = root;
        flag = 0;

        while (flag == 0)
        {
            if (curr->word <= temp->word)
            {
                if (temp->left == NULL)
                {
                    temp->left = curr;
                    flag = 1;
                    break;
                }
                else
                {
                    temp = temp->left;
                    flag = 0;
                }
            }
            else
            {

                if (temp->right == NULL)
                {
                    temp->right = curr;
                    flag = 1;
                    break;
                }
                else
                {
                    temp = temp->right;
                    flag = 0;
                }
            }
        }

        cout << "Enter Choice(Y/N)";
        cin >> choice;

    } while (choice == 'Y');
}

void BST::inorder()
{
    inorder(root);
}

void BST::inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->word << " ";
        inorder(root->right);
    }
}

void BST::preorder()
{
    preorder(root);
}

void BST::preorder(node *root)
{
    if (root != NULL)
    {
        cout << root->word << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void BST::postorder()
{
    postorder(root);
}

void BST::postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->word << " ";
    }
}

void swap(node *&root1, node *&root2)
{
    node *temp;
    temp = root1;
    root1 = root2;
    root2 = temp;
}

void BST::mirror_rec()
{
    mirror_rec(root);
}

void BST::mirror_rec(node *root)
{
    if (root != NULL)
    {
        swap(root->left, root->right);
        if (root->left != NULL)
        {
            mirror_rec(root->left);
        }
        if (root->right != NULL)
        {
            mirror_rec(root->right);
        }
    }
}

void BST::copy_rec()
{
    copy_rec(root);
}

node *BST::copy_rec(node *root)
{
    node *temp = NULL;

    if (root != NULL)
    {
        temp = new node();

        temp->word = root->word;

        temp->left = copy_rec(root->left);

        temp->right = copy_rec(root->right);
    }
    return temp;
}

int main()
{
    BST t;
    t.create_BST();
    cout<<"\nInorder: ";
    t.inorder();
    cout<<"\nPreorder: ";
    t.preorder();
    cout<<"\nPostorder: ";
    t.postorder();
    t.mirror_rec();
    cout << "\nMirrored Tree Inorder: ";
    t.inorder();
    cout<<"\nMirror Tree Preorder: ";
    t.preorder();
    cout<<"\nMirror Tree Postorder: ";
    t.postorder();
    
    BST n;
    n.root = t.copy_rec(t.root);
    n.inorder();


    return 0;
}
