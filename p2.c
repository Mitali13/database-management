#include "p2.h"
void GoodsEntry() {

	FILE *f;
	goods a;
	char ques;
	if ((f = fopen("goods.txt","ab+"))==NULL) {
		if ((f=fopen("goods.txt","wb+"))==NULL) {
			printf ("\nCannot open the file\n");
			getc(f);
		}
	}
	while(1) {
		printf ("\nEnter the item code to be added:");
		gets (a.itemcode);
		printf ("\nEnter the item name:");
		gets (a.itemname);
		printf ("\nEnter the rate for unit quantity:");
		scanf ("%d",&a.rate);
		fwrite(&a,sizeof(a),1,f);
		fflush(stdin);
		printf ("\nEnter the 'esc' key to exit or any other key to continue:");
		ques=getc(f);
		if(ques== 27)
			break;
		}
	fclose(f);
	ManagerMenu();
}
		
