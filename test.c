#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct Node{
    int data;
    struct Node* next;
};

typedef struct Node Name;

typedef struct Node* head_ref;

void insertNodeSelected(Name** head_ref, int new_data);
void printList(Name* head);
void deleteList(Name**, head_ref)

int main(int argc, char* argv[]){
    if(argc !=4){
        printf("Error: program needds atleast 3 integer CLA\n");
        return 1;
    }

    //Parsing the CLA
    int seed= atoi(argv[1]);
    int num_nodes = atoi(argv[2]);
    int max_num = atoi(argv[3]);

    //validating the input values for the user 
    if(seed <=0 || num_nodes <=0 || max_num <=0){
        printf("Error: all CLA must be positive integers inputted\n");
        return 1;
    }

    //seeding the random number generator
    srand(seed);

    Name* head= NULL;

    //integrate a loop to generate random numbers and insert to the linked list

    for (int i=0; i < num_nodes; i++){
        //generate a random number from [0, max_num]
        int new_data = rand() % (max_num + 1);

        //print the random number 
        printf("%d\n", new_data);

        //inserting a new node,sorted,to the list
        insertNodeSelected(&head_ref, new_data); //head replacement for head_ref
    }

    //printing the sorted list
    //function call
    printf("Sorted linked list:\n");
    printList(&Name, head); // replacement for deleeting just the name and leaving &head

    //delete the linked list
    deleteList(&head_ref); // replacement (&head) 

    return 0;
}

void insertNodeSelected(Name** head_ref, int new_data){
    //malloc for new node
    Name* new_node=(Name*)malloc(sizeof(Name));
    new_node->data=new_data;

    //if list is empty or the node is smaller than what is placed at head 
    //make it the new head
    if(*head_ref == NULL || new_data < (*head_ref)->data){
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else{
        //transversing the list to find the correct possition to insert the new node
        Name* current = *head_ref;
        while(current->next !=NULL && current->next->data <= new_data){
            current = current->next;
        }

        //insert the new node in the current position
        new_node->next = current->next;
        current->next = new_node;
    }
}

//Function to print the linked list in sorted order
void printList(Name* head){
    Name* current = head;
    while(current != NULL){
        printf("%d\n", current->data);
        current = current->next;
    }
}

//function on deleting the linked list
void deleteList(Name** head_ref){
    Name* current = *head_ref;
    Name* next;
    while (current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
    *head_ref = NULL;
}
