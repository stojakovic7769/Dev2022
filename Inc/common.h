#ifndef COMMON_H
#define COMMON_H
#include "qstring.h"

#define SELECT_STUDENT_MSG_BY_ID "SELECT * FROM STUINFO where ID = ?;"
#define SELECT_STUDENT_MSG_BY_NAME "SELECT * FROM STUINFO where NAME = ?;"

char * qstr_to_char(QString strInput);

typedef struct StuInfo
{
    char* ID;
    char* strName;
    char* strGrade;
    char* strDepartment;
    char* strSubject;
    char* strOrigin;
    char* strIdentity;
    char* strKnowBK;
}StuInfo_t;

typedef struct   
{
    char* ID;
    char* nItem_1_Grade;
    char* nItem_2_Grade;
    char* nItem_3_Grade;
    char* nItem_4_Grade;
    char* nItem_5_Grade;
    char* nItem_6_Grade;
    char* nTotal_Mark;
}GradeSubject;

#endif