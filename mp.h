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



typedef struct goods {
	char itemcode[50];
	char itemname[50];
	int rate;
}goods;



typedef struct goods2 {
	char itemcode[50];
	char itemname[50];
	int rate;
	int quantity;
	int cost;
}goods2;



int ManagerMenu();
void CashierMenu();
void GoodsEntry();
void GoodsListDisplay();
void EditGoods();
void DeleteGoods();
void Billing();
void TotalSalesDisplay();

