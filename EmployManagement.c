#include<stdio.h>
struct Employ_info{
  int id;
  char first_name[10];
  char last_name[10];
  char position[10];
  float salary;
}e1;
FILE *fp;
void add_data();
void show_data();
void welcome_screen();
void main(){
    welcome_screen();
    int option;
    while(option != 3){
        printf("\n\n>>>1.Add records\n>>>2.Show all records\n>>>3.Exit\n>>>Option: ");
        scanf("%d",&option);
        switch (option)
        {
            case 1:
            add_data();
            break;

            case 2:
            show_data();
            break;

            case 3:
            break;

            default:
            printf("Invalid Input");
            break;
        }
    }
}
void add_data(){
    fp = fopen("employ.dat","ab");
    if(fp==NULL){
        printf("cannot open file");
        fclose(fp);
    }
    else{
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("Enter Employ Details\n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("ID: ");
        scanf("%d",&e1.id);
        printf("FIRST NAME: ");
        scanf("%s",e1.first_name);
        printf("LAST NAME: ");
        scanf("%s",e1.last_name);
        printf("POSITION: ");
        scanf("%s",e1.position);
        printf("SALARY: ");
        scanf("%f",&e1.salary);
        fwrite(&e1,sizeof(e1),1,fp);
        fclose(fp);
    }
}
void show_data(){
    fp = fopen("employ.dat","rb");
    if(fp==NULL){
        printf("cannot open file");
        fclose(fp);
    }
    else{
        printf("-------------------------------------------\n");
        while(fread(&e1,sizeof(e1),1,fp)){
            printf("ID       : %d\n",e1.id);
            printf("Name     : %s ",e1.first_name);
            printf("%s\n",e1.last_name);
            printf("Position : %s\n",e1.position);
            printf("Salary   : %.2f\n",e1.salary);
            printf("-------------------------------------------\n");
        }
        fclose(fp);
        }
}
void welcome_screen(){
     printf("\t\t\t################################################\n");
    printf("\t\t\t##                    EMPLOY                  ##\n");
    printf("\t\t\t##                  MANAGEMENT                ##\n");
    printf("\t\t\t##                    SYSTEM                  ##\n");
    printf("\t\t\t################################################");
}