#include <stdio.h>
#include <string.h>

struct student {
        int roll;
        char name[50];
        float cgpa;
};

int main() {
        struct student s1;
        printf("Enter name: ");
        fgets(s1.name, 50, stdin);
        s1.name[strlen(s1.name) - 1] = '\0';
        printf("Enter roll: ");
        scanf("%d", &s1.roll);
        printf("Enter cgpa: ");
        scanf("%f", &s1.cgpa);
        printf("Name: %s, Roll: %d, CGPA: %f", s1.name, s1.roll, s1.cgpa);
        return 0;
}
