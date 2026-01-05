// Evelyn Nguyen, CS302, prog1, 10/14/25
// Menu implementation

#include "menu.h"
#include <iostream>
using namespace std;

Menu::Menu()
    : merch("Official Booth", {"T-Shirt", "Mug", "Poster"}, {20.0f, 10.0f, 5.0f}, 0.0f) {}

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

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        cin.ignore(100, '\n');

        switch (choice) {
            case 1: organizerMainMenu(); break;
            case 2: customerMainMenu(); break;
            case 3: cout << "Thank you for visiting Octoberfest!\n"; break;
            default: cout << "Invalid choice. Please try again.\n"; break;
        }
    } while (choice != 3);
}

// ORGANIZER MENU
void Menu::organizerMainMenu()
{
    int choice = 0;
    do {
        cout << "\n====== ORGANIZER MENU ======\n"
             << "1. Workshops\n"
             << "2. Film Screenings\n"
             << "3. Merchandise Booth\n"
             << "4. Return to Main Menu\n"
             << "Choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid input. Try again.\n";
            continue;
        }
        cin.ignore(100, '\n');

        switch (choice) {
            case 1: organizer_workshopMenu(); break;
            case 2: organizer_screeningMenu(); break;
            case 3: organizer_merchMenu(); break;
            case 4: return;
            default: cout << "Invalid choice.\n"; break;
        }
    } while (choice != 4);
}

// Workshop Management ----------

void Menu::organizer_workshopMenu()
{
    int choice = 0;
    do {
        cout << "\n--- ORGANIZER: Workshop Management ---\n"
             << "1. Add Workshop\n"
             << "2. Display All Workshops\n"
             << "3. Remove Workshop\n"
             << "4. Search Workshop\n"
             << "5. Return to Organizer Menu\n"
             << "Choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid input. Enter a number.\n";
            continue;
        }
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
            while (!(cin >> seats)) {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Invalid input. Enter a number: ";
            }

            cout << "Price: $";
            while (!(cin >> price)) {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Invalid price. Enter again: $";
            }
            cin.ignore(100, '\n');

            Workshop w(name, topic, instructor, seats, price);
            if (workshops.insert(w))
                cout << "Workshop added successfully!\n";
            else
                cout << "Failed to add workshop.\n";
        }
        else if (choice == 2) {
            if (workshops.display() == 0)
                cout << "(No workshops available.)\n";
        }
        else if (choice == 3) {
            string name;
            cout << "Enter workshop name to remove: ";
            getline(cin, name);

            if (workshops.remove(name.c_str()))
                cout << "Workshop removed successfully.\n";
            else
                cout << "Workshop not found.\n";
        }
        else if (choice == 4) {
            string name;
            cout << "Enter workshop name to search: ";
            getline(cin, name);

            if (workshops.find(name))
                cout << "Workshop found.\n";
            else
                cout << "Workshop not found.\n";
        }

    } while (choice != 5);
}

// ---------- Screening Management ----------

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

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid input. Enter a number.\n";
            continue;
        }
        cin.ignore(100, '\n');

        if (choice == 1) {
            char title[NAME_SIZE];
            string genre;
            int duration;
            float price;

            cout << "Enter film title: ";
            cin.getline(title, NAME_SIZE);
            cout << "Genre: ";
            getline(cin, genre);

            cout << "Duration (min): ";
            while (!(cin >> duration)) {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Invalid input. Enter a number: ";
            }

            cout << "Price: $";
            while (!(cin >> price)) {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Invalid price. Enter again: $";
            }
            cin.ignore(100, '\n');

            Screening s(title, title, genre, duration, price);
            if (screenings.insert(s))
                cout << "Screening added successfully.\n";
            else
                cout << "Failed to add screening.\n";
        }
        else if (choice == 2) {
            if (screenings.display() == 0)
                cout << "(No screenings scheduled.)\n";
        }
        else if (choice == 3) {
            string title;
            cout << "Enter film title to remove: ";
            getline(cin, title);

            if (screenings.remove(title.c_str()))
                cout << "Screening removed successfully.\n";
            else
                cout << "Screening not found.\n";
        }
        else if (choice == 4) {
            string title;
            cout << "Enter film title to search: ";
            getline(cin, title);

            if (screenings.find(title))
                cout << "Screening found.\n";
            else
                cout << "Screening not found.\n";
        }

    } while (choice != 5);
}

// ---------- Merchandise Booth ----------

void Menu::organizer_merchMenu()
{
    int choice = 0;
    do {
        cout << "\n--- ORGANIZER: Merchandise Booth Management ---\n"
             << "1. Display Booth Info\n"
             << "2. Add/Restock Item\n"
             << "3. Remove Item\n"
             << "4. Return to Organizer Menu\n"
             << "Choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid input. Enter a number.\n";
            continue;
        }
        cin.ignore(100, '\n');

        if (choice == 1)
            merch.display();
        else if (choice == 2) {
            string item;
            float price;
            cout << "Enter item name: ";
            getline(cin, item);

            cout << "Enter item price: $";
            while (!(cin >> price)) {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Invalid price. Enter again: $";
            }
            cin.ignore(100, '\n');

            merch.restock(item, price);
        }
        else if (choice == 3) {
            string item;
            cout << "Enter item name to remove: ";
            getline(cin, item);

            if (merch.removeItem(item))
                cout << "Item removed successfully.\n";
            else
                cout << "Item not found.\n";
        }

    } while (choice != 4);
}
// CUSTOMER MENU

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

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid input. Enter a number.\n";
            continue;
        }
        cin.ignore(100, '\n');

        switch (choice) {
            case 1: customer_workshopMenu(); break;
            case 2: customer_screeningMenu(); break;
            case 3: customer_merchMenu(); break;
            case 4: return;
            default: cout << "Invalid choice. Try again.\n"; break;
        }
    } while (choice != 4);
}

