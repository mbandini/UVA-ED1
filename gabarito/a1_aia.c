#include <stdio.h>
#define STUDENTS 2
#define TEAMS 4
#define MATCHES 10

typedef struct {
  long code;
  char name[100];
  float grade1;
  float grade2;
  float grade3;
} Student;

typedef struct
{
  long code;
  char name[100];
  int victories;
  int draws;
  int defeats;
  int goal_diff;
} Team;

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

void populate_teams (Team *teams) {
  int i;

  for (i = 0; i < TEAMS; i++) {
    do {
      printf ("Insira o nome do time %d: ", i + 1);
      setbuf(stdin, NULL);
      scanf("%[A-Z a-z 0-9]", teams[i].name);
      printf ("Insira a quantidade de vitórias do time %d: ", i + 1);
      scanf ("%d", &teams[i].victories);
      printf ("Insira a quantidade de empates do time %d: ", i + 1);
      scanf ("%d", &teams[i].draws);
      printf ("Insira a quantidade de derrotas do time %d: ", i + 1);
      scanf ("%d", &teams[i].defeats);
      printf ("Insira o saldo de gols do time %d: ", i + 1);
      scanf ("%d", &teams[i].goal_diff);
      if (teams[i].victories + teams[i].draws + teams[i].defeats != MATCHES) {
        printf ("A quantidade de partidas informadas está incorreta\n");
      }
    } while (teams[i].victories + teams[i].draws + teams[i].defeats != MATCHES);
  }
}

int tournment (Team *teams) {
  int i, champion_points = 0, champion_goal_diff = 0, champion;

  for (i = 0; i < TEAMS; i++) {
    if (((teams[i].victories * 3) + teams[i].draws > champion_points)) {
      champion = i;
      champion_points = (teams[i].victories * 3) + teams[i].draws;
      champion_goal_diff = teams[i].goal_diff;
    }
    if (((teams[i].victories * 3) + teams[i].draws == champion_points) && teams[i].goal_diff > champion_goal_diff) {
      champion = i;
      champion_points = (teams[i].victories * 3) + teams[i].draws;
      champion_goal_diff = teams[i].goal_diff;
    }
  }

  return champion;
}

void max_min (int *v, int N, int *max, int *min) {
  int i;
  *max = *min = v[0];
  for (i = 1; i < N; i++) {
    if (*max < v[i]) {
      *max = v[i];
    }
    if (*min > v[i]) {
      *min = v[i];
    }
  }
}

int bin_search (int *v, int begin, int end, int value) {
  int i = (begin + end) / 2;

  if (begin > end) {
    return -1;
  }
  if (v[i] == value) {
    return i;
  }
  if (v[i] < value) {
    return bin_search (v, i + 1, end, value); // verifica a segunda metade do vetor
  }
  return bin_search (v, begin, i - 1, value);
}

int product (int x, int n) {
  if (n == 0 || x == 0) {
    return 0;
  }
  else {
    return x + product (x, n - 1);
  }
}

int main () {
  int *min, *max, champion;
  Student stud[STUDENTS];
  Team teams[TEAMS];

  populate_teams (teams);
  champion = tournment (teams);

  printf ("Time campeão: %s\n", teams[champion].name);
  printf ("Pontuação do campeão: %d\n", (teams[champion].victories * 3) + teams[champion].draws);

  // populate_students (stud);
  // reports (stud);

  return 0;
}