#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)//取消scanf返回值的警告

//文件的操作  练习
//文件类型  分 文本文件  和 二进制文件（看不懂）
// 


#include <stdio.h>      //文件的输入输出流包含库

struct S
{
	int n;
	float score;
	char arr[10];
};

int main()
{
	int a = 10000;
	FILE* p_f = fopen("test.txt", "r");//打开文件test.txt   返回file*指针  wb代表打开模式 
	//相对路径
	//..表示上一级路径
	//.表示当前路径
	//fopen("../test.txt","wb");
	// //fopen("./test.txt","wb");
	//---------------------------- //
	//绝对路径的写法
	//D:\c语言文件\fileoperation/test.txt
	if (p_f==NULL)//打开失败 报错
	{
		perror("错误");
		return 0;
	}
	
	//fwrite(&a, 4, 1, p_f);//写入a  以二进制写入
	//
	////写入一个字符
	////fputc('b', p_f);
	////fputc('i', p_f);
	////fputc('t', p_f);


	////读一个字符
	//printf("%c", fgetc(p_f));
	//printf("%c", fgetc(p_f));
	//printf("%c", fgetc(p_f));

	////读一行字符
	//char buf[1024] = "sdafsadfsdafsadf";
	///*fgets(buf, 1024, p_f);
	//printf("%s",buf );*/

	////写一行
	//fputs(buf, p_f);
	//fputs(buf, p_f);

	//格式化的形式写文件  针对所有输出流
	struct S s = { 100,3.14f,"bit" };
	//fprintf(p_f, "%d %f %s", s.n, s.score, s.arr);

	////格式化读文件  针对所有输入流
	//struct S s = { 0 };
	//fscanf(p_f, "%d %f %s", &s.n, &s.score, &s.arr);

	//关闭文件 和fopen必须成对出现  释放
    fclose(p_f);
	p_f = NULL;

	//格式化字符串  将不同类型以字符串保存
	char buff[1024] = { 0 };
	sprintf(buff, "%d %f %s", s.n, s.score, s.arr);
	printf(buff);
	//格式化字符串  将不同类型以不同类型保存到
	struct S tmp = { 0 };
	sscanf(buff, "%d %f %s", &tmp.n, &tmp.score, s.arr);

		
	//int ch = fgetc(stdin);//从键盘读一个字符
	//fputc(ch,stdout);//从显示器输出一个字符

	//int ch=getc(stdin);
	//putc(ch, stdout);
	return 0;
}