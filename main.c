#include <stdio.h>
#include <stdlib.h>
#include "mp.h"


int ManagerMenu() {
	int choice4;	
	long int i, j;
	printf ("\nEnter 1 to add to good list.");
	printf ("\nEnter 2 to edit the good list.");
	printf ("\nEnter 3 to display list of goods.");
	printf ("\nEnter 4 to view the total sales.");
	printf ("\nPress 5 to delete to good list.");
	printf ("\nEnter 6 for Billing.");
	printf ("\nEnter 7 to EXIT\n");
	scanf("%d", &choice4);
	return choice4;
}



int main() {
	int choice4;
	long int i, j;
	printf ("\t\t\tWELCOME TO DEPARTMENTAL STORE MANAGEMENT SYSTEM\n\n");
	printf ("\nLoading");
	while(1) {
		choice4 = ManagerMenu();
		switch (choice4){
			case 1:GoodsEntry();
				break;
			case 2:EditGoods();
				break;
			case 3:GoodsListDisplay();
				break;
			case 4:TotalSalesDisplay();
				break;	
			case 5:DeleteGoods();
				break;
			case 6:Billing();
				break;
			case 7:exit(1);
				break;
			default:printf("\nInvalid Selection!\nEnter again:\n");
		}
	}
	return 0;
}

