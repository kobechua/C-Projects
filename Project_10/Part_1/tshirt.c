/*
Hanz Chua
U26738740
Source file for all tshirt functions
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tshirt.h"             //includes tshirt and readline header
#include "readline.h"

#define ORG_NAME_LEN 50
#define SIZE_LEN 3

void help() {                                                   //help function prints all menu options
	printf("List of operation codes:\n");
	printf("\t'a' for adding a t-shirt to the inventory;\n");
	printf("\t'h' for help;\n");
	printf("\t'o' for searching t-shirts by organization;\n");
	printf("\t's' for searching t-shirts by size;\n");
	printf("\t'p' for printing the inventory;\n");
	printf("\t'q' for quit.\n");
}

struct tshirt * add_to_inventory(struct tshirt *inventory) {
	struct tshirt *p;
	struct tshirt *new_node; 					//initializes structs

	struct tshirt *cur;
	struct tshirt *prev;

	new_node = malloc(sizeof(struct tshirt));

	printf("Enter organization name: ");		// takes input for new shirts org name and size
	read_line(new_node->org_name, 51);

	printf("Enter size: ");
	read_line(new_node->size, 4);


	for (p = inventory;p != NULL;p = p->next){
		if (strcmp(p->org_name, new_node->org_name)==0 && strcmp(p->size, new_node->size)==0){		//checks if the shirts exist
			printf("T-Shirt already exists.");
			return inventory;
		}
	}

	printf("Enter price: ");				//gets the price and quantity of the new shirt
	scanf("%lf", &new_node->price);

	printf("Enter quantity: ");
	scanf("%d", &new_node->quantity);

	for (cur = inventory, prev = NULL;
	 cur != NULL && strcmp(cur->org_name,new_node->org_name) < 0;			//for loop finds larger valued letter and returns current and previous pointer
	  prev = cur, cur = cur->next);

	if (cur != NULL && strcmp(new_node->org_name, cur->org_name) == 0){
		for (cur = inventory, prev = NULL;
		 cur != NULL && (strcmp(cur->size,new_node->size) < 0 || strcmp(new_node->org_name, cur->org_name) != 0);		//for loop finds matching value letters and finds larger valued letter of size
		  prev = cur, cur = cur->next);
	}

	new_node->next = cur;
  	if (prev == NULL)			//adds element based on prev and current value
    	return new_node;
  	else{
    	prev->next = new_node;
    	return inventory;
  	}
	return inventory;
}

void search_by_organization(struct tshirt *inventory) {
	struct tshirt *p;
	char name[51];
	int flag = 0;

	printf("Enter organization name: ");					//takes input of org name and checks for it
	read_line(name,51);

	for (p = inventory; p != NULL; p = p->next){
		if (strcmp(p->org_name, name)==0){
			flag = 1;
		}

	}

	if (flag == 0){											//if no org name matches it prints so, else prints all matching org names
		printf("No organization name found.\n");
	}

	else{

		printf("|----------------------------------------------------|-----|-------|------|\n");
		printf("| Student organization                               | Sz. | Price | Qty. |\n");
		printf("|----------------------------------------------------|-----|-------|------|\n");

		for (p = inventory; p != NULL; p = p->next){
			if (strcmp(p->org_name, name)==0){
				printf("| %-50s | %-3s | %5.2f | %4d |\n", p->org_name, p->size, p->price, p->quantity);
			}
		}
		printf("|----------------------------------------------------|-----|-------|------|\n");
		
	}
}



void search_by_size(struct tshirt *inventory) {
	struct tshirt *p;
	char size[4];
	int flag = 0;

	printf("Enter size: ");								//asks for size
	read_line(size,4);

	for (p = inventory; p != NULL; p = p->next){		//checks for size in inventory
		if (strcmp(p->size, size) == 0){
			flag = 1;
			break;
		}
	}

	if (flag == 0){										//if none it prints so, else it prints all shirts with size
		printf("No size found.\n");
	}

	else{

		printf("|----------------------------------------------------|-----|-------|------|\n");
		printf("| Student organization                               | Sz. | Price | Qty. |\n");
		printf("|----------------------------------------------------|-----|-------|------|\n");

		for (p = inventory; p != NULL; p = p->next){
			if (strcmp(p->size, size)==0){
				printf("| %-50s | %-3s | %5.2f | %4d |\n", p->org_name, p->size, p->price, p->quantity);
			}
		}
		printf("|----------------------------------------------------|-----|-------|------|\n");
		
	}
}

void print_inventory(struct tshirt *inventory) {

	struct tshirt *p;

	char student_organization[51];				
	char size[4];
	double price = 0;
	int quantity = 0;
	
	if(inventory != NULL){					//checks if inventory is empty, else prints all shirts

		printf("|----------------------------------------------------|-----|-------|------|\n");
		printf("| Student organization                               | Sz. | Price | Qty. |\n");
		printf("|----------------------------------------------------|-----|-------|------|\n");
		for(p=inventory;p != NULL; p = p->next){
			strcpy(student_organization,p->org_name);
			strcpy(size, p->size);
			price = p->price;
			quantity = p->quantity;
			printf("| %-50s | %-3s | %5.2f | %4d |\n", student_organization, size, price, quantity);
		}
		printf("|----------------------------------------------------|-----|-------|------|\n");
	}
	else{
		printf("No t-shirt found!\n");
	}
}

void clear_inventory(struct tshirt *inventory) {	//clears inventory

	struct tshirt *p;	
    while (inventory != NULL)
    {
        p = inventory;
        inventory = inventory->next;
        if (p != NULL)
            free(p);
    }

}