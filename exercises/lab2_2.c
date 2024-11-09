#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    char name[20];
    int student_number;
    char course[20];
    float mark;
} student;

void create(student *student) {
    printf("\nEnter name: ");
    scanf("%[^\n]%*c", student->name); // Read name with spaces

    printf("\nEnter roll number: ");
    scanf("%d", &student->student_number);
    getchar();

    printf("\nEnter the course name: ");
    scanf("%[^\n]%*c", student->course); // Read course name with spaces

    printf("\nEnter marks: ");
    scanf("%f", &student->mark);
    getchar();
}

void show(student *student) {
    printf("\nName: %s\nRoll number: %d\nCourse name: %s\nMarks: %.2f\n", 
           student->name, student->student_number, student->course, student->mark);
}

int main() {
    printf("Please enter the student information: \n");

    student stu[5]; // Array to store 5 students

    // Loop to input information for 5 students
    for (int i = 0; i < 5; i++) {
        create(&stu[i]); // Pass address of each student in the array
    }

    int i;
    printf("\nPlease enter the number of student to display information (0-4):\n");
    scanf("%d", &i);

    // Validate the input index
    if (i < 0 || i > 4) {
        printf("\nThere is no student at that index.\n");
    } else {
        show(&stu[i]); // Display the information of the selected student
    }

    return 0;
}
