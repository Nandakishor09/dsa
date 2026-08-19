#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int value;
    int exp;
    Node *next;
    Node(int data, Node *address, int e){
        value = data;
        next = address;
        exp = e;
    }
    Node(int data, int e){
        value = data;
        exp = e;
        next = nullptr;
    }
};

void print(Node *head){

    Node *temp = head;
    while(temp != nullptr){
        cout<<temp->value<<"^"<<temp->exp<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node *createLL(vector<int> arr, vector<int> exp){
    Node *head = new Node(arr[0], exp[0]);
    Node *temp = head;

    for(int i = 1; i < arr.size(); i++){
        Node *newnode = new Node(arr[i], exp[i]);
        temp->next = newnode;
        temp = newnode;
    }

    return head;
}

Node *polyAddition(Node *head1, Node *head2){

    Node *curr1 = head1;
    Node *curr2 = head2;
    Node *dummy = new Node(-1,-1);
    Node *newhead = dummy;

    while(curr1 != nullptr && curr2 != nullptr){

        if(curr1->exp == curr2->exp){
            int add = curr1->value + curr2->value;
            Node *newnode = new Node(add, curr1->exp);
            newnode->next = nullptr;
            dummy->next = newnode;
            dummy = newnode;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        else if(curr1->exp > curr2->exp){
            //curr1->next = nullptr;
            dummy->next = curr1;
            dummy = curr1;
            curr1 = curr1->next;
        }
        else if(curr2->exp > curr1->exp){
            //curr2->next = nullptr;
            dummy->next = curr2;
            dummy = curr2;
            curr2 = curr2->next;
        }
    }
    if(curr1){
        dummy->next = curr1;
    }
    else if(curr2){
        dummy->next = curr2;
    }

    return newhead->next;
}

int main(){

    vector<int> arr1 = {4,5,6};
    vector<int> expArr1 = {7,1,0};

    vector<int> arr2 = {7,8,9};
    vector<int> expArr2 = {9,1,0};

    Node *head1 = createLL(arr1, expArr1);
    Node *head2 = createLL(arr2, expArr2);

    print(head1);
    print(head2);

    Node *addition = polyAddition(head1,head2);

    print(addition);


    return 0;
}
