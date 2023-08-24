#include<iostream>
#include<vector>
#include<cctype>
#include<string>
#include<algorithm>

#include "menu_options_sections.h"

using namespace std;

int main() {

	char option[2] = { 'E' };
	int current_page = 0;

	vector<vector<string>> menu = {
		{"Filet o fish burger", "Fish fillet with a slice of chesses with tartar sauce"},
		{"Black pepper beef burger", "Grilled beef with black pepper sauce with vegetable"},
		{"Chesses beef burger", "Grilled beef patty topped with a simple layer of melted cheese"},
		{"Indian spicy chicken burger", "Crispy chicken patty with sauce recipe from India"},
		{"Crispy chicken cheese burger", "Crispy chicken patty with chicken strips ,cheese and mayonnaise"},
		{"Vege lover wrap", "Made from egg, fresh vegetables, and avocado dress with tartar sauce"},
		{"Crispy chicken wrap", "Fried chicken fillet come with fresh vegetables and cheese with mayonnaise"},
		{"Grilled beef wrap", "Grilled beef with black pepper sauce with fresh vegetables"},
		{"Fish fillet wrap", "Deep fried Dory with spice and vegetables with lemon butter sauce"},
		{"Cola", "Classic carbonated soft drink with a sweet and tangy flavor"},
		{"Lemonade", "Refreshing citrusy beverage made from lemon juice and water"},
		{"Iced Tea", "Chilled tea brewed and served cold, optionally sweetened"},
		{"Fruit Punch", "Fruity blend of juices, often with tropical flavors"},
		{"Milkshake", "Creamy drink with milk, ice cream, and various flavors"},
		{"Cheezy Wedges", "Made from fresh potato, served with Mayonnaise and Cheese Sauce"},		
		{"Dirty French Fries", "The french fries on top with Mayonnaise, ketchup and mustard sauce"},		
		{"Fried Calamari", "Golden-brown and crispy fried calamari served with ketchup"},		
		{"Fried Golden Enoki Mushroom", "Crispy fried enoki mushroom and on top with homemade salted-egg sauce"},
	};

	do {
		// refer to https://stackoverflow.com/questions/47503734/what-does-printf-033c-mean
        cout << "\033c";

		//header 
		cout << "rapidald" << "\n" << "\n";

		// main menu
		for (size_t i = 0; i < 9; i++) {
			size_t page_start_count = current_page * 9 + i;
			cout << page_start_count + 1 << ". " << menu[page_start_count][0] << "\n";
			cout << (page_start_count + 1 > 9 ? "    " : "   ") << menu[page_start_count][1] << "\n" << "\n";
		}
		
		// Options
		options_section(&current_page, option);

	} while(isalpha(option[0]) ? tolower(option[0]) != 'e' : true);

	return 0;
}