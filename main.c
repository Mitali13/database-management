/*  <DEPARTMENTAL STORE MANAGEMENT - The program keeps record of all items in the store, it basically shows the working of shops>
    Copyright (C) <2015>  <Mitali Gajbhiye>
    
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>. 

*/

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
	printf ("\nPress 5 to delete an item in the list.");
	printf ("\nEnter 6 for Billing.");
	printf ("\nEnter 7 to EXIT\n");
	scanf("%d", &choice4);

	return choice4;

}



int main() {
	int choice4;
	long int i, j;
	printf("\n\n\n");
	printf ("\t\t\t***WELCOME TO DEPARTMENTAL STORE MANAGEMENT SYSTEM***");
	printf("\n\n\n");
	
	while(1) {
		choice4 = ManagerMenu();
	
		switch (choice4) {
	
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



