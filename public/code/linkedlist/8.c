//8. IMPLEMENT THE OPERATIONS OF DOUBLY CIRCULAR LINKED LIST STORING STRING VALUES
(INSERT AT BEGIN,INSERT AT POS,INSERT AT END,DELETE AT BEGIN,DELETE AT END,
DELETE AT POS, ISEMPTY, ISFULL, DISPLAY, SEARCH)

#include< stdio.h >
#include< stdlib.h >
#include< string.h >

struct Node {
    char data[100];
    struct Node* next;
    struct Node* prev;
};

struct DCLList {
    struct Node* head;
};

struct Node* newNode(const char* value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    strncpy(node->data, value, 100);
    node->next = NULL;
    node->prev = NULL;
    return node;
}

struct DCLList* initList() {
    struct DCLList* list = (struct DCLList*)malloc(sizeof(struct DCLList));
    list->head = NULL;
    return list;
}

int isEmpty(struct DCLList* list) {
    return list->head == NULL;
}

void insertFront(struct DCLList* list, const char* value) {
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

void insertAt(struct DCLList* list, const char* value, int pos) {
    struct Node* node = newNode(value);
    if (pos == 0) {
        insertFront(list, value);
        return;
    }
    struct Node* curr = list->head;
    if (isEmpty(list)) {
        printf("Position out of bounds.\n");
        free(node);
        return;
    }
    for (int i = 0; i < pos - 1 && curr != NULL; i++) {
        curr = curr->next;
        if (curr == list->head) {
            break;
        }
    }
    if (curr == NULL || curr == list->head) {
        printf("Position out of bounds.\n");
        free(node);
        return;
    }
    node->next = curr->next;
    node->prev = curr;
    curr->next->prev = node;
    curr->next = node;
}

void insertEnd(struct DCLList* list, const char* value) {
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

void deleteFront(struct DCLList* list) {
    if (isEmpty(list)) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct Node* temp = list->head;
    if (temp->next == list->head) {
        free(temp);
        list->head = NULL;
    } else {
        struct Node* tail = list->head->prev;
        list->head = temp->next;
        tail->next = list->head;
        list->head->prev = tail;
        free(temp);
    }
}

void deleteEnd(struct DCLList* list) {
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

void deleteAt(struct DCLList* list, int pos) {
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
        if (curr == list->head) {
            break;
        }
    }
    if (curr == NULL || curr == list->head) {
        printf("Position out of bounds.\n");
        return;
    }
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    free(curr);
}

int search(struct DCLList* list, const char* value) {
    struct Node* curr = list->head;
    if (isEmpty(list)) return -1;
    int index = 0;
    do {
        if (strcmp(curr->data, value) == 0) {
            return index;
        }
        curr = curr->next;
        index++;
    } while (curr != list->head);
    return -1;
}

void display(struct DCLList* list) {
    if (isEmpty(list)) {
        printf("List is empty.\n");
        return;
    }
    struct Node* curr = list->head;
    printf("Doubly Circular Linked List: ");
    do {
        printf("%s <-> ", curr->data);
        curr = curr->next;
    } while (curr != list->head);
    printf("(head)\n");
}

int main() {
    struct DCLList* list = initList();
    int n, pos;
    char value[100];

    printf("How many elements do you want to add to the list? ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        printf("Enter string value %d: ", i + 1);
        fgets(value, 100, stdin);
        value[strcspn(value, "\n")] = 0;
        insertEnd(list, value);
    }

    display(list);

    printf("Enter a string to search: ");
    fgets(value, 100, stdin);
    value[strcspn(value, "\n")] = 0;
    printf("Searching for \"%s\": %s\n", value, search(list, value) != -1 ? "Found" : "Not Found");

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

    while (!isEmpty(list)) {
        deleteFront(list);
    }
    free(list);

    return 0;
}



