#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    node* next;
};


class linkedList {
protected:
    node* head;
public:
    linkedList();
    bool Insert(int e, int pos);//在链表的pos位置插入data：e
    void Delete(int pos);//删除链表的pos位置的节点
    void Print();
    //~linkedList();
};

//构造函数，用于创建链表
linkedList::linkedList() :head(NULL) {}

//添加节点
bool linkedList::Insert(int e, int pos) {
    node* newnode = new node();
    newnode->data = e;
    newnode->next = NULL;

    if (pos == 0) {//if pos=0,update head
        newnode->next = head;
        head = newnode;
        return true;
    }
    else if (pos > 0) {
        node* tmpPtr = head;
        for (int i = 0; i < pos - 1 && tmpPtr != NULL; i++) {//让tmpPtr指向pos的前一个节点
            tmpPtr = tmpPtr->next;
        }
        if (tmpPtr == NULL) {
            // Position is out of bounds
            delete newnode;
            return false;
        }
        newnode->next = tmpPtr->next;
        tmpPtr->next = newnode;
        return true;

    }
    else {
        return false;
    }
}

///删除节点
void linkedList::Delete(int pos) {
    if (pos == 0) {
        node* temp = head;
        head = head->next;
        delete temp;
    }
    else {
        node* tmpPtr = head;
        for (int i = 0; i < pos - 1 && tmpPtr != NULL; i++) {
            tmpPtr = tmpPtr->next;
        }
        node* temp = tmpPtr;
        tmpPtr->next = tmpPtr->next->next;
        delete temp->next;
    }
}

void linkedList::Print() {
    node* tmpPtr = new node();//用于遍历链表的指针
    tmpPtr = head;
    while (tmpPtr != NULL) {
        printf("%d ", tmpPtr->data);
        node* tmp = tmpPtr;
        tmpPtr = tmpPtr->next;
    }
    printf("\n");
}
int main() {
    linkedList ll;
    ll.Insert(3, 0);
    ll.Insert(2, 1);
    ll.Print();
    ll.Delete(1);
    ll.Print();
    return 0;

}