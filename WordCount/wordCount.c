#include <stdio.h>

int main(int argc,char *argv[])
{
	int opt=0; 
	while((opt=getopt(argc,argv,"c:w:"))!=-1)
	{
		switch(opt)
		{
			case 'c':
				printf("�ַ�����%d",cc(argv[2]));
				break;
			case 'w':
				printf("��������%d",ww(argv[2]));
				break;
		}
	} 
	return 0;
}

int cc(char *file)
{
	FILE *f=NULL;
	f=fopen(file,"r");
	if(NULL==f)
    {
        printf("���ļ�");
        return 0;
    }
	char c;
	int num=0;
	while(!feof(f))
	{
		c=fgetc(f);
		num++; 
	}
	fclose(f);
	return(num);
}

int ww(char *file)
{
	FILE *f=NULL;
	f=fopen(file,"r");
	if(NULL==f)
    {
        printf("���ļ�");
        return 0;
    }
	char c;
	int num=0;
	int last=0;//1�ַ� 0�� 
	while(!feof(f))
	{
		c=fgetc(f);
		
		if((c==' '||c==','))
			last=0;
		else 
		{
			
			if(last==0)
				num++; 
			last=1;
		}
	}
	fclose(f);
	return(num);
}

