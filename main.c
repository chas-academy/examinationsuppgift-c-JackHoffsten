#include <stdio.h>

#define NUMBER_OF_STUDENTS 5
#define NUMBER_OF_EXAMS 13
#define MAX_NAME_LENGTH 10

void capitalize_name(char name[]) {
  if (name[0] >= 'a' && name[0] <= 'z') {
    name[0] = name[0] - ('a' - 'A');
  }

  for (int i = 1; name[i] != '\0'; i++) {
    if (name[i] >= 'A' && name[i] <= 'Z') {
      name[i] = name[i] + ('a' - 'A');
    }
  }
} 

int main() {
  char names[NUMBER_OF_STUDENTS][MAX_NAME_LENGTH + 1]; 
  float averages[NUMBER_OF_STUDENTS];

  float group_sum = 0.0f;
  int max_average_index = 0;

  for (int i = 0; i < NUMBER_OF_STUDENTS; i++) {
    scanf("%s", names[i]);
    capitalize_name(names[i]);

    int sum = 0;

    for (int j = 0; j < NUMBER_OF_EXAMS; j++) {
      int x;
      scanf("%d", &x);
      sum += x;
    }

    averages[i] = (float)sum / NUMBER_OF_EXAMS;
    group_sum += averages[i];

    if (i != 0 && averages[i] > averages[max_average_index]) {
      max_average_index = i;
    }
  }

  printf("%s\n", names[max_average_index]);

  float group_average = (float)group_sum / NUMBER_OF_STUDENTS;

  for (int i = 0; i < NUMBER_OF_STUDENTS; i++) {
    if (averages[i] < group_average) {
      printf("%s\n", names[i]);
    }
  }

  return 0;
}