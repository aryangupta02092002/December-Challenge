#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int data;
    struct ListNode* next;
    
    ListNode(int x){
        data = x;
        next = NULL;
    }
};
void printList(ListNode* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next;
    }  
    cout<<"\n";
} 

class Solution{
    public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        
        ListNode* even = head->next, *evenHead = even;
        ListNode* odd = head;
        
        while(even != NULL && even->next != NULL){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct ListNode *head = new ListNode(data);
        struct ListNode *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new ListNode(data);
            tail = tail->next;
        }
        
        Solution ob;
        printList(ob.oddEvenList(head));
    }
    return 0;
}