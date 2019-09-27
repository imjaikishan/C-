#include<iostream>
using namespace std;
#define MAX_SIZE 100

class queue
{
	private:
		char a[MAX_SIZE];
		int front,rear;
	public:
		queue()
		{
			front=-1;
			rear=-1;
		}
	bool IsEmpty()
	{
		return(front==-1 && rear==-1); 
	}
	
	bool IsFull()
	{
		return(rear+1)%MAX_SIZE==front?true:false;
	}
	
	void Enqueue(char x)
	{
		cout<<"Enqueuing.. :"<<x<<"\n";
		if(IsFull())
		{
			cout<<"Error: Queue is Full ";
			return;
		}
		else if((rear+1)%MAX_SIZE==front)
		{
			return;
		}
		else if(IsEmpty())
		{
			front=rear=0;
		}
		else
		{
			rear=(rear+1)%MAX_SIZE;
		}
		a[rear]=x;
	}
	
	void Dequeue()
	{
		cout<<"Dequeuing \n";
		if(IsEmpty())
		{
			cout<<"Error:Queue is Empty\n";
			return;
		}
		else if(front==rear)
		{
			rear=front=-1;
		}
		else
		{
			front=(front+1)%MAX_SIZE;		
		}
			
	}
	
	int Front()
	{
		if(front==-1)
		{
			cout<<"Error: Queue is empty!!!!!!!!!\n";
			return -1;
		}
		return a[front];
	}
	
	void Print()
	{
		int count=(rear+MAX_SIZE-front)%MAX_SIZE +1;
		cout<<"Queue  :";
		for(int i=0;i<count;i++)
		{
			int index=(front+i)%MAX_SIZE;
			cout<<a[index]<<" ";
		}
		cout<<"\n\n";
	}
};

int main()
{
	int c;
	queue Q;
	start:
	cout<<"Menu\nenter your choice:\n1.)Enter into queue\n2.)Delete from queue\n3.)Exit\n";
	cin>>c;
	
	switch(c)
	{
		case 1: char b;
				cout<<"enter the enter the character:";
				cin>>b;
				Q.Enqueue(b);
				Q.Print();
				break;
		
		case 2: 
				Q.Dequeue();
				Q.Print();
				break;
		
		default: cout<<"exit..";
		 
    }
    if(c!=3)
	goto start;
	return 0;
	
	
}
