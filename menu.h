//===== MENU HEADER FILE =====
//Evelyn Nguyen, CS302, prog1, 10/17/25
//Menu header file
#ifndef MENU_H
#define MENU_H

#include "List.h"

class Menu {
public:
    Menu();
    void run(); // Main loop - displays role selection
private:
    // ADT lists for each event type
    WorkshopLLL workshops;
    ScreeningCLL screenings;
    MerchBooth merch;
    
    // ORGANIZER MENUS - for managing vendors
    void organizerMainMenu();
    void organizer_workshopMenu();
    void organizer_screeningMenu();
    void organizer_merchMenu();
    
    // CUSTOMER MENUS - for interacting with vendors
    void customerMainMenu();
    void customer_workshopMenu();
    void customer_screeningMenu();
    void customer_merchMenu();
};

#endif
