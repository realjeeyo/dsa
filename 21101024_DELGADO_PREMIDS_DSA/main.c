#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Data.h"
#include "Stack.h"

bool addProductBaseOnExpiry(Inventory *i, Product p) {
    if(i->currQty + p.prodQty <= 100){
        NodePtr newItem = malloc(sizeof(NodeType));
        Inventory tempInv;
        initInventory(&tempInv);
        
        if (newItem != NULL){
            newItem->prod = p;
            
            if(isEmpty(*i)){
                newItem->link = NULL;
                i->top = newItem;
                i->currQty += p.prodQty;
                return true;
            } else {
                
                while(!isEmpty(*i) && dateDifference(i->top->prod.expiry, p.expiry) >= 0){
                    NodePtr temp = i->top;
                    i->top = temp->link;
                    temp->link = tempInv.top;
                    tempInv.top = temp;
                }
                newItem->link = i->top;
                i->top = newItem;
                
                while(!isEmpty(tempInv)){
                    NodePtr temp = tempInv.top;
                    tempInv.top = temp->link;
                    temp->link = i->top;
                    i->top = temp;
                }
                i->currQty += p.prodQty;
                return true;
            }
        }
    }
    return false;
}

int main() {
    ProductList myProd;
    int numCount, selection;

    printf("Enter sequence or selection: (1-6): ");
    scanf("%d", &selection);
    printf("Enter the number of data: ");
    scanf("%d", &numCount);

    createAndPopulate(&myProd, selection, numCount);

    Inventory myInventory;
    initInventory(&myInventory);

    printf("\nORIGINAL PRODUCT:\n");
    for(int i = 0; i < myProd.count; ++i) {
        displayProduct(myProd.prods[i]);
        printf("\n");
    }

    for(int i = 0; i < myProd.count; ++i) {
        printf("\n[%d.] Adding %s (%d): %s\n", i+1, myProd.prods[i].prodName, myProd.prods[i].prodQty, addProductBaseOnExpiry(&myInventory, myProd.prods[i])? "Success":"Fail");
        visualize(myInventory);
    }

    printf("\nUSING ADD PRODUCT:\n");
    visualize(myInventory);


    return 0;
}