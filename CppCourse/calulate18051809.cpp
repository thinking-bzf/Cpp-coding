#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//����
void cls()
{
    system("cls");
}
//���������˵�
void tsMenu()
{
    cls();
    printf("\t\t\t��ϰ�˵�\n");
    printf("\t1.10��\n");
    printf("\t2.20��\n");
    printf("\t0.�˳�\n");
    printf("\n\n��ѡ����Ҫ�Ĺ���:");
}

//ѡ�����Ͳ˵�
void txMenu()
{
    cls();
    printf("1��10���ڵ������\n");
    printf("2��100���ڵ������\n");
    printf("3��10���ڵ������\n");
    printf("4��10���ڵ������(������Ϊ��)\n");
    printf("5��100���ڵ������\n");
    printf("6��100���ڵ������(������Ϊ��)\n");
    printf("7���������������\n");
    printf("8���������������(������Ϊ��)\n");
    printf("9��10���ڵ������\n");
    printf("10��100���ڵ�����10���ڵ������\n");
    printf("0���˳�\n");
}

void back()
{
    system("pause");
}



//ģʽ
int mode = 1;

int counts = 10;

//���������
int errors = 0;

char *txs[] = {
    "10���ڵ������",
    "100���ڵ������",
    "10���ڵ������",
    "10���ڵ������(������Ϊ��)",
    "100���ڵ������",
    "100���ڵ������(������Ϊ��)",
    "�������������",
    "�������������(������Ϊ��)",
    "10���ڵ������",
    "100���ڵ�����10���ڵ������"};

//���˵�
void MainMenu()
{
    cls();
    printf("\t\t\t��������\n");
    printf("\t1.����\n");
    printf("\t2.����\n");
    printf("\t3.��ǰ����\n");
    printf("\t0.�˳�\n");
    printf("\n\n��ѡ����Ҫ�Ĺ���:");
}

//���ò˵�
void szMenu()
{
    cls();
    printf("1�����ò�����Ŀ��\n");
    printf("2����������\n");
    printf("0���˳�\n");
    printf("\n\n��ѡ����Ҫ�Ĺ���:");
}
//ѡ������
void tsCount()
{
    int gn = 0;
    while (1)
    {
        tsMenu();
        scanf("%d", &gn);
        if (gn == 1)
        {
            printf("��ѡ�� 10 ��\n");
            counts = 10;
            back();
        }
        else if (gn == 2)
        {
            printf("��ѡ�� 20 ��\n");
            counts = 20;
            back();
        }
        else if (gn == 0)
        {
            goto out;
        }
        else
        {
            printf("ѡ�����\n");
            back();
        }
    }
out:;
}

void tx()
{
    int gn = 0;
    while (1)
    {
        txMenu();
        scanf("%d", &gn);
        if (gn > 0 && gn <= 10)
        {
            mode = gn;
            printf("��ѡ�� %s\n", txs[gn - 1]);
            back();
        }
        else if (gn == 0)
        {
            goto out;
        }
        else
        {
            printf("ѡ�����\n");
            back();
        }
    }
out:;
}

void sz()
{
    while (1)
    {
        szMenu();
        int gn;
        scanf("%d", &gn);
        switch (gn)
        {
        case 1:
            tsCount();
            break;
        case 2:
            tx();
            break;
        case 0:
            goto out;
        }
    }
out:;
}



