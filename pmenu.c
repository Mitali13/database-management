#include "pmenu.h"
void ManagerMenu() {
	char choice4;
	long int i,j;
	printf ("\nLoading");
	for (i=0;i<3;i++) {
		for (j=0;j<=200000000;j++);
			printf (".");
	}
	printf ("\nEnter (A) to add to good list.");
	printf ("\nEnter (E) to edit the good list.");
	printf ("\nEnter (D) to display list of goods.");
	printf ("\nEnter (S) to view the total sales.");
	printf ("\nPress (space bar) to delete to good list.");
	printf ("\nEnter (R) to return to MainMenu:\n");
	la2:
	choice4=getc();
	switch (choice4) {
	case 65:
	case 97:GoodsEntry();
		break;
	case 69:
	case 101:EditGoods();
		break;
	case 68:
	case 100:GoodsListDisplay();
		break;
	case 32:DeleteGoods();
		break;
	case 115:
	case 83:TotalSalesDisplay();
		break;
	case 82:
	case 114:mainmenu();
		break;
	default:printf("\nInvalid Selection!\nEnter again:\n");
	goto la2;
	}
}
