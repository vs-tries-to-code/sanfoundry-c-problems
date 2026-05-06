//This C Program display the inventory of items in a store
#include <stdio.h>
struct Date{
    int dd;
    int mm;
    int yyyy;
};

struct Item{
    char item_name[30];
    int item_code;
    float price;
    int qty;
    struct Date mfg;

};

int main(){
    int n;
    printf("Enter number of items:");
    scanf("%d", &n);
    struct Item items[10];
    for (int i=0; i<n; i++){
        printf("Enter item name:\n");
        scanf("%s", items[i].item_name);
        printf("Enter item code\n");
        scanf("%d", &items[i].item_code);
        printf("Enter price:\n");
        scanf("%f", &items[i].price);
        printf("Enter quantity:\n");
        scanf("%d", &items[i].qty);
        printf("Enter date of manufacturing (dd-mm-yyyy):\n");
        scanf("%d-%d-%d", &items[i].mfg.dd, &items[i].mfg.mm, &items[i].mfg.yyyy);
    }
    printf("S.NO\t|NAME\t|ITEM CODE\t|QUANTITY\t|PRICE\t|D.O.M\n");
    for (int i=0; i<n; i++){
        printf("%d\t%s\t%d\t%d\t%f\t%d-%d-%d\n",i+1, items[i].item_name, items[i].item_code, items[i].qty, items[i].qty * items[i].price, items[i].mfg.dd, items[i].mfg.mm, items[i].mfg.yyyy);
        printf("\n");

    }

    return 0;
    
}