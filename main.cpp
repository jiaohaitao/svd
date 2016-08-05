#include "svd.h"
#include "stdio.h"

#define M 4
#define N 3

int main()
{
	int i,j;
	/*double a[4][3]={{1.0,1.0,-1.0},{2.0,1.0,0.0},{1.0,-1.0,0.0},{-1.0,2.0,1.0}};
	double b[3][4]={{1.0,1.0,-1.0,-1.0},{2.0,1.0,0.0,2.0},{1.0,-1.0,0.0,1.0}};
	double u[4][4],v[3][3],c[4][3],d[3][4];*/
	double a[M*N]={1.0,1.0,-1.0,2.0,1.0,0.0,1.0,-1.0,0.0,-1.0,2.0,1.0};
	double b[M*N]={1.0,1.0,-1.0,-1.0,2.0,1.0,0.0,2.0,1.0,-1.0,0.0,1.0};
	double u[M*M],v[N*N],c[M*N],d[M*N];

	for(i=0;i<M*M;i++)
		u[i]=0;
	double eps=0.000001;
	i=dluav(a,M,N,u,v,eps,M+1);
	
	printf("\n");
	printf("i=%d\n",i);
	printf("\nMAT U Is:\n");
	for(i=0;i<=N;i++)
	{
		for(j=0;j<=N;j++)
			printf("%e ",u[i*M+j]);
		printf("\n");
	}
	printf("\n");
	printf("MAT V IS:\n");
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			printf("%e ",v[i*N+j]);
		printf("\n");
	}
	printf("\n");
	printf("MAT A Is:\n");
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
			printf("%e ",a[i*N+j]);
		printf("\n");
	}	
	printf("\n----the nrom is :%f\n",a[0]);
	damul(u,a,M,M,N,c);
	damul(c,v,M,N,N,a);
	printf("\nMAT UAV IS:\n");
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
			printf("%e ",a[i*N+j]);
		printf("\n");
	}
	printf("\n\n");
/*
	printf("第二个例子\n");
	i=dluav(b,3,4,v,u,eps,5);
	printf("i=%d\n",i);
	printf("\n");
	printf("MATUS IS:\n");
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
			printf("%e ",v[i*3+j]);
		printf("\n");
	}
	printf("\n");
	printf("MAT V IS:\n");
	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
			printf("%e ",u[i*3+j]);
		printf("\n");
	}
	printf("\nMAT B IS:\n");
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=3;j++)
			printf("%e ",b[i*4+j]);
		printf("\n");
	}
	printf("\n\n");
	printf("\n----the nrom is :%f\n",b[0]);
	printf("MAT UBV IS:\n");
	damul(v,b,3,3,4,d);
	damul(d,u,3,4,4,b);
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=3;j++)
			printf("%e ",b[i*4+j]);
		printf("\n");
	}
	printf("\n");
*/
	system("pause");
	return 0;

}