#include <stdio.h>
#include <conio.h>
int main()
{
	FILE *fp;
	FILE *fp1;
	char ch=')' , filename[50] = "c:\\a.txt", yes_no  ;
	int key,i=0,m , j=0 ,num=0 ;
	key=5 ;
		 printf("�������ļ�λ��(Please input file location)\n");
		 scanf("%s", filename);
		 getchar();/*�����ļ�����·��������*/
		 printf("��������Ҫ���������,��'#�ͻس���'����(Please type something that you wanna save,end up with '#'and enter)\n");
		 if ((fp = fopen(filename, "w")) == NULL)/*��ֻд��ʽ��ָ���ļ�*/
		 {
			   printf("λ�������⣬������ȷ�ϣ�(Please input location again)\n");
			   return 0;
		 }   
		while(ch!='#')
		{
			ch=getchar();
			if(ch!='#')
		{
		ch=ch+key;/*���ַ���ascal�����5λ����*/
		fputc(ch, fp);/*�����ܺ���ַ�д��fp�ļ�ָ��ָ����ļ���*/
		}
		if (ch=='#')
		{
			fclose(fp);
		}
		}
/*--------------���ܹ���------------------*/
		
	printf("�Ƿ�����ļ�,�ǰ�y����n(If you wanna decrypt file,click 'y')\n");
	yes_no=getch();
	if(yes_no=='n' || yes_no=='N')
	return 0 ;
	while(yes_no == 'Y' || yes_no == 'y')
	{
		printf("�������ļ���λ��(Please input file location):\n");
	    scanf("%s", filename);/*�����ļ�λ��*/
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
/*--------------���ܹ���------------------*/
		printf("\n���ܳɹ�(Decryp succeeded)");
		getchar();
		return 0;
}