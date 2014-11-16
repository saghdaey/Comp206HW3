//question 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIM " \n"

char *promptOfChoice="JOON4PRES";
char inputString[400];

int main(void){

  char *tok;
  
  while(1){
    printf("%s", promptOfChoice);
    if(!fgets(inputString, sizeof(inputString), stdin)){  
      break;
    }

    //use strtok to extract individual elements from commandline
    //character pointer to 1st token
    
    tok=strtok(inputString, DELIM);
  
    //case 1: user entered command set prompt

    if(strcasecmp(tok,"SET")==0){ //if first argument was set
      tok=strtok(NULL, DELIM); //go to 2nd token argument & check if it was prompt
      if(strcasecmp(tok, "PROMPT")==0)
      {
	//if it 2nd word is prompt then user typed in SET PROMPT and a 3rd argument that they would like to set the prompt to
	tok=strtok(NULL,DELIM);
	promptOfChoice=tok; //set prompt to what the user entered 
      }
    }

    //case 2: user entered reserve word exit
    else if(strcasecmp(tok,"EXIT")==0){
      break;
    }

    else{
      system(inputString);
    }
    return 0;
  }

}
