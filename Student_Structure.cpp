#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
    char name [20];
    char surname [20];
    int age;
};

struct student *add(char *name, char *surname, int age) {
    struct student *st = static_cast<student *>(malloc(sizeof(struct student)));
    strcpy(st->name, name);
    strcpy(st->surname, surname);
    st->age = age;
    return st;
}

int main(){
    struct student *st[30];
    int student_counter = 0;
    char tmp_name [20];
    char tmp_surname [20];
    int tmp_age;
    char ans[10];

    do {
        printf("%d student:\nName: ", student_counter + 1);
        scanf("%s", &tmp_name);
        printf("Surname: ");
        scanf("%s", &tmp_surname);
        printf("Age: ");
        scanf("%d", &tmp_age);
        st[student_counter] = add(tmp_name, tmp_surname, tmp_age);
        student_counter++;
        printf("End the filling and check the students list? [Y/n]: ");
        getchar();
        scanf("%s", &ans);
    } while (strcmp(ans, "Y")!=0);

    for (int i = 0; i < student_counter; i++) {
        printf("%d. |Name: %s|\t|Surname: %s|\t|%d y.o.|\n", i+1, st[i]->name, st[i]->surname, st[i]->age);
    }

    return 0;
}