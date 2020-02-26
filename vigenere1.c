#include <stdio.h>

int main() {
  FILE * fp;
  int c;
  int n = 0, i = 0;
  int distance = 0;
  // int fre[1000]={0};
  int nfr[1000] = {
    0
  };
  nfr[145] = 1263;
  nfr[146] = 64;
  nfr[147] = 162;
  nfr[148] = 155;
  nfr[149] = 895;
  nfr[150] = 31;
  nfr[151] = 456;
  nfr[152] = 116;
  nfr[153] = 880;
  nfr[154] = 359;
  nfr[155] = 254;
  nfr[156] = 327;
  nfr[157] = 590;
  nfr[158] = 42;
  nfr[159] = 920;
  nfr[160] = 395;
  nfr[161] = 412;
  nfr[163] = 667;
  nfr[164] = 761;
  nfr[165] = 391;
  nfr[166] = 72;
  nfr[167] = 123;
  nfr[168] = 15;
  nfr[169] = 194;

  int k = 0;
  int str[1000];
  fp = fopen("file.txt", "r");
  if (fp == NULL) {
    perror("Error in opening file");
    return (-1);
  }
  while ((c = fgetc(fp)) != EOF) {
    if (c == 206) continue;
    str[i] = c;
    i++;
  }
  int starting = 0;
  int starting1 = 0;
  while (starting != i - 6) {
    starting1 = starting + 1;

    while (starting1 != i - 5) {
      if (str[starting] == str[starting1] && str[starting + 1] == str[starting1 + 1] && str[starting + 2] == str[starting1 + 2]) //&& str[starting+3]==str[starting1+3]
      {
        printf("%c%c %c%c %c%c  ", 206, str[starting], 206, str[starting + 1], 206, str[starting + 2]);
        printf("%d %d\n", starting, starting1 - starting);
      }

      starting1++;

    }

    starting++;
  }
  int r = 0;
  int l = 0;
  int
  let = 0;
  //int letters[25]={0};
  //int original[25]={0};
  int or = 0;
  int keylenght = 5;
  int g = 0;
  int key[1000] = {
    0
  };
  for (g = 0; g < keylenght; g++) {
    int letters[25] = {
      0
    };
    int original[25] = {
      0
    };
    let = 0;
    or = 0;
    int fre[24] = {
      0
    };
    int alllet = 0;
    for (l = g; l < i - 1; l = l + keylenght) {
      if (fre[str[l]] == 0) {
        letters[let] = str[l];
        let ++;
        original[or] = str[l];
        or++;
      }
      fre[str[l]]++;
      alllet++;
    }
    int y = 0;
    for (y = 0; y < 9; y++)
      fre[162 + y] = fre[163 + y];
    for (y = 0; y < 24; y++)
      fre[y] = fre[145 + y];
    printf("SECTION\n");
    for (r = 0; r < 25; r++) {
      printf(" %c%c %d %d\n", 206, str[r], fre[145 + r] * 100 / alllet, alllet); //*10000/let);
    }
    int j = 0;
    int h = 0;
    int temp;
    int sum = 0;
    int shift = 0;
    int max = 0;
    for (h = 0; h < 24; h++) {
      for (j = 0; j < 24; j++) {
        //printf("%c%c %d  %d\n",206,letters[j], nfr[original[j]],10000*fre[letters[j]]/let);
        if (145 + j == 162) sum = sum + nfr[163] * fre[j];
        else sum = sum + nfr[145 + j] * fre[j];
      }
      if (sum > max) {
        max = sum;
        shift = h;
      }
      printf("sum=%d  max=%d\n", sum, max);
      sum = 0; {
        temp = fre[0];
        int d;
        temp = fre[0];
        for (d = 0; d < 23; d++)
          fre[d] = fre[d + 1];
        fre[d] = temp;
      }
    }
    key[g] = shift;
  }
  for (g = 0; g < keylenght; g++)

  {
    printf("%d  ", key[g]);
  }

  //int max=0;
  //int shift=0;
  //int j=0;
  //int sum=0
  //for(j=0;j<let;j++)
  //{ 

  int conv = 0;
  int u = 0;
  int w = 0;
  for (conv = 0; conv < i; conv++) {
    u = conv % 5;
    for (w = 0; w < key[u]; w++) {
      str[conv]--;
      if (str[conv] == 162) str[conv]--;
      else if (str[conv] == 144) str[conv] = 169;;

    }
    printf("%c%c", 206, str[conv]);
  }

  fclose(fp);
  return (0);
}