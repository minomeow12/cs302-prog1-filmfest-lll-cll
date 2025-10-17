
//Evelyn Nguyen, CS302, prog1, 10/14/25
//Menu implementation
#include "menu.h"
#include <iostream>
using namespace std;

Menu::Menu() : merch("Official Booth", {"T-Shirt", "Mug", "Poster"}, {20.0f, 10.0f, 5.0f}, 0.0f){}
void Menu::run()
{
    int choice = 0;
    do {
        cout << "\n========== OCTOBERFEST ==========\n"
             << "Welcome to the Octoberfest!\n"
             << "What is your role?\n"
             << "1. Organizer\n"
             << "2. Customer\n"
             << "3. Exit Program\n"
             << "Choice: ";
        cin >> choice;
        cin.ignore(100, '\n');
        switch (choice) 
	{
            case 1: organizerMainMenu(); break;
            case 2: customerMainMenu(); break;
            case 3: cout << "Thank you for visiting Octoberfest!\n"; break;
            default: cout << "Invalid choice. Please try again.\n"; break;
        }
    } while (choice != 3);
}

//ORGANIZER MENU FUNCTIONS

void Menu::organizerMainMenu()
{
    int choice = 0;
    do {
        cout << "\n====== ORGANIZER MENU ======\n"
             << "Manage your events:\n"
             << "1. Workshops\n"
             << "2. Film Screenings\n"
             << "3. Merchandise Booth\n"
             << "4. Return to Main Menu\n"
             << "Choice: ";
        cin >> choice;
        cin.ignore(100, '\n');
        switch (choice)
       	{
            case 1: organizer_workshopMenu(); break;
            case 2: organizer_screeningMenu(); break;
            case 3: organizer_merchMenu(); break;
            case 4: return;
            default: cout << "Invalid choice.\n"; break;
        }
    } while (choice != 4);
}

void Menu::organizer_workshopMenu()
{
    int choice = 0;
    do
    {
        cout << "\n--- ORGANIZER: Workshop Management ---\n"
             << "1. Add Workshop\n"
             << "2. Display All Workshops\n"
             << "3. Remove Workshop\n"
             << "4. Search Workshop\n"
             << "5. Return to Organizer Menu\n"
             << "Choice: ";
        cin >> choice;
        cin.ignore(100, '\n');

        if (choice == 1) {
            char name[NAME_SIZE];
            string topic, instructor;
            int seats;
            float price;

            cout << "Enter workshop name: ";
            cin.getline(name, NAME_SIZE);
            cout << "Topic: ";
            getline(cin, topic);
            cout << "Instructor: ";
            getline(cin, instructor);
            cout << "Seats available: ";
            cin >> seats;
            cout << "Price: $";
            cin >> price;
            cin.ignore(100, '\n');

            Workshop w(name, topic, instructor, seats, price);
            if (workshops.insert(w)) {
                cout << "Workshop added successfully!\n";
            } else {
                cout << "Failed to add workshop.\n";
            }
        }
        else if (choice == 2) {
            cout << "\n--- All Workshops ---\n";
            workshops.display();
        }
        else if (choice == 3) {
            string name;
            cout << "Enter workshop name to remove: ";
            getline(cin, name);
            if (workshops.remove(name.c_str())) {
                cout << "Workshop removed successfully!\n";
            } else {
                cout << "Workshop not found.\n";
            }
        }
        else if (choice == 4) {
            string name;
            cout << "Enter workshop name to search: ";
            getline(cin, name);
            Workshop* found = workshops.find(name);
            if (found) {
                cout << "Workshop found!\n";
                found->display();
            } else {
                cout << "Workshop not found.\n";
            }
        }
    } while (choice != 5);
}

void Menu::organizer_screeningMenu() 
{
    int choice = 0;
    do {
        cout << "\n--- ORGANIZER: Screening Management ---\n"
             << "1. Add Screening\n"
             << "2. Display All Screenings\n"
             << "3. Remove Screening\n"
             << "4. Search Screening\n"
             << "5. Return to Organizer Menu\n"
             << "Choice: ";
        cin >> choice;
        cin.ignore(100, '\n');

        if (choice == 1) {
            char filmTitle[NAME_SIZE];
            string genre;
            int duration;
            float price;

            cout << "Enter film title: ";
            cin.getline(filmTitle, NAME_SIZE);
            cout << "Genre: ";
            getline(cin, genre);
            cout << "Duration (min): ";
            cin >> duration;
            cout << "Price: $";
            cin >> price;
            cin.ignore(100, '\n');

            Screening s(filmTitle, filmTitle, genre, duration, price);
            if (screenings.insert(s)) {
                cout << "Screening added successfully!\n";
            } else {
                cout << "Failed to add screening.\n";
            }
        }
        else if (choice == 2) {
            cout << "\n--- All Screenings ---\n";
            screenings.display();
        }
        else if (choice == 3) {
            string title;
            cout << "Enter film title to remove: ";
            getline(cin, title);
            if (screenings.remove(title.c_str())) {
                cout << "Screening removed successfully!\n";
            } else {
                cout << "Screening not found.\n";
            }
        }
        else if (choice == 4) {
            string title;
            cout << "Enter film title to search: ";
            getline(cin, title);
            Screening* found = screenings.find(title);
            if (found) {
                cout << "Screening found!\n";
                found->display();
            } else {
                cout << "Screening not found.\n";
            }
        }

    } while (choice != 5);
}

