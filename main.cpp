#include "svd.h"
#include "stdio.h"
int main()
{
	int i,j;
	/*double a[4][3]={{1.0,1.0,-1.0},{2.0,1.0,0.0},{1.0,-1.0,0.0},{-1.0,2.0,1.0}};
	double b[3][4]={{1.0,1.0,-1.0,-1.0},{2.0,1.0,0.0,2.0},{1.0,-1.0,0.0,1.0}};
	double u[4][4],v[3][3],c[4][3],d[3][4];*/
	double a[12]={1.0,1.0,-1.0,2.0,1.0,0.0,1.0,-1.0,0.0,-1.0,2.0,1.0};
	double b[12]={1.0,1.0,-1.0,-1.0,2.0,1.0,0.0,2.0,1.0,-1.0,0.0,1.0};
	double u[16],v[9],c[12],d[12];

	for(i=0;i<16;i++)
		u[i]=0;
	double eps=0.000001;
	i=dluav(a,4,3,u,v,eps,5);
	
	printf("\n");
	printf("i=%d\n",i);
	printf("\nMAT U Is:\n");
	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
			printf("%e ",u[i*4+j]);
		printf("\n");
	}
	printf("\n");
	printf("MAT V IS:\n");
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
			printf("%e ",v[i*3+j]);
		printf("\n");
	}
	printf("\n");
	printf("MAT A Is:\n");
	for(i=0;i<=3;i++)
	{
		for(j=0;j<=2;j++)
			printf("%e ",a[i*3+j]);
		printf("\n");
	}	
	damul(u,a,4,4,3,c);
	damul(c,v,4,3,3,a);
	printf("\nMAT UAV IS:\n");
	for(i=0;i<=3;i++)
	{
		for(j=0;j<=2;j++)
			printf("%e ",a[i*3+j]);
		printf("\n");
	}
	printf("\n\n");
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

	system("pause");
	return 0;

}