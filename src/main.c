#include <stdio.h>
#include "quiz.h"

int main(void) {
    int choice;

    while (1) {
        printf("\n===== Online Quiz Application =====\n");
        printf("1. Add Question\n");
        printf("2. Display Questions\n");
        printf("3. Conduct Quiz\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            printf("Invalid input.\n");
            continue;
        }

        switch (choice) {
            case 1:
                addQuestion();
                break;
            case 2:
                displayQuestions();
                break;
            case 3:
                conductQuiz();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}