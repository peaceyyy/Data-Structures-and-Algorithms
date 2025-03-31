#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "checkIfPalindromeLL.c"

void test_isPalindrome_emptyList() {
    ListNode *head = NULL;
    if (isPalindrome(head)) {
        printf("Test empty list: Passed\n");
    } else {
        printf("Test empty list: Failed\n");
    }
}

void test_isPalindrome_singleElement() {
    ListNode *head = createNode(1);
    if (isPalindrome(head)) {
        printf("Test single element: Passed\n");
    } else {
        printf("Test single element: Failed\n");
    }
    freeList(head);
}

void test_isPalindrome_twoElementsPalindrome() {
    ListNode *head = NULL;
    appendNode(&head, 1);
    appendNode(&head, 1);
    if (isPalindrome(head)) {
        printf("Test two elements palindrome: Passed\n");
    } else {
        printf("Test two elements palindrome: Failed\n");
    }
    freeList(head);
}

void test_isPalindrome_twoElementsNotPalindrome() {
    ListNode *head = NULL;
    appendNode(&head, 1);
    appendNode(&head, 2);
    if (!isPalindrome(head)) {
        printf("Test two elements not palindrome: Passed\n");
    } else {
        printf("Test two elements not palindrome: Failed\n");
    }
    freeList(head);
}

void test_isPalindrome_multipleElementsPalindrome() {
    ListNode *head = NULL;
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 2);
    appendNode(&head, 1);
    if (isPalindrome(head)) {
        printf("Test multiple elements palindrome: Passed\n");
    } else {
        printf("Test multiple elements palindrome: Failed\n");
    }
    freeList(head);
}

void test_isPalindrome_multipleElementsNotPalindrome() {
    ListNode *head = NULL;
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    if (!isPalindrome(head)) {
        printf("Test multiple elements not palindrome: Passed\n");
    } else {
        printf("Test multiple elements not palindrome: Failed\n");
    }
    freeList(head);
}

int main() {
    test_isPalindrome_emptyList();
    test_isPalindrome_singleElement();
    test_isPalindrome_twoElementsPalindrome();
    test_isPalindrome_twoElementsNotPalindrome();
    test_isPalindrome_multipleElementsPalindrome();
    test_isPalindrome_multipleElementsNotPalindrome();
    return 0;
}