#include "p3.h"

void GoodsListDisplay() {
	
	FILE *f;
	goods a;
	int i,j;
	printf ("\nLoading");
	for (i=0;i<4;i++) {
		for (j=0;j<=100000000;j++) 
			printf (".");
		}
		printf ("\b\b\b \b\b\b");
	for (i=0;i<3;i++) {
		for (j=0;j<=100000000;j++);
			printf (".");
			}
		printf ("\b\b\b");
 
	if ((f=fopen("goods.txt","rb"))!=NULL) {
		printf ("\nItem codeItem name Cost(Rs.)\n");
		printf ("-------------------------------------------------------\n");
		do {
			printf("%s",a.itemcode);
			printf("\t\t");
			printf("%s",a.itemname);
				if ((strlen(a.itemname)>0)&& (strlen(a.itemname)<=7))
					printf("\t\t");
				if ((strlen(a.itemname)>7)&& (strlen(a.itemname)<13))
					printf ("\t ");
				if ((strlen(a.itemname)>=13) && (strlen(a.itemname)<16))
					printf ("\t");
				printf ("\t\t%d\n",a.rate);
				}
		while (fread(&a,sizeof(a),1,f)==1);
		fclose(f);
		getc();
	}
	ManagerMenu();
}
