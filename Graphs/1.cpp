#include<bits/stdc++.h>
using namespace std;

int main()
{
	char line[] =  "innovation by iet imparting knowledge on campus";
	char string1[10], string2[10], string3[10];
	sscanf(line, "%*s %*s %s %*s %*s %s %s", string1, string2, string3);
	printf("%s %s %s", string1, string2, string3);

}
