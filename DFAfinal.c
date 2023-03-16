#include<stdio.h>
#define max 100
int main() {
   char str[max],f='A';
   int i,n;
   printf("Enter the number of states.\n");
   scanf("%d",&n);
   printf("Total states are.\n");
   for(char j=f;j<f+n;j++)
   {
       printf("%c ",j);
   }
   printf("\nEnter the string to be checked: ");
   scanf("%s",str);
   for(i=0;str[i]!='\0';i++) {
      switch(f) {
         case 'A': if(str[i]=='1') f='B';
            else if(str[i]=='0') f='A';
         break;
         case 'B': if(str[i]=='0') f='A';
            else if(str[i]=='1') f='C';
         break;
         case 'C': if(str[i]=='0') f='A';
            else if(str[i]=='1') f='D';
         break;
         case 'D': if(str[i]=='0') f='D';
            else if(str[i]=='1') f='D';
         break;
      }
   }
   if(f=='D')
      printf("As the string reaches to the final state,String is accepted", f);
   else printf("As the string cannot reaches the final state,String is not accepted", f);
      return 0;
}

