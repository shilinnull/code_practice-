#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

#if 0

// - 第一题
//题目：有 1、2、3、4 四个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？
//程序分析：可填在百位、十位、个位的数字都是 1、2、3、4，组成所有的排列后再去掉不满足条件的排列。
int main() {
    int g, s, b;
    int count = 0; // 计算的个数
    for (g = 1; g <= 4; g++) {
        for (s = 1; s <= 4; s++) {
            for (b = 1; b <= 4; b++) {
                if (g != s && g != b && s && b) {
                    printf("%d,%d,%d\n", g, s, b);
                    count++;
                }
            }
        }
    }
    printf("count : %d\n", count);
    return 0;
}


// - 第二题
/*
题目：企业发放的奖金根据利润提成。

利润(i)低于或等于10万元时，奖金可提10%；
利润高于10万元，低于20万元时，低于10万元的部分按10%提成，高于10万元的部分，可提成7.5%；
20万到40万之间时，高于20万元的部分，可提成5%；
40万到60万之间时高于40万元的部分，可提成3%；
60万到100万之间时，高于60万元的部分，可提成1.5%；
高于100万元时，超过100万元的部分按1%提成。
从键盘输入当月利润i，求应发放奖金总数？

程序分析：请利用数轴来分界，定位。注意定义时需把奖金定义成双精度浮点(double)型。
*/

#include<stdio.h>
int main()
{

    double profit;
    double bonus1, bonus2, bonus4, bonus6, bonus10, bonus;
    printf("你的净利润是：");

    scanf("%lf", &profit);

    bonus1 = 100000 * 0.1;
    bonus2 = bonus1 + 100000 * 0.075;
    bonus4 = bonus2 + 200000 * 0.05;
    bonus6 = bonus4 + 200000 * 0.03;
    bonus10 = bonus6 + 400000 * 0.015;

    if (profit <= 100000) {
        bonus = profit * 0.1;
    }
    else if (profit <= 200000) {
        bonus = bonus1 + (profit - 100000) * 0.075;
    }
    else if (profit <= 400000) {
        bonus = bonus2 + (profit - 200000) * 0.05;
    }
    else if (profit <= 600000) {
        bonus = bonus4 + (profit - 400000) * 0.03;
    }
    else if (profit <= 1000000) {
        bonus = bonus6 + (profit - 600000) * 0.015;
    }
    else if (profit > 1000000) {
        bonus = bonus10 + (profit - 1000000) * 0.01;
    }
    printf("提成为：bonus=%lf", bonus);

    printf("\n");
}



/*
// - 第三题

题目：一个整数，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请问该数是多少？
程序分析：
假设该数为 x。
1、则：x + 100 = n2, x + 100 + 168 = m2
2、计算等式：m2 - n2 = (m + n)(m - n) = 168
3、设置： m + n = i，m - n = j，i * j =168，i 和 j 至少一个是偶数
4、可得： m = (i + j) / 2， n = (i - j) / 2，i 和 j 要么都是偶数，要么都是奇数。
5、从 3 和 4 推导可知道，i 与 j 均是大于等于 2 的偶数。
6、由于 i * j = 168， j>=2，则 1 < i < 168 / 2 + 1。
7、接下来将 i 的所有数字循环计算即可。
*/

#include <stdio.h>

int main()
{
    int  i, j, m, n, x;
    for (i = 1; i < 168 / 2 + 1; i++)
    {
        if (168 % i == 0)
        {
            j = 168 / i;
            if (i > j && (i + j) % 2 == 0 && (i - j) % 2 == 0)
            {
                m = (i + j) / 2;
                n = (i - j) / 2;
                x = n * n - 100;
                printf("%d + 100 = %d * %d\n", x, n, n);
                printf("%d + 268 = %d * %d\n", x, m, m);
            }
        }
    }
    return 0;
}

/*
// - 第四题
 题目：输入某年某月某日，判断这一天是这一年的第几天？
程序分析：以3月5日为例，应该先把前两个月的加起来，然后再加上5天即本年的第几天，
 特殊情况，闰年且输入月份大于3时需考虑多加一天。
*/

int main()
{
    int year, month, day; int is_year(int);
    int m[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    printf("input year month day: ");
    fflush(stdout);
    scanf("%d %d %d", &year, &month, &day);
    int i;
    for (i = 1; i < month; i++)
        day += m[i];
    if (is_year(year) && month >= 2)
        day++;
    printf("这一天是这一年的第%d天\n", day);

    return 0;
}

int is_year(int y) {
    return (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0));
}

// - 第五题
/*
题目：输入三个整数 x、y、z，请把这三个数由小到大输出。

程序分析：我们想办法把最小的数放到 x 上，先将 x 与 y 进行比较，如果 x>y 则将 x 与 y 的值进行交换，然后再用 x 与 z 进行比较，如果 x>z 则将 x 与 z 的值进行交换，这样能使 x 最小。

*/

int main()
{
    int x, y, z, t;
    scanf("%d %d %d", &x, &y, &z);

    if (x > y) { t = x; x = y; y = t; }
    if (x > z) { t = x; x = z; z = t; }
    if (y > z) { t = y; y = z; z = t; }
    printf("%d %d %d\n", x, y, z);

    return 0;
}




