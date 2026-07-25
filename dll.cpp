#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *back;
    Node(int d, Node *n, Node *b){
        data = d;
        next = n;
        back = b;
    }
};

Node *covertToDll(vector<int> arr){
    Node *head = new Node(arr[0], nullptr, nullptr);
    Node *prev = head;

    for(int i = 1; i < arr.size(); i++){
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node *head){
    Node *temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node *delhead(Node *head){
    if(head == NULL || head->next == NULL) return NULL;
    Node *temp = head;
    head = temp->next;
    head->back = nullptr;
    temp->next = nullptr;
    delete temp;
    return head;
}

Node *deltail(Node *head){
    if(head == NULL || head->next == NULL) return NULL;
    Node *tail = head;
    while(tail != nullptr){
        if(tail->next == nullptr){
            tail->back->next = nullptr;
            tail->back = nullptr;
            delete tail;
        }
        tail = tail->next;
    }
    return head;
}

Node *delkth(Node *head, int k){
    Node *temp = head;
    int cnt = 0;
    while(temp != nullptr){
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }
    Node *prev = temp->back;
    Node *front = temp->next;
    if(prev == NULL && front == NULL){
        delete temp;
        return NULL;
    }else if(prev == NULL){
        Node *t = delhead(head);
        return t;
    }
    else if(front == NULL){
        Node *t = deltail(head);
        return t;
    }
    else{
        prev->next = temp->next;
        front->back = temp->back;
        temp->next = nullptr;
        temp->back = nullptr;
        delete temp;

        return head;
    }
}

Node *insertByValue(Node *head, int val, int k){
    Node *prev = head;
    Node *temp = head;

    while(temp != nullptr){
        if(temp->data == k){
            Node *n = new Node(val, nullptr, nullptr);
            n->next = prev->next;
            prev->next = n;
            n->back = temp->back;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *inserthead(Node *head, int val){
    Node *n = new Node(val, nullptr, nullptr);
    n->next = head;
    head->back = n;
    return n;
}

Node *insertBeforeTail(Node *head, int val){
    Node *n = new Node(val, nullptr, nullptr);
    Node *temp = head;

    while(temp->next!= nullptr){
        temp = temp->next;
    }

    n->next = temp;
    n->back = temp->back;
    n->back->next = n;

    return head; 
}

Node *insertBeforeKth(Node *head, int val, int k){
    Node *temp = head;
    int cnt = 0;
    while(temp != nullptr){
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }

    Node *n = new Node(val, nullptr, nullptr);
    n->next = temp;
    n->back = temp->back;
    temp->back->next = n;

    return head;
}
int main(){
    vector<int> arr = {3,4,2,1,7};
    Node *head1 = covertToDll(arr);

    //print(head1);
    //Node *head2 = delhead(head1);
    //print(head2);

    //print(head1);
    //Node *head2 = deltail(head1);
    //print(head2);

    print(head1);
    Node *head2 = insertBeforeKth(head1, 100,2);
    print(head2);

    return 0;
}