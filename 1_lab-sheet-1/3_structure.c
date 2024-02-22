/*Store and retrieve the name of the students and obtained marks in c programming in 1st semester 
using structure.*/
#include <stdio.h>

// Define a structure using typedef
typedef struct {
    char name[50];
    float marks;
} Student;

int main() {
    int num_students;

    
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    
    Student students[num_students];

    // take input
    for (int i = 0; i < num_students; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", students[i].name);

        printf("Enter the marks of student %d: ", i + 1);
        scanf("%f", &students[i].marks);
    }

    // display information 
    printf("\nStudent Information:\n");
    for (int i = 0; i < num_students; i++) {
        printf("Name: %s, Marks: %.2f\n", students[i].name, students[i].marks);
    }

    return 0;
}
