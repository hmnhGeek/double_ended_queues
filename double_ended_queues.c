#include<stdio.h>
#define size 5

// Defining a data structure for implementing doubly ended queues. //
typedef struct{
	int element[size];
	int front;
	int rear;
}dqueue;

// Initialising an object instance of the dqueue structure. //
dqueue q;

// Defining init() function to initialise the doubly ended queue. //
dqueue init(){
	q.front = -1;
	q.rear = -1;
	return q;
} // End of init() function. //

void insert( int item ){
	/* The very first step must be to check overflow condition. */
	
	if( ( q.front == q.rear + 1 ) || ( q.front == 0 && q.rear == size - 1 ) ){
		/* if front is 0 and rear is size -1 or front is rear +1,
		that implies that the queue is full and nothing can be added
		in it. It is because in first case rear is at end anf front is
		at initial position. In second case, however, rear is just behind
		front and elements in doubly ended queues can only be insert in 
		between front and rear, and in this case it is not possible. */
		printf("Cannot insert the element, queue is empty.\n");
	}
	else{
		if( q.front == -1 ){
			/* This means that queue is empty and so along with inserting
			the element we must also do front = 0 and rear = 0. */
			q.front = 0;
			q.rear = 0;
		}
		else if( q.rear == size - 1 ){
			/* Now if rear is at end, then new element can only be inserted
			from front end of the queue, so, set rear as 0. */
			q.rear = 0;
			printf("Rear is back at 0.\n");
		}
		else{
			/* In all other cases, just do rear ---> rear + 1. */
			q.rear += 1;
		}
		q.element[q.rear] = item;
		printf("Element inserted!!\n");
	}
} // End of insert() function. //

void delete(){
	/* The very first step must be to check the underflow condition. */
	
	if( q.front == -1 ){
		/* This implies that queue is empty and hence, no item to delete. */
		printf("Cannot delete since queue is empty.\n");
	}
	else{	
		/* The item should be reported. */
		int item = q.element[q.front];
		if( q.front == q.rear ){
			/* Since front is equal to rear, this means we have only
			one element in the queue and for deleis element,
			we should update front and rear both to the initial position 
			then only this thing thand then only it can be called circular
			queue. :D */
			q.front = -1;
			q.rear = -1;
		}
		else if( q.front == size - 1 ){
			/* Now here front is at end of the queue, and to delete the element
			at last position we have to update front to front = 0. */
			q.front = 0;
		}
		else{
			/* Ignore the element and update the value of front. */
			q.front += 1;
		}
		printf("The front item %d is popped out.\n", item);
	}
} // End of delete() function. //

void display(){
	// First check underflow condition, else it will print garbage value//
	// at q.element[-1 = front for empty queue]//
	
	if(q.front == -1){
		printf("Empty queue.\n");
	}
	else{
		// if front is less than rear then simply traverse the queue from front to end. //
	
		if ( q.front <= q.rear ){
			// Now traverse the queue. //
			int i = q.front;
		
			for( i; i<q.rear+1; i+=1 ){
				printf("%d\n", q.element[i]);
			}
		}
		else{
			// since front is after rear, we shall first print front to end. //
			// Then we will print from 0 to rear. //
			int i, j;
			
			for(i = 0, j = q.front; i <= q.rear && j <= size-1; i++, j++){
				printf("%d\n", q.element[i]);
				printf("%d\n", q.element[j]);
			}
		}
		printf("Done!!\n");
	}
} // End of display() function. //

void main(){
	// First make a call to init() so that it can initialise the circular queue. //
	init();
	// Initialising a variable ch = 1 for menu driven program. //
	
	int ch = 1;
	
	while( ch == 1 ){
		printf("1. Insert.\n");
		printf("2. Delete.\n");
		printf("3. Display.\n");
		printf("4. Exit.\n");
		// Initialising a choice variable x. /
		
		int x;
		printf("Enter choice: ");
		scanf("%d", &x);
		
		if( x == 1 ){
			// Ask user to enter an element. //
			int elem;
			printf("Enter the element: ");
			scanf("%d", &elem);
			// Now make a call to insert(). //
			insert( elem );
		}
		else if( x == 2 ){
			// Make a call to delete(). //
			delete();
		}
		else if( x == 3 ){
			// Make a call to display(). //
			display();
		}
		else if( x == 4 ){
			// Make ch = 0 to halt the while loop. //
			ch = 0;
		}
		else{
			printf("Invalid choice!!\n");
		}
	}
} // End of main() function. //
