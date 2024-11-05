//6.MPLEMENT THE OPERATIONS OF SINGLE CIRCULAR LINKED LIST STORING STRING VALUES 
(INSERT AT BEGIN,INSERT AT POS,INSERT AT END,DELETE AT BEGIN,DELETE AT END, DELETE AT POS,
ISEMPTY, ISFULL, DISPLAY, SEARCH)

#include< stdio.h >
#include< stdlib.h >
#include< string.h >

struct Node {
    char data[100];
    struct Node* next;
};

struct CList {
    struct Node* head;
};

struct Node* newNode(const char* value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    strncpy(node->data, value, 100);
    node->next = NULL;
    return node;
}

struct CList* initList() {
    struct CList* list = (struct CList*)malloc(sizeof(struct CList));
    list->head = NULL;
    return list;
}

int isEmpty(struct CList* list) {
    return list->head == NULL;
}

void insertFront(struct CList* list, const char* value) {
    struct Node* node = newNode(value);
    if (isEmpty(list)) {
        list->head = node;
        node->next = node;
    } else {
        struct Node* tail = list->head;
        while (tail->next != list->head) {
            tail = tail->next;
        }
        node->next = list->head;
        tail->next = node;
        list->head = node;
    }
}

void insertAt(struct CList* list, const char* value, int pos) {
    struct Node* node = newNode(value);
    if (pos == 0) {
        insertFront(list, value);
        return;
    }
    if (isEmpty(list)) {
        printf("Position out of bounds.\n");
        free(node);
        return;
    }
    struct Node* curr = list->head;
    for (int i = 0; i < pos - 1 && curr->next != list->head; i++) {
        curr = curr->next;
    }
    if (curr->next == list->head) {
        printf("Position out of bounds.\n");
        free(node);
        return;
    }
    node->next = curr->next;
    curr->next = node;
}

void insertEnd(struct CList* list, const char* value) {
    struct Node* node = newNode(value);
    if (isEmpty(list)) {
        list->head = node;
        node->next = node;
    } else {
        struct Node* tail = list->head;
        while (tail->next != list->head) {
            tail = tail->next;
        }
        tail->next = node;
        node->next = list->head;
    }
}

void deleteFront(struct CList* list) {
    if (isEmpty(list)) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct Node* temp = list->head;
    if (temp->next == list->head) {
        free(temp);
        list->head = NULL;
    } else {
        struct Node* tail = list->head;
        while (tail->next != list->head) {
            tail = tail->next;
        }
        list->head = temp->next;
        tail->next = list->head;
        free(temp);
    }
}

void deleteEnd(struct CList* list) {
    if (isEmpty(list)) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct Node* curr = list->head;
    if (curr->next == list->head) {
        free(curr);
        list->head = NULL;
    } else {
        struct Node* prev = NULL;
        while (curr->next != list->head) {
            prev = curr;
            curr = curr->next;
        }
        free(curr);
        prev->next = list->head;
    }
}

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
    for (int i = 0; i < pos - 1 && curr->next != list->head; i++) {
        curr = curr->next;
    }
    if (curr->next == list->head) {
        printf("Position out of bounds.\n");
        return;
    }
    struct Node* temp = curr->next;
    curr->next = temp->next;
    free(temp);
}

int search(struct CList* list, const char* value) {
    if (isEmpty(list)) return -1;
    struct Node* curr = list->head;
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

void display(struct CList* list) {
    if (isEmpty(list)) {
        printf("List is empty.\n");
        return;
    }
    struct Node* curr = list->head;
    printf("Singly Circular Linked List: ");
    do {
        printf("%s -> ", curr->data);
        curr = curr->next;
    } while (curr != list->head);
    printf("(head)\n");
}

int main() {
    struct CList* list = initList();
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




