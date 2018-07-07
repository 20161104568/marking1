//
//  main.c
//  marking1
//
//  Created by 20161104568 on 2018/7/7.
//  Copyright © 2018年 20161104568. All rights reserved.
//
#pragma once
#ifndef _STUDENT
#define _STUDENT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//extern int amount;

struct Teacher
{
    char name[10];
    char sex[5];
    long num;
};
struct Teacher t[100];
struct Student
{
    int snum;
    char name[10];
    char sex[5];
    char showname[30];
    char showtype[10];
    char stuclass[10];
    long num;
    float grade;
};
struct Student s[100];
extern int menu_select();
extern void t_output();
extern void s_output();
extern void mark();
#endif
int main()
{
    while (1)
    {
        switch (menu_select())
        {
            case 1:
                t_output();
                break;
            case 2:
                s_output();
                break;
            case 3:
                mark();
                break;
            case 4:
                //show();
                break;
            case 0:
                //save();
                printf("Thank you for using！\n");
                system("pause");
                return 0;
        }
    }
}
//菜单模块
extern int menu_select()
{
    int MenuItem;
    printf("\n ");
    printf("         | ***********打分系统*********** |          \n");
    printf("          | ------------------------------ |          \n");
    printf("          |            主菜单项            |          \n");
    printf("          | ------------------------------ |          \n");
    printf("          |	  1 --- 显示裁判信息       |          \n");
    printf("          |	  2 --- 显示选手信息	   |          \n");
    printf("          |	  3 --- 裁判打分环节	   |          \n");
    printf("          |	  4 --- 显示参赛成绩	   |          \n");
    printf("          |	  0 --- 退出系统  	   |          \n");
    do
    {
        printf("\n请输入选项（0－4）：");
        fflush(stdin);
        scanf("%d", &MenuItem);
    } while (MenuItem<0 || MenuItem>4);
    return MenuItem;
}
//裁判信息输出模块
extern void t_output()
{
    FILE *fp;
    int i;
    fp = fopen("//Users//a20161104568//Desktop//teacher.numbers", "r");
    if (fp == NULL)
    {
        printf("文件打开失败！\n");
        exit(-1);
    }
    else
    {
        printf("姓名 性别 电话号码\n");
        for (i = 0; i < 5; i++)
            fscanf(fp,"%s %s %ld\n", &t[i].name, &t[i].sex, &t[i].num);
        for (i = 0; i < 5; i++)
            printf("%2s %3s %8ld\n", t[i].name, t[i].sex, t[i].num);
    }
    fclose(fp);
}
//选手信息输出模块
extern void s_output()
{
    FILE *fp;
    int i;
    fp = fopen("//Users//a20161104568//Desktop//student.numbers", "r");
    if (fp == NULL)
    {
        printf("文件打开失败！\n");
        exit(-1);
    }
    else
    {
        printf("序号 姓名   性别  节目名称  节目类别   班级    电话号码\n");
        for (i = 0; i < 6; i++)
            fscanf(fp, "%d %s %s %s %s %s %ld\n", & s[i].snum, &s[i].name, &s[i].sex, &s[i].showname, &s[i].showtype, &s[i].stuclass, &s[i].num);
        for (i = 0; i < 6; i++)
            printf("%3d %6s %4s %9s %8s %10s %9ld\n", s[i].snum, s[i].name, s[i].sex, s[i].showname, s[i].showtype, s[i].stuclass, s[i].num);
    }
    fclose(fp);
}
//裁判打分模块
extern void mark()
{
    float grade[10];
    float sum;
    int i,j,n,x;
    float temp;
    for(n = 0;n < 6;n++)
    {
        printf("---请给第 %d 位选手打分---\n", s[n].snum);
        for (x = 0; x < 5; x++)
        {
            printf("请第 %d 位裁判打分:\n", x + 1);
            scanf("%f", &grade[x]);
        }
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 4; j++)
            {
                if (grade[j] > grade[j+1])
                {
                    temp = grade[j];
                    grade[j] = grade[j+1];
                    grade[j + 1] = temp;
                }
            }
        }
        sum = 0;
        for (i = 1; i < 4; i++)
        {
            sum = sum + grade[i];
        }
        s[j].grade = sum / 3.0;
        printf("平均成绩：%.2f\n",s[j].grade);
    }
}
        
