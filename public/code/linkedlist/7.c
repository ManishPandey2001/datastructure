// 7. IMPLEMENT THE OPERATIONS OF DOUBLY LINKED LIST STORING STRING VALUES
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

struct DList {
    struct Node* head;
};

struct Node* newNode(const char* value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    strncpy(node->data, value, 100);
    node->next = NULL;
    node->prev = NULL;
    return node;
}

struct DList* initList() {
    struct DList* list = (struct DList*)malloc(sizeof(struct DList));
    list->head = NULL;
    return list;
}

int isEmpty(struct DList* list) {
    return list->head == NULL;
}

void insertFront(struct DList* list, const char* value) {
    struct Node* node = newNode(value);
    if (isEmpty(list)) {
        list->head = node;
    } else {
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
    }
    list->head->prev = NULL;
}

void insertAt(struct DList* list, const char* value, int pos) {
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
    if (curr->next != NULL) {
        curr->next->prev = node;
    }
    curr->next = node;
}

void insertEnd(struct DList* list, const char* value) {
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

void deleteFront(struct DList* list) {
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

void deleteEnd(struct DList* list) {
    if (isEmpty(list)) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct Node* curr = list->head;
    if (curr->next == NULL) {
        free(curr);
        list->head = NULL;
    } else {
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->prev->next = NULL;
        free(curr);
    }
}

void deleteAt(struct DList* list, int pos) {
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

int search(struct DList* list, const char* value) {
    struct Node* curr = list->head;
    int index = 0;
    while (curr != NULL) {
        if (strcmp(curr->data, value) == 0) {
            return index;
        }
        curr = curr->next;
        index++;
    }
    return -1;
}

void display(struct DList* list) {
    if (isEmpty(list)) {
        printf("List is empty.\n");
        return;
    }
    struct Node* curr = list->head;
    printf("Doubly Linked List: ");
    while (curr != NULL) {
        printf("%s <-> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main() {
    struct DList* list = initList();
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



