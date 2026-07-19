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

ListNode *findMiddle(ListNode *head){

    ListNode *slow = head;
    ListNode *fast = head->next;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode *mergeSort(ListNode *left, ListNode *right){

    ListNode *dummy = new ListNode(-1);
    ListNode *temp = dummy;

    while(left != nullptr && right != nullptr){
        if(left->val <= right->val){
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    if(left){
        temp->next = left;
    }else{
        temp->next = right;
    }

    return dummy->next;
}

ListNode* sortList(ListNode* head) {

    if(head == nullptr || head->next == nullptr) return head;

    ListNode *middle = findMiddle(head);
    ListNode *left = head;
    ListNode *right = middle->next;
    middle->next = nullptr;

    left = sortList(left);
    right = sortList(right);
    return mergeSort(left, right);
}

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


void print(ListNode *head){
    
    ListNode *temp = head;
    while(temp != nullptr){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}

int main(){
    
    vector<int> arr1 = {1,3,5,44,8,0,7};
    
    ListNode *head1 = ll(arr1);

    ListNode *newHead = sortList(head1);
    print(newHead);
    
    return 0;
}
