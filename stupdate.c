#include <stdio.h>
#include "student.h"
/* ���Ͽ� ����� �л� ������ �����Ѵ�. */
int main(int argc, char *argv[])
{
   struct student rec;
   int id;
   char c;
   FILE *fp;
   if (argc != 2) {
      fprintf(stderr, "����: %s �����̸�\n", argv[0]);
      exit(1);
   }

   if ((fp = fopen(argv[1], "rb+")) == NULL) {
      fprintf(stderr, "���� ���� ����\n");
      exit(2);
   }
   do {
   printf("������ �л��� �й� �Է�: ");
   if (scanf("%d", &id) == 1) {
      fseek(fp, (id - START_ID) * sizeof(rec), SEEK_SET);
      if ((fread(&rec, sizeof(rec), 1, fp) > 0)&&(rec.id != 0)) {
         printf("�й�: %8d �̸�: %4s ����: %4d\n", rec.id, rec.name, rec.score);
         printf("���ο� ���� �Է�: ");
         scanf("%d", &rec.score);
         fseek(fp, -sizeof(rec), SEEK_CUR);
         fwrite(&rec, sizeof(rec), 1, fp);
      } else printf("���ڵ� %d ����\n", id);
   } else printf("�Է¿���\n");

   printf("����ϰڽ��ϱ�?(Y/N)");
   scanf(" %c",&c);
} while (c == 'Y');
fclose(fp);
exit(0);
}

