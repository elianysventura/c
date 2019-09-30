//Elianys Ventura Rodriguez
////Panther ID: 5652936
//This is a program that makes a grade claculation.
////“I affirm that I wrote this program myself without any help form any other people or sources from the internet.”.
#include <stdio.h>
int main(void)
{

char name[20]={" Elianys Ventura"};//Student Name

int pantherID= 12345678;//Panther ID

char courses[6][20]={"COP2210","ENC1101","CGS3095","COP2101","COP2202","COP2303"};//List of course

int credits[]={2,3,3,4,3,4};//Amount of credits

int totalCredits=19;//Amount of total credits

float grade[]={4.00,3.53,3.29,2.48,3.93,4.00};//Grade point average for each course

float gradePointsEarned;//Grade points earned for each course

float total=0;//Total grade points earned

float gpa=0;//GPA

int i;//Index



printf("\n");

printf("Student Name:%s\n",name);//Prints student name

printf("Panther ID:%d\n",pantherID);//Prints student panther id

printf("\n");


printf("-------|------------|--------|----------------------------|\n");//Table

printf("Course |    Credits |   Grade|         Grade Points Earned|\n");//Table

printf("-------|------------|--------|----------------------------|\n");//Table

for(i=0;i<6;i++)//This loop calculates and prints the grade points earned for each course as well as the total grade points earned

{

gradePointsEarned=credits[i]*grade[i];//Grade point earned claculation for each course

printf("%-5s|\t%d   |\t%5.2f|             \t%10.2f|\n",courses[i],credits[i],grade[i],gradePointsEarned);//Prints all the information

total+=gradePointsEarned;//Total grade point earned calculation


}

gpa=total/totalCredits;//GPA calculation


printf("-------|------------|--------|----------------------------|\n");//Table

printf("Total: | \t%d  | \t                      \t%10.2f|\n",totalCredits,total);//Prints total credits and grade points earned

printf("-------|------------|--------|----------------------------|\n");//Table

printf("\n");

printf("Current GPA: %.2f\n",gpa);//Prints GPA

printf("\n");

return 0;

}


