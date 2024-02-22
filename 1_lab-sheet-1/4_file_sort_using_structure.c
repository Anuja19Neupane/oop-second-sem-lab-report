/* Write a program to read name, rollno, address, and phone number of each student in your class using structure.
 Store the information in file so that you can recover the information later. 
While recovering the information from the file sort the information alphabetically according to the name.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a student
typedef struct {
    char name[50];
    int rollno;
    char address[100];
    char phone_number[15];
} Student;

// Function to compare two student names for sorting
int compareNames(const void *a, const void *b) {
    return strcmp(((Student*)a)->name, ((Student*)b)->name);
}

int main() {
    int numStudents;

    // Get input
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Declare an array of structures to store information for each student
    Student students[numStudents];

    // Input information for each student
    for (int i = 0; i < numStudents; i++) {
        printf("\nEnter information for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);

        printf("Roll Number: ");
        scanf("%d", &students[i].rollno);

        printf("Address: ");
        scanf("%s", students[i].address);

        printf("Phone Number: ");
        scanf("%s", students[i].phone_number);
    }

    // Write information to a file
    FILE *file = fopen("student_info.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    fwrite(students, sizeof(Student), numStudents, file);
    fclose(file);

    // Read information from the file
    file = fopen("student_info.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    fread(students, sizeof(Student), numStudents, file);
    fclose(file);

    // Sort the information alphabetically by name
    qsort(students, numStudents, sizeof(Student), compareNames);

    // Display sorted information
    printf("\nSorted Student Information:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Roll Number: %d\n", students[i].rollno);
        printf("Address: %s\n", students[i].address);
        printf("Phone Number: %s\n", students[i].phone_number);
    }

    return 0;
}
