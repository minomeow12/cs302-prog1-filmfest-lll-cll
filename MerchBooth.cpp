//Evelyn Nguyen, CS302, 10/13/25
//MerchBooth.cpp file
#include "FilmFest.h"

MerchBooth::MerchBooth() : Event() {}
MerchBooth::MerchBooth(const char * init_name, const vector<string> & init_items, const vector<float> & init_prices, float init_price) : Event(init_name, "Vendor Row", init_price), items(init_items), prices(init_prices) {}

MerchBooth::~MerchBooth() {}


bool MerchBooth::purchaseItem(const string & itemName, float & balance)
{
    bool found = false;	
    for (size_t i = 0; i < items.size() &&!found; ++i) 
    {
        if (items[i] == itemName) 
	{
            if (balance < prices[i]) 
	    {
                cout << "Not enough balance to buy " << itemName << "!\n";
	    }
	    else
	    { 
            	balance -= prices[i];
            	cout << "You purchased " << itemName << " for $" << prices[i] << "!\n";
            	found =  true;
	    }
        }
    }
    if (!found)
    	cout << itemName << " not found.\n";
    return found;
}

bool MerchBooth::restock(const string & itemName, float price)
{
    bool found = false;
    // Search for existing item
    for (size_t i = 0; i < items.size() && !found; i++) {
        if (items[i] == itemName) {
            prices[i] = price;  // Update existing price
            cout << "Updated " << itemName << " price to $" << price << " in " << name << ".\n";
            found =  true;
        }
    }

    // If not found, add new item
    if (!found)
    {
	items.push_back(itemName);
    	prices.push_back(price);
    	cout << "Added " << itemName << " for $" << price << " to " << name << ".\n";
    }
    return found;
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
    bool found = false;	
    for (size_t i = 0; i < items.size()  && !found; i++) {
        if (items[i] == itemName) {
            items.erase(items.begin() + i);
            prices.erase(prices.begin() + i);
            cout << "Removed " << itemName << " from inventory.\n";
            found =  true;
        }
    }
    if (!found)
    	cout << "Item not found.\n";
    return found;
}
