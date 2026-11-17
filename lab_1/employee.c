#include<stdio.h>

struct employee{
    char name[50];
    int salary;
};

int main(){
    int n ;
    printf("Enter no. of employee : ");
    scanf("%d", &n);
    FILE *fp = fopen("file.txt", "wb");

    if (fp == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    struct employee emp[n];
    for(int i = 0; i < n; i++){
        printf("\nEnter employee %d details : \nname : ", i+1);
        scanf("%s", emp[i].name);
        printf("salary : ");
        scanf("%d", &emp[i].salary);
        fwrite(&emp[i], sizeof(emp[i]), 1, fp);
        
    }
    fclose(fp);

    fp = fopen("file.txt", "rb");
    
    struct employee emp2[n];
    printf("\n\n\nemployee salaries (after increment) :\n");
    for(int i = 0; i < n; i++){
        fread(&emp2[i], sizeof(emp2[i]), 1, fp);
        if(emp2[i].salary > 50000){
            emp2[i].salary = emp2[i].salary*1.05;
        }
        else if(emp2[i].salary > 20000){
            emp2[i].salary = emp2[i].salary*1.10;
  
        }
        else{
            emp2[i].salary = emp2[i].salary*1.15;
        }
        printf("Name : %s\nSalary : %d\n\n", emp2[i].name, emp2[i].salary);
    }
    fclose(fp);

return 0;
}


// to write in readable form - 
//    fprintf(fp, "employee %d -\n\nName : %s\nSalary : %d\n\n\n", i+1, emp[i].name, emp[i].salary);
