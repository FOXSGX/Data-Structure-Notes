#include <iostream>
using namespace std;

//structure
struct Node{
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {} 
};

//help to output
void out(Node* head){
    Node* r = head->next;
    if (r == nullptr) cout << "EMPTY\n";
    else{
        cout << r->data;
        r = r->next;
        while (r != nullptr){
            cout << " " << r->data;
            r = r->next;
        }
        cout << "\n";
    }
}



int main(){
    int n, m;
    cin >> n >> m;

    //input
    Node* tail1 = new Node(0);
    Node* head1 = tail1;
    Node* tail2 = new Node(0);
    Node* head2 = tail2;
    for (int i=0;i<n;i++){
        int x;
        cin >> x;
        tail1->next = new Node(x);
        tail1 = tail1->next;
    }
    for (int i=0;i<m;i++){
        int x;
        cin >> x;
        tail2->next = new Node(x);
        tail2 = tail2->next;
    }
    

    //Interseciton
    Node* head3 = new Node(0);
    Node* tail3 = head3;
    Node* p1 = head1->next;
    Node* p2 = head2->next;
    while (p1 != nullptr && p2 != nullptr){
        if (p1->data == p2->data){
            tail3->next = new Node(p1->data);
            tail3 = tail3->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        else{
            if (p1->data < p2->data) p1 = p1->next;
            else p2 =p2->next;
        }
    }

    //Union
    Node* head4 = new Node(0);
    Node* tail4 = head4;
    Node* q1 = head1->next;
    Node* q2 = head2->next;
    while(q1 != nullptr && q2 != nullptr){
        if (q1->data == q2->data){
            tail4->next = new Node(q1->data);
            tail4 = tail4->next;
            q1 = q1->next;
            q2 = q2->next;
        }
        else if (q1->data < q2->data){
            tail4->next = new Node(q1->data);
            tail4 = tail4->next;
            q1 = q1->next;
        }
        else{
            tail4->next = new Node(q2->data);
            tail4 = tail4->next;
            q2 = q2->next;
        }
    }
    if (q1 == nullptr) {
        while(q2 != nullptr){
            tail4->next = new Node(q2->data);
            tail4 = tail4->next;
            q2 = q2->next;
        }
    }
    if (q2 == nullptr){
        while(q1 != nullptr){
            tail4->next = new Node(q1->data);
            tail4 = tail4->next;
            q1 = q1->next;
        }
    }

    //output
    out(head3);
    out(head4);
}


