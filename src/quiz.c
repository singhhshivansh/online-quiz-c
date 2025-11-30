#include <stdio.h>
#include <string.h>
#include "quiz.h"

/* Global question list (only in this file) */
static struct Question questions[MAX_QUESTIONS];
static int questionCount = 0;

/* Clear leftover characters from input buffer */
void clearInputBuffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        /* do nothing */
    }
}

/* Add a new question */
void addQuestion(void) {
    if (questionCount >= MAX_QUESTIONS) {
        printf("Cannot add more questions. Limit reached.\n");
        return;
    }

    struct Question *q = &questions[questionCount];
    int optionNumber;

    clearInputBuffer();   /* remove newline left by previous scanf */

    printf("Enter the question text:\n");
    fgets(q->questionText, MAX_QUESTION_LENGTH, stdin);
    q->questionText[strcspn(q->questionText, "\n")] = '\0';

    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf("Enter option %d:\n", i + 1);
        fgets(q->options[i], MAX_OPTION_LENGTH, stdin);
        q->options[i][strcspn(q->options[i], "\n")] = '\0';
    }

    printf("Enter correct option (1-4): ");
    if (scanf("%d", &optionNumber) != 1) {
        clearInputBuffer();
        printf("Invalid input. Setting correct option to 1.\n");
        optionNumber = 1;
    }

    if (optionNumber < 1 || optionNumber > 4) {
        printf("Invalid option. Setting correct option to 1.\n");
        optionNumber = 1;
    }

    q->correctOption = optionNumber - 1;
    questionCount++;

    printf("Question added successfully.\n");
}

/* Display all stored questions */
void displayQuestions(void) {
    if (questionCount == 0) {
        printf("No questions to display.\n");
        return;
    }

    for (int i = 0; i < questionCount; i++) {
        printf("\nQuestion %d: %s\n", i + 1, questions[i].questionText);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("  %d) %s\n", j + 1, questions[i].options[j]);
        }
        printf("Correct option: %d\n", questions[i].correctOption + 1);
    }
}

/* Conduct quiz and show score */
void conductQuiz(void) {
    if (questionCount == 0) {
        printf("No questions available for quiz.\n");
        return;
    }

    int score = 0;
    int answer;

    for (int i = 0; i < questionCount; i++) {
        printf("\nQuestion %d: %s\n", i + 1, questions[i].questionText);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("  %d) %s\n", j + 1, questions[i].options[j]);
        }

        printf("Enter your answer (1-4): ");
        if (scanf("%d", &answer) != 1) {
            clearInputBuffer();
            printf("Invalid input. This question will be marked wrong.\n");
            answer = -1;
        }

        if (answer == questions[i].correctOption + 1) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong. Correct answer: %d) %s\n",
                   questions[i].correctOption + 1,
                   questions[i].options[questions[i].correctOption]);
        }
    }

    printf("\nYou scored %d out of %d.\n", score, questionCount);
}