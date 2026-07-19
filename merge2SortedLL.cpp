#include <bits/stdc++.h>
using namespace std;


class ListNode{
public:
    ListNode *next;
    int val;
    
    ListNode(int num, ListNode *node){
        next = node;
        val = num;
    }
    
    ListNode(int num){
        next = nullptr;
        val = num;
    }
};

ListNode *ll(vector<int> arr){
    
    ListNode *head = new ListNode(arr[0]);
    ListNode *temp = head;
    
    for(int i = 1; i < arr.size(); i++){
        ListNode *node = new ListNode(arr[i]);
        temp->next = node;
        temp = node;
    }
    
    return head;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
    ListNode *t1 = list1;
    ListNode *t2 = list2;
    ListNode *dummy = new ListNode(-1);
    ListNode *temp = dummy;

    while(t1 != nullptr && t2 != nullptr){

        if(t1->val <= t2->val){
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }
        else{
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }
    if(t1 != nullptr){
        temp->next = t1;
    }else{
        temp->next = t2;
    }

    return dummy->next;
}

void print(ListNode *head){
    
    ListNode *temp = head;
    while(temp != nullptr){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}
int main(){
    
    vector<int> arr1 = {1,3,5,7};
    vector<int> arr2 = {2,4,6};
    
    ListNode *head1 = ll(arr1);
    ListNode *head2 = ll(arr2);
    
    ListNode *newHead = mergeTwoLists(head1, head2);
    print(newHead);
    
    return 0;
}