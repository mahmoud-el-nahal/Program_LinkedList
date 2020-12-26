#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;  
};

static void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node
        = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

static void printList(struct Node *head){

    struct Node *temp;
    temp = head;
    
    while (temp != 0){
    
        printf ("%d -> ", temp -> data);
        temp = temp -> next;
    };
    printf ("\n");
};

int getLength(struct Node *head){
    
    struct Node *temp;
    int count = 0;
    temp = head;
    
    while(temp != 0){
        count++;
        temp = temp -> next;
    };

    printf ( "\nLength is: %d \n" , count );
    return count;
};

static void Reverse(struct Node **head_ref){                                     // Function recevices the head of a linkedlist as an input 
    
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;
    
    while (current != NULL) {
        // Store next
        next = current->next;
 
        // Reverse current node's pointer
        current->next = prev;
 
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    *head_ref = prev;
};

static void DelFromBeg(struct Node **head_ref){

    struct Node *temp;
    temp = *head_ref;
    *head_ref = temp -> next;

    free(temp);
};

static void DelFromPos(struct Node **head_ref ,int pos){
    
    struct Node *prevnode ,*posnode, *nextnode;
    int i = 1;    
    posnode = *head_ref;

    if (*head_ref == 0){
        
            printf ("List is empty");
        }else{

        while (i < pos && posnode != 0){
            prevnode = posnode;
            posnode = posnode -> next;
            nextnode = posnode ->next;
            i++;
        };
        prevnode -> next = nextnode;
        *head_ref = prevnode;

        free(posnode);        
        };
};

static void DelFromEnd(struct Node **head_ref){

    struct Node *prevnode, *temp;
    temp = *head_ref;
    
    while (temp -> next!= 0){
        
        prevnode = temp;
        temp = temp -> next;
    };
    
    prevnode -> next = 0;
    
    free(temp);
};

static void InsertFromBeg(struct Node **head_ref){

    struct Node *temp, *newnode;
    temp = *head_ref;
    newnode = (struct Node *) malloc(sizeof(struct Node));

    printf("Enter the dataue: ");
    scanf ("%d",&newnode -> data);
    *head_ref = newnode;
    newnode -> next = temp;
};

static void InsertFromPos(struct Node **head_ref){
    
    struct Node *prevnode ,*posnode, *nextnode, *newnode;
    newnode = (struct Node *) malloc(sizeof(struct Node));

    int i = 1;
    int pos;
    int count = getLength(*head_ref);
    posnode = *head_ref;

    printf("Enter the Postion: ");
    scanf ("%d",&pos);

    if (pos > count){
        
        printf ("Indataid Position.");
    }else{
                
        while (i < pos && posnode != 0){
            prevnode = posnode;
            posnode = posnode -> next;
            //nextnode = posnode ->next;
            i++;
        };
        
        printf (" Current dataue : %d -> ", posnode -> data);

        printf("Enter the dataue: ");
        scanf ("%d",&newnode -> data);

        newnode -> next = posnode;
        prevnode -> next = newnode;
    };
};

static void InsertFromEnd(struct Node **head_ref){

    struct Node *temp, *newnode;
    temp = *head_ref;
    newnode = (struct Node *) malloc(sizeof(struct Node));

    while (temp -> next != 0){
        temp = temp -> next;
    };

    printf("Enter the value: ");
    scanf ("%d",&newnode -> data);
    temp -> next = newnode;
    newnode -> next = 0;
};

struct Node * CreateLinkedList(struct Node **Emptyhead){
    
    struct Node *head = *Emptyhead, *newnode, *temp;

    int choice = 1;
    
    while (choice){
        
        newnode = (struct Node *) malloc(sizeof(struct Node));

        printf ("Enter Data: ");
        scanf  ("%d", &newnode -> data);

        newnode -> next = 0;

        if (head == 0){
            
            head = newnode;
            temp = head;
        }else{

            temp -> next = newnode;
            temp = newnode;
        }

        printf ("More Data ? Enter 0 for No and  1 for Yes: ");
        scanf  ("%d", &choice);
    };
    return head;
};

struct Node* addTwoNumbers(struct Node** l1, struct Node** l2){

    struct Node anchor  = { .next = NULL }, *curr = &anchor;
    struct Node *prev, *temp = NULL;
    struct Node* newHead = NULL;
    struct Node* current_node_l1 = *l1;             //head of l1
    struct Node* current_node_l2 = *l2;             //head of l2
    
    int carry = 0, sum;
    
    while (current_node_l1 != NULL || current_node_l2 != NULL || carry != 0){
        
        int data1 = (current_node_l1 ? current_node_l1 -> data : 0);
        int data2 = (current_node_l2 ? current_node_l2 -> data : 0) ;
        
        sum = carry +data1 +data2;
        
        carry = (sum >= 10) ? 1 : 0;

        curr = curr->next = malloc(sizeof(struct Node));

        curr->data = sum % 10;
        curr->next = NULL;
        
        if (current_node_l1 != NULL){
            current_node_l1 = current_node_l1 -> next;
        }
        
        if(current_node_l2 != NULL){
            current_node_l2 = current_node_l2 -> next;
        }        
    }
    printList(anchor.next);
    return anchor.next;
}

int main (){

    struct Node* head = 0; 
    struct Node *head_l1  = 0;
    struct Node *head_l2  = 0;

    int num;


    char * temp;

    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 85);
    push(&head, 30);

/* TWO Lists assigned for addTwoNumbers function */
    //First List
    push(&head_l1, 9);
    push(&head_l1, 9);
    push(&head_l1, 9);
    push(&head_l1, 9);
    push(&head_l1, 9);
    push(&head_l1, 9);
    push(&head_l1, 9);

    //Second List
    push(&head_l2, 9);
    push(&head_l2, 9);
    push(&head_l2, 9);
    push(&head_l2, 9);




    /* Display Menu */
    while(1) {

        printf("\n *****************Main Menu 0****************\n");
        printf("\n *  Linked list operations:               *\n");
        printf("\n *    1. Add                              *\n");
        printf("\n *    2. Remove                           *\n");
        printf("\n *    3. Count                            *\n");
        printf("\n *    4. Print                            *\n");
        printf("\n *    5. ReverseList                      *\n");
        printf("\n *    6. AddTWoLists                      *\n");    
        printf("\n *    7. Quit                             *\n");    
        printf("\n ******************************************\n");
        printf("\n Choose an option1 [1-6] : ");
        
        int option1;
        int option2;
        int pos;

        if (scanf("%d", &option1) != 1) {
            printf(" *Error: Indataid input. Press try again.\n");
            scanf("%s", temp); /*this will clear the input buffer */
            continue;
        }

        switch (option1) {
            
            case 1:        /* Add */

                printf("\n **************** 1. Add ******************\n");
                printf("\n *  You Choosed Adding to list Operation  *\n");
                printf("\n *    1. At Beggining                     *\n");
                printf("\n *    2. At Position                      *\n");
                printf("\n *    3. At End                           *\n");
                printf("\n *    4. Go Main Menu                     *\n");
                printf("\n *    5. Quit                             *\n");
                printf("\n ******************************************\n");
                

                if (scanf("%d", &option2) != 1) {
                printf(" *Error: Indataid input. Press try again.\n");
                scanf("%s", temp); /*this will clear the input buffer */
                continue;
                }
                switch (option2) {
            
                    case 1:        /* Add */
                        InsertFromBeg(&head);
                        printList(head);
                        printf("\nPress any key to continue...");
                        getchar();
                        break;
                    
                    case 2:        /* Add */
                        InsertFromPos(&head);
                        printList(head);
                        printf("\nPress any key to continue...");
                        getchar();
                        break;     

                    case 3:        /* Add */
                        InsertFromEnd(&head);
                        printList(head);
                        printf("\nPress any key to continue...");
                        getchar();
                        break;
                    
                    case 4:        /* Go To Main Menu */
                        break;

                    case 5:       /* Exit */
                        return(0);
                        break;

                    default:
                        printf("Indataid Option1. Please Try again.");
                        getchar();
                        
                }


            case 2:        /* Remove */

                printf("\n **************** 2. Remove ***************\n");
                printf("\n * You Choosed Remove from list Operation *\n");
                printf("\n *    1. From Beggining                   *\n");
                printf("\n *    2. From Position                    *\n");
                printf("\n *    3. From End                         *\n");
                printf("\n *    4. Go Main Menu                     *\n");
                printf("\n *    5. Quit                             *\n");
                printf("\n ******************************************\n");
                

                if (scanf("%d", &option2) != 1) {
                printf(" *Error: Indataid input. Press try again.\n");
                scanf("%s", temp); /*this will clear the input buffer */
                continue;
                }
                switch (option2) {
            
                    case 1:        /* Remove */
                        
                        DelFromBeg(&head);
                        printList(head);
                        printf("\nPress any key to continue...");
                        getchar();
                        break;
                    
                    case 2:        /* Remove */
                        
                        if (scanf("%d", &pos) != 1) {
                            printf(" *Error: Indataid input. Press try again.\n");
                            scanf("%s", temp); /*this will clear the input buffer */
                            continue;
                        }

                        if (pos > getLength(head)){
                            printf("\nInvalid Postions Press any key to continue....");
                            getchar();
                            break;
                        }

                        else{
                            DelFromPos(&head, pos);
                            printList(head);
                            printf("\nPress any key to continue...");
                            getchar();
                            break;
                        }
     

                    case 3:        /* Remove */
                        DelFromEnd(&head);
                        printList(head);
                        printf("\nPress any key to continue...");
                        getchar();
                        break;
                    
                    case 4:        /* Go To Main Menu */
                        break;

                    case 5:       /* Exit */
                        return(0);
                        break;

                    default:
                        printf("Indataid Option1. Please Try again.");
                        getchar();
                        
                }


            case 3:    /* Count */
                printf("\nYour linked list contains %d nodes", getLength(head));
                printf("\nPress any key to continue...");
                getchar();
                break;


            case 4: /* Print */
                printf("\nYour linked list contains the following dataues: \n [ ");
                printList(head);
                printf("]\n\nPress any key to continue...");
                getchar();
                break;


            case 5:    /* Reversed */
                printf("\nYour Reversed linked list: \n [ ");
                Reverse(&head);
                printList(head);
                
                printf("\nPress any key to continue...");
                getchar();
                break;


            case 6:    /* Add Two Lists */

                printf("\nEnter first linked list: \n [ ");
                printf("\nGiven linked list \n");
                //CreateLinkedList(&head_l1);
                printList(head_l1);

                printf("\nEnter second linked list: \n [ ");
                printf("\nGiven linked list \n");
                //CreateLinkedList(&head_l2);
                printList(head_l2);

                printf("\nResult: \n [ ");
                addTwoNumbers(&head_l1, &head_l2);
                
                printf("\n Enter 0 to go to main or 7 to quit: ");
                getchar();
                break;


            case 7:    /* Exit */
                return(0);
                break;


            default:
                printf("Indataid Option1. Please Try again.");
                getchar();

            } /* End of Switch */
    } /* End of While */
};


/* // Different Function Decleration in the Link
    //https://www.opentechguides.com/how-to/article/c/141/linkedlist-add-del-print-count.html


typedef struct node_t {
    int data;
    struct node_t *next;
} Node;

Node * add(int, Node *);
Node * remove(int, Node *);
void print(Node *);
int count(Node *);

Node * add(int num, Node *head) {
    Node *new_node;
    new_node = (Node *) malloc(sizeof(Node));
    new_node->data = num;
    new_node->next= head;
    head = new_node;
return head;
}


*/

// Modifiy this program for better use.

// ALL THE Important functions to deal with linked lists.
// CHECK OUT How to change Static voide to Node *
// As in test1.c

// ADD NEW FUNCTIONS