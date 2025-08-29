#include <stdio.h>
#include <string.h>

// Function to get the integer value of a Roman numeral character
int roman_value(char c) {
  switch (c) {
  case 'I':
    return 1;
  case 'V':
    return 5;
  case 'X':
    return 10;
  case 'L':
    return 50;
  case 'C':
    return 100;
  case 'D':
    return 500;
  case 'M':
    return 1000;
  default:
    return -1; // Invalid character
  }
}

// Function to convert a Roman numeral string to an integer
int roman_to_arabic(char *s) {
  int result = 0;
  int length = strlen(s);

  for (int i = 0; i < length; i++) {
    int current_val = roman_value(s[i]);

    // Handle subtractive notation (e.g., IV = 4)
    if (i + 1 < length) {
      int next_val = roman_value(s[i + 1]);

      if (current_val < next_val) {
        result += (next_val - current_val);
        i++; // Skip the next character as it's already processed
      } else {
        result += current_val;
      }
    } else {
      result += current_val;
    }
  }
  return result;
}

int main() {
  char roman_numeral[20];

  printf("Enter a Roman numeral: ");
  scanf("%s", roman_numeral);

  int arabic_value = roman_to_arabic(roman_numeral);

  if (arabic_value == -1) {
    printf("Invalid Roman numeral.\n");
  } else {
    printf("Arabic equivalent: %d\n", arabic_value);
  }

  return 0;
}
