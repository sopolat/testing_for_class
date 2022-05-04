#include <iostream>

using namespace std;
int mem[251][251];
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
	//testing git
	return total;
}

int main()
{
	for(int i=0;i<251;i++)
		for(int j=0;j<251;j++)
			mem[i][j]=0;
    cout<<ans(250);

    return 0;
}