// - 第六题

/*
 题目：用*号输出字母c的图案。
程序分析：可先用'*'号在纸上写出字母c，再分行输出。
*/

int main()
{
    int i, j, n;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("* ");
    }
    printf("\n");
    for (i = 1; i < n - 1; i++) {
        printf("*\n");
    }
    for (i = 0; i < n; i++) {
        printf("* ");
    }

    return 0;
}



// - 第七题
/*
题目：输出特殊图案，请在c环境中运行，看一看，very beautiful!

程序分析：字符共有256个。不同字符，图形不一样。

vc6.0下出现中文乱码(原因 + 解决方法) :

    176的16进制是b0，219的16进制是db，0xb0db是"佰"字的内码，所以输出的就是"佰"了。

    主要原因是文件信息的代码页不同，我们所使用的操作系统中文状态下的代码页，要显示扩展的ascii码需要在437 oem - 美国这个下面显示，这样就可以显示出你所希望的。具体修改控制台的默认代码页步骤如下：

    1.点击运行界面左上角标题栏图标【c:\】，选择默认值一项
    2.修改默认代码页，936（ansi / oem - 简体中文gbk）为437 oem - 美国
    3、关闭后重新运行一下即可

*/


#include<stdio.h>
int main()
{
    char a = 176, b = 219;
    printf("%c%c%c%c%c\n", b, a, a, a, b);
    printf("%c%c%c%c%c\n", a, b, a, b, a);
    printf("%c%c%c%c%c\n", a, a, b, a, a);
    printf("%c%c%c%c%c\n", a, b, a, b, a);
    printf("%c%c%c%c%c\n", b, a, a, a, b);
    return 0;
}



// c 练习实例8

/*题目：输出 9*9 口诀。
程序分析：分行与列考虑，共 9 行 9 列，i 控制行，j 控制列。*/

int main()
{
    int n, i, j;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d*%d=%d ", j, i, i * j);
        }
        printf("\n");
    }
    return 0;
}

// 程序打印斐波那契数列的前20项
/*
题目：古典问题（兔子生崽）：有一对兔子，从出生后第3个月起每个月都生一对兔子，
小兔子长到第三个月后每个月又生一对兔子，
假如兔子都不死，问每个月的兔子总数为多少？（输出前40个月即可）*/
#include<stdio.h>

int main()
{
    int cnt;
    int cnt1 = 1, cnt2 = 1;
    printf("第1个月：%d\n", cnt1);
    printf("第2个月：%d\n", cnt2);

    for (int i = 3; i < 41; ++i)
    {
        cnt = cnt1 + cnt2;
        printf("第%d个月：%d\n", i, cnt);
        cnt1 = cnt2;
        cnt2 = cnt;
    }
    return 0;
}



/*
题目：判断 101 到 200 之间的素数。

程序分析：判断素数的方法：用一个数分别去除 2 到 sqrt(这个数)，如果能被整除，
则表明此数不是素数，反之是素数。

*/


#include <stdio.h>
#include <math.h>
int main()
{
    int i, j;
    for (i = 101; i <= 200; i++) {
        for (j = 2; j <= sqrt(i); j++) {
            if (i % j == 0)
                break;
        }
        if (j > sqrt(i))
            printf("%d ", i);
    }
    return 0;
}


/*
13
题目：打印出所有的"水仙花数"，所谓"水仙花数"是指一个三位数，
其各位数字立方和等于该数本身。例如：153是一个"水仙花数"，因为153 = 1的三次方＋5的三次方＋3的三次方。

*/

int main()
{
    int i, g,s,b;
    for (i = 100; i <= 999; i++) {
        g = i % 10;
        s = i / 10 % 10;
        b = i / 100 % 10;
        if (i == g * g * g + s * s * s + b * b * b) 
            printf("%d ", i);
    }
    return 0;
}



/*
14
题目：将一个正整数分解质因数。例如：输入90，打印出90=2*3*3*5。

分析：对n进行分解质因数，应先找到一个最小的质数k，然后按下述步骤完成：
(1)n能被k整除，则应打印出k的值，并用n除以k的商，作为新的正整数n。重复执行。
(2)如果n不能被k整除，则用k+1作为k的值，重复执行第一步。

*/

    
int main()
{
    int i;
    int n = 90;
    printf("%d=", n);
    for (i = 2; i <= n; i++) {
        while (n % i == 0) {
            printf("%d", i);
            n = n / i;
            if (n != 1)
                printf("*");
        }
    }
    return 0;
}
#endif
/*
15
题目：利用条件运算符的嵌套来完成此题：
学习成绩>=90分的同学用A表示，60-89分之间的用B表示，60分以下的用C表示。

程序分析：(a>b)?a:b这是条件运算符的基本例子。
*/

#define GRAND(x) (x >= 90) ? 'A' : (x > 60 ? 'B' : 'C')

int main()
{
    int score;
    while (~scanf("%d", &score)) {
        printf("学习成绩为：%c\n", GRAND(score));
    }
    return 0;
}