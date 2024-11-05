// 3. IMPLEMENT THE OPERATIONS OF DOUBLY LINKED LIST STORING INTEGER VALUES
 (INSERT AT BEGIN,INSERT AT POS,INSERT AT END,DELETE AT BEGIN,DELETE AT END
             DELETE AT POS, ISEMPTY, ISFULL, DISPLAY, SEARCH)
             
    #include< stdio.h >
    #include< stdlib.h >

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct DoublyLinkedList {
    struct Node* head;
};


struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->prev = NULL;
    node->next = NULL;
    return node;
}


struct DoublyLinkedList* initList() {
    struct DoublyLinkedList* list = (struct DoublyLinkedList*)malloc(sizeof(struct DoublyLinkedList));
    list->head = NULL;
    return list;
}


int isEmpty(struct DoublyLinkedList* list) {
    return list->head == NULL;
}


void insertFront(struct DoublyLinkedList* list, int value) {
    struct Node* node = newNode(value);
    if (isEmpty(list)) {
        list->head = node;
    } else {
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
    }
}


void insertAt(struct DoublyLinkedList* list, int value, int pos) {
    struct Node* node = newNode(value);
    if (pos == 0) {
        insertFront(list, value);
        return;
    }

    struct Node* curr = list->head;
    for (int i = 0; i < pos - 1 && curr != NULL; i++) {
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Position out of bounds.\n");
        free(node);
        return;
    }

    node->next = curr->next;
    node->prev = curr;
    curr->next = node;
    if (node->next != NULL) {
        node->next->prev = node;
    }
}

void insertEnd(struct DoublyLinkedList* list, int value) {
    struct Node* node = newNode(value);
    if (isEmpty(list)) {
        list->head = node;
    } else {
        struct Node* curr = list->head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = node;
        node->prev = curr;
    }
}


void deleteFront(struct DoublyLinkedList* list) {
    if (isEmpty(list)) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node* temp = list->head;
    list->head = list->head->next;
    if (list->head != NULL) {
        list->head->prev = NULL;
    }
    free(temp);
}


void deleteEnd(struct DoublyLinkedList* list) {
    if (isEmpty(list)) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node* curr = list->head;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    if (curr->prev != NULL) {
        curr->prev->next = NULL;
    } else {
        list->head = NULL; 
    }
    free(curr);
}


void deleteAt(struct DoublyLinkedList* list, int pos) {
    if (isEmpty(list)) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    if (pos == 0) {
        deleteFront(list);
        return;
    }

    struct Node* curr = list->head;
    for (int i = 0; i < pos && curr != NULL; i++) {
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    if (curr->prev != NULL) {
        curr->prev->next = curr->next;
    }
    if (curr->next != NULL) {
        curr->next->prev = curr->prev;
    }
    free(curr);
}


int search(struct DoublyLinkedList* list, int value) {
    struct Node* curr = list->head;
    int index = 0;
    while (curr != NULL) {
        if (curr->data == value) {
            return index;
        }
        curr = curr->next;
        index++;
    }
    return -1;
}

void display(struct DoublyLinkedList* list) {
    if (isEmpty(list)) {
        printf("List is empty.\n");
        return;
    }

    struct Node* curr = list->head;
    printf("Doubly Linked List: ");
    while (curr != NULL) {
        printf("%d <-> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main() {
    struct DoublyLinkedList* list = initList();
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
         
    
