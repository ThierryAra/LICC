// Manage_students
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct manage_students {
    unsigned short int age;
    int ID;
    char *name;
    char *course;
} Student;

char *receive_strings ();
void search_student_course (Student *students, int ID, int amount_students, char *course);
void print_students (Student *students, int amount_students);

int main (){

    int option, amount_students = 0, stop = 0, ID;
    Student *student_list = malloc (1 * sizeof(Student));

    // Receiving all the students
    while (stop == 0) {
        scanf ("%i", &ID);
        getchar();
        if (ID == -1) {
            stop = 1;
        } else {
            amount_students++;
            student_list = realloc (student_list, amount_students * sizeof(Student));
            student_list[amount_students - 1].ID = ID; 
            student_list[amount_students - 1].name = receive_strings();
            student_list[amount_students - 1].course = receive_strings();
            scanf ("%hu", &student_list[amount_students - 1].age);
        }
    }

    char *course = NULL;
    scanf ("%i", &option);
    while (option != -1) {
        getchar();
        switch (option) { 
        case 1:
            scanf ("%i", &ID);
            search_student_course (student_list, ID, amount_students, " ");
            break;
        case 2:
            course = receive_strings();
            search_student_course (student_list, 0101, amount_students, course);
            free (course);
            break;
        case 3:
            print_students (student_list, amount_students);
            break;
        }
        scanf ("%i", &option);
    }
    
    for (int i = 0; i < amount_students; i++){
        free (student_list[i].course);
        free (student_list[i].name);
    }
    free (student_list);
    return 0;
}

char *receive_strings () {
    char input;
    char *string = NULL;
    int i = 1;

    input = getchar();
    while (input != '\n' && input != '$') {
        string = (char*)realloc(string, i * sizeof(char *));
        *(string + (i - 1)) = input;
        i++;
        input = getchar();
    }

    // Adding '\0' to the end of the string
    string = realloc(string, i * sizeof(char *));
    *(string + (i - 1)) = '\0';
    return string;
}

void search_student_course (Student *students, int ID, int amount_students, char *course){   
    for (int i = 0; i < amount_students; i++)
    {
        if (students[i].ID == ID || strcmp(students[i].course,course) == 0){
            printf ("Nome: %s\n", students[i].name); // Name:
            printf ("Curso: %s\n", students[i].course); // Course:
            printf ("N USP: %i\n", students[i].ID); // ID USP:
            printf ("IDADE: %hu\n\n", students[i].age); // Age:
        }
    }
}

void print_students (Student *students, int amount_students){  
    for (int i = 0; i < amount_students; i++)
    {
        printf ("Nome: %s\n", students[i].name);
        printf ("Curso: %s\n", students[i].course);
        printf ("N USP: %i\n", students[i].ID);
        printf ("IDADE: %hu\n\n", students[i].age);
    }
}