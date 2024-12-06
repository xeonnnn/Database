#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

// Structure to store student information
struct Student {
    int id;
    char name[50];
    float marks;
};

// Global array to store students
struct Student students[MAX_STUDENTS];
int studentCount = 0;

// Function to add a student
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Student limit reached!\n");
        return;
    }

    struct Student s;
    printf("Enter student ID: ");
    scanf("%d", &s.id);
    printf("Enter student name: ");
    getchar(); // To consume the newline character left by scanf
    fgets(s.name, 50, stdin);
    s.name[strcspn(s.name, "\n")] = '\0'; // Remove trailing newline
    printf("Enter student marks: ");
    scanf("%f", &s.marks);

    students[studentCount++] = s;
    printf("Student added successfully!\n");
}

// Function to display all students
void displayStudents() {
    if (studentCount == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\nStudent Records:\n");
    printf("ID\tName\t\tMarks\n");
    printf("--------------------------------\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%d\t%s\t\t%.2f\n", students[i].id, students[i].name, students[i].marks);
    }
    printf("\n");
}

// Function to save students to a file
void saveToFile() {
    FILE *file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        fprintf(file, "%d,%s,%.2f\n", students[i].id, students[i].name, students[i].marks);
    }

    fclose(file);
    printf("Students saved to file successfully!\n");
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Save to File\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                saveToFile();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}