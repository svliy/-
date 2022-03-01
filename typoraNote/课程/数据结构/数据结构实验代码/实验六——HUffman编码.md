```C
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//动态分配数组存储Huffman树 
typedef struct {
	unsigned int weight;  //权值 
	unsigned int parent;
	int lchild;
	int rchild;
}HTNode, * HuffmanTree;

typedef struct{
	 char self;
	 int weight;
	 char code[50];
}combi;
int a[26] = { 0 };//记录字母出现的次数 

//存储短文 
void AddEssay();
//统计出现的字母个数n和字母出现的次数
void Count();
//显示统计的字母出现的字母次数 
void PrintNum();
//字母和数字的转换 
int Transiton(char c);
//构建HuffmanTree
void Select(HTNode HuffTree[], int k, int *s1,int *s2);

void CreateHuffTree(HTNode HuffTree[],combi w[], int n);
//Huffman编码
void HuffmanCoding(HTNode HuffTree[],combi w[],int n);
//编码文件a并存入文件b 
void Codetxt(combi w[],int n);
//译码文件b存入c 
void Uncodetxt(HTNode HuffTree[],combi w[],int n);
//比较a和c
void CompareTxt();
int NumPiPe(int x,int n,combi w[]){
	int i;
	for(i=0;i<n;i++)
	{
		if(w[i].weight==x)
			return i;
	}
}

int main()
{
	AddEssay();
	Count();
	//计算叶子节点个数 
	int n=0;
	for(int i=0;i<26;i++)
	{
		if(a[i]!=0)
			n++;
	}
	printf("叶子结点个数是%d",n);
	int m=2*n-1;
	combi w[n];
	HTNode HuffTree[m];
	
    CreateHuffTree(HuffTree,w,n);
    printf("\n");
    //printf("%d",NumPiPe(8,n,w));
	HuffmanCoding(HuffTree,w,n);
	Codetxt(w,n);
	Uncodetxt(HuffTree,w,n);
	CompareTxt();
	return 0;
}

//存储短文 
void AddEssay()
{
	FILE* pFile;

	if (!(pFile = fopen("a.txt", "w")))
	{
		printf("文件打开失败!");
		exit(1);
	}
	char c;

	while ((c = getchar()) != EOF)
	{
		fputc(c, pFile);
	}

	fclose(pFile);
}
//显示 
void PrintNum() {
	int i;
	for (i = 0; i < 26; i++)
	{
		if (a[i] != 0)
			printf("%c出现次数是:a[%d]=%d\n", i + 65, i,a[i]);
	}
}
//计数 
void Count()
{
	FILE* pFile;
	int pt; 
	if (!(pFile = fopen("a.txt", "r")))
	{
		printf("文件打开失败!");
		exit(1);
	}
	char c;

	while ((c = fgetc(pFile)) != EOF)
	{
		if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
		{
			pt=Transiton(c);
		    a[pt]++;
		}
	}
//	PrintNum();
	fclose(pFile);
}
// 
void Select(HTNode HuffTree[], int k, int *s1, int *s2)
{
	//这里s1作为最小，s2次小,接收的是序号 
	//parent=-1说明未参与构建HuffmanTree
	int i;
	int min1=1000;
	int min2=1000;
	for (i=0;i<k;i++)
	{
		if (HuffTree[i].parent == -1 && HuffTree[i].weight < min1)
		{
			*s1 = i;
			min1=HuffTree[i].weight;
		}
	}
	for (i=0;i<k;i++)
	{
		if (HuffTree[i].parent == -1 && HuffTree[i].weight < min2&&i!=(*s1))
		{
			*s2 = i;
			min2=HuffTree[i].weight;
		}
	}
}
//创建HuffmanTree 
void CreateHuffTree(HTNode HuffTree[],combi w[], int n)
{
	
	//m是有效结点个数 ,即总的结点的个数 
	//w[]存储权值 
	int m = 2 * n - 1;
	int i,k;
	int s1, s2;
	//赋值给权值集合w[].weight 
	int j=0,l=0;
	for(i=0;i<n;i++)//控制w[]中的叶子结点个数 
	{
		while(j<26)
		{
			if(a[j]!=0)
			{
				w[l].weight=a[j];
				w[l].self=j+65;
				l++;
			}
			j++;
		}
	}
	//
	printf("\n");
/*	printf("叶子结点的权值:\n");
	for(int i=0;i<n;i++)
	{
		printf("w[%d]=%d\n",i,w[i].weight);
	}*/
	//初始化所有节点的项目为-1
	for (i = 0; i < m; i++)
	{
		HuffTree[i].parent = -1;
		HuffTree[i].lchild = -1;
		HuffTree[i].rchild = -1;
		HuffTree[i].weight = -1;
	}
	//初始化前n个结点的权值
	for (i = 0; i < n; i++)
	{
		HuffTree[i].weight = w[i].weight;
	}

	//构建Huffman树
	for (k= n; k < 2 * n - 1; k++)
	{
		//可以用的节点的parent=-1
		//找到权值最小的两个结点
		Select(HuffTree,k,&s1,&s2);
	//	printf("min=%d\tmin_=%d\n",s1,s2);
		HuffTree[k].weight = HuffTree[s1].weight + HuffTree[s2].weight;
		HuffTree[k].lchild = s1;
		HuffTree[k].rchild = s2;

		HuffTree[s1].parent = k;
		HuffTree[s2].parent = k;
	//	printf("HuffTree[s2].parent=%d\tHuffTree[s2].parent=%d\n",HuffTree[s1].parent,HuffTree[s2].parent);
	}
	//打印HuffmanTree
/*	printf("\n");
	printf("序号\tweight\tparent\tlchild\trchild\n");
	for(i=0;i<m;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\n",i,HuffTree[i].weight,HuffTree[i].parent,HuffTree[i].lchild,HuffTree[i].rchild);
	 } */
}
void HuffmanCoding(HTNode HuffTree[],combi w[],int n)
{
	char *HuffCode[n];
	int i=0;
	//定义工作空间，存储临时产生的编码串
	char temp[n];
	temp[n-1]='\0';
	//遍历Huffman数组，生成Huffman编码 
	for(int i=0;i<n;i++)
	{
		int start=n-1;
		int pos=i;//记录当前位置 
		int parent=HuffTree[i].parent;//找到父亲节点
		//左孩子赋值0，右孩子赋值1 
		while(parent!=-1)
		{
			if(HuffTree[parent].lchild==pos)
				temp[--start]='0';
			else
				temp[--start]='1';
			//更新结点 
			pos=parent;
			parent=HuffTree[parent].parent;
    	}
    /*	while(start<n-1)
    	{
    		printf("%c",temp[start++]);
		}*/
		HuffCode[i]=(char *)malloc(sizeof(char)*(n-start));
		strcpy(HuffCode[i],&temp[start]);
	//	printf("\n");
	}
	//打印Huffman编码
	printf("Huffman编码:\n");
	for(int i=0;i<n;i++)
	{
		strcpy(w[i].code,HuffCode[i]);
	//	printf("%s\n",HuffCode[i]);
		printf("%c\t%d\t%s\n",w[i].self,w[i].weight,w[i].code);
	}
}
//编码文件a并存入文件b 
void Codetxt(combi w[],int n)
{	
	FILE* pFile_a;
	if (!(pFile_a= fopen("a.txt", "r")))
	{
		printf("文件打开失败!");
		exit(1);
	}
	FILE* pFile_b;
	if (!(pFile_b = fopen("b.txt", "w")))
	{
		printf("文件打开失败!");
		exit(1);
	}
	char c;
    int m;
	while ((c = fgetc(pFile_a)) != EOF)
	{
		if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
		{
			for(m=0;m<n;m++)
			{
				if(c==(w[m].self+32)||c==w[m].self)
				{
					fprintf(pFile_b,"%s",w[m].code);
				}
			}	
		}
		//printf("%c",c);
	}
	fclose(pFile_a);
	fclose(pFile_b);
}
//译码文件b存入c 
void Uncodetxt(HTNode HuffTree[],combi w[],int n)
{
	FILE* pFile_b;
	if (!(pFile_b = fopen("b.txt", "r")))
	{
		printf("文件打开失败!");
		exit(1);
	}
	FILE* pFile_c;
	if (!(pFile_c = fopen("c.txt", "w")))
	{
		printf("文件打开失败!");
		exit(1);
	}
	char c;
	int t=1;
	int pT=n*2-2;//记录当前位置 
	int lchild=HuffTree[pT].lchild;
	int rchild=HuffTree[pT].rchild;
    while ((c = fgetc(pFile_b)) != EOF)
	{
		if(c=='1')
			pT=rchild;
		if(c=='0')
			pT=lchild;
		lchild=HuffTree[pT].lchild;
		rchild=HuffTree[pT].rchild;
		if(lchild==-1&&rchild==-1)
		{
		//	t=NumPiPe(HuffTree[pT].weight,n,w);
			fprintf(pFile_c,"%c",w[pT].self);
			pT=n*2-2;
			lchild=HuffTree[pT].lchild;
			rchild=HuffTree[pT].rchild;
		}
	}
	fclose(pFile_b);
	fclose(pFile_c);
}
//比较a和c
void CompareTxt()
{
	FILE* pFile_a;
	if (!(pFile_a = fopen("a.txt", "r")))
	{
		printf("文件打开失败!");
		exit(1);
	}
	FILE* pFile_c;
	if (!(pFile_c = fopen("c.txt", "r")))
	{
		printf("文件打开失败!");
		exit(1);
	}
	
	char c_a,c_c;
	char ap[1000];
	char bp[1000];
	int app=0;
	fread(bp,1,500,pFile_c);
	while ((c_a = fgetc(pFile_a)) != EOF)
	{
		if((c_a>='a'&&c_a<='z')||(c_a>='A'&&c_a<='Z'))
		{
			ap[app++]=c_a;
		}
	}
	printf("文件a中的短文\n%s\n解码后存入文件c中的短文\n%s\n",ap,bp);
	if(strcasecmp(ap,bp)==0)
	{
		printf("same!!!!!\n");
	}
	else
	{
		printf("different!!!!!\n");
	}
	fclose(pFile_a);
	fclose(pFile_c);
}
int Transiton(char c)
{
		switch (c)
		{
		case 'a':
		case 'A':return 0;
		case 'b':
		case 'B':return 1;
		case 'c':
		case 'C':return 2;
		case 'd':
		case 'D':return 3;
		case 'e':
		case 'E':return 4;
		case 'f':
		case 'F':return 5;
		case 'g':
		case 'G':return 6;
		case 'h':
		case 'H':return 7;
		case 'i':
		case 'I':return 8;
		case 'j':
		case 'J':return 9;
		case 'k':
		case 'K':return 10;
		case 'l':
		case 'L':return 11;
		case 'm':
		case 'M':return 12;
		case 'n':
		case 'N':return 13;
		case 'o':
		case 'O':return 14;
		case 'p':
		case 'P':return 15;
		case 'q':
		case 'Q':return 16;
		case 'r':
		case 'R':return 17;
		case 's':
		case 'S':return 18;
		case 't':
		case 'T':return 19;
		case 'u':
		case 'U':return 20;
		case 'v':
		case 'V':return 21;
		case 'w':
		case 'W':return 22;
		case 'x':
		case 'X':return 23;
		case 'y':
		case 'Y':return 24;
		case 'z':
		case 'Z':return 25;
		}
}
```

