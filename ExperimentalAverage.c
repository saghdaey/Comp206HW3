

//question 1

#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include <string.h>

#define DELIM ","


int main(int argc, char* argv[])
{
	if(argc==2) //1 file specialized at command line
	{
		FILE *file;
		char currLine[2000];
		char *token;
		int lineIntegers[2000];
		int counter=0;
		int i=0;
		int sum=0;
		//printf("Calculating averages from experimental data in %s\n", argv[1]); //argv(1) is filename
		
		//open and read file
		file=fopen(argv[1], "rt"); //t since txt file
		
		char expirement[100];		

		while(fgets(currLine, sizeof(currLine), file)) //keep reading
		{
			token=strtok(currLine, DELIM); //gets 1st line, name of experiment
			strncpy(expirement, token, sizeof(expirement));
			printf("%s ", expirement);


			while((token=strtok(NULL,DELIM))!=NULL)
			{
			//token=strtok(NULL, DELIM);
			lineIntegers[i++]=atoi(token); //assign int value to spot in array
			sum += lineIntegers[i-1];
			counter++;
			//token=strtok(NULL, DELIM);
			}

		
		
		double average;
		
		average=(double)sum/(double)counter;
		printf("%.2lf\n", average);
		sum=0;
		counter=0;
		i=0;
		}
	
	fclose(file);
	return 0;
	}
	
}	
