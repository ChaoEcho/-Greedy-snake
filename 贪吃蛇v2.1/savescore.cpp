#include "head.h"
#include <stdio.h>
#include <graphics.h>


void savescore()
{
	Mark *head_1 = head;

	FILE *fp = fopen("Ӣ�۰�.txt", "a+");

	if (fp == NULL)
		printf("���ִ����ļ���ʧ��");

	//����˽����ݴ��ļ����뵽����
	while (!feof(fp))
	{
		Mark *tem = (Mark *)malloc(sizeof(Mark));
		tem->next = NULL;

		fscanf(fp, "%10s %d", &tem->name, &tem->score);
		tem->next = NULL;

		if (head == NULL)
		{
			head_1 = tem;
			head = head_1;
		}
		else
		{
			head_1->next = tem;
			head_1 = head_1->next;
		}
	}
	
	//ָ����ͷָ��
	head_1 = head;

	int num_1 = 0, num_2 = 0;
	while (head_1->next!=NULL)
	{
		num_1++;
		int num=strcmp(first, head_1->name);
		if (num == 0)
		{
			if(head_1->score<score)
			head_1->score = score;
		}
		else num_2++;

		head_1 = head_1->next;
	}

	if (num_1 == num_2)
	{
		fprintf(fp, "%-10s %d\n", first, score);
	}
	else
	{
		fclose(fp);

		fp = fopen("Ӣ�۰�.txt", "w+");

		head_1 = head;
		while (head_1->next != NULL)
		{
			fprintf(fp, "%-10s %d\n", head_1->name, head_1->score);
			head_1 = head_1->next;
		}
	}
	fclose(fp);
}




//void savescore()
//{
//	FILE *fp = fopen("Ӣ�۰�.txt", "a+");
//	
//	fprintf(fp, "%-10s %d\n", first, score);
//
//	fclose(fp);
//}