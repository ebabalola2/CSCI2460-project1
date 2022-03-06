#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUFF_SIZE 100



void replaces(char * buff, char* given, char* replace)
{
    int index = 0, length;
    char * ptr, temp_BUFF[BUFF_SIZE];

    length = strlen(given);
    while((ptr = strstr(buff, given)) != NULL)
    {
        strcpy(temp_BUFF, buff);
        index = ptr - buff;
        buff[index] = '\0';
        strcat(buff, replace);
        strcat(buff, temp_BUFF + index + length);
    }
    
}

int main(int argc, char * argv[])
{
    FILE * f_ptr, * f_temp, * f_count;  // Opening file
    char buffer[BUFF_SIZE], read[100]; // assgining a buffer

  // seeing the right number of argument is given
  if (argc < 3)
  {
      fprintf(stderr, "Not Enough Arguments\n");
      exit(1);
  }

  if((f_ptr = fopen(argv[1], "r")) == NULL)
  {
      perror("No Text File To READ\n");
      exit(1);

  }
// find the length of the given word and replace word then make them into chars. 

int length1 = 0;
int length2 = 0;
int occur = 0;
length1 = strlen(argv[2]);
length2 = strlen(argv[3]);

char given[length1 +1];
char replace[length2 + 1];

strcpy(given, argv[2]);
strcpy(replace, argv[3]);

// Make a new file to save the new text after the word is replace.
f_ptr = fopen(argv[1], "r");
f_temp = fopen("temp.txt", "w");

while ((fgets(buffer,BUFF_SIZE,f_ptr)) != NULL)
{
    replaces(buffer,given,replace);
    fputs(buffer,f_temp);
}
fclose(f_temp);

f_count = fopen("temp.txt", "r");
while(!feof(f_count))
{
    fscanf(f_count, "%s", read);
    if(strcmp(read, replace)== 0)
    {
        occur +=1;
    }
    fprintf(f_count, "%s", read);
}
fclose(f_count);
printf("Words that were replaced: %d\n", occur);

fclose(f_ptr);
return 0;

}