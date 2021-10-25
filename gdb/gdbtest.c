#include <stdio.h>
#define MAX_STUDENTS 4

typedef struct Student Student;

struct Student {
    char name[20];
    int age;
    int score;
};

int printStudant(Student* s) {
    printf("----- Student Status -----\n");
    printf("Name = %s\n", s->name);
    printf("Age = %d\n", s->age);
    printf("score = %d\n", s->score);
}

char getStudentGrade(int score) {
    if (score >= 90) return 'A';
    else if (score >= 80) return 'B';
    else if (score >= 70) return 'C';
    else if (score >= 60) return 'D';
    else return 'F';
}

int main(void) {
    Student s[3] = {{"John", 15, 80}, {"Eric", 15, 65}, {"Chris", 15, 50}};

    for (int i = 0; i < MAX_STUDENTS; i++) {
        printStudant(&s[i]);
        
        char grade = getStudentGrade(s[i].score);
        if (grade == 'A' || grade == 'B') {
            printf("Good Grade\n");
        }
        else {
            printf("Bad Grade\n");
        }
    }
    return 0;
}
