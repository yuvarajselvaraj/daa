#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 0 ; i<T ; i++)
    {
        int ans[7] = {0,0,0,0,0,0,0};
        int n;
        int temp;
        char in[4];
        scanf("%d %s",&n,in);
        if(in[0]=='m')
        {
            temp = 0;
        }
        else if(in[0]=='t' && in[1]=='u')
        {
           
            temp = 1;
        }
        else if(in[0]=='w')
        {
           temp = 2;
        }
        else if(in[0]=='t' && in[1]=='h')
        {
            
            temp = 3;
        }
        else if(in[0]=='f')
        {
           
            temp = 4;
        }
        else if(in[0]=='s' && in[1]=='a')
        {
            
            temp  = 5;
        }
        else
        {
            
            temp = 6;
        }
        for(int j = 0 ; j<n ; j++)
        {
            ans[(temp+j)%7]++;
        }
        for(int k = 0 ; k<7 ; k++)
        {
            printf("%d ",ans[k]);
        }
        printf("\n");
    }
}
