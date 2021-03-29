#include<stdio.h>
#include<string.h>
int i;
struct Employ_info{
  int id;
  char first_name[10];
  char last_name[10];
  char position[10];
  float salary;
}e1;
FILE *fp;
void welcome_screen();
void getting_id();
void add_data();
void show_data();
void search_data();
void search_data_by_name();
void search_data_by_id();
void search_data_by_position();
void modify_data();
void delete_data();
void main(){
    i=0;
    welcome_screen();
    getting_id();
    int option;
    while(option != 6){
        printf("\n\n>>>1.Add records\n>>>2.Show all records\n>>>3.Search\n>>>4.Modify\n>>>5.Delete\n>>>6.Exit\n>>>Option: ");
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
            search_data();
            break;

            case 4:
            modify_data();
            break;

            case 5:
            delete_data();
            break;

            case 6:
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
        printf("ID: %d\n",i+1);
        e1.id=i+1;
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
        i++;
    }
}
void show_data(){
    fp = fopen("employ.dat","rb");
    if(fp==NULL){
        printf("cannot open file");
        fclose(fp);
    }
    else{
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("Sr.No.   ID    First Name   Last Name   Position     Salary\n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        int j=1;
        while(fread(&e1,sizeof(e1),1,fp)){
            printf("%-9d%-6d%-13s%-12s%-13s%.2f\n",j,e1.id,e1.first_name,e1.last_name,e1.position,e1.salary);
            printf("---------------------------------------------------------------------\n");
            j++;
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
void getting_id(){
    fp = fopen("employ.dat","rb");
    if(fp==NULL){
        fclose(fp);
    }
    else{
        while (fread(&e1,sizeof(e1),1,fp) == 1){
            i=e1.id;
        }
        fclose(fp);
    }
}
void search_data(){
    int search_option;
    fp=fopen("employ.dat","rb");
    if(fp==NULL){
        printf("File is Empty");
        fclose(fp);
    }
    else{
        int loop_search=1;
        while (loop_search==1){
            printf("\nSearch by:\n");
            printf(">>>1.Name\n>>>2.ID\n>>>3.Position\n>>>Option: ");
            scanf("%d",&search_option);
            switch (search_option){
                case 1:
                loop_search=2;
                search_data_by_name();
                break;

                case 2:
                loop_search=2;
                search_data_by_id();
                break;

                case 3:
                loop_search=2;
                search_data_by_position();
                break;

                default:
                printf("Invalid Input...");
        
            }
        }    
    }
}
void search_data_by_name(){
    char search_name[10];
    printf("Enter Name: ");
    scanf("%s",search_name);
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Sr.No.   ID    First Name   Last Name   Position     Salary\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    int j=1;
    while(fread(&e1,sizeof(e1),1,fp)){
        if(strcmp(e1.first_name,search_name)==0){
            printf("%-9d%-6d%-13s%-12s%-13s%.2f\n",j,e1.id,e1.first_name,e1.last_name,e1.position,e1.salary);
            printf("-----------------------------------------------------------------------\n");
            j++;
        }
    }
}
void search_data_by_id(){
    int search_id;
    printf("Enter ID: ");
    scanf("%d",&search_id);
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Sr.No.   ID    First Name   Last Name   Position     Salary\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    int j=1;
    while(fread(&e1,sizeof(e1),1,fp)){
        if(e1.id==search_id){
            printf("%-9d%-6d%-13s%-12s%-13s%.2f\n",j,e1.id,e1.first_name,e1.last_name,e1.position,e1.salary);
            printf("-----------------------------------------------------------------------\n");
            j++;
        }
    }
}
void search_data_by_position(){
    char search_position[10];
    printf("Enter Position: ");
    scanf("%s",search_position);
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Sr.No.   ID    First Name   Last Name   Position     Salary\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    int j=1;
    while(fread(&e1,sizeof(e1),1,fp)){
        if(strcmp(e1.position,search_position)==0){
            printf("%-9d%-6d%-13s%-12s%-13s%.2f\n",j,e1.id,e1.first_name,e1.last_name,e1.position,e1.salary);
            printf("-----------------------------------------------------------------------\n");
            j++;
        }
    }
}
void modify_data(){}
void delete_data(){}