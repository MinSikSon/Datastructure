// '['�� '*'�� ������ ���ؼ� ���ڿ��� �Է¹޴´�
// [?,?] �ټ����� ���ڿ��� ������ ��, ������ �͸� ���͸� �Ͽ�
// �񱳸� ���� �迭�� �����Ѵ�.
// ���� ���� �� �ٷ� ���� ������ ���ؼ� �������ش�.
// ���������� ������ ���ش�.

#include<stdio.h>
#define DOUBLE_MAX 100
#define MAX 10
#define FIVE 5
#define TWO 2
typedef struct{
	int poly[MAX][TWO];
}polynomial;



int main()
{
	FILE* input = fopen("hw2.inp", "r");
	FILE* output = fopen("hw2.out", "w");

	int i;

	int input_buf[TWO];
	char trash;
	int poly_buf[DOUBLE_MAX][TWO];
	int poly1[MAX][TWO];
	int poly2[MAX][TWO];
	int count =0;

	do{
		for(i=0; i<10; i++)
		{
			fscanf(input, "%c", &trash);
			if(trash == '*')
				break;

			fscanf(input, "%d%c%d%c%c", &input_buf[0], &trash, &input_buf[1], &trash, &trash);
			printf("%d %d\n", input_buf[0], input_buf[1]);
		}
		printf("\n");
		count++;
	}while(count != 2);





	fclose(input);
	fclose(output);
	return 0;
}