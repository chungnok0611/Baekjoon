#include<stdio.h>
#define max 5
struct Queue {
	int data[max];
	int front, rear;
};
void init_queue(struct Queue* q) {
	q->front = 0;
	q->rear = 0;
}
int is_empty(struct Queue* q) {
	return q->front == q->rear;
}

int is_full(struct Queue* q) {
	return q->front == (q->rear + 1) % max;
}

void print_queue(struct Queue* q) {
	int i = q->front;//초기화 값은 뭐로 해야할까요?
		if (!is_empty(q)) {
			while (i != q->rear) { //괄호에 들어갈 조건은?
				i = (i + 1) % max;
				printf("%d | ", q->data[i]);
			}
		}
	printf("\n");
}

void enqueue(struct Queue* q, int item) {
	if (is_full(q)) printf("포화상태\n");
	else {
		q->rear = (q->rear + 1) % max;
		q->data[q->rear] = item;
	}
}

int dequeue(struct Queue* q) {
	if (is_empty(q)) {
		printf("공백상태\n");
		return 0;
	}
	else {
		q->front = (q->front + 1) % max;
		return q->data[q->front];
	}
}

int main() {
	struct Queue q;
	init_queue(&q);
	enqueue(&q, 80);	print_queue(&q);
	enqueue(&q, 50);	print_queue(&q);
	enqueue(&q, 20);	print_queue(&q);
	dequeue(&q);		print_queue(&q);
	enqueue(&q, 90);	print_queue(&q);
	dequeue(&q);		print_queue(&q);
	enqueue(&q, 15);	print_queue(&q);
	return 0;
}