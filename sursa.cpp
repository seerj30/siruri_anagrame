#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
ofstream g("atestat.out");

void sterg(char s[])
{
	int i;
	for(i=0;i<strlen(s);i++)
		if(isspace(s[i]))
			strcpy(s+i,s+i+1);
	cout<<s;
}

int anagrame(char a[],char b[])
{
	int ap1[127]={},ap2[127]={},i;
	char x[100],y[100];
	strcpy(x,a);
	strcpy(y,b);
	strlwr(x);strlwr(y);
	for(i=0;i<strlen(a);i++)
		ap1[(int)x[i]]++;
	for(i=0;i<strlen(b);i++)
		ap2[(int)y[i]]++;
	for(i=97;i<=123;i++)
		if(ap1[i]!=ap2[i])
			return 0;
	return 1;
}

void separ(char s[],char v[100][25],int &n)
{
	char *p;
	n=0;
	p=strtok(s," ");
	while(p)
	{
		if(p)
			strcpy(v[++n],p);
		p=strtok(NULL," ");
	}
}

int main()
{
	char s[255],s1[255],s2[255],v[100][25];
	int n,i,j;
	cin.get(s,255);
	strcpy(s1,s);
	cout<<strupr(s1);
	cout<<endl;
	strcpy(s2,s);
	sterg(s2);
	separ(s,v,n);
	for(i=1;i<n;i++)
		for(j=i+1;j<=n;j++)
			if(anagrame(v[i],v[j]))
				g<<v[i]<<" "<<v[j]<<endl;
	g.close();
	return 0;
}