void Menu::organizer_merchMenu() {
    int choice = 0;
    do {
        cout << "\n--- ORGANIZER: Merchandise Booth Management ---\n"
             << "1. Display Booth Info\n"
             << "2. List Items\n"
             << "3. Add/Restock Item\n"
	     << "4. Remove Item\n" 
             << "5. View Inventory\n"
             << "6. Return to Organizer Menu\n"
             << "Choice: ";
        cin >> choice;
        cin.ignore(100, '\n');

        if (choice == 1) {
            merch.display();
        }
        else if (choice == 2) {
            merch.listItems();
        }
        else if (choice == 3) {
            string item;
            float price;
            cout << "Enter item name: ";
            getline(cin, item);
            cout << "Enter item price: $";
            cin >> price;
            cin.ignore(100, '\n');

            if (merch.restock(item, price)) {
                cout << "Item restocked successfully!\n";
            } else {
                cout << "Failed to restock item.\n";
            }
        }
	else if (choice == 4)
	{
		string item;
		cout << "Enter item name to remove: ";
	        getline(cin, item);	
		if (merch.removeItem(item))
			cout << "Removed successfully\n";
		else
			cout << "No item found\n";
	}
        else if (choice == 5) {
            cout << "\n--- Inventory ---\n";
            merch.display();
        }

    } while (choice != 6);
}

// CUSTOMER MENU FUNCTIONS

void Menu::customerMainMenu() {
    int choice = 0;
    do {
        cout << "\n====== CUSTOMER MENU ======\n"
             << "Choose what you'd like to do:\n"
             << "1. Register for a Workshop\n"
             << "2. Watch a Film Screening\n"
             << "3. Visit Merchandise Booth\n"
             << "4. Return to Main Menu\n"
             << "Choice: ";
        cin >> choice;
        cin.ignore(100, '\n');

        switch (choice) {
            case 1: customer_workshopMenu(); break;
            case 2: customer_screeningMenu(); break;
            case 3: customer_merchMenu(); break;
            case 4: return;
            default: cout << "Invalid choice.\n"; break;
        }
    } while (choice != 4);
}

void Menu::customer_workshopMenu() {
    int choice = 0;
    do {
        cout << "\n--- CUSTOMER: Workshops ---\n"
             << "1. View All Workshops\n"
             << "2. Register for a Workshop\n"
             << "3. Cancel Registration\n"
             << "4. Get Certificate\n"
             << "5. Test isAffordable()\n"
             << "6. Test getDiscountedPrice()\n"
             << "7. Return to Customer Menu\n"
             << "Choice: ";
        cin >> choice;
        cin.ignore(100, '\n');

        if (choice == 1) {
            cout << "\n--- Available Workshops ---\n";
            workshops.display();
        }
        else if (choice == 2) {
            string name, attendee;
            cout << "Enter workshop name: ";
            getline(cin, name);
            cout << "Enter your name: ";
            getline(cin, attendee);

            Workshop* found = workshops.find(name);
            if (found) {
                if (found->registerAttendee(attendee)) {
                    cout << "Successfully registered!\n";
                } else {
                    cout << "Registration failed.\n";
                }
            } else {
                cout << "Workshop not found.\n";
            }
        }
        else if (choice == 3) {
            string name, attendee;
            cout << "Enter workshop name: ";
            getline(cin, name);
            cout << "Enter your name: ";
            getline(cin, attendee);

            Workshop* found = workshops.find(name);
            if (found) {
                if (found->cancelRegistration(attendee)) {
                    cout << "Registration cancelled!\n";
                } else {
                    cout << "Cancellation failed.\n";
                }
            } else {
                cout << "Workshop not found.\n";
            }
        }
        else if (choice == 4) {
            string name;
            cout << "Enter workshop name: ";
            getline(cin, name);

            Workshop* found = workshops.find(name);
            if (found) {
                found->printCertificate();
            } else {
                cout << "Workshop not found.\n";
            }
        }
        else if (choice == 5) {
            string name;
            float balance;
            cout << "Enter workshop name: ";
            getline(cin, name);
            cout << "Enter your balance: $";
            cin >> balance;
            cin.ignore(100, '\n');

            Workshop* found = workshops.find(name);
            if (found) {
                if (found->isAffordable(balance)) {
                    cout << "You can afford this workshop!\n";
                } else {
                    cout << "You cannot afford this workshop.\n";
                }
            } else {
                cout << "Workshop not found.\n";
            }
        }
        else if (choice == 6) {
            string name;
            float discount;
            cout << "Enter workshop name: ";
            getline(cin, name);
            cout << "Enter discount rate (e.g., 0.1 for 10%): ";
            cin >> discount;
            cin.ignore(100, '\n');

            Workshop* found = workshops.find(name);
            if (found) {
                float discountedPrice = found->getDiscountedPrice(discount);
                cout << "Discounted price: $" << discountedPrice << "\n";
            } else {
                cout << "Workshop not found.\n";
            }
        }

    } while (choice != 7);
}

