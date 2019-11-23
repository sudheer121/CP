#include<iostream>
using namespace std;
struct node 
{
int info;
node* left;
node* right;
};
node* nnode(int data)//creates new node,returns its address
{
    node* x = new node();
    x->left=NULL;x->right=NULL;
    x->info = data;
    return x;
}
node* insert(int x,node* root)// recursive_insert
{   
   if(root==NULL){root=nnode(x); return root;}
   else if(x<root->info)
   {
       root->left= insert(x,root->left);
   }
   else
   {
       root->right= insert(x,root->right);
   }
}
void search(int x,node* root)
{
    if(root==NULL){cout<<"DNE\n";}
    else if(x==root->info){cout<<root->info<<"  exists\n";}
    else if(x<root->info)
    {
        search(x,root->left);
    }
    else
    {
        search(x,root->right);
    }
}
void traverse(node* root)
{  if(root==NULL){return;}
   traverse(root->left);
   cout<<root->info<<" ";
   traverse(root->right);
}
void breadthfirst(node* root)
{
    if(root==NULL){return;}
    else
    { node* p=NULL,q=NULL;
      while(1)
      {
          cou
      }
    }
}
void minmaxbst(node* root)
{   node* p=root;
    while(p->left!=NULL) {  p = p->left; }
    cout<<"minimum is "<<p->info<<"\n";
    p = root;
    while(p->right!=NULL) {  p = p->right; }
    cout<<"maximum is "<<p->info<<"\n";
}
int l=-1,r=-1;
int maxheight(node* root)
{
//logic: height of a node = max(h of left subtree,h of right subtree)+1     
    if(root==NULL){return -1;}
    l = maxheight(root->left);//height of left subtree
    r = maxheight(root->right);//height of right subtree
    if(l>r){return l+1;}
    else{return r+1;}
}
int main()
{ node* root = NULL;
int x;
root = insert(10,root);
root = insert(15,root);
root = insert(12,root);
root = insert(9,root);
root = insert(8,root);
traverse(root);cout<<"\n";
search(25,root);
minmaxbst(root);
cout<<maxheight(root)<<"\n";
breadthfirst(root);
return 0;
}
/*node* insert(int x,node* root) //iterative insert
{   
    if(root==NULL){root = nnode(x); return root;}
    else
    {   node* p = root;
        while(1)
        {    if(x< p->info && p->left!=NULL) { p=p->left;}
             else if(p->right!=NULL){ p=p->right;}
             else { break; }
        }
        if( x<p->info ){p->left = nnode(x);}
        else { p->right = nnode(x);}
    }
    return root;
}*/