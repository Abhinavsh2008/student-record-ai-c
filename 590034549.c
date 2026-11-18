#include <stdio.h>

struct Student {
    int sapid;
    int rollno;
    char name[50];
    char phone[15];
    char email[50];
    int year;
    int semester;
    float sgpa[8];
};

struct Student s[100];
int n = 0;

void addStudent() {
    int i;

    if (n >= 100) {
        printf("Student limit reached!\n");
        return;
    }

    printf("Enter SAP ID: ");
    scanf("%d", &s[n].sapid);

    printf("Enter Roll Number: ");
    scanf("%d", &s[n].rollno);

    printf("Enter Name: ");
    scanf(" %49[^\n]", s[n].name);

    printf("Enter Phone Number: ");
    scanf("%14s", s[n].phone);

    printf("Enter Email: ");
    scanf("%49s", s[n].email);

    printf("Enter Year (1-4): ");
    scanf("%d", &s[n].year);

    printf("Enter Semester (1-8): ");
    scanf("%d", &s[n].semester);

    for (i = 0; i < 8; i++) {
        s[n].sgpa[i] = 0;
    }

    for (i = 0; i < s[n].semester && i < 8; i++) {
        printf("Enter SGPA for Semester %d: ", i + 1);
        scanf("%f", &s[n].sgpa[i]);
    }

    n++;
    printf("\nStudent added successfully!\n");
}
void searchStudent() {
    int id, i, found = 0;

    printf("Enter SAP ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < n; i++) {
        if (s[i].sapid == id) {
            printf("\nName: %s", s[i].name);
            printf("\nRoll No: %d", s[i].rollno);
            printf("\nPhone: %s", s[i].phone);
            printf("\nEmail: %s", s[i].email);
            printf("\nYear: %d", s[i].year);
            printf("\nSemester: %d\n", s[i].semester);

            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("Student not found!\n");
    }
}

float calculateCGPA(int i) {
    float sum = 0;
    int j, count = 0;

    for (j = 0; j < 8; j++) {
        if (s[i].sgpa[j] > 0) {
            sum = sum + s[i].sgpa[j];
            count++;
        }
    }

    if (count > 0) {
        return sum / count;
    }

    return 0;
}

void averageCGPAByYear() {
    int year, i, count;
    float sum, cgpa;

    for (year = 1; year <= 4; year++) {
        sum = 0;
        count = 0;

        for (i = 0; i < n; i++) {
            if (s[i].year == year) {
                cgpa = calculateCGPA(i);

                if (cgpa > 0) {
                    sum = sum + cgpa;
                    count++;
                }
            }
        }

        if (count > 0) {
            printf("Year %d Average CGPA: %.2f\n",
                   year, sum / count);
        }
        else {
            printf("Year %d: No CGPA available\n", year);
        }
    }
}

void displayStudents() {
    int i;

    for (i = 0; i < n; i++) {
        printf("\nSAP ID: %d", s[i].sapid);
        printf("\nRoll No: %d", s[i].rollno);
        printf("\nName: %s", s[i].name);
        printf("\nYear: %d", s[i].year);
        printf("\nSemester: %d", s[i].semester);
        printf("\nCGPA: %.2f\n", calculateCGPA(i));
    }
}
int main() {
    int choice;

    do {
        printf("\n===== STUDENT RECORD SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Search Student\n");
        printf("3. Display All Students\n");
        printf("4. Calculate CGPA\n");
        printf("5. Average CGPA By Year\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            addStudent();
        }
        else if (choice == 2) {
            searchStudent();
        }
        else if (choice == 3) {
            displayStudents();
        }
        else if (choice == 4) {
            int i;

            for (i = 0; i < n; i++) {
                printf("%s CGPA: %.2f\n",
                       s[i].name, calculateCGPA(i));
            }
        }
        else if (choice == 5) {
            averageCGPAByYear();
        }
        else if (choice == 6) {
            printf("Thank you!\n");
        }
        else {
            printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}