//��ǰ����
void dqsz()
{
    printf("����:��ѡ�� %d ��\n", counts);
    printf("����: %s\n", txs[mode - 1]);
    back();
}
void check(int user, int result)
{
    int b = (user == result);
    if (b == 0)
    {
        errors++;
    }
    printf("%s ,���� %d\n", b ? "���� ��ȷ" : "���� ����", result);
}
void ys(int mode, int count)
{
    int a, b, result, user, flag;
    cls();
    for (int aCount = 0; aCount < count; aCount++)
    {
        switch (mode)
        {
        case 1: //10 �ӷ�
            a = rand() % 10;
            b = rand() % 10;
            result = a + b;
            printf("\n\nNo.%d\t%d + %d = \n", aCount, a, b);
            printf("���Ľ����:");
            scanf("%d", &user);
            check(user, result);
            break;
        case 2: //100 �ӷ�
            a = rand() % 100;
            b = rand() % 100;
            result = a + b;
            printf("\n\nNo.%d\t%d + %d = \n", aCount, a, b);
            printf("���Ľ����:");
            scanf("%d", &user);
            check(user, result);
            break;
        case 3: //10 ����
            a = rand() % 10;
            b = rand() % a;
            result = a - b;
            printf("\n\nNo.%d\t%d - %d = \n", aCount, a, b);
            printf("���Ľ����:");
            scanf("%d", &user);
            check(user, result);
            break;
        case 4: //10 ���� �ɸ�
            a = rand() % 10;
            b = rand() % 10;
            result = a - b;
            printf("\n\nNo.%d\t%d - %d = \n", aCount, a, b);
            printf("���Ľ����:");
            scanf("%d", &user);
            check(user, result);
            break;
        case 5: //100 ����
            a = rand() % 100;
            b = rand() % a;
            result = a - b;
            printf("\n\nNo.%d\t%d - %d = \n", aCount, a, b);
            printf("���Ľ����:");
            scanf("%d", &user);
            check(user, result);
            break;
        case 6: //100 ���� �ɸ�
            a = rand() % 100;
            b = rand() % 100;
            result = a - b;
            printf("\n\nNo.%d\t%d - %d = \n", aCount, a, b);
            printf("���Ľ����:");
            scanf("%d", &user);
            check(user, result);
            break;
        case 7: //��Ӽ� ���
            flag = rand() % 2;
            if (flag)
            {
                a = rand() % 100;
                b = rand() % 100;
                result = a + b;
            }
            else
            {
                a = rand() % 100;
                b = rand() % a;
                result = a - b;
            }
            printf("\n\nNo.%d\t%d %s %d = \n", aCount, a, flag ? "+" : "-", b);
            printf("���Ľ����:");
            scanf("%d", &user);
            check(user, result);
            break;
        case 8: //��Ӽ� ��� �ɸ�
            flag = rand() % 2;
            if (flag)
            {
                a = rand() % 100;
                b = rand() % 100;
                result = a + b;
            }
            else
            {
                a = rand() % 100;
                b = rand() % 100;
                result = a - b;
            }
            printf("\n\nNo.%d\t%d %s %d = \n", aCount, a, flag ? "+" : "-", b);
            printf("���Ľ����:");
            scanf("%d", &user);
            check(user, result);
            break;
        case 9: //10 �˷�
            a = rand() % 10;
            b = rand() % 10;
            result = a * b;
            printf("\n\nNo.%d\t%d * %d = \n", aCount, a, b);
            printf("���Ľ����:");
            scanf("%d", &user);
            check(user, result);
            break;
        case 10: //10 100 �˷�
            a = rand() % 100;
            b = rand() % 10;
            result = a * b;
            printf("\n\nNo.%d\t%d * %d = \n", aCount, a, b);
            printf("���Ľ����:");
            scanf("%d", &user);
            check(user, result);
            break;
        }
    }
    printf("%d ����,������ %d ��,��ȷ�� %d%%\n", count, errors, (count - errors) * 100 / count);
    back();
}

void test()
{
    int gn;
    int count;
    scanf("%d", &gn);
    switch (gn)
    {
    case 1:
        count = 10;
        break;
    case 2:
        count = 20;
        break;
    }
    ys(1, count);
}

int main()
{

    int gn = 0;
    srand((unsigned int)time(NULL));
    while (1)
    {
        MainMenu();
        scanf("%d", &gn);
        cls();
        errors = 0;
        switch (gn)
        {
        case 1:
            ys(mode, counts);
            break;
        case 2:
            sz();
            break;
        case 3:
            dqsz();
            break;
        case 0:
            goto out;
        }
    }
out:;
}
