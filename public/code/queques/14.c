// 14. Length of the longest valid substring
#include < stdio.h >
#include < stdlib.h >

int longestValidParentheses(const char* s) {
    int maxLength = 0;          
    int* stack = (int*)malloc((strlen(s) + 1) * sizeof(int)); 
    int top = -1;               
    int lastInvalid = -1;       

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
          
            stack[++top] = i;
        } else {
            
            if (top != -1) {
                
                top--; // Pop the top element (opening parenthesis)
                if (top == -1) {
                   
                    maxLength = (i - lastInvalid > maxLength) ? (i - lastInvalid) : maxLength;
                } else {
                    
                    maxLength = (i - stack[top] > maxLength) ? (i - stack[top]) : maxLength;
                }
            } else {
                
                lastInvalid = i;
            }
        }
    }

    free(stack); 
    return maxLength; 
}


int main() {
    const char* input1 = "((()";
    const char* input2 = ")()())";
    const char* input3 = "()(()))))";

    printf("Longest valid parentheses length for \"%s\": %d\n", input1, longestValidParentheses(input1));
    printf("Longest valid parentheses length for \"%s\": %d\n", input2, longestValidParentheses(input2));
    printf("Longest valid parentheses length for \"%s\": %d\n", input3, longestValidParentheses(input3));

    return 0;
}

