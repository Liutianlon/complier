#include "./main.h"

int main() {

   Scaner scaner(100);
   FILE* fp=scaner.openFile((char*)"..\\a.txt");
   if(fp==NULL)
       cout<<1<<endl;
   char ch=0;
   while(ch!=-1){

       ch=scaner.scan(fp);
       cout<<ch<<endl;

   }
   return 0;
}