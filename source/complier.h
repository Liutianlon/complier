//
// Created by dell on 2019/3/18.
//

#ifndef UNTITLED2_COMPLIER_H
#define UNTITLED2_COMPLIER_H

#include "public.h"
namespace complier{

    enum Tag{
        ERR,
        END,
        ID,
        KW_INT,KW_CHAR,KW_VOID,
        KW_EXTERN,
        NOT
    };
    class Scaner{
    public:
        Scaner();
        Scaner(int BufLen);
        virtual  ~Scaner();
        FILE *openFile(char* path);
        char scan(FILE *file);

    private:
        int BufLen;
        int Pos;
        int dataLen;
        char *Buff;

        int rowNum;
        int colNum;

        char lastch;

    };

}
using namespace complier;
#endif //UNTITLED2_COMPLIER_H
