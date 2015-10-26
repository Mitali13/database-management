

typedef struct goods {
	char itemcode[50];
	char itemname[50];
	int rate;
}goods;



typedef struct authorize {
	char admin_name[50];
	char admin_password[50];
	char user_name[50];
	char user_password[50];
}authorize;



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

