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
    ListNode *middleNode(ListNode *head)
    {
        // Your code here
        ListNode *slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
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
        printList(ob.middleNode(head));
    }
    return 0;
}