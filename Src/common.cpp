
#include "common.h"

//GitTest
char * qstr_to_char(QString strInput)
{
    char *chTemp = NULL;

    //20220221：注，sqlite使用UTF-8字符集。
    QByteArray baTemp = strInput.toUtf8();
    chTemp = baTemp.data();

    return chTemp;
}

