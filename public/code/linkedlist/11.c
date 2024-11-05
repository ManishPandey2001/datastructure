      
//11. ENTER THE 2 POLYNOMIAL EQUATIONS DYNAMICALLY, MULTIPLY THEM AND DISPLAY THE ANSWER.

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
            curr->coeff += coeff; // Combine terms
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

struct Term* multiplyPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;
    for (struct Term* curr1 = poly1; curr1 != NULL; curr1 = curr1->next) {
        for (struct Term* curr2 = poly2; curr2 != NULL; curr2 = curr2->next) {
            int newCoeff = curr1->coeff * curr2->coeff;
            int newExp = curr1->exp + curr2->exp;
            insertTerm(&result, newCoeff, newExp);
        }
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

    struct Term* result = multiplyPolynomials(poly1, poly2);
    printf("Resulting Polynomial (First * Second): ");
    displayPolynomial(result);

    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);

    return 0;
}


     