// ---------- Customer: Workshop Menu ----------

void Menu::customer_workshopMenu() {
    int choice = 0;
    do {
        cout << "\n--- CUSTOMER: Workshops ---\n"
             << "1. View All Workshops\n"
             << "2. Register for a Workshop\n"
             << "3. Cancel Registration\n"
             << "4. Print Certificate\n"
             << "5. Check if Affordable\n"
             << "6. Return to Customer Menu\n"
             << "Choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid input. Enter a number.\n";
            continue;
        }
        cin.ignore(100, '\n');

        if (choice == 1) {
            if (workshops.display() == 0)
                cout << "(No workshops currently available.)\n";
        }
        else if (choice == 2) {
            string name, attendee;
            cout << "Enter workshop name: ";
            getline(cin, name);
            cout << "Enter your name: ";
            getline(cin, attendee);

            if (workshops.registerAttendee(name, attendee))
                cout << "You are registered for '" << name << "'!\n";
            else
                cout << "Workshop not found or full.\n";
        }
        else if (choice == 3) {
            string name, attendee;
            cout << "Enter workshop name: ";
            getline(cin, name);
            cout << "Enter your name: ";
            getline(cin, attendee);

            if (workshops.cancelRegistration(name, attendee))
                cout << "Registration cancelled successfully.\n";
            else
                cout << "Could not cancel -workshop not found or no registration.\n";
        }
        else if (choice == 4) {
            string name;
            cout << "Enter workshop name: ";
            getline(cin, name);

            if (workshops.printCertificate(name))
                cout << "Certificate printed for '" << name << "'.\n";
            else
                cout << "Workshop not found or no registration found.\n";
        }
        else if (choice == 5) {
            string name;
            float balance;
            cout << "Enter workshop name: ";
            getline(cin, name);
            cout << "Enter your balance: $";
            while (!(cin >> balance)) {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Invalid number. Enter balance again: $";
            }
            cin.ignore(100, '\n');

            if (workshops.isAffordable(name, balance))
                cout << "You can afford this workshop!\n";
            else
                cout << "Either not found or insufficient funds.\n";
        }

    } while (choice != 6);
}

// ---------- Customer: Screening Menu ----------

void Menu::customer_screeningMenu() {
    int choice = 0;
    do {
        cout << "\n--- CUSTOMER: Film Screenings ---\n"
             << "1. View All Screenings\n"
             << "2. Purchase Ticket\n"
             << "3. Rate Film\n"
             << "4. View Schedule\n"
             << "5. Check if Affordable\n"
             << "6. Get Discounted Price\n"
             << "7. Return to Customer Menu\n"
             << "Choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid input. Enter a number.\n";
            continue;
        }
        cin.ignore(100, '\n');

        if (choice == 1) {
            if (screenings.display() == 0)
                cout << "(No screenings currently scheduled.)\n";
        }
        else if (choice == 2) {
            string title;
            float balance;
            cout << "Enter film title: ";
            getline(cin, title);
            cout << "Enter your balance: $";
            while (!(cin >> balance)) {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Invalid amount. Try again: $";
            }
            cin.ignore(100, '\n');

            if (screenings.purchaseTicket(title, balance))
                cout << "Ticket purchased for '" << title << "'!\n";
            else
                cout << "Screening not found or insufficient funds.\n";
        }
        else if (choice == 3) {
            string title;
            int rating;
            cout << "Enter film title: ";
            getline(cin, title);
            cout << "Enter rating (1–5): ";
            while (!(cin >> rating) || rating < 1 || rating > 5) {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Invalid rating. Enter 1–5: ";
            }
            cin.ignore(100, '\n');

            if (screenings.rateFilm(title, rating))
                cout << "Thank you for rating!\n";
            else
                cout << "Film not found.\n";
        }
        else if (choice == 4) {
            if (screenings.display() == 0)
                cout << "(No schedule available.)\n";
        }
        else if (choice == 5) {
            string title;
            float balance;
            cout << "Enter film title: ";
            getline(cin, title);
            cout << "Enter your balance: $";
            while (!(cin >> balance)) {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Invalid amount. Try again: $";
            }
            cin.ignore(100, '\n');

            if (screenings.isAffordable(title, balance))
                cout << "You can afford this screening!\n";
            else
                cout << "Screening not found or too expensive.\n";
        }
        else if (choice == 6) {
            string title;
            float discount;
            cout << "Enter film title: ";
            getline(cin, title);
            cout << "Enter discount rate (0.1 = 10%): ";
            while (!(cin >> discount) || discount < 0.0f) {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Invalid rate. Enter again (e.g., 0.2): ";
            }
            cin.ignore(100, '\n');

            if (screenings.getDiscountedPrice(title, discount))
                cout << "Discount applied successfully.\n";
            else
                cout << "Screening not found.\n";
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
            merch.display();
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


