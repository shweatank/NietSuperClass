#include<stdio.h>
#include<stdarg.h>
#include<string.h>

int arg(char* arg1,...){
	int len;
	va_list argp;
	va_start(argp,arg1);
	char* p;
	len=strlen(arg1);
	while((p=va_arg(argp,char*))!=NULL)
		len+=strlen(p);
	va_end(argp);
	return len;
}

int mystrstr(char * str1,unsigned int n1,char* str2,unsigned int n2){
	if(*str2=='\0')return 0;
	for(int i=0;i<(n1-n2+1);i++){
		int j=0;
		for(;j<n2;j++)
			if(str1[i+j]!=str2[j])break;
		if(j==n2)return i;
	}
	return -1;
}

void revstr(char* str,unsigned int len){
	int i=0,j=len-1;
	while(j>i){
		str[i]^=str[j];
		str[j]^=str[i];
		str[i]^=str[j];
		i++;
		j--;
	}
}

int main(void){
	int len=arg("hello","hi","how","are","you",(char*)NULL);
	printf("%d\n",len);
	printf("%d\n",mystrstr("hello",5,"ll",2));
	printf("%d\n",mystrstr("hello",5,"lu",2));
	char a[20],b[20];
	memset(a,'\0',20);
	memset(b,'\0',20);
	//scanf("%s",a);
	//scanf("%s",b);
	int a1,b1;
	//scanf("%d%d",&a1,&b1);
	//printf("%s %s %d %d",a,b,a1,b1);
	//printf("%d\n",mystrstr(a,a1,b,b1));
	printf("%d %d",sizeof("hello"),strlen("hello"));
	char arr[]="hello";
	revstr(arr,5);
	printf("%s\n",arr);
	return 0;
}
