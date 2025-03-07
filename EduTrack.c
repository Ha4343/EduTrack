#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    int rollNo;
    char name[50];
    float marks;
};

struct Student students[MAX_STUDENTS];
int studentCount = 0;

// Function to add a new student
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Student database is full!\n");
        return;
    }

    printf("\nEnter Student Name: ");
    scanf(" %[^\n]", students[studentCount].name);
    printf("Enter Roll Number: ");
    scanf("%d", &students[studentCount].rollNo);
    printf("Enter Marks: ");
    scanf("%f", &students[studentCount].marks);

    studentCount++;
    printf("Student added successfully!\n");
}

// Function to display all students
void displayStudents() {
    if (studentCount == 0) {
        printf("\nNo students in the database.\n");
        return;
    }
    printf("\nStudent Records:\n");
    printf("----------------------------\n");
    for (int i = 0; i < studentCount; i++) {
        printf("Roll No: %d\nName: %s\nMarks: %.2f\n", students[i].rollNo, students[i].name, students[i].marks);
        printf("----------------------------\n");
    }
}

// Function to search for a student by roll number
void searchStudent() {
    int roll;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNo == roll) {
            printf("\nStudent Found!\n");
            printf("Name: %s\nMarks: %.2f\n", students[i].name, students[i].marks);
            return;
        }
    }
    printf("Student with Roll No %d not found.\n", roll);
}

// Function to calculate and display the average marks
void calculateAverage() {
    if (studentCount == 0) {
        printf("\nNo students available to calculate average.\n");
        return;
    }

    float totalMarks = 0;
    for (int i = 0; i < studentCount; i++) {
        totalMarks += students[i].marks;
    }
    printf("\nClass Average Marks: %.2f\n", totalMarks / studentCount);
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Student Grade Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Calculate Class Average\n");
        printf("5. Exit\n");
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
                searchStudent();
                break;
            case 4:
                calculateAverage();
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
