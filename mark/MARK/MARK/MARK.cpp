// MARK.cpp: 定义控制台应用程序的入口点。
//

#include "MARK.h"
int main()
{
	while (1)
	{
		switch (menu_select())
		{
		case 1:
			s_display();
			break;
		case 2:
			t_display();
			break;
		case 3:
			mark();
			break;
		case 4:
			output();
			break;
		case 5:
			sort();
			break;
		case 0:
			save();
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
	printf("          |	  1 --- 选手信息           |          \n");
	printf("          |	  2 --- 裁判信息	   |          \n");
	printf("          |	  3 --- 打分	           |          \n");
	printf("          |	  4 --- 选手成绩	   |          \n");
	printf("          |	  5 --- 选手排名	   |          \n");
	printf("          |	  0 --- 退出系统  	   |          \n");
	do
	{
		printf("\n请输入选项（0－5）：");
		fflush(stdin);
		scanf("%d", &MenuItem);
	} while (MenuItem<0 || MenuItem>5);
	return MenuItem;
}
//裁判信息输出模块
extern void t_display()
{
	FILE *fp;
	int i;
	fp = fopen("teacher.txt", "r");
	if (fp == NULL)
	{
		printf("文件打开失败！\n");
		exit(-1);
	}
	else
	{
		printf("姓名 性别 电话号码\n");
		for (i = 0; i < 5; i++)
			fscanf(fp, "%s %s %ld\n", &t[i].name, &t[i].sex, &t[i].num);
		for (i = 0; i < 5; i++)
			printf("%2s %3s %8ld\n", t[i].name, t[i].sex, t[i].num);
	}
	fclose(fp);
}
//选手信息输出模块
extern void s_display()
{
	FILE *fp;
	int i;
	fp = fopen("student.txt", "r");
	if (fp == NULL)
	{
		printf("文件打开失败！\n");
		exit(-1);
	}
	else
	{
		printf("序号 姓名   性别  节目名称 类别 节目类别   班级    电话号码\n");
		for (i = 0; i < 6; i++)
			fscanf(fp, "%d %s %s %s %s %s %s %ld\n", &s[i].snum, &s[i].name, &s[i].sex, &s[i].showname, &s[i].type, &s[i].showtype, &s[i].stuclass, &s[i].num);
		for (i = 0; i < 6; i++)
			printf("%3d %6s %4s %9s %3s %8s %10s %9ld\n", s[i].snum, s[i].name, s[i].sex, s[i].showname, &s[i].type, s[i].showtype, s[i].stuclass, s[i].num);
	}
	fclose(fp);
}
//裁判打分模块
extern void mark()
{
	float grade[10];
	float sum;
	int i, j, n, x;
	float temp;
	for (n = 0; n < 6; n++)
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
				if (grade[j] > grade[j + 1])
				{
					temp = grade[j];
					grade[j] = grade[j + 1];
					grade[j + 1] = temp;
				}
			}
		}
		sum = 0;
		for (i = 1; i < 4; i++)
		{
			sum = sum + grade[i];
		}
		s[n].grade = sum / 3.0;
		printf("平均成绩：%.2f\n", s[n].grade);
	}
}
//显示选手成绩模块
extern void output()
{
	int i;
	printf("序号 姓名   性别  节目名称  类别   节目类别   班级    电话号码  平均成绩\n");
	for (i = 0; i < 6; i++)
	{
		printf("%3d %6s %4s %9s %5s %9s %10s %9ld %8.2f\n", s[i].snum, s[i].name, s[i].sex, s[i].showname, &s[i].type, s[i].showtype, s[i].stuclass, s[i].num, s[i].grade);
	}
}
//显示选手排名模块
extern void sort()
{
	int i, j;
	int x;
	struct Student t[100];
	struct Student temp;
	for (i = 0; i < 6; i++)
	{
		t[i] = s[i];
	}
	x = 0;
	for (i = 0; i < 6; i++)
	{
		if (strcmp(t[i].type, "A") == 0)
		{
			sing[x] = t[i];
			x++;
		}
	}
	samount = x;
	for (i = 0; i < x - 1; i++)
	{
		for (j = 0; j < x - 1; j++)
		{
			if (sing[j].grade < sing[j + 1].grade)
			{
				temp = sing[j];
				sing[j] = sing[j + 1];
				sing[j + 1] = temp;
			}
		}
	}
	printf("----唱歌类排名----\n");
	printf("序号 姓名     节目名称  节目类别     平均成绩  排名\n");
	for (i = 0; i < x; i++)
	{
		printf("%3d %6s  %9s  %8s  %8.2f %5d\n", sing[i].snum, sing[i].name, sing[i].showname, sing[i].showtype, sing[i].grade, i + 1);
	}
	x = 0;
	for (i = 0; i < 6; i++)
	{
		if (strcmp(t[i].type, "B") == 0)
		{
			magic[x] = t[i];
			x++;
		}
	}
	mamount = x;
	for (i = 0; i < x - 1; i++)
	{
		for (j = 0; j < x - 1; j++)
		{
			if (magic[j].grade < magic[j + 1].grade)
			{
				temp = magic[j];
				magic[j] = magic[j + 1];
				magic[j + 1] = temp;
			}
		}
	}
	printf("----魔术类排名----\n");
	printf("序号 姓名     节目名称  节目类别     平均成绩  排名\n");
	for (i = 0; i < x; i++)
	{
		printf("%3d %6s  %9s  %8s  %8.2f %5d\n", magic[i].snum, magic[i].name, magic[i].showname, magic[i].showtype, magic[i].grade, i + 1);
	}
}
//保存模块
int samount;
int mamount;
extern void save()
{
	int i;
	FILE *fp;
	FILE *fw;
	fp = fopen("sing.txt", "w");
	fw = fopen("magic.txt", "w");
	if (fp == NULL)
	{
		printf("文件打开失败！\n");
		exit(-1);
	}
	else
	{
		for (i = 0; i<samount; i++)
		{
			fprintf(fp, "%d %s %s %s %s %s %s %ld %.2f %d\n", sing[i].snum, sing[i].name, sing[i].sex, sing[i].showname, &sing[i].type, sing[i].showtype, sing[i].stuclass, sing[i].num, sing[i].grade, i + 1);
		}
	}
	fclose(fp);
	if (fw == NULL)
	{
		printf("文件打开失败！\n");
		exit(-1);
	}
	else
	{
		for (i = 0; i<mamount; i++)
		{
			fprintf(fw, "%d %s %s %s %s %s %s %ld %.2f %d\n", magic[i].snum, magic[i].name, magic[i].sex, magic[i].showname, magic[i].type, magic[i].showtype, magic[i].stuclass, magic[i].num, magic[i].grade, i + 1);
		}
	}
	fclose(fp);
}