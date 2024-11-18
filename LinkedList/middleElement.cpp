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
  ListNode(int x) {
    val = x;
    next = NULL;
  }
};

ListNode* insertFirst(ListNode* head, int x){
    ListNode* newNode  = new ListNode(x);
    newNode->next =  head;
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
    return head;
}

void printList(ListNode* head){
    ListNode* temp = head;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}
ListNode* middleElement(ListNode* head){
        ListNode* temp = head;
        ListNode* temp2 = head;
        while(temp2 != NULL && temp2->next != NULL){
            temp = temp->next;
            temp2 = temp2->next;
            temp2 = temp2->next;
        }
        return temp;
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
    ListNode* ans = middleElement(head);
    cout<<ans->val<<endl;
    return 0;
}