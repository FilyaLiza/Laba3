#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h> //���������� ��� getch
#include <time.h>

double Funk(double x) // �������� �������
{
    return 5*pow(x,3)-2*pow(x,2)+3.5*x+15;
}

void Dump(double Xi, double fault,int N, double Timer)
{
    printf("Xi = %lf \n", Xi);
    printf("Fault = %lf \n", fault);
    printf("Count of iterations = %d \n", N);
    printf("Calculation time = %lf \n", Timer);
}
int main()
{
    // My function y=5*pow(x,3)-2*pow(x,2)+3.5*x+15
    double X1, X2, Xi, Timer,fault;
    unsigned int N, n=0, varik; // n ����������������� ����������
    char i; //������
    printf("1-chord method \n 2-half chord method \n");
    scanf("%d",&varik);
    switch(varik)
    {
  case 1:
     do
     {
         X1=0;
         X2=0;
         do
         {
             X1--;
             X2++;

         }
         while (Funk(X1)* Funk(X2)<0);
         printf("%lf \n", X1);
         printf("%lf \n", X2);
        printf("Left limit: \n");
        scanf("%lf", &X1);
        printf("Right limit: \n");
        scanf("%lf",&X2);
     }
    while(Funk(X1)>0 && Funk(X2)<0); //���������� ���������� ���������, ������� ������ ���������� ��������� � ������� �����. �������� �1=-1 � �2=1
    printf("Fault: \n");
    scanf("%lf", &fault);
    printf("Max count of iterations: \n");
    clock_t T1= clock();// ���������� � ����������� �1 �������� ������� ����, ���������� �������� ������� � ������ ������� ���������.
    scanf("%d", &N);
     do
     {
       Xi=((Funk(X2)*X1)-(Funk(X1)*X2))/(Funk(X2)-Funk(X1));
       if(Funk(Xi)>0)
       {
           X2=Xi;
       }
       else
       {
           X1=Xi;
       }
       if(n==N)
       {
           printf("Maximum number of iterations reached \n"); //���������� ������������ ���������� ��������
           printf("Press only the ESC key to complete or any other to continue \n"); //������� ������ ������� ��� ��� ���������� ��� ����� ������ ��� �����������
           i=getch(); //�������� ������� ������ ������� �������
           if((int)i==27)//� ������� ���� ESC ����� ����� 27, �� ��������� ��� � ��� � ���������� ��  ��������
           {
               system("cls"); //������ �������
               break;
           }
           else
           {
               system("cls");
           }
       }
       n++;
     }
     while(fabs(Funk(Xi))>fault);
        clock_t T2=clock();
     Dump(Xi, fabs(Funk(Xi)), n, (double)(T2-T1)/CLOCKS_PER_SEC);//�������� ������� � �������� � �� 4 ���������
     break;
  case 2:
     do
     {
        printf("Left limit: \n");
        scanf("%lf", &X1);
        printf("Right limit: \n");
        scanf("%lf",&X2);
     }
    while(Funk(X1)>0 && Funk(X2)<0);
    printf("Fault: \n");
    scanf("%lf", &fault);
    printf("Max count of iterations: \n");
    clock_t T11=clock();
    scanf("%d", &N);
     do
     {
       Xi=(X1+X2)/2;
       if(Funk(Xi)>0)
       {
           X2=Xi;
       }
       else
       {
           X1=Xi;
       }
       if(n==N)
       {
        printf("Maximum number of iterations reached \n");
        printf("Press only the ESC key to complete or any other to continue \n");
        i=getch();
        if((int)i==27)
        {
            system("cls");
            break;
        }
        else
        {
            system("cls");
        }
       }
       n++;
     }
     while(fabs(Funk(Xi))>fault);
     clock_t T22=clock();
     Dump(Xi, fabs(Funk(Xi)), n, (double)(T22-T11)/CLOCKS_PER_SEC); //CLOCKS_PER_SEC = ��������� ��� ����� 1000
     break;
    }
    return 0;
}
