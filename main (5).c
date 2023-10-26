#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the student structure
struct Student {
    char name[50];
    char roll_number[15];
    float cgpa;
};

// Comparison function for qsort to compare students based on CGPA
int compare_students(const void *a, const void *b) {
    const struct Student *studentA = (const struct Student *)a;
    const struct Student *studentB = (const struct Student *)b;

    if (studentA->cgpa < studentB->cgpa) {
        return 1; // Return a positive value if A's CGPA is less than B's CGPA
    } else if (studentA->cgpa > studentB->cgpa) {
        return -1; // Return a negative value if A's CGPA is greater than B's CGPA
    } else {
        return 0; // Return 0 if CGPAs are equal
    }
}

// Function to sort students based on CGPA in descending order
void sort_students(struct Student students[], int num_students) {
    qsort(students, num_students, sizeof(struct Student), compare_students);
}

int main() {
    // Create an array of students
    struct Student students[] = {
        {"Alice", "A123", 3.75},
        {"Bob", "B234", 3.85},
        {"Charlie", "C345", 3.65},
        {"David", "D456", 3.95},
        {"Eve", "E567", 3.75},
    };

    int num_students = sizeof(students) / sizeof(students[0]);

    // Sort the students based on CGPA
    sort_students(students, num_students);

    // Print the sorted list
    printf("Sorted list of students based on CGPA (descending order):\n");
    for (int i = 0; i < num_students; i++) {
        printf("Name: %s, Roll Number: %s, CGPA: %.2f\n", students[i].name, students[i].roll_number, students[i].cgpa);
    }

    return 0;
}
