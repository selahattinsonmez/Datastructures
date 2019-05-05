#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {

int id;
char name[100];
char surname[100];
float salary;

}EMPLOYEE;
int insert(EMPLOYEE *a)
{
static int count = 0;

count++;

printf("ENTER ID:\t");
scanf("%d", &a->id);
printf("ENTER NAME :\t");
scanf("%s", a->name);
printf("ENTER SURNAME:\t");
scanf("%s", a->surname);
printf("ENTER SALARY\t");
scanf("%f", &a->salary);
return count;
}
int main()
{
FILE * ft;
EMPLOYEE emps;
char ch;
int count = 0;
int success, i, j = 0, unmatched = 0;
char ** list;

ft = fopen("records.txt", "w+b");
if (!ft)
exit(-1);

while (1)
{
printf("TO INSERT PRESS y, TO LIST press n");
scanf(" %c", &ch);
if (ch == 'n')
break;
count = insert(&emps);
success = fwrite(&emps, sizeof(emps), 1, ft);
if (success != 1)
exit(-1);
}
list = (char **)calloc(count, sizeof(char*));
for (i = 0; i<count; i++)
{
list[i] = (char *)calloc(100, sizeof(char));
}

printf("LISTING UNIQUE NAMES\n");
rewind(ft);
while (fread(&emps, sizeof(emps), 1, ft) != 0)
{
unmatched = 0;
for (i = 0; i < j; i++)
{
if (strcmp(emps.name, list[i]) == 0)
{
unmatched = -1;
break;
}
else
{
unmatched++;
}
}
if (unmatched >= 0)
{

strcpy(list[j], emps.name);
printf("%s\n", emps.name);
j++;
}
}
for (i = 0; i<count; i++)
{
free(list[i]);
}
free(list);
fclose(ft);
return 0;
}

