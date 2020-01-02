#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct queue{
    double arr[SIZE];
    int front;
    int rear;
};

bool isEmpty(queue *q) {
    if(q->front == q->rear)
        return true;
    else
        return false;
}

void push(queue *q, double x) {

    // dolu olup olmadığına bakarız
	if (((q->rear) + 1)%SIZE == q->front)	// Son hucreye eleman eklenmemeli!
	{
		printf("Kuyruk DOLU! %.1f elemani eklenemedi! \n",x);
	}
	else
	{
		q->rear = (q->rear + 1)%SIZE;	// Cevrimsel kuyruk : modüler artim
		q->arr[q->rear] = x;
		//printf("%.1f elemani kuyruga eklendi! \n",x);
	}
}

double pop(queue *q) {
	if (!isEmpty(q))
	{
		q->front = (q->front + 1)%SIZE;	 // Çevrimsel kuyruk : modüler artim
		double d = q->arr[q->front];

		return d;
	}
	else
	{
		printf("Kuyruk BOS! remove islemi yapilamadi! \n");
        return -1;
	}

}

void printQueue3(struct queue q)
{
	while (!isEmpty(&q))
	{
		printf("%.1f  ", pop(&q));
	}
}

double findBiggest(struct queue q, int *yer) {
    if(!isEmpty(&q)) {
        double max = pop(&q);
        *yer = 1;
        int i = 1;
        while(!isEmpty(&q)) {
            double d = pop(&q);
            i++;
            if(d > max){
                max = d;
                *yer = i; 
            }
        }
        return max;
    }
    else{
        printf("Liste boş\n");
        return -1;
    }
}




int main() {

    queue q1;
    q1.rear = SIZE - 1;
    q1.front = SIZE - 1;

    push(&q1, 5.0);
    push(&q1, 8.2);
    push(&q1, 3.6);
    push(&q1, 92.1);

    int yer;
    double max = findBiggest(q1, &yer);
    printf("Max deger: %.2f, yeri: %d\n",max,yer);

}