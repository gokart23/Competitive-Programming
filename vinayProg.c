#include <stdio.h>
#include <stdlib.h>

struct playerStruct{
    char name[50];
    int age,matches,avg;
}p[20],s[20];

int cmpfncn(const void* s1,const void* s2)
{
    if(((struct playerStruct*)s1)->avg > ((struct playerStruct*)s2)->avg)
        return 1;
    else
        return 0;
}

void main()
{
    int i,j,n,av[20];
    printf("how many enteries would u like to enter\n");
    scanf("%d",&n);
    printf("enter the entries\n");
    
    for(i=0;i<n;i++)
    {
       scanf("%s %d %d %d",p[i].name,&p[i].age,&p[i].matches,&p[i].avg);
    }
    
    /*for(i=0;i<n;i++)
    {
        av[i]=p[i].avg;
        printf("%d\n",av[i]);
    }*/
    
    qsort(p,n,sizeof(p[0]),cmpfncn);
    
    /*for(i=0;i<n;i++)
    {
        printf("%d\n",av[i]);
    }
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
         if(p[j].avg==av[i])
                {
                    s[i]=p[j];
                }
        }
    }*/
    
    printf("after sorting the outcome is\n");
    
    for(i=0;i<n;i++)
    {
        printf("%s %d %d %d\n",p[i].name,p[i].age,p[i].matches,p[i].avg);
    }
}