/************ mycgi.c file ****************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX 1000
typedef struct{

	char *name;
	char *value;
}ENTRY;

ENTRY entry[MAX];
///extern int getinputs();  // in util.o 


int main(int argc, char *argv[]){
	
	int i, n;
	char cwd[128];
	//n = getinputs();
	getcwd(cwd, 128);
	

	// this consider HTML don't panic  
	printf("Content-type: text/html\n\n");
	printf("<html>");
	printf("<body bgcolor=\"#FFFF00\">");
	printf("<p>pid=%d uid=%d cwd=%s\n", getpid(), getuid(), cwd);
	printf("<H2> Echo Your Input </H2>");
	printf("You submitted the following name/value pairs:<p>");
	/*for (i=0; i<=n; i++)
		printf("%s= %s<p>", entry[i].name, entry[i].value);
	printf("<p>");*/


	// create a form webpage for user to submit again
	printf("-----------SEND BACK A FORM AGAIN-------------<p>");
	printf("<FORM METHOD=\"POST\"ACTION=\"http://localhost/mycgi.bin\">");
	printf("<font color=\"RED\">");
	printf("Enter command: <INPUT NAME=\"command\"> <p>");
	printf("Enter filename1: <INPUT NAME=\"filename1\"> <p>");
	
	printf("Enter filename2: <INPUT NAME=\"filename2\"> <p>");
	printf("Submit command: <INPUT TYPE=\"submit\" VALUE=\"\" click to submit\"> <p>");
	printf("</form>");
	printf("</font>");
	printf("-----------------------------------------------<p>");
	printf("</body>");
	printf("</html>");

}
