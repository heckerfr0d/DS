#include<stdio.h>

int n;

void color(int[n][n], int[], char[], int);
int degree(int[], int[]);

int main()
{
    int i, j, m, a, b, av;
    scanf("%d%d", &n, &m);
    int G[n][n], r[n];
	char C[n];
    for(i=0;i<n;i++)
	{
        for(j=0;j<n;j++)
            G[i][j]=0;
		r[i]=1;
		C[i]='#';
	}
    for(i=0;i<m;i++)
    {
        scanf("%d%d", &a, &b);
        G[a][b]=1;
        G[b][a]=1;
    }
	av = n;
	color(G, r, C, av);
	for(i=0;i<n;i++)
		printf("%c\n", C[i]);
    return 0;
}

void color(int G[n][n], int r[], char C[], int av)
{
	int i, j, k;
	if(av==1)
	{
		for(i=n-1;i>=0;i--)
		{
			if(r[i])
			{
				C[i] = 'a';
				return;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(r[i] && C[i]=='#')
		{
			if(degree(G[i], r)<6)
			{
				r[i]=0;
				color(G, r, C, av-1);
				r[i]=1;
				int a[6]={1, 1, 1, 1, 1, 1};
				for(j=0;j<n;j++)
					if(r[j] && G[i][j] && C[j]!='#')
						a[C[j]-'a']=0;
				for(k=0;k<6;k++)
				{
					if(a[k])
					{
						C[i]='a'+k;
						return;
					}
				}
			}
		}
	}
}

int degree(int a[], int r[])
{
	int i, c=0;
	for(i=0;i<n;i++)
		if(r[i] && a[i])
			c++;
	return c;
}
