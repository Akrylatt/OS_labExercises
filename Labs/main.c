#include <stdio.h>

struct node{

  struct node *right;
  int value;

};

struct linkedList{
  struct node *right;
};

void addElement(int value, struct linkedList* head, struct node *newNode){
  struct node* oldFirst = head->right;
  newNode->value = value;

  head->right = newNode;
  newNode->right = oldFirst;

}

void deleteElement(int toDelete, struct linkedList* head){
    struct node* previous = NULL;
    if(head->right == NULL){
        return;
    }
    struct node* current = head->right;
    while(current != NULL){
        if(current->value == toDelete){
            if(previous == NULL){
                head->right = current->right;
            }
            else{
                previous->right = current->right;
            }
            return;
        }
        previous = current;
        current = current->right;
    }
}

void printList(struct linkedList *n) {
    struct node *t = n->right;
    while (t->right != NULL) {
        printf("%d ", t->value);
        t = t->right;
    }
    printf("%d ", t->value);

}
int main() {
    struct node n;
    struct node n2;
    struct node n3;
    struct node n4;
    n.value = 0;
    n.right = NULL;

    struct linkedList list;
    list.right = &n;

    addElement(1, &list, &n2);
    addElement(2, &list, &n3);
    addElement(3, &list, &n4);

    printList(&list);
    printf("\n");

    deleteElement(0, &list);
    deleteElement(2, &list);

    printList(&list);

    return 0;
}