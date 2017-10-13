#include <stdio.h>
#include <malloc.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

void insertAtTail(int);
void insertAtHead(int);
void insertAtPosition(int,int);
void delete(int);
void search(int);
Node* createNewNode(int);
void print();

Node *head;

int main() {
    int option = 0;
    int data;
    int position;
    while (option != 8){
        printf("Welcome the best demo ever for linkedlist:)\n");
        printf("Choose one submenu!\n");
        printf("1) Insert a node at the head\n");
        printf("2) Insert a node at the tail\n");
        printf("3) Insert a node at a specified position\n");
        printf("4) Delete a node from the linkedlist\n");
        printf("5) Print the list\n");
        printf("6) Search the list\n");
        printf("7) Reset the list\n");
        printf("8) Exit\n");
        scanf("%d", &option);
        switch (option){
            case 1:{
                printf("Enter the number to insert at the head: \n");
                scanf("%d", &data);
                insertAtHead(data);
                break;
            }
            case 2:{
                printf("Enter the number to insert at the tail: \n");
                scanf("%d", &data);
                insertAtTail(data);
                break;
            }
            case 3:{
                printf("Enter the number to insert: \n");
                scanf("%d", &data);
                printf("\nDetermine the position to insert at list: \n");
                scanf("%d", &position);
                insertAtPosition(data, position);
                break;
            }
            case 4:{
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                delete(position);
                break;
            }
            case 5:{
                print();
                break;
            }
            case 6:{
                int query;
                printf("Enter the query to search for: \n");
                scanf("%d", &query);
                search(query);
                break;
            }
            case 7:{
                printf("Resetting the list!\n");
                head = NULL;
                break;
            }
        }
    }
    return 0;
}
void insertAtTail(int data){
    printf("\ninsertAtTail function!\n");
    if(head == NULL){
        printf("The head of the list has not ever assigned!\n");
        Node *temp = createNewNode(data);
        head = temp;
        return;
    }
    Node *newNode = createNewNode(data);
    Node *temp = head;
    while( temp->next != NULL ){
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtHead(int data){
    printf("\ninsertAtHead function!\n");
    if(head ==NULL){
        printf("The head of the list has not ever assigned!\n");
        Node *newNode = createNewNode(data);
        head = newNode;
        return;
    }
    Node *newNode = createNewNode(data);
    newNode->next = head;
    head = newNode;
}

void insertAtPosition(int data, int position){
    printf("\ninsertAtPosition function!\n");
    if(head == NULL){
        printf("The head of the list has not ever assigned!\n");
        if(position == 1){
            Node *newNode = createNewNode(data);
            head = newNode;
        }else{
            printf("So the required position is not reachable at all!\n");
        }
        return;
    }
    if(position == 1){
        insertAtHead(data);
        return;
    }
    Node *temp = head;
    Node *newNode = createNewNode(data);
    int i = 1;
    for ( ; i < position - 1 ; ++i) {
        if( temp != NULL ){
            temp = temp->next;
        }else{
            break;
        }
    }
    if( temp != NULL){
        newNode->next = temp->next;
        temp->next = newNode;
    }else{
        printf("The required position is not reachable!\n");
    }
}

void delete(int position){
    printf("\ndelete function!\n");

}

void print(){
    printf("\nPrint function!\n");
    Node *temp = head;
    if( temp == NULL ){
        printf("The list is empty!\n");
        return;
    }
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void search(int query){
    printf("\nsearch function!\n");

}

Node* createNewNode(int data){
    Node *newNode = realloc(NULL, sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
}