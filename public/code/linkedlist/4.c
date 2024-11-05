//4. IMPLEMENT THE OPERATIONS OF DOUBLY CIRCULAR LINKED LIST STORING INTEGER VALUES 
(INSERT AT BEGIN,INSERT AT POS,INSERT AT END,DELETE AT BEGIN,DELETE AT END,
DELETE AT POS, ISEMPTY, ISFULL, DISPLAY, SEARCH)

#include< stdio.h >
#include< stdlib.h >

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct DCList {
    struct Node* head;
};

struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

struct DCList* initList() {
    struct DCList* list = (struct DCList*)malloc(sizeof(struct DCList));
    list->head = NULL;
    return list;
}


int isEmpty(struct DCList* list) {
    return list->head == NULL;
}

void insertFront(struct DCList* list, int value) {
    struct Node* node = newNode(value);
    if (isEmpty(list)) {
        list->head = node;
        node->next = node;
        node->prev = node;
    } else {
        struct Node* tail = list->head->prev;
        node->next = list->head;
        node->prev = tail;
        tail->next = node;
        list->head->prev = node;
        list->head = node;
    }
}


void insertAt(struct DCList* list, int value, int pos) {
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
    curr->next->prev = node;
    curr->next = node;
}


void insertEnd(struct DCList* list, int value) {
    struct Node* node = newNode(value);
    if (isEmpty(list)) {
        list->head = node;
        node->next = node;
        node->prev = node;
    } else {
        struct Node* tail = list->head->prev;
        tail->next = node;
        node->prev = tail;
        node->next = list->head;
        list->head->prev = node;
    }
}


void deleteFront(struct DCList* list) {
    if (isEmpty(list)) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node* temp = list->head;
    if (temp->next == list->head) {
        free(temp);
        list->head = NULL;
    } else {
        struct Node* tail = temp->prev;
        list->head = temp->next;
        tail->next = list->head;
        list->head->prev = tail;
        free(temp);
    }
}


void deleteEnd(struct DCList* list) {
    if (isEmpty(list)) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node* tail = list->head->prev;
    if (tail == list->head) {
        free(tail);
        list->head = NULL;
    } else {
        struct Node* newTail = tail->prev;
        newTail->next = list->head;
        list->head->prev = newTail;
        free(tail);
    }
}


void deleteAt(struct DCList* list, int pos) {
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

    if (curr == NULL || curr == list->head) {
        printf("Position out of bounds.\n");
        return;
    }

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    free(curr);
}


int search(struct DCList* list, int value) {
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


void display(struct DCList* list) {
    if (isEmpty(list)) {
        printf("List is empty.\n");
        return;
    }

    struct Node* curr = list->head;
    printf("Doubly Circular Linked List: ");
    do {
        printf("%d <-> ", curr->data);
        curr = curr->next;
    } while (curr != list->head);
    printf("(head)\n");
}

int main() {
    struct DCList* list = initList();
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

 
