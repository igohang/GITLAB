#include <stdio.h>
#define MaxItems 20
#define MaximumProducts 40
int main()
{
int ItemCodeList[MaximumProducts];
float ItemPriceList[MaximumProducts];
char ItemNameList[MaximumProducts][40];
int ListSize, FoundIndex, j, ItemCode[MaxItems], done;
char ItemName[MaxItems][40], CustomerName[40], TodayDate[20];
int i, NumberOfItems, Quantity[MaxItems], InvoiceNumber;
float UnitPrice[MaxItems], ItemValue[MaxItems], InvoiceValue, InvoiceTax, InvoiceTotalAmount;
float DailyValue, DailyTax, DailyTotalAmount;
/*Create Code Price List*/
ItemCodeList[0] = 100; ItemPriceList[0] = 15.0; strcpy(ItemNameList[0], "Pepsi Can");
ItemCodeList[1] = 101; ItemPriceList[1] = 25.0; strcpy(ItemNameList[1], "Reynold Pencil");
ItemCodeList[2] = 102; ItemPriceList[2] = 40.0; strcpy(ItemNameList[2], "Bic Pen");
ItemCodeList[3] = 103; ItemPriceList[3] = 20; strcpy(ItemNameList[3], "Kit Kat");
ItemCodeList[4] = 104; ItemPriceList[4] = 14; strcpy(ItemNameList[4], "Slurpy");
ItemCodeList[5] = 105; ItemPriceList[5] = 12; strcpy(ItemNameList[5], "Lux Beauty Soap");
ItemCodeList[6] = 106; ItemPriceList[6] = 60; strcpy(ItemNameList[6], "Clairol Shampoo");
ListSize = 7;
DailyValue = DailyTax = DailyTotalAmount = 0.0;
printf("Enter Today's Date: "); scanf("%s", TodayDate);
printf("\nEnter Invoice Number (0 to QUIT): "); scanf("%d", &InvoiceNumber);
while (InvoiceNumber > 0)
{
InvoiceValue = InvoiceTax = InvoiceTotalAmount = 0.0 ;
printf("Enter Customer Name: ");
scanf("%s", CustomerName);
i=0;
NumberOfItems=0;
do
    {
    FoundIndex=-1;
    printf("Enter Item Code and Quantity (0 0 to end list)# %d ",i+1);
    scanf("%d %d",&ItemCode[i],&Quantity[i]);
    if(ItemCode[i]!=0 && Quantity[i]!=0)
        {
            for(j=0;j<ListSize && FoundIndex==-1;j++)
            {
                if(ItemCode[i]==ItemCodeList[j])
                        {
                        FoundIndex=j;
                        strcpy(ItemName[i],ItemNameList[FoundIndex]);
                        UnitPrice[i]=ItemPriceList[FoundIndex];
                        ItemValue[i]=Quantity[i]*UnitPrice[i];
                        NumberOfItems++;
                        DailyValue+=ItemValue[i];
                        InvoiceValue+=ItemValue[i];
                        i++;
                        }
            }
            if(FoundIndex==-1)
                {
                printf("Invalid Item Code. Please type again. \n");
                }
        }
    }
while(ItemCode[i]!=0 || Quantity[i]!=0);
InvoiceTax=(InvoiceValue*7)/100;
InvoiceTotalAmount=InvoiceValue+InvoiceTax;

DailyTax=(DailyValue*7)/100;
DailyTotalAmount=DailyValue+DailyTax;

/*Print Invoice Part*/
printf("\n___________________________________________________________________________\n");
printf("---------------------------------------------------------------------------\n");
printf("Invoice No.: %5d Dated: %s\n", InvoiceNumber, TodayDate);
printf("Customer: %-30s\n\n", CustomerName);
printf(" # |Code| Item Name           | Unit Price   | Quantity   | Total Price\n");
printf("___________________________________________________________________________\n");
for(i=0; i<NumberOfItems; i++)
printf("%2d |%4d| %-20s| %12.2f | %10d | %12.2f \n", i+1, ItemCode[i],ItemName[i], UnitPrice[i], Quantity[i], ItemValue[i]);
printf("___________________________________________________________________________\n");
printf("                                Invoice Total:            %10.2f\n", InvoiceValue);
printf("                                Invoice Tax:              %10.2f\n", InvoiceTax);
printf("                                Invoice Total Amount Due: %10.2f\n", InvoiceTotalAmount);
printf("___________________________________________________________________________\n");
printf("---------------------------------------------------------------------------\n");
printf("\n\nEnter Invoice Number (0 to QUIT): "); scanf("%d", &InvoiceNumber);
}
printf("\n\nCash Register Summary for Date: %s\n", TodayDate);
printf(" Daily Total:               %10.2f\n", DailyValue);
printf(" Daily Tax:                 %10.2f\n", DailyTax);
printf(" Daily Total Amount Due:    %10.2f\n", DailyTotalAmount);
scanf("%d", &InvoiceNumber);
}
