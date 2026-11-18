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

int main() {
    int choice;

    do {
        printf("\n===== STUDENT RECORD SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            addStudent();
        }
        else if (choice == 2) {
            printf("Thank you!\n");
        }
        else {
            printf("Invalid choice!\n");
        }

    } while (choice != 2);

    return 0;
}
