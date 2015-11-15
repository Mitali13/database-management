/*  <DEPARTMENTAL STORE MANAGEMENT - The program keeps record of all items in the store/shops>
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
#include <string.h>
#include <stdlib.h>
#include "mp.h"


char CashierName[50];
int grandtotal = 0;
char choice1, choice2;


void CashierMenu() {

long int i, j;
char ch;
printf ("\nBilling is ready!");

}



void GoodsEntry() {

	FILE *f;
	goods a;
	char ques;
	
	if ((f = fopen("goods.txt","a+")) == NULL) {
		if ((f = fopen("goods.txt", "wb+")) == NULL) {
			printf ("\nCannot open the file\n");
			getc(f);
		}
	}
	
	while(f) {
		
		printf ("\nEnter the item code to be added:");
		scanf ("%s",a.itemcode);
		printf("\nEnter the item name to be added:");
		scanf ("%s",a.itemname);
		printf ("\nEnter the rate for unit quantity:");
		scanf ("%d",&a.rate);
		fwrite(&a,sizeof(a),1,f);
		fflush(stdin);
		break;
		}
	
	fclose(f);
	
	}



void GoodsListDisplay() {

	FILE *f;
	int i, j;
	goods a;

	printf ("\b\b\b \b\b\b");
	
	if ((f = fopen("goods.txt","r")) != NULL) {
		printf ("\nItem code\tItem name\t\tCost(Rs.)\n");
		printf ("-------------------------------------------------------\n");
	
		do{
			printf("%s", a.itemcode);
			printf("\t\t");
			printf("%s", a.itemname);
	
			if ((strlen(a.itemname)>0)&& (strlen(a.itemname)<=7))
				printf("\t\t");
	
			if ((strlen(a.itemname)>7)&& (strlen(a.itemname)<13))
				printf ("\t ");
	
			if ((strlen(a.itemname)>=13) && (strlen(a.itemname)<16))
				printf ("\t");
			printf ("\t\t%d\n", a.rate);
		}
	
		while (fread(&a,sizeof(a),1,f) == 1);
			getchar();
	}
	fflush(stdin);
	fclose(f);

}



void EditGoods() { 

	FILE *f;
	goods a;
	char itemcode[50];
	int size=sizeof(a);
	
	if ((f = fopen("goods.txt","r+")) != NULL){
		printf ("\nEnter the item code of the product:");
		scanf("%s", itemcode);
		fflush(stdin);

		while (fread(&a,sizeof(a),1,f) == 1){

			if (strcmp(a.itemcode,itemcode) == 0){
				printf ("\nEnter the new item code:");
				scanf("%s",a.itemcode);
				printf ("\nEnter the new item name:");
				scanf("%s",a.itemname);
				printf ("\nEnter the rate for unit quantity:");
				scanf ("%d",&a.rate);
				fseek(f,-size,SEEK_CUR);
				fwrite(&a, sizeof(a), 1, f);
				printf ("Done.\n");
				getchar();
				break;
			}
		}

	fclose(f);

}

}



void DeleteGoods() { 

	FILE *f, *temp;
	goods a;
	char itemcode[50];
	
	f=fopen("goods.txt","rb");
	temp=fopen("tempgoods.txt","wb");
	
	printf ("\nEnter the item code of the product to be deleted:");
	scanf("%s", itemcode);
	
	while (fread(&a, sizeof(a), 1, f) == 1){
	
		if (strcmp(a.itemcode,itemcode) == 0)
			continue;
	
		else 
			fwrite(&a, sizeof(a), 1, temp);
		}
	rename("tempgoods.txt","goods.txt");

	fclose(f);

	fclose(temp);

	printf ("\nSuccessfully Deleted!");

}



void Billing() {

	goods2 b[50];
	goods a;
	goods2 c;
	FILE *f;
	FILE *f1;
	char itemcode[50];
	int i = 0, j, sum = 0;
	int quantity[200], cost[200], tender, change;
	
	f=fopen("goods.txt","rb+");
	f1=fopen("keeprecords.dat","ab+");
	
	do {
		printf ("\nEnter the item code:\n");
		scanf("%s",itemcode);
	
		while(fread(&a, sizeof(a), 1, f) == 1){
	
			if(strcmp(a.itemcode,itemcode) == 0){
			puts(a.itemname);
			printf ("Rs.%d\n",a.rate);
			strcpy (b[i].itemcode, a.itemcode);
			strcpy (b[i].itemname, a.itemname);
			b[i].rate = a.rate;
			printf("Enter the quantity:");
			scanf ("%d",&quantity[i]);
			cost[i] = quantity[i] * b[i].rate;
			sum = sum + cost[i];
			strcpy (c.itemcode, b[i].itemcode);
			strcpy (c.itemname, b[i].itemname);
			c.rate = b[i].rate;
			c.quantity = quantity[i];
			c.cost = cost[i];
			fwrite(&c, sizeof(c), 1, f1);
			fflush(stdin);
			i++;
			break;
			}
		}

		rewind(f);

	}

	while (strlen(itemcode) == 6);
	fclose(f);
	fclose(f1);
	printf ("\nItem code\tItem name\t\tCost\t\tQty\tAmount\n");
	printf ("---------------------------------------------------------------\n");
	
	for (j = 0; j < i; j++){
		printf("%s", b[j].itemcode);
		printf("\t\t");
		printf("%s", b[j].itemname);
	
		if ((strlen(b[j].itemname)>0)&& (strlen(b[j].itemname)<=7))
			printf("\t\t");
	
		if ((strlen(b[j].itemname)>7)&& (strlen(b[j].itemname)<13))
			printf ("\t");
	
		if ((strlen(b[j].itemname)>=13) && (strlen(b[j].itemname)<16))
			printf ("\t");
		printf ("\t%d\t\t%d\t\t%d\n",b[j].rate,quantity[j],cost[j]);
		}
	printf ("\n\t\t\tTotal:\tRs.%d", sum);
	printf ("\n\t\t\tTender:\tRs.");
	scanf ("%d",&tender);
	change = tender - sum;
	printf ("\t\t\tChange:\tRs.%d", change);
	printf ("\nCashier: ");
	//getchar();
	fflush(stdin);
	CashierMenu();
	
}


void TotalSalesDisplay() {

	FILE *f4;
	goods2 c;
	long int i = 0, j, k;
	
	if ((f4 = fopen("keeprecords.dat","r+")) != NULL){
		printf ("\nItem code\tItem name\t\tCost\tQuantity\tAmount\n");
		printf ("-------------------------------------------------------------------------\n");
	
		do{
			printf("%s", c.itemcode);
			printf("\t\t");
			printf("%s", c.itemname);
			grandtotal = grandtotal + c.cost;
	
				if ((strlen(c.itemname)>0)&& (strlen(c.itemname)<=7))
					printf("\t\t");
	
				if ((strlen(c.itemname)>7)&& (strlen(c.itemname)<13))
						printf ("\t");
	
				if ((strlen(c.itemname)>=13) && (strlen(c.itemname)<16))
					printf ("\t");
				printf ("\t%d\t %d\t\t%d\n", c.rate, c.quantity, c.cost);
			i = i + 1;
		}
	
		while (fread(&c,sizeof(c),1,f4) == 1);
			printf ("\nTotal Sales = Rs. %d.00", grandtotal);
	
	fclose(f4);
	fflush(stdin);
	//getchar();

	}

}


			