void Menu::customer_screeningMenu() {
    int choice = 0;
    do {
        cout << "\n--- CUSTOMER: Film Screenings ---\n"
             << "1. View All Screenings\n"
             << "2. Buy a Ticket\n"
             << "3. Rate a Film\n"
             << "4. View Schedule\n"
             << "5. Test isAffordable()\n"
             << "6. Test getDiscountedPrice()\n"
             << "7. Return to Customer Menu\n"
             << "Choice: ";
        cin >> choice;
        cin.ignore(100, '\n');

        if (choice == 1) {
            cout << "\n--- Available Screenings ---\n";
            screenings.display();
        }
        else if (choice == 2) {
            string title;
            float balance;
            cout << "Enter film title: ";
            getline(cin, title);
            cout << "Enter your balance: $";
            cin >> balance;
            cin.ignore(100, '\n');

            Screening* found = screenings.find(title);
            if (found) {
                if (found->purchaseTicket(balance)) {
                    cout << "Ticket purchased successfully!\n";
                } else {
                    cout << "Purchase failed. Insufficient funds?\n";
                }
            } else {
                cout << "Film not found.\n";
            }
        }
        else if (choice == 3) {
            string title;
            int rating;
            cout << "Enter film title: ";
            getline(cin, title);
            cout << "Enter your rating (1-5): ";
            cin >> rating;
            cin.ignore(100, '\n');

            Screening* found = screenings.find(title);
            if (found) {
                if (found->rateFilm(rating)) {
                    cout << "Thank you for rating!\n";
                } else {
                    cout << "Rating failed.\n";
                }
            } else {
                cout << "Film not found.\n";
            }
        }
        else if (choice == 4) {
            screenings.display();
        }
        else if (choice == 5) {
            string title;
            float balance;
            cout << "Enter film title: ";
            getline(cin, title);
            cout << "Enter your balance: $";
            cin >> balance;
            cin.ignore(100, '\n');

            Screening* found = screenings.find(title);
            if (found) {
                if (found->isAffordable(balance)) {
                    cout << "You can afford this screening!\n";
                } else {
                    cout << "You cannot afford this screening.\n";
                }
            } else {
                cout << "Film not found.\n";
            }
        }
        else if (choice == 6) {
            string title;
            float discount;
            cout << "Enter film title: ";
            getline(cin, title);
            cout << "Enter discount rate (e.g., 0.1 for 10%): ";
            cin >> discount;
            cin.ignore(100, '\n');

            Screening* found = screenings.find(title);
            if (found) {
                float discountedPrice = found->getDiscountedPrice(discount);
                cout << "Discounted price: $" << discountedPrice << "\n";
            } else {
                cout << "Film not found.\n";
            }
        }

    } while (choice != 7);
}

void Menu::customer_merchMenu()
{
    int choice = 0;
    do {
        cout << "\n--- CUSTOMER: Merchandise Booth ---\n"
             << "1. View Available Items\n"
             << "2. Buy an Item\n"
             << "3. Return to Customer Menu\n"
             << "Choice: ";
        cin >> choice;
        cin.ignore(100, '\n');

        if (choice == 1) {
            merch.listItems();
        }
        else if (choice == 2) {
            string item;
            float balance;
            cout << "Enter item name: ";
            getline(cin, item);
            cout << "Enter your balance: $";
            cin >> balance;
            cin.ignore(100, '\n');

            if (merch.purchaseItem(item, balance)) {
                cout << "Purchase successful!\n";
            } else {
                cout << "Purchase failed. Insufficient funds?\n";
            }
        }

    } while (choice != 3);
}
