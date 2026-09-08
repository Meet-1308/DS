#include<stdio.h>
# define size 3
int Q[size];
int f=-1;
int r=-1;
void enq(int y){
	if(r==size-1){
		printf("queue overflow");
		return;
	}
	r++;
	Q[r]=y;
	if(f==-1)
	{
		f=0;
	}
}

int deq()
{
	if(f==-1)
	{
		printf("underflow");
	}
	else{
		int y=Q[f];
		if(f==r)
		{
			f=r=-1;
			return y;
		}
		else{
			f++;
			return y;
		}
	}
}

void display()
{
	if (f == -1) {
        printf("Queue is empty\n");
        return;
    }
    int i;
    for (i = f; i <= r; i++) {
        printf("%d ", Q[i]);
    }
    printf("\n");
}

void main()
{
	int choice, value;

    while (1) {
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue\n: ");
                scanf("%d", &value);
                enq(value);
                break;
            case 2:
                deq();
                if (value != -1) {
                    printf("Dequeued value: %d\n", value);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
