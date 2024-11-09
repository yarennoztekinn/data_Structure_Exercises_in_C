#include <stdio.h>
#include <stdlib.h>

typedef struct Student{
    char name[20];
    int student_number;
    char course[20];
    float mark;
} student;

void create(student *student){
    printf("\nEnter name: ");
    scanf("%[^\n]%*c", student->name); 

    printf("\nEnter roll number: ");
    scanf("%d", &student->student_number);
    getchar();  // To consume the newline left in the input buffer

    printf("\nEnter the course name: ");
    scanf("%[^\n]%*c", student->course);  // Get course name including spaces

    printf("\nEnter marks: \n");
    scanf("%f", &student->mark);

}

void show(student *student){
    printf("Name: %s\nRoll number: %d\nCourse name: %s\nMarks: %.2f", 
           student->name, student->student_number, student->course, student->mark);
}

int main(){
    student *student1 = (student*)malloc(sizeof(student));

    printf("Please enter the student information: \n");

    create(student1);

    printf("\nThe information you entered:\n");

    show(student1);

    free(student1);//

    return 0;
}
