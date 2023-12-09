#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void viewbook(void);
void addbook(void);
void issuebook(void);
void depositbook(void);
void srecord(void);
void delbrec(void);
void delsrec(void);

struct book
{
    int b_id;
    char b_name[50];
    char a_name[50];
    int quantity;
};

struct student
{
    char s_name[30];
    int roll_no;
    struct book record;


};

FILE *fp,*fs;
void main ()
{
    while(1)
    {
        int i,j;
        printf("PRESS 1 -> IF YOU ARE A TEACHER\n");
        printf("PRESS 2 -> IF YOU ARE A STUDENT\n");
        printf("PRESS 3 -> IF YOU WANT TO EXIT\n");
        scanf("%d",&i);
        if(i==1)
        {
            printf("PRESS 1 -> IF YOU WANT TO ADD A BOOK\n");
            printf("PRESS 2 -> IF YOU WANT TO VIEW ALL BOOKS\n");
            printf("PRESS 3 -> IF YOU WANT TO VIEW STUDENT RECORD\n");
            scanf("%d",&j);
            if(j==1)
                addbook();
            else if(j==2)
                viewbook();
            else if(j==3)
                srecord();
            else
                printf("INVALID CHOICE\n");
        }
        else if (i==2)
        {
            printf("PRESS 1 -> IF YOU WANT TO ISSUE A BOOK\n");
            printf("PRESS 2 -> IF YOU WANT TO DEPOSIT A BOOK\n");
            scanf("%d",&j);
            if(j==1)
                issuebook();
            else if(j==2)
                depositbook();
            else
                printf("INVALID CHOICE\n");
        }
        else if(i==3)
            exit(0);
        else
            printf("INVALID CHOICE\n");
    }

}


void addbook(void)
{
    int i=0;
    struct book w,r;
    printf("enter book id\n");
    scanf("%d",&w.b_id);
    fflush(stdin);
    printf("Enter name of the book\n");
    gets(w.b_name);
    fflush(stdin);
    printf("enter number of copis you want to add\n");
    scanf("%d",&w.quantity);
    fflush(stdin);
    printf("enter author name\n");
    gets(w.a_name);
    fp=fopen("lmmm","rb+");
    if(fp=='\0')
    {
        fclose(fp);
        fp=fopen("lmmm","ab+");
        fwrite(&w,sizeof(w),1,fp);
        fclose(fp);
    }
    else
    {
        printf("number of copis you entered = %d\n",w.quantity);
        for(; fread(&r,sizeof(r),1,fp)!=0;)
        {

            if(r.b_id==w.b_id)
            {

                if(!strcmp(r.b_name,w.b_name))
                {

                    if(!strcmp(r.a_name,w.a_name))
                    {

                        w.quantity=r.quantity+w.quantity;

                        fseek(fp,-sizeof(w),SEEK_CUR);

                        fwrite(&w,sizeof(w),1,fp);
                        i=1;
                        break;
                    }
                }

            }
        }
        if(i==0)
        {
            printf("\nhello\n");
            fwrite(&w,sizeof(w),1,fp);
            printf("BOOK ADDED SUCCESSFULY\n");
        }
    }
    fclose(fp);
}


void viewbook()
{
    struct book r;
    fp=fopen("lmmm","rb+");
    for(; fread(&r,sizeof(r),1,fp)!=0;)
    {
        printf("BOOK ID = %d\n",r.b_id);
        printf("BOOK NAME = %s\n",r.b_name);
        printf("AUTHOR NAME = %s\n",r.a_name);
        printf("NUMBER OF COPIES = %d\n\n\n\n",r.quantity);
    }
    fclose(fp);

}

