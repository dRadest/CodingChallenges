    /*
    * https://www.spoj.com/problems/JULKA/
    * http://code.cloudkaksha.org/spoj/spoj-julka-solution
    */
    #include <stdio.h>
    #include <string.h>
    /*This method adds two Numbers represnted using strings*/
    void add(char v1[], char v2[])// v1 = v1+v2;
    {
         int i,d,c=0;
         int l1=strlen(v1);
         int l2=strlen(v2);
         for(i=l1;i<l2;i++) 
              v1[i]='0';
         for(i=l2;i<l1;i++) 
              v2[i]='0';
         for(i=0;i<l1||i<l2;i++)
         {
              d=(v1[i]-'0')+(v2[i]-'0')+c;
              c=d/10;
              d%=10;
              v1[i]='0'+d;
         }
         while(c)
         {
              v1[i]='0'+(c%10);
              c/=10;
              i++;
         }
         v1[i]='\0';
         v2[l2]='\0';
    }
    /*This function subtracts two numbers represnted using string*/
    void subs(char v1[], char v2[])
    // v1=v1-v2;
    {
         int i,d,c=0;
         int l1=strlen(v1);
         int l2=strlen(v2);
         for(i=l2;i<l1;i++)
              v2[i]='0';
         for(i=0;i<l1;i++)
         {
              d=(v1[i]-'0'-c)-(v2[i]-'0');
              if(d<0)
              {
                   d+=10; 
                   c=1;
              }
              else c=0;
              v1[i]='0'+d;
         }
         v2[l2]='\0';
         i=l1-1;
         while(i>0 && v1[i]=='0') 
              i--;
         v1[i+1]='\0';
    }
    /*This function divides a number represented using string by a constant*/
    int divi(char v[], int q)
    // returns the reminder
    {
         int i,l=strlen(v);
         int c=0,d;
         for(i=l-1;i>=0;i--)
         {
              d=c*10+(v[i]-'0');
              c=d%q; d/=q; v[i]='0'+d;
         }
         i=l-1;
         while(i>0 && v[i]=='0') 
              i--;
         v[i+1]='\0';
         return c;
    }
    /*This function reverses the number*/
    void rev(char v[]) 
    {
         int l=strlen(v);
         int i; char cc;
         for(i=0;i<l-1-i;i++)
         {
              cc=v[i];v[i]=v[l-1-i];v[l-i-1]=cc;
         }
    }
    /*All the above codes are predefined given in the pdf link above on Pg no. 25*/
    int main() {
         char a[102],b[102];
         for(int i=0; i<10 ;++i)
         {
              /*Inputing numbers as strings*/
              gets(a);
              gets(b);
              
              /*We can apply the above functions
         only if the numbers are represented 
            in reverse manner*/ 
              rev(a);
              rev(b);
             
              /*Adding both numbers*/ 
              add(a,b);
              /*we divide to get one answer*/
              divi(a,2);
             
              /*Reverse and output answer*/ 
              rev(a);
              puts(a);
              
              /*To calculate further, we need to 
         again reverse the number*/ 
              rev(a);
              subs(a,b);
              /*Reverse and output second answer*/  
              rev(a);
              puts(a);
              
              
         }
         return 0;
    }