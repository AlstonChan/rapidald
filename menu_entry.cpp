#include<iostream>
#include<string>

#include "menu_var.h"

using namespace std;

void header(void);
void menu_options(int& current_page, string& option);
void termination(void);
void menu_main_list(int current_page);

string menu_list_item[18][3] = {
	{"Filet o fish burger", "Fish fillet with a slice of chesses with tartar sauce","20"},
	{"Black pepper beef burger", "Grilled beef with black pepper sauce with vegetables","22"},
	{"Chesses beef burger", "Grilled beef patty topped with a simple layer of melted cheese","24"},
	{"Indian spicy chicken burger", "Crispy chicken patty with sauce recipe from India", "22"},
	{"Crispy chicken cheese burger", "Crispy chicken patty with chicken strips ,cheese and mayonnaise","20"},
	{"Vege lover wrap", "Made from egg, fresh vegetables, and avocado dress with tartar sauce", "14"},
	{"Crispy chicken wrap", "Fried chicken fillet come with fresh vegetables and cheese with mayonnaise", "14"},
	{"Grilled beef wrap", "Grilled beef with black pepper sauce with fresh vegetables", "18"},
	{"Fish fillet wrap", "Deep fried Dory with spice and vegetables with lemon butter sauce", "16"},
	{"Cola", "Classic carbonated soft drink with a sweet and tangy flavor", "4"},
	{"Lemonade", "Refreshing citrusy beverage made from lemon juice and water", "4"},
	{"Iced Tea", "Chilled tea brewed and served cold, optionally sweetened", "4"},
	{"Fruit Punch", "Fruity blend of juices, often with tropical flavors", "6"},
	{"Milkshake", "Creamy drink with milk, ice cream, and various flavors", "6"},
	{"Cheezy Wedges", "Made from fresh potato, served with Mayonnaise and Cheese Sauce", "4"},
	{"Dirty French Fries", "The french fries on top with Mayonnaise, ketchup and mustard sauce", "4"},
	{"Fried Calamari", "Golden-brown and crispy fried calamari served with ketchup", "6"},
	{"Fried Golden Enoki Mushroom", "Crispy fried enoki mushroom and on top with homemade salted-egg sauce", "8"},
};

void menu_entry() {

	string option = "E";
	int current_page = 0;

	do {
		// refer to https://stackoverflow.com/questions/47503734/what-does-printf-033c-mean
        cout << "\033c";

		//header 
		header();

		// main menu
		menu_main_list(current_page);
		
		// Options
		menu_options(current_page, option);

	// continue to loop if option is not E or e
	} while(isalpha(option[0]) ? tolower(option[0]) != 'e' : true);

	if (isalpha(option[0]) && tolower(option[0]) != 'e') {
		termination();
	}
}

void menu_main_list(int current_page) {
	for (size_t i = 0; i < 9; i++) {
		unsigned int item_id = current_page * 9 + i;
		cout << item_id + 1 << ". " << menu_list_item[item_id][0] << "\n";
		cout << (item_id + 1 > 9 ? "    " : "   ") << menu_list_item[item_id][1] << "\n" << "\n";
	}
}