void issuebook(void)
{
    struct book r;
    struct student s,w;
    int i,k=0,j,copi,ind;
    char a[30];
    printf("YOU CAN SEARCH BOOK BY ID AND NAME\n");
    printf("ENTER 1-> IF YOU WANT TO SEARCH BY ID\n");
    printf("ENTER 2-> IF YOU WANT TO SEARCH BY NAME\n");
    scanf("%d",&i);
    if(i==1)
    {
        printf("ENTER ID\n");
        scanf("%d",&j);
        fp=fopen("lmmm","rb+");
        for(; fread(&r,sizeof(r),1,fp)!=0;)
        {
            if(r.b_id==j)
            {
                printf("Enter number of copies\n");
                scanf("%d",&copi);
                if(r.quantity>=copi)
                {
                    printf("Enter your name");
                    fflush(stdin);
                    gets(w.s_name);
                    printf("Enter your rollno");
                    scanf("%d",&w.roll_no);
                    fs=fopen("st.bin","rb+");

                    for(; fread(&s,sizeof(s),1,fs)!=0;)
                    {

                        if(s.record.b_id==j)
                        {

                            if(!strcmp(s.s_name,w.s_name))
                            {

                                if(s.roll_no==w.roll_no)
                                {

                                    s.record.quantity=copi+s.record.quantity;

                                    fseek(fs,-(sizeof(w)),SEEK_CUR);

                                    fwrite(&s,sizeof(s),1,fs);
                                    k=1;
                                    break;
                                }
                            }

                        }
                    }
                    if(k==0)
                    {
                        w.record=r;
                        w.record.quantity=copi;
                        printf("\nposition%d\n",ftell(fs));
                        fwrite(&w,sizeof(w),1,fs);
                    }

                    fclose(fs);
                    r.quantity=r.quantity-copi;
                    fseek(fp,-sizeof(r),SEEK_CUR);
                    printf("\n%d  %s  %s\n",r.b_id,r.a_name,r.b_name);
                    printf("quantity= %d\n",r.quantity);
                    fwrite(&r,sizeof(r),1,fp);
                    fclose(fp);
                    ind=1;
                    break;
                }

                else
                {
                    printf("no such quantity available");
                    break;
                }

            }

        }

        if(ind==1)
            printf("\nbook added succesfully\n");
        else
            printf("\nbook not available\n");
        delbrec();
    }

    else if (i==2)
    {
        printf("ENTER BOOK NAME\n");
        fflush(stdin);
        gets(a);
        fp=fopen("lmmm","rb+");
        //   printf("%d",ftell(fp));
        for(; fread(&r,sizeof(r),1,fp)!=0;)
        {
            if(!strcmp(a,r.b_name))
            {
                printf("Enter number of copies\n");
                scanf("%d",&copi);
                if(r.quantity>=copi)
                {
                    printf("Enter your name");
                    fflush(stdin);
                    gets(w.s_name);
                    printf("Enter your rollno");
                    scanf("%d",&w.roll_no);
                    fs=fopen("st.bin","rb+");
                    for(; fread(&s,sizeof(s),1,fp)!=0;)
                    {

                        if(!strcmp(a,s.record.b_name))
                        {

                            if(!strcmp(s.s_name,w.s_name))
                            {

                                if(s.roll_no==w.roll_no)
                                {

                                    s.record.quantity=s.record.quantity+copi;

                                    fseek(fs,-sizeof(w),SEEK_CUR);

                                    fwrite(&s,sizeof(w),1,fs);
                                    k=1;
                                    break;
                                }
                            }

                        }
                    }
                    if(k==0)
                    {
                        w.record=r;
                        w.record.quantity=copi;
                        fwrite(&w,sizeof(w),1,fs);
                    }
                    fclose(fs);
                    r.quantity=r.quantity-copi;
                    fseek(fp,-sizeof(r),SEEK_CUR);
                    fwrite(&r,sizeof(r),1,fp);
                    ind=1;
                    fclose(fp);
                    break;
                }
                else
                {
                    printf("no such quantity available");
                    break;
                }
            }
        }
        if(ind==1)
            printf("book added succesfully");
        else
            printf("book not available");

        delbrec();

    }
    else
        printf("INVALID CHOICE");



}
void depositbook(void)
{
    struct student s;
    struct book r,w;
    int id,roll,copi,ind=0;
    char name[50];
    printf("Enter your name");
    fflush(stdin);
    gets(name);
    printf("Enter your rollno");
    scanf("%d",&roll);
    printf("Enter book id");
    scanf("%d",&id);
    fs=fopen("st.bin","rb+");
    for(; fread(&s,sizeof(s),1,fs)!=0;)
    {
        if(!strcmp(s.s_name,name))
        {
            if(s.roll_no==roll)
            {
                if(s.record.b_id==id)
                {
                    printf("Enter number of copies\n");
                    scanf("%d",&copi);
                    s.record.quantity=s.record.quantity-copi;
                    printf("squantity = %d\n",s.record.quantity);
                    printf("\n%d\n",ftell(fs));
                    fseek(fs,-sizeof(s),SEEK_CUR);
                    printf("\n%d\n",ftell(fs));
                    fwrite(&s,sizeof(s),1,fs);
                    w=s.record;
                    fp=fopen("lmmm","rb+");
                    if(fp=='\0')
                        printf("FILE NOT OPENED\n");
                    else
                    {
                        for(; fread(&r,sizeof(r),1,fp)!=0;)
                        {

                            if(r.b_id==w.b_id)
                            {

                                if(!strcmp(r.b_name,w.b_name))
                                {

                                    if(!strcmp(r.a_name,w.a_name))
                                    {

                                        r.quantity=copi+r.quantity;
                                        //printf("quantity = %d\n",w.quantity);

                                        fseek(fp,-sizeof(w),SEEK_CUR);

                                        fwrite(&r,sizeof(w),1,fp);
                                        ind=1;
                                        break;
                                    }
                                }

                            }

                        }
                        if(ind==0)
                        {
                            w.quantity=copi;
                            fwrite(&w,sizeof(w),1,fp);
                            break;
                        }

                    }
                    break;

                }
            }
        }

    }

    fclose(fp);
    fclose(fs);
    delsrec();

}
void srecord(void)
{
    struct student r;
    fs=fopen("st.bin","rb+");
    if(fs==NULL)
        printf("file not opened\n");
    for(; fread(&r,sizeof(r),1,fs)!=0;)
    {
        printf("NAME = %s\n",r.s_name);
        printf("ROLL NO = %d\n",r.roll_no);
        printf("BOOK ID = %d\n",r.record.b_id);
        printf("BOOK NAME = %s\n",r.record.b_name);
        printf("AUTHOR NAME = %s\n",r.record.a_name);
        printf("NUMBER OF COPIES = %d\n\n\n\n",r.record.quantity);
    }
    fclose(fs);

}

