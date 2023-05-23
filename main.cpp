#include <iostream>
#include<string.h>
#include<fstream>
using namespace std;

void NextVal(char P[],int nextval[]) {
    int i,j;
    nextval[i = 0] = j = -1;
    int len = strlen(P);
    while (i < len - 1) {
        if (j == -1 || P[i] == P[j]) {
            i++,j++;
            if (P[i] == P[j]) {
                nextval[i] = nextval[j];
            }
            else nextval[i] = j;
        }
        else j = nextval[j];
    }
}
int KMP(char s[], char p[])
{
    int len =strlen(s);
    int plen =strlen(p);
	int next[len];
	NextVal(p,next);
	int k = -1;
	int i = 0;
	for (; i < len; i++)
	{
 		while (k > -1 && p[k+1]!=s[i])
		{
			k = next[k];
		}
		if(p[k+1] == s[i])
		{
			k++;
		}
		if (k == plen-1)//匹配成功，返回短串在长串的位置。
		{
			return i-plen+1;

		}
	}
	return -1;
}

void Virus_detection()
{
	int i=0;
	char virus[20],temp[20];
	char person[100];
	int an[999];
	while(true)
	{
		scanf("%s %s",virus,person);
		if(virus[0]=='0'&&person[0]=='0')
            break;
		string temp="";
		for(int yy=0;virus[yy];yy++)
            temp +=virus[yy];
        int len =temp.length();
        char Virus[len];
        for(int y=1;y<=len;y++)
        {
            for(int yx=0;yx<len;yx++)
                Virus[yx] =temp[yx];
            int k =KMP(person,Virus);
            if(k==-1)
            {
               an[i]=1;
            }
            else{
               an[i] = -1;
               break;
            }
            temp=temp.substr(1)+temp[0];
        }
		i++;
	}
	for(int yy=0;an[yy]!=0;yy++)
        if(an[yy]==-1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
}
int main()
{
    Virus_detection();
    return 0;
}
