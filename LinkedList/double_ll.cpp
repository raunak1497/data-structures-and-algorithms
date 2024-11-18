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

class ListNode {
  public:
    int val;
  ListNode * next;
  ListNode * prev;
  ListNode(int x) {
    val = x;
    next = NULL;
  }
};

ListNode* insertFirst(ListNode* head, int x){
    ListNode* newNode  = new ListNode(x);
    newNode->next =  head;
    newNode->prev = NULL;
    head = newNode;
    return head;
}

ListNode* insertLast(ListNode* head, int x){
    ListNode* newNode  = new ListNode(x);
    newNode->next = NULL;
    if(head == NULL){
      return newNode;
    }
    ListNode* temp = head;
    while(temp->next != NULL){
      temp = temp->next;
    }
    temp->next =  newNode;
    newNode->prev = temp;
    return head;
}
//inser nod at a given position
ListNode* addNode(ListNode *head, int p, int data)
{
   // Your code here
   ListNode* temp = head;
   ListNode* temp1 = head->next;
   while(p--){
       temp = temp1;
       temp1 = temp1->next;
       cout<<p<<" "<<temp->val<<endl;
   }
   ListNode* newNode = new ListNode(data);
   if(temp1 == NULL){
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = NULL;
   }else{
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = temp1;
        temp1->prev = newNode;
   }
   return head;
}

ListNode* deleteNode(ListNode* head, int p) {
    ListNode* temp = head;
    ListNode* temp1 = head->next;
    if(p==0){
        temp1->prev = NULL;
        temp->next = NULL;
        return temp1;
    }
   while(p--){
       cout<<p<<" "<<temp->val<<endl;
       temp = temp1;
       temp1 = temp1->next;
   }
   if(temp1==NULL){
       ListNode* curr = temp->prev;
       curr->next = NULL;
       temp->prev = NULL;
   }else{
        ListNode* curr = temp->prev;
        curr->next = temp1;
        temp1->prev = curr;
        temp->prev = NULL;
        temp->next = NULL;
   }
   return head;
}

void printList(ListNode* head){
    ListNode* temp = head;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}
int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin >> n;
    ListNode* head = NULL;
    while(n--){
        cin>>x;
        // head = insertFirst(head,x);
        head = insertLast(head,x);
    }
    printList(head);
    int pos,val;
    // cout<<"Insert the value and position to be inserted"<<endl;
    cin>>pos;
    // head = addNode(head,pos,val);
    head = deleteNode(head,pos-1);
    printList(head);
    return 0;
}