void delbrec(void)
{
    int ind=0;
    struct book r;
    fp=fopen("lmmm","rb+");
    fs=fopen("temp","wb+");
    printf("\nin delete\n");
    while(fread(&r,sizeof(r),1,fp)!=0)
    {
        if(r.quantity!=0)
        {
            fwrite(&r,sizeof(r),1,fs);
        }
        else
            ind=1;
    }

    fclose(fs);
    fs=fopen("temp","rb");
    while(fread(&r,sizeof(r),1,fs)!=0)
    {
        printf("%s %d  %s  %d\n\n",r.a_name,r.b_id,r.b_name,r.quantity);
    }
    fclose(fs);
    fclose(fp);
    if(ind==1)
    {
        fp=fopen("lmmm","wb+");
        fs=fopen("temp","rb");
        while(fread(&r,sizeof(r),1,fs)!=0)
        {
            fwrite(&r,sizeof(r),1,fp);
        }
        fclose(fp);
        fclose(fs);

    }

}

void delsrec(void)
{
    int ind=0;
    struct student r;
    fp=fopen("st.bin","rb+");
    fs=fopen("temp","wb+");
    printf("\nin delete\n");
    while(fread(&r,sizeof(r),1,fp)!=0)
    {
        if(r.record.quantity!=0)
        {
            fwrite(&r,sizeof(r),1,fs);
        }
        else
            ind=1;
    }

    fclose(fs);
    fclose(fp);
    if(ind==1)
    {
        fp=fopen("st.bin","wb+");
        fs=fopen("temp","rb");
        while(fread(&r,sizeof(r),1,fs)!=0)
        {
            fwrite(&r,sizeof(r),1,fp);
        }
        fclose(fp);
        fclose(fs);

    }

}
