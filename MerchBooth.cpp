//Evelyn Nguyen, CS302, 10/13/25
//MerchBooth.cpp file
#include "FilmFest.h"

MerchBooth::MerchBooth() : Event() {}
MerchBooth::MerchBooth(const char * init_name, const vector<string> & init_items, const vector<float> & init_prices, float init_price) : Event(init_name, "Vendor Row", init_price), items(init_items), prices(init_prices) {}

MerchBooth::~MerchBooth() {}

bool MerchBooth::listItems() const
{
	cout << "Items available at " << name << ":\n";
	for (size_t i = 0; i < items.size(); ++i)
		cout << "- " << items[i] << "($" << prices[i] << ")\n";
	return true;
}

bool MerchBooth::purchaseItem(const string & itemName, float & balance)
{
    for (size_t i = 0; i < items.size(); ++i) 
    {
        if (items[i] == itemName) 
	{
            if (balance < prices[i]) 
	    {
                cout << "Not enough balance to buy " << itemName << "!\n";
                return false;
            }
            balance -= prices[i];
            cout << "You purchased " << itemName << " for $" << prices[i] << "!\n";
            return true;
        }
    }
    cout << itemName << " not found.\n";
    return false;
}

bool MerchBooth::restock(const string & itemName, float price)
{
    // Search for existing item
    for (size_t i = 0; i < items.size(); i++) {
        if (items[i] == itemName) {
            prices[i] = price;  // Update existing price
            cout << "Updated " << itemName << " price to $" << price << " in " << name << ".\n";
            return true;
        }
    }

    // If not found, add new item
    items.push_back(itemName);
    prices.push_back(price);
    cout << "Added " << itemName << " for $" << price << " to " << name << ".\n";
    return true;
}

bool MerchBooth::display() const
 {
    Event::display();
    cout << "Items for sale: " << items.size() << endl;
    for (size_t i = 0; i < items.size(); ++i)
        cout << "  - " << items[i] << " ($" << prices[i] << ")\n";
    return true;
}
bool MerchBooth::removeItem(const string & itemName) {
    for (size_t i = 0; i < items.size(); i++) {
        if (items[i] == itemName) {
            items.erase(items.begin() + i);
            prices.erase(prices.begin() + i);
            cout << "Removed " << itemName << " from inventory.\n";
            return true;
        }
    }
    cout << "Item not found.\n";
    return false;
}
