#pragma once
#ifndef _STUDENT
#define _STUDENT

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <iostream>

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
	char type[3];
	char showtype[5];
	char stuclass[10];
	long num;
	float grade;
};
struct Student s[100];
struct Student sing[100];
struct Student magic[100];
extern int samount;
extern int mamount;
extern int menu_select();
extern void s_display();
extern void t_display();
extern void mark();
extern void output();
extern void sort();
extern void save();
#endif
