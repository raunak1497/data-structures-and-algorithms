#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <stack>
using namespace std;
#define max(a, b) (a < b ? b : a) 
#define min(a, b) ((a > b) ? b : a) 
#define mod 1e9 + 7 
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++) 
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003 
typedef long long int ll; 
typedef vector<int> vi; 
typedef pair<int, int> pi;
#define f first
#define s second
#define pb push_back
#define pob pop_back
#define mp make_pair

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));

  node->data = data;

  node->left = NULL;
  node->right = NULL;
  return (node);
}

node* create_tree_level(node* root,int a[],int n,int i){
    if(i<n){
      node* temp = newNode(a[i]);
      root = temp;
      root->left =  create_tree_level(root->left,a,n,2*i+1);
      root->right = create_tree_level(root->right,a,n,2*i+2);
    }
    return root;
}

void preorderTraversal(node* root){
  if(root != NULL){
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
  }
  return;
}

void levelorderTraversal(node* root){
  if(root != NULL){
    cout<<root->left<<" ";
    preorderTraversal(root->left);
    cout<<root->right<<" ";
    preorderTraversal(root->right);
  }
  return;
}

int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    FOR(i, n)
        cin >> a[i];
    node* head = NULL;
    head = create_tree_level(head,a,n,0);
    preorderTraversal(head);
    levelorderTraversal(head);
    return 0;
}