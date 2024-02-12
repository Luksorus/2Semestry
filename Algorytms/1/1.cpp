#include <bits/stdc++.h>

using namespace std;

struct node{
    node *left;
    node *right;
    int data;
    int h ;
    node(int value):left(nullptr),right(nullptr),data(value),h(0){}
};

int geth(node*n){
    if (n == nullptr){
        return -1;
    }else{
        return n->h;
    }

}
void f5(node*&t){
    t->h = max(geth(t->left), geth(t->right))+1;

}

node* searchn(node*&t, int key){
    if(t ==nullptr ){
        return nullptr;
    }
    if( (t -> data) == key){
       return t;
    }
    else{
       return searchn((t-> data > key)? t->left: t->right,key);
    }

}

void insert(node*& root, int data){
    if( (root -> data) > data){
        if( root -> left == nullptr){
            root -> left = new node(data);
        }
        else{
            insert(root ->left, data);
        }
    }
    else{
        if( root -> right == nullptr){
            root -> right = new node(data);
        }
        else{
            insert(root ->right, data);
        }
    }
    f5(root);
}

void printnode(node*& root){
    if(root == nullptr){
        return;
    }
    else{
        printnode(root-> left);
        cout << root -> data << endl;
        printnode(root -> right);
    }
}

node* generator(int data){
    node *p = new node(rand()%100) ;
    for(int i = 0; i < data ;i++){
        insert(p,rand()%100);
    }
    return p;

}



node *getMax(node *&n) {
    if (n == nullptr) return nullptr;
    if (n->right == nullptr) return n;
    return getMax(n->right);
}

node *delNode(node *&n, int key) {
    if (n == nullptr) return nullptr;
    else if (n->data > key) n->left = delNode(n->left, key);
    else if (n->data< key) n->right = delNode(n->right, key);
    else {
        if (n->left == nullptr || n->right == nullptr)
            n = (n->left == nullptr) ? n->right : n->left;
        else {
            node *maxLeft = getMax(n->left);
            n->data = maxLeft->data;
            n->left = delNode(n->left, maxLeft->data);
        }
    }
    if (n!= nullptr) f5(n);
    return n;
}




int main() {
    srand(time(0));
    node* no = generator(10);
    cout<< "h" << endl;
    cout << no->h+1 << endl;
    cout<< "search" << endl;
    insert(no,90);
    printnode(no);
    cout << searchn(no, 90) << endl;
    no = delNode(no,90);
    printnode(no);
}
