#include <stdio.h>
#define STUDENTS 2

typedef struct {
  long code;
  char name[100];
  float grade1;
  float grade2;
  float grade3;
} Student;

void populate_students (Student *s) {
  int i;

  for (i = 0; i < STUDENTS; i++) {
    printf ("insira o código do aluno %d: ", i + 1);
    scanf ("%ld", &s[i].code);
    printf ("insira o nome do aluno %d: ", i + 1);
    setbuf(stdin, NULL);
    scanf("%[A-Z a-z 0-9]", s[i].name);
    printf ("insira a primeira nota do aluno %d: ", i + 1);
    scanf ("%f", &s[i].grade1);
    printf ("insira a segunda nota do aluno %d: ", i + 1);
    scanf ("%f", &s[i].grade2);
    printf ("insira a terceira nota do aluno %d: ", i + 1);
    scanf ("%f", &s[i].grade3);
  }
}

void reports (Student *s) {
  int i, max_avg_index, min_avg_index;
  float avg;
  float max_avg, min_avg;
  max_avg = min_avg = (s[0].grade1 + s[0].grade2 + s[0].grade3) / 3;
  max_avg_index = min_avg_index = 0;

  printf ("\n");
  printf ("CÓDIGO\t|\tNAME\t|\tNOTA 1\t|\tNOTA 2\t|\tNOTA 3\t|\tMEDIA\n");
  for (i = 0; i < STUDENTS; i++) {
    avg = (s[i].grade1 + s[i].grade2 + s[i].grade3) / 3;
    printf ("%ld\t|\t%s\t|\t%f\t|\t%f\t|\t%f\t|\t%f\n", s[i].code, s[i].name, s[i].grade1, s[i].grade2, s[i].grade3, avg);
    if (i > 0) {
      if (avg > max_avg) {
        max_avg = avg;
        max_avg_index = i;
      }
      if (avg < min_avg) {
        min_avg = avg;
        min_avg_index = 1;
      }
    }
  }
  printf ("Aluno com maior média é %s, com valor %f\n", s[max_avg_index].name, max_avg);
  printf ("Aluno com menor média é %s, com valor %f\n", s[min_avg_index].name, min_avg);
  printf ("\n");
}

int main () {
  Student stud[STUDENTS];

  populate_students (stud);
  reports (stud);

  return 0;
}