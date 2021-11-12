#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h> //библиотека для getch
#include <time.h>

double Funk(double x) // Основная функция
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
    unsigned int N, n=0, varik; // n инициализированая переменная
    char i; //символ
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
    while(Funk(X1)>0 && Funk(X2)<0); //сравниваем допустимые параметры, функции должны возвращать результат с разными знаки. например Х1=-1 а Х2=1
    printf("Fault: \n");
    scanf("%lf", &fault);
    printf("Max count of iterations: \n");
    clock_t T1= clock();// записываем в перременную Т1 значение функции слок, возвращает значение времени с начала запуска программы.
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
           printf("Maximum number of iterations reached \n"); //Достигнуто максимальное количество итераций
           printf("Press only the ESC key to complete or any other to continue \n"); //Нажмите только клавищу ЕСК для завершения или любую другую для продолжения
           i=getch(); //програма ожидает любого нажатия клавишь
           if((int)i==27)//в таблице аски ESC имеет номер 27, мы переводим чар в инт и сравниваем их  значения
           {
               system("cls"); //чистим консоль
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
     Dump(Xi, fabs(Funk(Xi)), n, (double)(T2-T1)/CLOCKS_PER_SEC);//Вызиваем функцию и передаем в неё 4 параметра
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
     Dump(Xi, fabs(Funk(Xi)), n, (double)(T22-T11)/CLOCKS_PER_SEC); //CLOCKS_PER_SEC = константа что равна 1000
     break;
    }
    return 0;
}
