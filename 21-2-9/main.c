//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//    printf("Hello world!\n");
//    return 0;
//}
//#include<stdio.h>
//char *day[]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
//char hour[]="0123456789ABCDEFGHIJKLMN";
//int inhour(char tmp)
//{
//    int i;
//    for(i=0;i<24;i++)
//    {
//        if(tmp==hour[i])
//            return i+1;
//    }
//    return 0;
//}
//int main()
//{
//    int flag1=1,flag2=1,i=0,arr[3],count=0;
//    char arr1[61],arr2[61];
//    scanf("%s%s",arr1,arr2);
//    while(arr1[i]&&arr2[i])
//    {
//        if(arr1[i]==arr2[i])
//        {
//            if(flag1&&(arr1[i]>='A'&&arr1[i]<='G'))
//            {
//                arr[count]=arr1[i]-'A'+1;
//                count++;
//                flag1=0;
//            }
//            else if(!flag1&&flag2&&((arr1[i]>='A'&&arr1[i]<='N')||(arr1[i]>='0'&&arr1[i]<='9')))
//            {
//                arr[count]=inhour(arr1[i])-1;
//                count++;
//                flag2=0;
//            }
//        }
//        i++;
//    }
//    scanf("%s%s",arr1,arr2);
//    i=0;
//    while(arr1[i]&&arr2[i])
//    {
//        if(arr1[i]==arr2[i]&&arr1[i]>='A'&&arr1[i]<='z')
//        {
//            arr[count]=i;
//            count++;
//            break;
//        }
//        i++;
//    }
//    printf("%s %02d:%02d",day[arr[0]-1],arr[1],arr[2]);
//    return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//struct stu
//{
//    int id;
//    int cai;
//    int de;
//};
//int cmp(const void*a,const void*b)
//{
//    if((((struct stu*)a)->cai+((struct stu*)a)->de)==(((struct stu*)b)->cai+((struct stu*)b)->de))
//    {
//        if(((struct stu*)a)->de==((struct stu*)b)->de)
//        {
//            return ((struct stu*)b)->id-((struct stu*)a)->id;
//        }
//        else
//            return ((struct stu*)a)->de-((struct stu*)b)->de;
//    }
//    else
//        return ((struct stu*)a)->cai+((struct stu*)a)->de-((struct stu*)b)->cai+((struct stu*)b)->de;
//}
//int main()
//{
//    int count1=0,count2=0,count3=0,count4=0,i,n,h,l,count=0,cai,de,id;
//    scanf("%d%d%d",&n,&l,&h);
//    struct stu s1[n],s2[n],s3[n],s4[n];
//    for(i=0;i<n;i++)
//    {
//        scanf("%d%d%d",&id,&de,&cai);
//        if(de>=l&&cai>=l)
//        {
//            count++;
//            if(de>=h&&cai>=h)
//            {
//                s1[count1].id=id;
//                s1[count1].cai=cai;
//                s1[count1].de=de;
//                count1++;
//            }
//            else if(de>=h&&cai<h)
//            {
//                s2[count2].id=id;
//                s2[count2].de=de;
//                s2[count2].cai=cai;
//                count2++;
//            }
//            else if(de<h&&cai<h&&de>=cai)
//            {
//                s3[count3].id=id;
//                s3[count3].cai=cai;
//                s3[count3].de=de;
//                count3++;
//            }
//            else
//            {
//                s4[count4].id=id;
//                s4[count4].cai=cai;
//                s4[count4].de=de;
//                count4++;
//            }
//        }
//    }
//    qsort(s1,count1,sizeof(struct stu),cmp);
//    qsort(s2,count2,sizeof(struct stu),cmp);
//    qsort(s3,count3,sizeof(struct stu),cmp);
//    qsort(s4,count4,sizeof(struct stu),cmp);
//    printf("%d",count);
//    if(count)
//        printf("\n");
//    for(i=0;i<count1;i++)
//    {
//        printf("%d %d %d",s1[i].id,s1[i].de,s1[i].cai);
//        if(i!=count1-1||count2)
//            printf("\n");
//    }
//    for(i=0;i<count2;i++)
//    {
//        printf("%d %d %d",s2[i].id,s2[i].de,s2[i].cai);
//        if(i!=count2-1||count3)
//            printf("\n");
//    }
//    for(i=0;i<count3;i++)
//    {
//        printf("%d %d %d",s3[i].id,s3[i].de,s3[i].cai);
//        if(i!=count3-1||count4)
//            printf("\n");
//    }
//    for(i=0;i<count4;i++)
//    {
//        printf("%d %d %d",s4[i].id,s4[i].de,s4[i].cai);
//        if(i!=count4-1)
//            printf("\n");
//    }
//    return 0;
//}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stu
{
    int id;
    int cai;
    int de;
};
int cmp(const void*a,const void*b)
{
    if((((struct stu*)a)->cai+((struct stu*)a)->de-((struct stu*)b)->cai+((struct stu*)b)->de)==0)
    {
        if((((struct stu*)a)->de-((struct stu*)b)->de)==0)
        {
            return ((struct stu*)b)->id-((struct stu*)a)->id;
        }
        else
            return ((struct stu*)a)->de-((struct stu*)b)->de;
    }
    else
        return ((struct stu*)a)->cai+((struct stu*)a)->de-((struct stu*)b)->cai+((struct stu*)b)->de;
}
void mqsort(void*s,int n,int width,int (*p)(const void*a,const void*b))
{
    int i,j;
    char *tmp=(char*)malloc(width);
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(p((char*)s+width*j,(char*)s+width*(j+1))>0)
            {
                memcpy(tmp,(char*)s+width*j,width);
                memcpy((char*)s+width*j,(char*)s+width*(j+1),width);
                memcpy((char*)s+width*(j+1),tmp,width);
            }
        }
    }
    free(tmp);
}
int main()
{
    int count1=0,count2=0,count3=0,count4=0,i,n,h,l,count=0,cai,de,id;
    scanf("%d%d%d",&n,&l,&h);
    struct stu s1[n],s2[n],s3[n],s4[n];
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&id,&de,&cai);
        if(de>=l&&cai>=l)
        {
            count++;
            if(de>=h&&cai>=h)
            {
                s1[count1].id=id;
                s1[count1].cai=cai;
                s1[count1].de=de;
                count1++;
            }
            else if(de>=h&&cai<h)
            {
                s2[count2].id=id;
                s2[count2].de=de;
                s2[count2].cai=cai;
                count2++;
            }
            else if(de<h&&cai<h&&de>=cai)
            {
                s3[count3].id=id;
                s3[count3].cai=cai;
                s3[count3].de=de;
                count3++;
            }
            else
            {
                s4[count4].id=id;
                s4[count4].cai=cai;
                s4[count4].de=de;
                count4++;
            }
        }
    }
    mqsort(s1,count1,sizeof(struct stu),cmp);
    mqsort(s2,count2,sizeof(struct stu),cmp);
    mqsort(s3,count3,sizeof(struct stu),cmp);
    mqsort(s4,count4,sizeof(struct stu),cmp);
    printf("%d",count);
    if(count)
        printf("\n");
    for(i=0;i<count1;i++)
    {
        printf("%d %d %d",s1[i].id,s1[i].de,s1[i].cai);
        if(i!=count1-1||count2)
            printf("\n");
    }
    for(i=0;i<count2;i++)
    {
        printf("%d %d %d",s2[i].id,s2[i].de,s2[i].cai);
        if(i!=count2-1||count3)
            printf("\n");
    }
    for(i=0;i<count3;i++)
    {
        printf("%d %d %d",s3[i].id,s3[i].de,s3[i].cai);
        if(i!=count3-1||count4)
            printf("\n");
    }
    for(i=0;i<count4;i++)
    {
        printf("%d %d %d",s4[i].id,s4[i].de,s4[i].cai);
        if(i!=count4-1)
            printf("\n");
    }
    return 0;
}
