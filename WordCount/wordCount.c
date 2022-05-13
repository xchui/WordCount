#include <stdio.h>

int main(int argc,char *argv[])
{
	int opt=0; 
	while((opt=getopt(argc,argv,"c:w:"))!=-1)
	{
		switch(opt)
		{
			case 'c':
				printf("字符数：%d",cc(argv[2]));
				break;
			case 'w':
				printf("单词数：%d",ww(argv[2]));
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
        printf("空文件");
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
        printf("空文件");
        return 0;
    }
	char c;
	int num=0;
	int last=0;//1字符 0空 
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

