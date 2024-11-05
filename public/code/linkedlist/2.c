//2. IMPLEMENT THE OPERATIONS OF SINGLE CIRCULAR LINKED LIST STORING INTEGER VALUES.
(INSERT AT BEGIN,INSERT AT POS,INSERT AT END,DELETE AT BEGIN,DELETE AT END,
                          DELETE AT POS, ISEMPTY, ISFULL, DISPLAY, SEARCH)
                          
        #include<stdio.h >
       #include<stdlib.h >

struct Node {
    int data;
    struct Node* next;
};

struct CList {
    struct Node* head;
};

//  new node
struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->next = node;  // Pointing to itself
    return node;
}

//  circular list
struct CList* initList() {
    struct CList* list = (struct CList*)malloc(sizeof(struct CList));
    list->head = NULL;
    return list;
}

//  empty
int isEmpty(struct CList* list) {
    return list->head == NULL;
}

// Insert at the beginning
void insertFront(struct CList* list, int value) {
    struct Node* node = newNode(value);
    if (isEmpty(list)) {
        list->head = node;
    } else {
        struct Node* tail = list->head;
        while (tail->next != list->head) {
            tail = tail->next;
        }
        tail->next = node;
    }
    node->next = list->head;
    list->head = node;
}

// Insert at a specific position
void insertAt(struct CList* list, int value, int pos) {
    struct Node* node = newNode(value);
    if (pos == 0) {
        insertFront(list, value);
        return;
    }

    struct Node* curr = list->head;
    for (int i = 0; i < pos - 1 && curr != NULL; i++) {
        curr = curr->next;
        if (curr == list->head) break;
    }

    if (curr == NULL || curr->next == list->head) {
        printf("Position out of bounds.\n");
        free(node);
        return;
    }

    node->next = curr->next;
    curr->next = node;
}

// Insert at the end
void insertEnd(struct CList* list, int value) {
    struct Node* node = newNode(value);
    if (isEmpty(list)) {
        list->head = node;
    } else {
        struct Node* tail = list->head;
        while (tail->next != list->head) {
            tail = tail->next;
        }
        tail->next = node;
    }
    node->next = list->head;
}

// Delete at the beginning
void deleteFront(struct CList* list) {
    if (isEmpty(list)) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node* tail = list->head;
    while (tail->next != list->head) {
        tail = tail->next;
    }

    if (list->head == tail) {
        free(list->head);
        list->head = NULL;
    } else {
        struct Node* temp = list->head;
        tail->next = list->head->next;
        list->head = list->head->next;
        free(temp);
    }
}

// Delete at the end
void deleteEnd(struct CList* list) {
    if (isEmpty(list)) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node* tail = list->head;
    struct Node* prev = NULL;

    while (tail->next != list->head) {
        prev = tail;
        tail = tail->next;
    }

    if (prev == NULL) {
        free(tail);
        list->head = NULL;
    } else {
        free(tail);
        prev->next = list->head;
    }
}

//  specific position
void deleteAt(struct CList* list, int pos) {
    if (isEmpty(list)) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    if (pos == 0) {
        deleteFront(list);
        return;
    }

    struct Node* curr = list->head;
    struct Node* prev = NULL;

    for (int i = 0; i < pos && curr != NULL; i++) {
        prev = curr;
        curr = curr->next;
        if (curr == list->head) break;
    }

    if (curr == NULL || curr == list->head) {
        printf("Position out of bounds.\n");
        return;
    }

    prev->next = curr->next;
    free(curr);
}

// Search  value in  list
int search(struct CList* list, int value) {
    if (isEmpty(list)) return -1;

    struct Node* curr = list->head;
    int index = 0;
    do {
        if (curr->data == value) {
            return index;
        }
        curr = curr->next;
        index++;
    } while (curr != list->head);

    return -1;
}

// Display the list
void display(struct CList* list) {
    if (isEmpty(list)) {
        printf("List is empty.\n");
        return;
    }

    struct Node* curr = list->head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", curr->data);
        curr = curr->next;
    } while (curr != list->head);
    printf("(head)\n");
}


int main() {
    struct CList* list = initList();
    int n, value, pos;

    printf("How many elements do you want to add to the list? ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        insertEnd(list, value);
    }

    display(list);

    printf("Enter a value to search: ");
    scanf("%d", &value);
    printf("Searching for %d: %s\n", value, search(list, value) != -1 ? "Found" : "Not Found");

    printf("Deleting at the beginning...\n");
    deleteFront(list);
    display(list);

    printf("Deleting at the end...\n");
    deleteEnd(list);
    display(list);

    printf("Enter position to delete: ");
    scanf("%d", &pos);
    deleteAt(list, pos);
    display(list);
    
    return 0;
}
                  

     



              