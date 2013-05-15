#include <stdio.h>
#include <conio.h>
int main()
{
	FILE *fp;
	FILE *fp1;
	char ch=')' , filename[50] = "c:\\a.txt", yes_no  ;
	int key,i=0,m , j=0 ,num=0 ;
	key=5 ;
		 printf("请输入文件位置(Please input file location)\n");
		 scanf("%s", filename);
		 getchar();/*输入文件所在路径及名称*/
		 printf("请输入您要保存的内容,以'#和回车键'结束(Please type something that you wanna save,end up with '#'and enter)\n");
		 if ((fp = fopen(filename, "w")) == NULL)/*以只写方式打开指定文件*/
		 {
			   printf("位置有问题，请重新确认！(Please input location again)\n");
			   return 0;
		 }   
		while(ch!='#')
		{
			ch=getchar();
			if(ch!='#')
		{
		ch=ch+key;/*对字符的ascal码后移5位加密*/
		fputc(ch, fp);/*将加密后的字符写入fp文件指针指向的文件内*/
		}
		if (ch=='#')
		{
			fclose(fp);
		}
		}
/*--------------解密过程------------------*/
		
	printf("是否解密文件,是按y，否按n(If you wanna decrypt file,click 'y')\n");
	yes_no=getch();
	if(yes_no=='n' || yes_no=='N')
	return 0 ;
	while(yes_no == 'Y' || yes_no == 'y')
	{
		printf("请输入文件的位置(Please input file location):\n");
	    scanf("%s", filename);/*输入文件位置*/
		getchar();
		if ((fp = fopen(filename, "rt")) == NULL)
			return -1;
		ch = fgetc(fp);
		while (ch != EOF)
		{
			ch=ch-5;
			putchar(ch);
			ch = fgetc(fp);
		}
		break;
	}
		fclose(fp);
/*--------------解密过程------------------*/
		printf("\n解密成功(Decryp succeeded)");
		getchar();
		return 0;
}