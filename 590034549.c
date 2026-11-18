#include <stdio.h>
#include<string.h>

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

void deleteStudent() {
    int id, i, j, found = 0;

    printf("Enter SAP ID to delete: ");
    scanf("%d", &id);

    for (i = 0; i < n; i++) {
        if (s[i].sapid == id) {
            for (j = i; j < n - 1; j++) {
                s[j] = s[j + 1];
            }

            n--;
            found = 1;
            printf("Student deleted successfully!\n");
            break;
        }
    }

    if (found == 0) {
        printf("Student not found!\n");
    }
}

void sortBySAP() {
    int i, j;
    struct Student temp;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (s[i].sapid > s[j].sapid) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    printf("Students sorted by SAP ID!\n");
    displayStudents();
}

void sortByName() {
    int i, j;
    struct Student temp;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(s[i].name, s[j].name) > 0) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    printf("Students sorted by Name!\n");
    displayStudents();
}

void academicAdvisor() {
    int i;
    float cgpa;

    if (n == 0) {
        printf("No student records available!\n");
        return;
    }

    for (i = 0; i < n; i++) {
        cgpa = calculateCGPA(i);

        printf("\nStudent: %s\n", s[i].name);
        printf("CGPA: %.2f\n", cgpa);

        if (cgpa == 0) {
            printf("No SGPA available.\n");
        }
        else if (cgpa >= 9) {
            printf("Excellent Performance!\n");
            printf("Maintain your current study pattern.\n");
        }
        else if (cgpa >= 8) {
            printf("Good Performance!\n");
            printf("Keep practicing and improve weak subjects.\n");
        }
        else if (cgpa >= 6) {
            printf("Needs Improvement!\n");
            printf("Focus more on subjects with lower SGPA.\n");
        }
        else {
            printf("Requires Immediate Attention!\n");
            printf("Follow a study timetable and seek teacher guidance.\n");
        }
    }
}
int main() {
    int choice, i;

    do {
        printf("\n===== STUDENT RECORD SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Search Student\n");
        printf("3. Display All Students\n");
        printf("4. Calculate CGPA\n");
        printf("5. Average CGPA By Year\n");
        printf("6. Delete Student\n");
        printf("7. Sort By SAP ID\n");
        printf("8. Sort By Name\n");
        printf("9. AI Academic Advisor\n");
        printf("10. Exits\n");

        printf("Enter your choice: ");
        if(scanf("%d",&choice) != 1){
            printf("Invalid input or input ended!\n");
            break;
        }

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
            for (i = 0; i < n; i++) {
                printf("%s CGPA: %.2f\n",
                       s[i].name, calculateCGPA(i));
            }
        }
        else if (choice == 5) {
            averageCGPAByYear();
        }
        else if (choice == 6) {
            deleteStudent();
        }
        else if (choice == 7) {
            sortBySAP();
        }
        else if (choice == 8) {
            sortByName();
        }
        else if (choice == 9) {
            academicAdvisor();
        }
        else if(choice == 10){
            printf("Thank you!\n");
        }
        else {
            printf("Invalid choice!\n");
        }

    } while (choice != 10);

    return 0;
}
