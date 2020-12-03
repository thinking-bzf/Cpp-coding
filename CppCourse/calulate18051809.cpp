#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//清屏
void cls()
{
    system("cls");
}
//设置题数菜单
void tsMenu()
{
    cls();
    printf("\t\t\t练习菜单\n");
    printf("\t1.10题\n");
    printf("\t2.20题\n");
    printf("\t0.退出\n");
    printf("\n\n请选择需要的功能:");
}

//选择题型菜单
void txMenu()
{
    cls();
    printf("1、10以内的数相加\n");
    printf("2、100以内的数相加\n");
    printf("3、10以内的数相减\n");
    printf("4、10以内的数相减(容许结果为负)\n");
    printf("5、100以内的数相减\n");
    printf("6、100以内的数相减(容许结果为负)\n");
    printf("7、相加相减混合运算\n");
    printf("8、相加相减混合运算(容许结果为负)\n");
    printf("9、10以内的数相乘\n");
    printf("10、100以内的数与10以内的数相乘\n");
    printf("0、退出\n");
}

void back()
{
    system("pause");
}



//模式
int mode = 1;

int counts = 10;

//错误的题数
int errors = 0;

char *txs[] = {
    "10以内的数相加",
    "100以内的数相加",
    "10以内的数相减",
    "10以内的数相减(容许结果为负)",
    "100以内的数相减",
    "100以内的数相减(容许结果为负)",
    "相加相减混合运算",
    "相加相减混合运算(容许结果为负)",
    "10以内的数相乘",
    "100以内的数与10以内的数相乘"};

//主菜单
void MainMenu()
{
    cls();
    printf("\t\t\t四则运算\n");
    printf("\t1.测试\n");
    printf("\t2.设置\n");
    printf("\t3.当前设置\n");
    printf("\t0.退出\n");
    printf("\n\n请选择需要的功能:");
}

//设置菜单
void szMenu()
{
    cls();
    printf("1、设置测试题目数\n");
    printf("2、设置题型\n");
    printf("0、退出\n");
    printf("\n\n请选择需要的功能:");
}
//选择题数
void tsCount()
{
    int gn = 0;
    while (1)
    {
        tsMenu();
        scanf("%d", &gn);
        if (gn == 1)
        {
            printf("已选择 10 题\n");
            counts = 10;
            back();
        }
        else if (gn == 2)
        {
            printf("已选择 20 题\n");
            counts = 20;
            back();
        }
        else if (gn == 0)
        {
            goto out;
        }
        else
        {
            printf("选择错误\n");
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
            printf("已选择 %s\n", txs[gn - 1]);
            back();
        }
        else if (gn == 0)
        {
            goto out;
        }
        else
        {
            printf("选择错误\n");
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



//当前设置
void dqsz()
{
    printf("题数:已选择 %d 题\n", counts);
    printf("题型: %s\n", txs[mode - 1]);
    back();
}
void check(int user, int result)
{
    int b = (user == result);
    if (b == 0)
    {
        errors++;
    }
    printf("%s ,答案是 %d\n", b ? "计算 正确" : "计算 错误", result);
}
void ys(int mode, int count)
{
    int a, b, result, user, flag;
    cls();
    for (int aCount = 0; aCount < count; aCount++)
    {
        switch (mode)
        {
        case 1: //10 加法
            a = rand() % 10;
            b = rand() % 10;
            result = a + b;
            printf("\n\nNo.%d\t%d + %d = \n", aCount, a, b);
            printf("您的结果是:");
            scanf("%d", &user);
            check(user, result);
            break;
        case 2: //100 加法
            a = rand() % 100;
            b = rand() % 100;
            result = a + b;
            printf("\n\nNo.%d\t%d + %d = \n", aCount, a, b);
            printf("您的结果是:");
            scanf("%d", &user);
            check(user, result);
            break;
        case 3: //10 减法
            a = rand() % 10;
            b = rand() % a;
            result = a - b;
            printf("\n\nNo.%d\t%d - %d = \n", aCount, a, b);
            printf("您的结果是:");
            scanf("%d", &user);
            check(user, result);
            break;
        case 4: //10 减法 可负
            a = rand() % 10;
            b = rand() % 10;
            result = a - b;
            printf("\n\nNo.%d\t%d - %d = \n", aCount, a, b);
            printf("您的结果是:");
            scanf("%d", &user);
            check(user, result);
            break;
        case 5: //100 减法
            a = rand() % 100;
            b = rand() % a;
            result = a - b;
            printf("\n\nNo.%d\t%d - %d = \n", aCount, a, b);
            printf("您的结果是:");
            scanf("%d", &user);
            check(user, result);
            break;
        case 6: //100 减法 可负
            a = rand() % 100;
            b = rand() % 100;
            result = a - b;
            printf("\n\nNo.%d\t%d - %d = \n", aCount, a, b);
            printf("您的结果是:");
            scanf("%d", &user);
            check(user, result);
            break;
        case 7: //相加减 混合
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
            printf("您的结果是:");
            scanf("%d", &user);
            check(user, result);
            break;
        case 8: //相加减 混合 可负
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
            printf("您的结果是:");
            scanf("%d", &user);
            check(user, result);
            break;
        case 9: //10 乘法
            a = rand() % 10;
            b = rand() % 10;
            result = a * b;
            printf("\n\nNo.%d\t%d * %d = \n", aCount, a, b);
            printf("您的结果是:");
            scanf("%d", &user);
            check(user, result);
            break;
        case 10: //10 100 乘法
            a = rand() % 100;
            b = rand() % 10;
            result = a * b;
            printf("\n\nNo.%d\t%d * %d = \n", aCount, a, b);
            printf("您的结果是:");
            scanf("%d", &user);
            check(user, result);
            break;
        }
    }
    printf("%d 道题,您错了 %d 道,正确率 %d%%\n", count, errors, (count - errors) * 100 / count);
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
