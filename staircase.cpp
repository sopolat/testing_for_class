#include <iostream>

using namespace std;
int mem[201][201];
int helper(int maxH,int bricks)
{
	if(mem[maxH][bricks]!=0)
		return mem[maxH][bricks];
	int total=0;
	if(bricks<0)
		return 0;
	if(bricks==0)
		return 1;
	for(int i=maxH;i>0;i--)
	{
		total +=helper(i-1,bricks-i);
	}
	mem[maxH][bricks]=total;
	return total;
}
int ans(int n)
{
	int total=0;
	for(int i=n-1;i>1;i--)
	{
		total +=helper(i-1,n-i);
	}
	return total;
}

int main()
{
	for(int i=0;i<201;i++)
		for(int j=0;j<201;j++)
			mem[i][j]=0;
    cout<<ans(200);

    return 0;
}
