/*
   family3.c

   Lee A. Christie

   Reads a 3-bit fuction class from STDIN space-separated e.g.
     7 4 4 1 4 1 1 0

   Computes and outputs the class with its Walsh family to STDOUT e.g.
     [7, 4, 4, 1, 4, 1, 1, 0]        {0B, 3F, 4B, 7F}

  Terminates on non-numberical input marker e.g.
     END

  Suggested usage:
     ./family3 <all.txt >out.txt

*/

#include <stdio.h>

/* Returns the structure of the given specific function by appplying
   the Fast Walsh-Hadamard Transform (FWHT) and converting the
   resulting non-zero structure to a numerical code. */
int find_structure(int* f) {
  int rv = 0;
  int ff[16];
  ff[0] = f[0] + f[4];
  ff[1] = f[1] + f[5];
  ff[2] = f[2] + f[6];
  ff[3] = f[3] + f[7];
  ff[4] = f[0] - f[4];
  ff[5] = f[1] - f[5];
  ff[6] = f[2] - f[6];
  ff[7] = f[3] - f[7];
  ff[8] = ff[0] + ff[2];
  ff[9] = ff[1] + ff[3];
  ff[10] = ff[0] - ff[2];
  ff[11] = ff[1] - ff[3];
  ff[12] = ff[4] + ff[6];
  ff[13] = ff[5] + ff[7];
  ff[14] = ff[4] - ff[6];
  ff[15] = ff[5] - ff[7];
  if (ff[8] - ff[9]) rv += 1;
  if (ff[10] + ff[11]) rv += 2;
  if (ff[10] - ff[11]) rv += 4;
  if (ff[12] + ff[13]) rv += 8;
  if (ff[12] - ff[13]) rv += 16;
  if (ff[14] + ff[15]) rv += 32;
  if (ff[14] - ff[15]) rv += 64;
  return rv;
}

/* Returns the number of distinct values for a specified class. */
int calc_num_ranks(int* clazz) {
  int rv = 0;
  int i, j, is_new;
  for (i = 0; i < 8; i++) {
    is_new = 1;
    for (j = 0; j < i-1; j++) {
      if (clazz[i] == clazz[j]) {
        is_new = 0;
      }
    }
    if (is_new) {
      rv++;
    }
  }
  return rv;
}

/* Finds the class for a specified funtion. */
void function_to_class(int* function, int* clazz) {
  int i, j, num_lower;
  for (i = 0; i < 8; i++) {
    num_lower = 0;
    for (j = 0; j < 8; j++) {
      if (function[j] < function[i]) {
        num_lower++;
      }
    }
    clazz[i] = num_lower;
  }
}

/* Converts a clazz in-place into tokens for replacement. */
void tokenise(int* clazz) {
  int used;
  int rank, i;
  int token = -1;
  for (rank = 0; rank < 8; rank++) {
    used = 0;
    for (i = 0; i < 8; i++) {
      if (clazz[i] == rank) {
        clazz[i] = token;
        used = 1;
      }
    }
    if (used) {
      token--;
    }
  }
}

/* Creates an instance specified tokeneized class as fitnesses
   with the given values. */
void detokenise(int* t_clazz, int* fitnesses, int* vals) {
  int i;
  for (i = 0; i < 8; i++) {
    fitnesses[i] = vals[-t_clazz[i] - 1];
  }
}

/* Computes the Walsh family for the specified tokenised
   class with 3 distinct ranks. */
void find_family_3(int* t_clazz, int* family) {
  int v[3], f[8];
  for (v[0] = 0; v[0] <= 2; v[0]++) {
    for (v[1] = v[0] + 1; v[1] <= 3; v[1]++) {
      for (v[2] = v[1] + 1; v[2] <= 4; v[2]++) {
        detokenise(t_clazz, f, v);
        family[find_structure(f)] = 1;
}}}}

/* Computes the Walsh family for the specified tokenised
   class with 4 distinct ranks. */
void find_family_4(int* t_clazz, int* family) {
  int v[4], f[8];
  for (v[0] = 0; v[0] <= 4; v[0]++) {
    for (v[1] = v[0] + 1; v[1] <= 5; v[1]++) {
      for (v[2] = v[1] + 1; v[2] <= 6; v[2]++) {
        for (v[3] = v[2] + 1; v[3] <= 7; v[3]++) {
          detokenise(t_clazz, f, v);
          family[find_structure(f)] = 1;
}}}}}

/* Computes the Walsh family for the specified tokenised
   class with 5 distinct ranks. */
void find_family_5(int* t_clazz, int* family) {
  int v[5], f[8];
  for (v[0] = 0; v[0] <= 6; v[0]++) {
    for (v[1] = v[0] + 1; v[1] <= 7; v[1]++) {
      for (v[2] = v[1] + 1; v[2] <= 8; v[2]++) {
        for (v[3] = v[2] + 1; v[3] <= 9; v[3]++) {
          for (v[4] = v[3] + 1; v[4] <= 10; v[4]++) {
            detokenise(t_clazz, f, v);
            family[find_structure(f)] = 1;
}}}}}}

