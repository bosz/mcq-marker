/*
The program marks the scipts of a mcq test.
I assumed that the candidate answered all the question leacing out none unanswer.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void passed_failed(int *, int *, int, int);
/*It take the number of questions at the command line, N*/
//int main(int argc, char *argv[])
int main()
{
	//int N=atoi(argv[2]);
	int N=5, total_mark=0, total_cand_num=0, passed_num=0, failed_num=0;
/*We make use of 2 arrays to contain firstly, the correct answers and 
	secondly the answers given by the candidate.*/
	FILE *fp;
	char given_ans[N], correct_ans[N], cand_number[3];
	register int i;
	printf("\n\n\t\tYou are going to input the correct response,\n\t\tall in Upper case letters and with no space\n");
		scanf("%s", correct_ans, N);//gets the correct answers.
	puts("Candidate number :3digits (xxx), e.g023, 334,999.001\n0 to exit : ");
		scanf("%s", cand_number, 3);
	if((fp=fopen("Results.txt", "a+"))==NULL)
	{
		puts("File not found"); 
		abort();	
	}
	

	fprintf(fp, "\t\t\tTest results out of %d\n", N*5);//Heading of the file results.

	while(strcmp(cand_number, "0")!=0)
	{
		int sum=0;
		total_cand_num+=1;
		char num_str[5]="ST";
		strcat(num_str, cand_number); 
		printf("Give me %s's answers: ", num_str);
		scanf("%s", given_ans, N);
		for(i=0; i<N; i++)
		{
			if(*(given_ans+i)==*(correct_ans+i))
				{	sum+=5;	continue;	}
			if(*(given_ans+i)!=*(correct_ans+i))
				{	sum-=1;	continue;	}
		}
		total_mark+=sum;
		passed_failed(&passed_num, &failed_num, sum, N);
		fprintf(fp, "%5s_______________________________%3d\n", num_str, sum);
		printf("score of %5s is %d\n\n", num_str, sum);
		printf("Next candidate number, 0 to exit:");
		scanf("%s", cand_number, 3);
	}
	fprintf(fp, "\t\t\tANALYSIS\n\t\t    -----------\n");
	fprintf(fp, " ------------------------------------------------------\n");
	fprintf(fp, "|  Total Students sat\t\t\t%3d\n", total_cand_num);
	fprintf(fp, "|  Total passed \t\t\t%3d\n", passed_num);
	fprintf(fp, "|  Total failed \t\t\t%3d\n", failed_num);
	fprintf(fp, "|  Class average\t\t\t%3d\n\n\n", total_mark/(N*5));
	printf("Total mark : %4d\n\n", total_mark);

	fclose(fp);

	printf("\n\n\tWe have come to the end of the evaluation.\n\tVisit Results.dat for the summary"
		" of the results.\n");
	printf("\n\n\nThanks to all those who find it usefull and will like someone to optimize it\n\n");
	puts("PLEASE OPTIMIZE THE CODE\n\n\n\n");
	
	return 0;
}


void passed_failed(int *p, int *f, int sum, int N)
{
	if(sum<(N*5)/2)
		{	*f+=1;	return; }
	if(sum>(N*5)/2)
		{	*p+=1;	return;	}
}
