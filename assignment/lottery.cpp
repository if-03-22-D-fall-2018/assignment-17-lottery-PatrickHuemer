/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			lottery.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * Implementation of a library for analyzing lottery tips.
 *-----------------------------------------------------------------------------
*/
#include <stdio.h>
#include "lottery.h"

FILE* fd;
int draw[TIP_SIZE];
char seperator;

#define 	UUID_LEN   40
#define 	MAX_TIP_LEN   17
#define 	MAX_LINE_LEN   (UUID_LEN + 1 + MAX_TIP_LEN + 1)


bool 	init_lottery (const char *csv_file, char csv_separator){
  fd = fopen(csv_file,"r");
  seperator = csv_separator;

  for (int i = 0; i < TIP_SIZE; i++) {
    draw[i] = 0;
  }
  return fd != 0;
}

int char_to_int(char* chars, int count){
  int number = 0;

  for (int i = 0; i < count; i++) {
    number = number * 10 + chars[i] - '0';
  }
  return number;
}

int search_start(char* line){
  for (int i = 0; i < MAX_LINE_LEN; i++) {
    if (line[i] == seperator) {
      return i+1;
    }
  }
  return -1;
}

bool 	get_tip (int tip_number, int tip[TIP_SIZE]){
  char line[MAX_LINE_LEN];
  fseek(fd, 0, SEEK_SET);

  if (tip_number < 0) {
    return false;
  }

  for (int i = 0; i < count; i++) {
    if (fgets(line, MAX_LINE_LEN, fd) == 0) {
      return false;
    }
  }

  int idx = 0, count = 0;
  for (int i = 0; i < count; i++) {
    char numbers[2];

    if (line[i] == seperator || line[i] == '\n' || line[i] == '\0') {
      tip[idx++] = char_to_int(numbers, count);
      count = 0;
      if (index == TIP_SIZE) {
        break;
      }
    }
    else{
      numbers[count++] = line[i];
    }
  }
  return true;
}
bool 	set_drawing (int drawing_numbers[TIP_SIZE]){
  for (int i = 0; i < TIP_SIZE; i++) {
    if (drawing_numbers[i] < 1 || drawing_numbers[i] > 45) {
      return false;
    }
    drawing[i] = drawing_numbers[i];
  }
  return true;
}

int 	get_tip_result (int tip_number){
  return -1;
}
int 	get_right_tips_count (int right_digits_count){
  return -1;
}