/* Computes the Walsh family for the specified tokenised
   class with 6 distinct ranks. */
void find_family_6(int* t_clazz, int* family) {
  int v[6], f[8];
  for (v[0] = 0; v[0] <= 7; v[0]++) {
    for (v[1] = v[0] + 1; v[1] <= 8; v[1]++) {
      for (v[2] = v[1] + 1; v[2] <= 9; v[2]++) {
        for (v[3] = v[2] + 1; v[3] <= 10; v[3]++) {
          for (v[4] = v[3] + 1; v[4] <= 11; v[4]++) {
            for (v[5] = v[4] + 1; v[5] <= 12; v[5]++) {
              detokenise(t_clazz, f, v);
              family[find_structure(f)] = 1;
}}}}}}}

/* Computes the Walsh family for the specified tokenised
   class with 7 distinct ranks. */
void find_family_7(int* t_clazz, int* family) {
  int v[7], f[8];
  for (v[0] = 0; v[0] <= 8; v[0]++) {
    for (v[1] = v[0] + 1; v[1] <= 9; v[1]++) {
      for (v[2] = v[1] + 1; v[2] <= 10; v[2]++) {
        for (v[3] = v[2] + 1; v[3] <= 11; v[3]++) {
          for (v[4] = v[3] + 1; v[4] <= 12; v[4]++) {
            for (v[5] = v[4] + 1; v[5] <= 13; v[5]++) {
              for (v[6] = v[5] + 1; v[6] <= 14; v[6]++) {
                detokenise(t_clazz, f, v);
                family[find_structure(f)] = 1;
}}}}}}}}

/* Computes the Walsh family for the specified tokenised
   class with 8 distinct ranks. */
void find_family_8(int* t_clazz, int* family) {
  int v[8], f[8];
  for (v[0] = 0; v[0] <= 8; v[0]++) {
    for (v[1] = v[0] + 1; v[1] <= 9; v[1]++) {
      for (v[2] = v[1] + 1; v[2] <= 10; v[2]++) {
        for (v[3] = v[2] + 1; v[3] <= 11; v[3]++) {
          for (v[4] = v[3] + 1; v[4] <= 12; v[4]++) {
            for (v[5] = v[4] + 1; v[5] <= 13; v[5]++) {
              for (v[6] = v[5] + 1; v[6] <= 14; v[6]++) {
                for (v[7] = v[6] + 1; v[7] <= 15; v[7]++) {
                  detokenise(t_clazz, f, v);
                  family[find_structure(f)] = 1;
}}}}}}}}}

/* Computes the Walsh fmaily for the specified class. */
void find_family(int* clazz, int* family) {
  int i, num_ranks;
  /* Clears the array to store the Walsh family. */
  for (i = 0; i < 128; i++) {
    family[i] = 0;
  }
  num_ranks = calc_num_ranks(clazz);
  if (num_ranks == 1) {
    /* Family is always {00}. */
    family[0] = 1;
  } else if (num_ranks == 2) {
    /* Family contains only one element. */
    family[find_structure(clazz)] = 1;
  } else {
    tokenise(clazz);
    switch (num_ranks) {
      case 3:
        find_family_3(clazz, family);
      break;
      case 4:
        find_family_4(clazz, family);
      break;
      case 5:
        find_family_5(clazz, family);
      break;
      case 6:
        find_family_6(clazz, family);
      break;
      case 7:
        find_family_7(clazz, family);
      break;
      case 8:
        find_family_8(clazz, family);
      break;
    }
  }
}

/* Prints the specified funciton to STDOUT in decimal. */
void print_function(int* function) {
  int i;
  printf("[");
  for (i = 0; i < 8; i++) {
    if (i != 0) {
      printf(", ");
    }
    printf("%d", function[i]);
  }
  printf("]\t");
}

/* Prints the specified Walsh family to STDOUT in hex. */
void print_family(int* family) {
  int i, first = 1;
  printf("{");
  for (i = 0; i < 128; i++) {
    if (family[i]) {
      if (!first) {
        printf(", ");
      }
      printf("%02X", i);
      first = 0;
    }
  }
  printf("}\n");
}

/* Main method. */
int main(void) {
  int done = 0;
  int f[8];
  int clazz[8];
  int family[128];
  while(!done) {
    /* Reads a function. */
    if (scanf("%d %d %d %d %d %d %d %d",
          f, f+1, f+2, f+3, f+4, f+5, f+6, f+7)) {
      /* Gets the class. */
      function_to_class(f, clazz);
      /* Outputs the class. */
      print_function(clazz);
      /* Calculates the Walsh family. */
      find_family(clazz, family);
      /* Outputs the Walsh family */
      print_family(family);
    } else {
      done = 1;
    }
  }
  return 0;
}