
#include <stdio.h>
#include <stdlib.h>

#define MAX 15
#define MAX_LENGTH 30

//function prototypes
int openFiles(char* input, char* output);
int readContent();
void sort(int size, int option);
void writeFile(int size);
void closeFiles();
int main(int argc, char** argv);
FILE *in;
FILE *out;

//Defining structure to store `student information
typedef struct
{
	int id;
	char name[MAX_LENGTH];
	double gpa;
}data;

data Students[MAX];

//Main code
int main(int argc, char** argv)
{

if (openFiles(argv[1], argv[2]) == -1) {
	//ERROR Check
	printf("Cannot read input file");
	return 1;
}
//Call readContent and return number of students
int num_students=readContent();
printf("\nHow would you like to sort the list?");
printf("\n1) By ID");
printf("\n2) By GPA");
printf("\nYour selection: ");
int selection=0;
scanf("%d", &selection);
//Call sort to sort students by GPA or ID
sort(num_students, selection);
//Call writeFile to output file
writeFile(num_students);
//Close the 2 files
closeFiles();
}

//Function that takes the argv[1] and argv[2] as input and output the file names.
// Return -1 if files couldn't be opened. Output in read mode and output in write mode.
int openFiles(char* input, char* output)
{
 in =fopen (input,"r");
 out = fopen(output, "w");
  if (output==NULL)
  {
	return	-1;
  }
    if (input==NULL)
  {
	return -1;
  }
  return 0;

}

//Function that reads the content from the file. First line contains number of students listed.
//The rest is Student ID, Student Name, and GPA. Stores the content to an array. Return the number of students.
int readContent()
{
int num_stu = 0;
int i=0;
fscanf(in, "%d", &num_stu);
for (i = 0; i < num_stu; ++i) {
	fscanf(in, "%d", &Students[i].id);
	fscanf(in, "%s", Students[i].name);
	fscanf(in, "%lf", &Students[i].gpa);
	
}

return num_stu;
}

//Sort the array by either ID or GPA. Takes in number of students and option for sorting. Nothing is returned.
void sort(int size, int option)
{

while (option!=1 && option!=2)
{
printf("Please type a 1 or 2: ");
scanf("%d", &option);
}
// Did not have enough time for sorting.
}

//Write the sorted students information to the output file. The content is formatted. Writes to the output file and screen.
void writeFile(int size)
{
int i=0;
//print to file
fprintf(out, "ID			Name		GPA\n");
for (i = 0; i < size; ++i) {
	fprintf(out, "%d		 ", Students[i].id);
	fprintf(out, "%s	     ", Students[i].name);
	fprintf(out, "%lf      \n", Students[i].gpa);
	
}
//Print to screen.
i=0;
printf("ID			Name		GPA\n");
for (i = 0; i < size; ++i) {
	printf("%d			", Students[i].id);
	printf("%s		", Students[i].name);
	printf("%lf			\n", Students[i].gpa);
	
}
}

//Close files.
void closeFiles()
{
fclose(in);
fclose(out);
}