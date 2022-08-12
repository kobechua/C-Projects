/*
Hanz Chua
U26738740
This program keeps track of shirt inventory and helps search based on organization and size.
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//////////////////////
// data definitions //
//////////////////////

#define ORG_NAME_LEN 50
#define SIZE_LEN 3

struct tshirt {
	char org_name[ORG_NAME_LEN+1];
	char size[SIZE_LEN+1];
	double price;
	int quantity;
	struct tshirt *next;
};

/////////////////////////
// function prototypes //
/////////////////////////

struct tshirt * add_to_inventory(struct tshirt *inventory);
void search_by_organization(struct tshirt *inventory);
void search_by_size(struct tshirt *inventory);
void print_inventory(struct tshirt *inventory);
void clear_inventory(struct tshirt *inventory);
int read_line(char str[], int n);
void help();

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main() {
	char code;

	struct tshirt *inventory = NULL;

	help();
	printf("\n");

	for (;;) {
		// read operation code
		printf("Enter operation code: ");
		scanf(" %c", &code);
		while(getchar() != '\n') /* skips to end of line */
			;

		// run operation
		switch (code) {
			case 'a':
				inventory = add_to_inventory(inventory);
				break;
			case 'h':
				help();
				break;
			case 'o':
				search_by_organization(inventory);
				break;
			case 's':
				search_by_size(inventory);
				break;
			case 'p':
				print_inventory(inventory);
				break;
			case 'q':
				clear_inventory(inventory);
				return 0;
			default:
				printf("Illegal operation code!\n");
		}
		printf("\n");
	}
}

//////////////////////////
// function definitions //
//////////////////////////

void help() {
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

	new_node->next = NULL;

	if (inventory == NULL) return new_node;

	for (p = inventory;p->next != NULL;p = p->next);		//sets next of previous node to new_node

	p->next = new_node;


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

int read_line(char str[], int n) {
	int ch, i=0;

	while (isspace(ch = getchar()))
		;
	str[i++] = ch;
	while ((ch = getchar()) != '\n') {
		if (i < n)
			str[i++] = ch;    
	}
	str[i] = '\0';
	return i;
}

