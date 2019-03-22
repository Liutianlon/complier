//
// Created by dell on 2019/3/18.
//
#include "complier.h"
Scaner::Scaner() {

    BufLen=200;
    Buff = new char[BufLen];

    rowNum=1;
    colNum=1;

    Pos=-1;
    dataLen=0;
    lastch=-1;

}
Scaner::Scaner(int BufLen) {

    this->BufLen=BufLen;
    Buff=new char[BufLen];
}
Scaner::~Scaner() {

    delete []Buff;
}
FILE *Scaner::openFile(char* path){

    return fopen(path,"r");
}
char Scaner::scan(FILE *file) {

    if (!file)
        return -1;
    if(Pos==dataLen-1)
    {
        dataLen=fread(Buff,1,BufLen,file);
        if(dataLen==0)
        {
            dataLen=1;
            Buff[0]=-1;
        }
        Pos=-1;

    }
    Pos++;
    char ch=Buff[Pos];

    if(lastch=='\n')
    {
        rowNum++;
        colNum=0;
    }
    if (ch==-1)
    {
        fclose(file);
        file=NULL;
    }
    else if(ch!='\n')
    {
        colNum++;
    }
    lastch=ch;
    return ch;
}