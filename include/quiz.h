#ifndef QUIZ_H
#define QUIZ_H

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_OPTION_LENGTH 50
#define MAX_QUESTION_LENGTH 100

/* Structure to store one quiz question */
struct Question {
    char questionText[MAX_QUESTION_LENGTH];
    char options[MAX_OPTIONS][MAX_OPTION_LENGTH];
    int correctOption;   /* 0 to 3 */
};

/* Functions used in the program */
void addQuestion(void);
void displayQuestions(void);
void conductQuiz(void);
void clearInputBuffer(void);
