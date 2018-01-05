#include <iostream>

using namespace std;

void insertedge(int a[][10], int x, int y, int ch)
{
	if(ch==1)
	a[x][y]=a[y][x]=1;
	else
	a[x][y]=1;
}

void deleteedge(int a[][10], int x, int y, int ch)
{
	if(ch==1)
	a[x][y]=a[y][x]=0;
	else
	a[x][y]=0;
}
void deletevert(int a[][10],int n, int x)
{
	for(int i=0;i<n;i++)
	{
		a[i][x]=a[x][i]=0;
	}
}

void insertvert(int a[][10], int n, int cho )
{
	char ch;
	if(cho==1)
	{
		for(int i=0;i<n+1;i++)
			{
			cout<<"\n Edge Between "<<i<<" and "<<n+1<<" (y/n)?"<<endl;
			cin>>ch;
			if(ch=='y')
				a[n+1][i]=a[i][n+1]=1;
			else
				a[i][n+1]=a[n+1][i]=0;
			}
	}
	else
	{


		for(int i=0;i<n+1;i++)
		{
			cout<<"\n Edge Between "<<i<<" and "<<n+1<<" (y/n)?"<<endl;
			cin>>ch;
			if(ch=='y')
				a[n+1][i]=0;
			else
				a[n+1][i]=0;
		}

		for(int i=0;i<n+1;i++)
		{
			cout<<"\n Edge Between "<<n+1<<" and "<<i<<" (y/n)?"<<endl;
			cin>>ch;
			if(ch=='y')
			a[i][n+1]=0;
			else
			a[i][n+1]=0;
		}
	}
}


void create(int a[][10], int n, int choice)
{
	char ch;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		a[i][j]=0;
	}


	if (choice==1)
	{
		for (int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(a[i][j]==1 || i==j)
					continue;
				cout<<"\n Edge Between "<<i<<" and "<<j<<" (y/n)?"<<endl;
				cin>>ch;
				if(ch=='y')
					a[i][j]=a[j][i]=1;
				else
					a[i][j]=a[j][i]=0;
			}
		}
	}
	else
	{
		for (int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i==j)
					continue;
				cout<<"\n Edge Between "<<i<<" and "<<j<<" (y/n)?"<<endl;
				cin>>ch;
				if(ch=='y')
					a[i][j]=1;
				else
					a[i][j]=0;
			}
		}
	}

}

void display(int a[][10],int n)
{
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}


int main()
{
	int n,no,x,y,val,ch;
	cout<<"\n Enter number of vertices ";
	cin>>n;
	int a[n][10];
	cout<<"\n 1.Directed  2.Undirected "<<endl;
	cin>>ch;
	create(a,n,ch);
	while (1)
	{
		cout<<"\n Enter choice ";
		cout<<"\n 1.Insert Edge ";
		cout<<"\n 2.Insert Vertex ";
		cout<<"\n 3.Delete Edge ";
		cout<<"\n 4.Delete Vertex ";
		cout<<"\n 5.Display ";
		cin>>no;
		switch(no)
		{
			case 1:
				cout<<"\n Enter Position (x,y) ";
				cin>>x;
				cin>>y;
				insertedge(a,x,y,ch);
				break;
			case 2:
				insertvert(a,n,ch);
				break;
			case 3:
				cout<<"\n Enter Position (x,y) ";
				cin>>x;
				cin>>y;
				deleteedge(a,x,y,ch);
				break;
			case 4:
				cout<<"\n Enter Vertex ";
				cin>>x;
				deletevert(a,n,x);
				break;
			case 5:
				display(a,n);
				break;
		}
	}

}
