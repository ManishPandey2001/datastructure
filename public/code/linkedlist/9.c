//9. ENTER THE 2 POLYNOMIAL EQUATIONS DYNAMICALLY, ADD THEM AND DISPLAY THE ANSWER.

#include< stdio.h >
#include< stdlib.h >

struct Term {
    int coeff;
    int exp;
    struct Term* next;
};

struct Term* createTerm(int coeff, int exp) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    newTerm->coeff = coeff;
    newTerm->exp = exp;
    newTerm->next = NULL;
    return newTerm;
}

void insertTerm(struct Term** head, int coeff, int exp) {
    struct Term* newTerm = createTerm(coeff, exp);
    if (*head == NULL || (*head)->exp < exp) {
        newTerm->next = *head;
        *head = newTerm;
    } else {
        struct Term* curr = *head;
        while (curr->next != NULL && curr->next->exp > exp) {
            curr = curr->next;
        }
        if (curr->exp == exp) {
            curr->coeff += coeff; // Combine like terms
            free(newTerm);
        } else {
            newTerm->next = curr->next;
            curr->next = newTerm;
        }
    }
}

void displayPolynomial(struct Term* head) {
    if (head == NULL) {
        printf("0");
        return;
    }
    struct Term* curr = head;
    while (curr != NULL) {
        if (curr->coeff > 0 && curr != head) {
            printf("+");
        }
        printf("%dx^%d ", curr->coeff, curr->exp);
        curr = curr->next;
    }
    printf("\n");
}

struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;
    struct Term* curr1 = poly1;
    struct Term* curr2 = poly2;

    while (curr1 != NULL) {
        insertTerm(&result, curr1->coeff, curr1->exp);
        curr1 = curr1->next;
    }
    while (curr2 != NULL) {
        insertTerm(&result, curr2->coeff, curr2->exp);
        curr2 = curr2->next;
    }
    return result;
}

void freePolynomial(struct Term* head) {
    struct Term* curr = head;
    while (curr != NULL) {
        struct Term* next = curr->next;
        free(curr);
        curr = next;
    }
}

int main() {
    struct Term* poly1 = NULL;
    struct Term* poly2 = NULL;
    int n, coeff, exp;

    printf("Enter number of terms for first polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent (e.g., 3 2 for 3x^2): ");
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly1, coeff, exp);
    }

    printf("Enter number of terms for second polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent (e.g., 4 1 for 4x^1): ");
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly2, coeff, exp);
    }

    printf("First Polynomial: ");
    displayPolynomial(poly1);
    printf("Second Polynomial: ");
    displayPolynomial(poly2);

    struct Term* result = addPolynomials(poly1, poly2);
    printf("Resulting Polynomial: ");
    displayPolynomial(result);

    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);

    return 0;
}




       