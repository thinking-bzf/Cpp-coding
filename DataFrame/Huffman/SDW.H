/*

�����������ʾ��ɫ 

Author: ɮ����
Time: 2015.11
*/

#ifndef _SDW_H_
#define _SDW_H_

//��������������ʾ����ɫ�Ŀ�
#include "windows.h"   



//�ڵ׺��� 
void setRedonBlack()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
            FOREGROUND_RED); //����Ϊ��ɫ���� 
}

//�ڵ����� 
void setGreenonBlack()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
            FOREGROUND_GREEN); //����Ϊ��ɫ���� 
}


//�ڵ׻���
void setYellowonBlack()
{
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY
|FOREGROUND_RED | FOREGROUND_GREEN);
}

//�ڵ������ Magenta on Black��
void setMagentaonBlack()
{
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY
|FOREGROUND_RED | FOREGROUND_BLUE);
}
//�ڵ�����Cyan on Black��
void setCyanonBlack()
{
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY
|FOREGROUND_GREEN | FOREGROUND_BLUE);
}

//�ڵװ��� 
void setWhiteonBlack()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
            FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); //����Ϊ��ɫ���� 
} 

//�׵׺��� 
void setRedonWhite()
{
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY |
            FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE |
            FOREGROUND_RED); 
}

//�׵׺��� 
void setBlackonWhite()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY |
             BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
} 

//�׵����� 
void setGreenonWhite()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY |
            FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE |
            FOREGROUND_GREEN); 
}
 

//������ɫ��ϣ���system("color 3f")Ϊ��
//ǳ���װ��� 
void setWhiteon3f()//Ĭ��ֵ 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x3f);  
}
//ǳ���׺���
void setBlackon3f()//Ĭ��ֵ 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x30);  
}

//ǳ���׺���
void setRedon3f()//Ĭ��ֵ 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x3C); 
}

//ǳ���׻���
void setYellowon3f()//Ĭ��ֵ 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x3e);  
}


//ǳ��������
void setGreenon3f()//Ĭ��ֵ 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x3a);  
}

//ǳ��������
void setCayonon3f()//Ĭ��ֵ 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x3b); 
}

//ǳ�������ɫ����
void setMagentaon3f()//Ĭ��ֵ 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x3d);  
}


//������ɫ��ϣ���system("color 4f")Ϊ��
//�ϵװ��� 
void setWhiteon4f()//Ĭ��ֵ 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x4f);  
}
//�ϵ׺���
void setBlackon4f()//Ĭ��ֵ 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x40);  
}

//�ϵ׺���
void setRedon4f()//Ĭ��ֵ 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x4C);  
}

//�ϵ׻���
void setYellowon4f()//Ĭ��ֵ 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x4e);  
}

//�ϵ�����
void setCayonon4f()//Ĭ��ֵ 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x4b); 
}


//����
void setGreenon4f()//Ĭ��ֵ 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x4a); 
}

//�ϵ����ɫ����
void setMagentaon4f()//Ĭ��ֵ 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x4d);  
}

//��ɫ����
void setGreyon4f()//Ĭ��ֵ 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x48);  
}



//��ɫ����
void setGreyon3f()//Ĭ��ֵ 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x38);  
}


//��ɫ����
void setGreyon5f()//Ĭ��ֵ 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x58);  
}


//������ɫ��ϣ���system("color 5f")Ϊ��
//���ϵװ��� 
void setWhiteon5f()//Ĭ��ֵ 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x5f);  
}
//���ϵ׺���
void setBlackon5f()//Ĭ��ֵ 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x50);  
}

//���ϵ׺���
void setRedon5f()//Ĭ��ֵ 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x5C);  
}

//���ϵ׻���
void setYellowon5f()//Ĭ��ֵ 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x5e);  
}

//���ϵ�����
void setCayonon5f()//Ĭ��ֵ 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x5b); 
}


//���ϵ�����
void setGreenon5f()//Ĭ��ֵ 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x5a); 
}

//���ϵ����ɫ����
void setMagentaon5f()//Ĭ��ֵ 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x5d);  
}

bool color(int _color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),_color);
}

#endif
