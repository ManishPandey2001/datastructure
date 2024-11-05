//5. IMPLEMENT THE OPERATIONS OF SINGLE LINKED LIST STORING STRING VALUES
(INSERT AT BEGIN,INSERT AT POS,INSERT AT END,DELETE AT BEGIN,DELETE AT END,
DELETE AT POS, ISEMPTY, ISFULL, DISPLAY, SEARCH)            
                
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

struct Node {
    char data[MAX_STR_LEN];
    struct Node* next;
};

struct SList {
    struct Node* head;
};

struct Node* newNode(const char* value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    strncpy(node->data, value, MAX_STR_LEN);
    node->next = NULL;
    return node;
}

struct SList* initList() {
    struct SList* list = (struct SList*)malloc(sizeof(struct SList));
    list->head = NULL;
    return list;
}

int isEmpty(struct SList* list) {
    return list->head == NULL;
}

void insertFront(struct SList* list, const char* value) {
    struct Node* node = newNode(value);
    node->next = list->head;
    list->head = node;
}

void insertAt(struct SList* list, const char* value, int pos) {
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
    curr->next = node;
}

void insertEnd(struct SList* list, const char* value) {
    struct Node* node = newNode(value);
    if (isEmpty(list)) {
        list->head = node;
    } else {
        struct Node* curr = list->head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = node;
    }
}

void deleteFront(struct SList* list) {
    if (isEmpty(list)) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct Node* temp = list->head;
    list->head = list->head->next;
    free(temp);
}

void deleteEnd(struct SList* list) {
    if (isEmpty(list)) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct Node* curr = list->head;
    if (curr->next == NULL) {
        free(curr);
        list->head = NULL;
    } else {
        while (curr->next->next != NULL) {
            curr = curr->next;
        }
        free(curr->next);
        curr->next = NULL;
    }
}

void deleteAt(struct SList* list, int pos) {
    if (isEmpty(list)) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    if (pos == 0) {
        deleteFront(list);
        return;
    }
    struct Node* curr = list->head;
    for (int i = 0; i < pos - 1 && curr != NULL; i++) {
        curr = curr->next;
    }
    if (curr == NULL || curr->next == NULL) {
        printf("Position out of bounds.\n");
        return;
    }
    struct Node* temp = curr->next;
    curr->next = temp->next;
    free(temp);
}

int search(struct SList* list, const char* value) {
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

void display(struct SList* list) {
    if (isEmpty(list)) {
        printf("List is empty.\n");
        return;
    }
    struct Node* curr = list->head;
    printf("Singly Linked List: ");
    while (curr != NULL) {
        printf("%s -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main() {
    struct SList* list = initList();
    int n, pos;
    char value[MAX_STR_LEN];

    printf("How many elements do you want to add to the list? ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        printf("Enter string value %d: ", i + 1);
        fgets(value, MAX_STR_LEN, stdin);
        value[strcspn(value, "\n")] = 0;
        insertEnd(list, value);
    }

    display(list);

    printf("Enter a string to search: ");
    fgets(value, MAX_STR_LEN, stdin);
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




   