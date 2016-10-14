#include <iostream>
#include <stdlib.h>
using namespace std;
#define N 1000000
#define M 2000000
void secondary();
struct node
{
	long long int n;
	struct node* next;
}*node_ptr;
struct primary
{
	long long int n;
	struct node* head;
	long long int* arr;
};
primary *prime= new primary[M];
	long long int p1=10000000019,p2=10000099999;
	int a1,b1;
	//long long int primary[M];
	int main()
	{
		
		long long int x,sum=0;
		for(int i=0;i<M;i++)
			prime[i].n=0;
		a1=rand()%1000;
		FILE *fp;
		fp=fopen("input.txt","r");
		do
		{
			//cout<<"hii";
			sum=0;
			b1=rand()%1000;
			for(int i=0;i<N;i++)
			{
			
				//cout<<"hii";
				fscanf(fp,"%lld",&x);
				//cout<<x;
				long long int index;
				index=((x*a1+b1)%p1)%M;
				//cout<<"index="<<index;
				prime[index].n++;
				if(prime[index].head==NULL)
				{
					prime[index].head=new node;
					prime[index].head->next=NULL;
				}
				else
				{
					node_ptr=new node;
					node_ptr->next=prime[index].head;
					prime[index].head=node_ptr;
					//prime[index].end->next=new node;
					//prime[index].end=prime[index].end->next;
				}
				prime[index].head->n=x;
				//prime[index].end->next=NULL;
			}
			for(int i=0;i<M;i++)
			{
				sum=sum+(prime[i].n*prime[i].n);
			}
			cout<<"sum="<<sum<<endl;
			rewind(fp);
		}while(sum>M);
		for(int i=0;i<20;i++)
		{
			node_ptr=prime[i].head;
			cout<<"i="<<i<<": ";
			while(node_ptr!=NULL)
			{
				cout<<node_ptr->n<<" ";
				node_ptr=node_ptr->next;
			}
			cout<<endl;
		}
		
	cout<<a1<<" "<<b1<<" "<<sum;
	secondary();
	
	return 0;
	}
	void secondary()
	{
		long long int count=0;
		cout<<endl;
		for(int i=0;i<M;i++)
		{
			//cout<<"i="<<i<<endl;
			if(prime[i].n>0)
			{
				int n_i=prime[i].n*prime[i].n;
				int collide;
				prime[i].arr=new long long int[n_i+2];
				long long int a,b;
				srand(count);
				count++;
						
				do
				{
					a=rand()%100000;
					b=rand()%100000;
					fill_n(prime[i].arr,n_i+2,0);
					prime[i].arr[0]=a;
					prime[i].arr[1]=b;
					collide=0;
					node_ptr=prime[i].head;
					
					while(node_ptr!=NULL)
					{
						//cout<<"hii"<<endl;
						long long int index,x;
						x=node_ptr->n;
						node_ptr=node_ptr->next;
						//cout<<"x="<<x<<" a="<<a<<" b="<<b<<" p="<<p2<<endl;
						index=((x*a+b)%p2)%n_i;
					//	cout<<"n_i="<<n_i<<" index= "<<index<<endl;
						if(prime[i].arr[index+2]==0)
						{
							prime[i].arr[index+2]=x;
							//cout<<prime[i].arr[index+2]<<endl;
						}
						else
						{
							if(prime[i].arr[index+2]!=x)
							{
							collide=1;
							}
							break;
						}
					}
						char s;
				//cin>>s;
			//	cout<<"collide="<<collide<<endl;	
				}while(collide==1);
			//	cout<<"i="<<i<<" a="<<prime[i].arr[0]<<" b="<<prime[i].arr[1]<<endl;
				node_ptr=prime[i].head;
				struct node* node_ptr2;
				node_ptr2=node_ptr->next;
				while(node_ptr!=NULL)
				{
					free(node_ptr);
					node_ptr=node_ptr2;
					if(node_ptr!=NULL)
					node_ptr2=node_ptr->next;
				}
			}
		}
	/*	for(int i=0;i<20;i++)
		{
			int n_i;
			//cout<<"i="<<i<<": "<<endl;
			n_i=(prime[i].n)*(prime[i].n);
			if(n_i>0)
			{
				n_i=n_i+2;
				//cout<<"n_i="<<n_i<<endl;
				for(int j=0;j<n_i;j++)
				{
					cout<<prime[i].arr[j]<<" ";
				}
				
			}
			cout<<endl;
		}
	*/	
	}
	
	
	
