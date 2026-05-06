//to find size of Union
#include <stdio.h>
union Student
{
    char name[20];
    int rollno;
    int mark;
    
};

int main(){
    union Student A;
    printf("Enter name of student\n");
    scanf("%s", A.name);
    
    //A.rollno occupies the size of the union, A.name would contain garbage values now and it results in undefined behaviour
    printf("Enter roll number:\n");
    scanf("%d", &A.rollno);
    printf("%s\n", A.name);


    printf("Enter mark:\n");
    scanf("%d", &A.mark);

    printf("Size of Union : %d\n", sizeof(A));
    //returns 20 (bytes), which was the size of the char array defined

    return 0;
}
