#ifndef DISPLAY_CONTROL_H
#define DISPLAY_CONTROL_H

#include<Arduino.h>

// Library defination here

// Variables
static char get_data_from_screen;
static bool screen_update_status = true;
static int on_page_count = 0;
static int item_active = 0;
static int priority_count = 0;  // decides the priority of the customer
//String send0;

// Class
class customer{
  public:
    int unit_item1 = 0;
    int unit_item2 = 0;
    int unit_item3 = 0;
    int unit_item4 = 0;
    int priority = 0;   // customer priority factor;
    int ID;
    bool active = false;
    bool busy_ = false;
    customer(int id){
      this->ID = id;
    }
};

static customer customer1(1), customer2(2), customer3(3), customer4(4);

// Funtions
void serial_check();
void busy_work();
void ID_to_work(int ID);
void getting_screen();
void initializing_page0();
void customer_page1(bool c1, bool c2, bool c3, bool c4);
void item_page2(int ID, int item1, int item2, int item3, int item4);
void item_count_page3(int item_ID, int item_count);
void done_page4(int item1, int item2, int item3, int item4);
void thank_page5(int ID);

#endif