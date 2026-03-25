#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{
	int reg_no;
	char name[50];
	int m1,m2,m3;
	int total;
	char grade;
	int avg;
	char topper[50];
};

void save(struct Student s[]){
	FILE *fp=fopen("students.txt","w");
	for(int i=0;i<3;i++){
		fprintf(fp,"%d %s %d %d %d %d %d %c\n",
		s[i].reg_no,s[i].name,s[i].m1,s[i].m2,s[i].m3,
		s[i].total,s[i].avg,s[i].grade);
	}
	fclose(fp);
}

void load(struct Student s[]){
	FILE *fp=fopen("students.txt","r");
	if(fp==NULL) return;

	for(int i=0;i<3;i++){
		fscanf(fp,"%d %s %d %d %d %d %d %c",
		&s[i].reg_no,s[i].name,&s[i].m1,&s[i].m2,
		&s[i].m3,&s[i].total,&s[i].avg,&s[i].grade);
	}
	fclose(fp);
}

void AddStudent(struct Student s[]){
	for(int i=0;i<3;i++){

		printf("Enter Student name\n");
		scanf("%s",s[i].name);
		printf("Enter student register number\n");
		scanf("%d",&s[i].reg_no);
		while(s[i].reg_no<=0){
			printf("Invalid register number. Enter again\n");
			scanf("%d",&s[i].reg_no);
		}

		printf("Enter Student subject marks in maths, science, english:\n");
		scanf("%d %d %d",&s[i].m1,&s[i].m2,&s[i].m3);

		while(s[i].m1<0||s[i].m1>100){
			printf("Invalid marks. Enter again\n");
			scanf("%d",&s[i].m1);
		}

		while(s[i].m2<0||s[i].m2>100){
			printf("Invalid marks. Enter again\n");
			scanf("%d",&s[i].m2);
		}

		while(s[i].m3<0||s[i].m3>100){
			printf("Invalid marks. Enter again\n");
			scanf("%d",&s[i].m3);
		}
	}

	save(s);
	printf("\n\n");
}

void Display(struct Student s[]){
	for(int i=0;i<3;i++){
		printf("For Student %d\n",i);
		printf("Name of Student: %s\n",s[i].name);
		printf("Register Number of Student: %d\n",s[i].reg_no);
		printf("Marks in maths sci and eng: %d %d %d\n",
		s[i].m1,s[i].m2,s[i].m3);
		printf("\n\n");
	}
}

void total(struct Student s[]){
	for(int i=0;i<3;i++){
		s[i].total=s[i].m1+s[i].m2+s[i].m3;

		printf("The total marks for each student is %d\n",s[i].total);

		s[i].avg=s[i].total/3;

		printf("The average for each student is %d\n",s[i].avg);
		printf("\n");
	}

	save(s);
	printf("\n\n");
}

void grade(struct Student s[],int n){
	for(int i=0;i<n;i++){

		if(s[i].avg>=90)
			s[i].grade='A';

		else if(s[i].avg>=80)
			s[i].grade='B';

		else if(s[i].avg>=70)
			s[i].grade='C';

		else if(s[i].avg>=60)
			s[i].grade='D';

		else if(s[i].avg>=50)
			s[i].grade='E';

		else
			s[i].grade='F';
	}

	for(int i=0;i<n;i++){
		printf("The grade for each student is : %c\n",s[i].grade);
	}

	save(s);
	printf("\n\n");
}

void topper(struct Student s[],int n){
	int max=s[0].avg;
	int index=0;

	for(int i=1;i<n;i++){
		if(s[i].avg>max){
			max=s[i].avg;
			index=i;
		}
	}

	printf("Topper: %s\n",s[index].name);
	printf("Average: %d\n",s[index].avg);
	printf("\n\n");
}

void statistics(struct Student s[],int n){
	int sum=0;
	int highest=s[0].total;
	int lowest=s[0].total;

	for(int i=0;i<n;i++){

		sum=sum+s[i].total;

		if(s[i].total>highest)
			highest=s[i].total;

		if(s[i].total<lowest)
			lowest=s[i].total;
	}

	float class_avg=sum/n;

	printf("Class Average: %.2f\n",class_avg);
	printf("Highest Total: %d\n",highest);
	printf("Lowest Total: %d\n",lowest);
	printf("\n\n");
}

void graded(struct Student s[],int n){

	int A=0,B=0,C=0,D=0,E=0,F=0;

	for(int i=0;i<n;i++){

		if(s[i].grade=='A') A++;
		else if(s[i].grade=='B') B++;
		else if(s[i].grade=='C') C++;
		else if(s[i].grade=='D') D++;
		else if(s[i].grade=='E') E++;
		else if(s[i].grade=='F') F++;
	}

	printf("Grade Distribution:\n");
	printf("A: %d\n",A);
	printf("B: %d\n",B);
	printf("C: %d\n",C);
	printf("D: %d\n",D);
	printf("E: %d\n",E);
	printf("F (Fail): %d\n",F);
	printf("\n\n");
}

int main(){

	printf("Project Title: Movie Ticket Booking System \n Student Name:Anvesha Chaudhari \n Register No:25BCE1761 \n");

	struct Student s[3];

	load(s);

	int choice;

	while(1){

		printf("1.Add student info\n");
		printf("2.Display Student info\n");
		printf("3.Display total marks of each students\n");
		printf("4.Display grade for each student\n");
		printf("5.Display topper name\n");
		printf("6.Display statistics\n");
		printf("7.Display grade distribution\n");

		printf("Enter your function choice:\n\n");

		scanf("%d",&choice);

		switch(choice){

			case 1:
				AddStudent(s);
				break;
			case 2: 
				Display(s); 
				break;
			case 3: 
				total(s); 
				break;
			case 4: 
				grade(s,3); 
				break;
			case 5: 
				topper(s,3); 
				break;
			case 6: 
				statistics(s,3); 
				break;
			case 7: 
				graded(s,3); 
				break;

			default: 
				printf("Invalid choice\n");
		}
	}

	return 0;
}
