#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <dirent.h> 
#include <locale.h>

struct node{// I made a struct that type of node.
	char name[100];
    int Total_numberofdocuments;//total number elements this term occur
    struct node *next;
    struct node *next2;
    int data;
};
 typedef struct node mynode;
 
 FILE *inpf;
 int i=0;
 char Term_Name[100][100];//reader for term name in the text
 

   main(void)//start of main
 { 
 setlocale(LC_CTYPE,"turkish");//to know turkish's words
 mynode *sptr,*previousptr,*currentptr,*newptr;
 sptr = NULL;

 
    DIR *n;
    struct dirent *dir;
    n = opendir("econ");
    if (n)
    {
        while ((dir = readdir(n)) != NULL)
        {
          
		   inpf=fopen(&dir->d_name[0],"r");//reading file from directory
        
        }
        closedir(n);
    }


while (!feof(inpf)) { 
fscanf(inpf,"%s",Term_Name[i]);
insert(&sptr);
i++;
}

fclose(inpf);


}//end of main

  

void insert(mynode **sptr){

mynode *previousptr,*currentptr;
previousptr = malloc(sizeof(mynode));
if(*sptr==NULL&&i==0){//if there is no node ý added previousptr as first node to MLL
*sptr = previousptr;
previousptr->next=NULL;
 strcpy(previousptr->name,Term_Name[i]); 
printf("TERMNAME%d:%s\n",i,previousptr->name);  
		
}
else{//if there is a node ý added one more node to MLL
	currentptr = *sptr; 
	currentptr->next=previousptr;
	while(currentptr->next!=NULL){
		currentptr=currentptr->next;
		 strcpy(currentptr->name,Term_Name[i]); 
		printf("TERMNAME%d:%s\n",i,currentptr->name);  
		
}
}
}






