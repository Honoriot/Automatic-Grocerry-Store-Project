#include<display_control.h>
#include<stepper_control.h>
// customer customer1(1), customer2(2), customer3(3), customer4(4);

// Busy or not checker
void busy_work(){
	Serial.print("I am 1: "); Serial.println(customer1.priority);
	Serial.print("I am 2: "); Serial.println(customer2.priority);
	
  if(customer1.busy_ && customer1.priority==1){
    Serial.print("I am 1 getting busy: ");
    Serial.println(customer1.priority);
    ID_to_work(1);
    if(customer1.priority>=1)
		customer1.priority = customer1.priority - 1;
	if(customer2.priority>=1)
		customer2.priority = customer2.priority - 1;
	if(customer3.priority>=1)
		customer3.priority = customer3.priority - 1;
	if(customer4.priority>=1)
		customer4.priority = customer4.priority - 1;
	if(priority_count>=1)
		priority_count = priority_count - 1;
  }
  else if(customer2.busy_ && customer2.priority==1){
    Serial.print("I am 2 getting busy");
    ID_to_work(2); //    work();
    if(customer1.priority>=1)
		customer1.priority = customer1.priority - 1;
	if(customer2.priority>=1)
		customer2.priority = customer2.priority - 1;
	if(customer3.priority>=1)
		customer3.priority = customer3.priority - 1;
	if(customer4.priority>=1)
		customer4.priority = customer4.priority - 1;
	if(priority_count>=1)
		priority_count = priority_count - 1;
  }
  else if(customer3.busy_ && customer3.priority==1){
    ID_to_work(3); //    work();
    if(customer1.priority>=1)
		customer1.priority = customer1.priority - 1;
	if(customer2.priority>=1)
		customer2.priority = customer2.priority - 1;
	if(customer3.priority>=1)
		customer3.priority = customer3.priority - 1;
	if(customer4.priority>=1)
		customer4.priority = customer4.priority - 1;
	if(priority_count>=1)
		priority_count = priority_count - 1;
  }
  else if(customer4.busy_ && customer4.priority==1){
    ID_to_work(4); //    work();
    if(customer1.priority>=1)
		customer1.priority = customer1.priority - 1;
	if(customer2.priority>=1)
		customer2.priority = customer2.priority - 1;
	if(customer3.priority>=1)
		customer3.priority = customer3.priority - 1;
	if(customer4.priority>=1)
		customer4.priority = customer4.priority - 1;
	if(priority_count>=1)
		priority_count = priority_count - 1;
  } 
}


// ID to work for
void ID_to_work(int ID){
  if(ID == 1){
    work();
    customer1.busy_ = false;
  }else if(ID == 2){
    work();
    customer2.busy_ = false;
  }else if(ID == 3){
    work();
    customer3.busy_ = false;
  }else if(ID == 4){
    work();
    customer4.busy_ = false;
  }else{
    // no work
  }

}

void serial_check(){
	if(Serial1.available()>0){
		getting_screen();
	}
}

void getting_screen(){
  // presenting all screen code here
  while(Serial1.available()>0){
    get_data_from_screen = Serial1.read();
    //Serial.println(get_data_from_screen);
    screen_update_status = true;
  }

  if(screen_update_status){
   if(get_data_from_screen=='a'){
    customer_page1( customer1.busy_, customer2.busy_, customer3.busy_, customer3.busy_);
   }
   else if(get_data_from_screen=='b' && customer1.busy_==false){
    customer1.active = true;
    item_page2(customer1.ID, customer1.unit_item1, customer1.unit_item2, customer1.unit_item3, customer1.unit_item4);
   }
   else if(get_data_from_screen=='c' && customer2.busy_==false){
    customer2.active = true;
    item_page2(customer2.ID, customer2.unit_item1, customer2.unit_item2, customer2.unit_item3, customer2.unit_item4);
   }
   else if(get_data_from_screen=='d' && customer3.busy_==false){
    customer3.active = true;
    item_page2(customer3.ID, customer3.unit_item1, customer3.unit_item2, customer3.unit_item3, customer3.unit_item4);
   }
   else if(get_data_from_screen=='e' && customer4.busy_==false){
    customer4.active = true;
    item_page2(customer4.ID, customer4.unit_item1, customer4.unit_item2, customer4.unit_item3, customer4.unit_item4);
   }
   else if(get_data_from_screen=='l'){
    if(customer1.active){
      customer1.active = false;
    }
    else if(customer2.active){
      customer2.active = false;
    }
    else if(customer3.active){
      customer2.active = false;
    }
    else if(customer4.active){
      customer2.active = false;
    }
    customer_page1( customer1.busy_, customer2.busy_, customer3.busy_, customer3.busy_);
   }

   // Item1 selected
   else if(get_data_from_screen=='f'){
    if(customer1.active){
      item_count_page3( 1, customer1.unit_item1);
    }
    else if(customer2.active){
      item_count_page3( 1, customer2.unit_item1);
    }
    else if(customer3.active){
      item_count_page3( 1, customer3.unit_item1);
    }
    else if(customer4.active){
      item_count_page3( 1, customer4.unit_item1);
    }

    item_active = 1;
   }

   // Item2 selected
   else if(get_data_from_screen=='i'){
    if(customer1.active){
      item_count_page3( 2, customer1.unit_item2);
    }
    else if(customer2.active){
      item_count_page3( 2, customer2.unit_item2);
    }
    else if(customer3.active){
      item_count_page3( 2, customer3.unit_item2);
    }
    else if(customer4.active){
      item_count_page3( 2, customer4.unit_item2);
    }
    item_active = 2;
   }

   // Item3 selected
   else if(get_data_from_screen=='j'){
    if(customer1.active){
      item_count_page3( 3, customer1.unit_item3);
    }
    else if(customer2.active){
      item_count_page3( 3, customer2.unit_item3);
    }
    else if(customer3.active){
      item_count_page3( 3, customer3.unit_item3);
    }
    else if(customer4.active){
      item_count_page3( 3, customer4.unit_item3);
    }
    item_active = 3;
   }

   // Item4 selected
   else if(get_data_from_screen=='k'){
    if(customer1.active){
      item_count_page3( 4, customer1.unit_item4);
    }
    else if(customer2.active){
      item_count_page3( 4, customer2.unit_item4);
    }
    else if(customer3.active){
      item_count_page3( 4, customer3.unit_item4);
    }
    else if(customer4.active){
      item_count_page3( 4, customer4.unit_item4);
    }
    item_active = 4;
   }

   // Proceed button on item select page
   else if(get_data_from_screen=='m'){
    if(customer1.active){
      done_page4( customer1.unit_item1, customer1.unit_item2, customer1.unit_item3, customer1.unit_item4);
    }
    else if(customer2.active){
      done_page4( customer2.unit_item1, customer2.unit_item2, customer2.unit_item3, customer2.unit_item4);
    }
    else if(customer3.active){
      done_page4( customer3.unit_item1, customer3.unit_item2, customer3.unit_item3, customer3.unit_item4);
    }
    else if(customer4.active){
      done_page4( customer4.unit_item1, customer4.unit_item2, customer4.unit_item3, customer4.unit_item4);
    }
   }

   // for increment on page data 
   else if(get_data_from_screen=='n'){
    if(customer1.active){
      if(item_active==1){
        on_page_count = 1 + on_page_count;
        item_count_page3( 1, on_page_count);
      }
      else if(item_active==2){
        on_page_count = 1 + on_page_count;
        item_count_page3( 2, on_page_count);
      }
      else if(item_active==3){
        on_page_count = 1 + on_page_count;
        item_count_page3( 3, on_page_count);
      }
      else if(item_active==4){
        on_page_count = 1 + on_page_count;
        item_count_page3( 4, on_page_count);
      }
    }

    else if(customer2.active){
      if(item_active==1){
        on_page_count = 1 + on_page_count;
        item_count_page3( 1, on_page_count);
      }
      else if(item_active==2){
        on_page_count = 1 + on_page_count;
        item_count_page3( 2, on_page_count);
      }
      else if(item_active==3){
        on_page_count = 1 + on_page_count;
        item_count_page3( 3, on_page_count);
      }
      else if(item_active==4){
        on_page_count = 1 + on_page_count;
        item_count_page3( 4, on_page_count);
      }
    }

    else if(customer3.active){
      if(item_active==1){
        on_page_count = 1 + on_page_count;
        item_count_page3( 1, on_page_count);
      }
      else if(item_active==2){
        on_page_count = 1 + on_page_count;
        item_count_page3( 2, on_page_count);
      }
      else if(item_active==3){
        on_page_count = on_page_count + 1;
        item_count_page3( 3, on_page_count);
      }
      else if(item_active==4){
        on_page_count = on_page_count + 1;
        item_count_page3( 4, on_page_count);
      }
    }

    else if(customer4.active){
      if(item_active==1){
        on_page_count = on_page_count + 1;
        item_count_page3( 1, on_page_count);
      }
      else if(item_active==2){
        on_page_count = on_page_count + 1;
        item_count_page3( 2, on_page_count);
      }
      else if(item_active==3){
        on_page_count = on_page_count + 1;
        item_count_page3( 3, on_page_count);
      }
      else if(item_active==4){
        on_page_count = on_page_count + 1;
        item_count_page3( 4, on_page_count);
      }
    }
   }

   // for decrement on page data 
   else if(get_data_from_screen=='o'){
    if(customer1.active){
      if(item_active==1){
        on_page_count = on_page_count - 1;
        if(on_page_count<0){
          on_page_count = 0;
        }
        item_count_page3( 1, on_page_count);
      }
      else if(item_active==2){
        on_page_count = on_page_count - 1;
        if(on_page_count<0){
          on_page_count = 0;
        }
        item_count_page3( 2, on_page_count);
      }
      else if(item_active==3){
        on_page_count = on_page_count - 1;
        if(on_page_count<0){
          on_page_count = 0;
        }
        item_count_page3( 3, on_page_count);
      }
      else if(item_active==4){
        on_page_count = on_page_count - 1;
        if(on_page_count<0){
          on_page_count = 0;
        }
        item_count_page3( 4, on_page_count);
      }
    }

    else if(customer2.active){
      if(item_active==1){
        on_page_count = on_page_count - 1;
        if(on_page_count<0){
          on_page_count = 0;
        }
        item_count_page3( 1, on_page_count);
      }
      else if(item_active==2){
        on_page_count = on_page_count - 1;
        if(on_page_count<0){
          on_page_count = 0;
        }
        item_count_page3( 2, on_page_count);
      }
      else if(item_active==3){
        on_page_count = on_page_count - 1;
        if(on_page_count<0){
          on_page_count = 0;
        }
        item_count_page3( 3, on_page_count);
      }
      else if(item_active==4){
        on_page_count = on_page_count - 1;
        if(on_page_count<0){
          on_page_count = 0;
        }
        item_count_page3( 4, on_page_count);
      }
    }

    else if(customer3.active){
      if(item_active==1){
        on_page_count = on_page_count - 1;
        if(on_page_count<0){
          on_page_count = 0;
        }
        item_count_page3( 1, on_page_count);
      }
      else if(item_active==2){
        on_page_count = on_page_count - 1;
        if(on_page_count<0){
          on_page_count = 0;
        }
        item_count_page3( 2, on_page_count);
      }
      else if(item_active==3){
        on_page_count = on_page_count - 1;
        if(on_page_count<0){
          on_page_count = 0;
        }
        item_count_page3( 3, on_page_count);
      }
      else if(item_active==4){
        on_page_count = on_page_count - 1;
        if(on_page_count<0){
          on_page_count = 0;
        }
        item_count_page3( 4, on_page_count);
      }
    }

    else if(customer4.active){
      if(item_active==1){
        on_page_count = on_page_count - 1;
        if(on_page_count<0){
          on_page_count = 0;
        }
        item_count_page3( 1, on_page_count);
      }
      else if(item_active==2){
        on_page_count = on_page_count - 1;
        if(on_page_count<0){
          on_page_count = 0;
        }
        item_count_page3( 2, on_page_count);
      }
      else if(item_active==3){
        on_page_count = on_page_count - 1;
        if(on_page_count<0){
          on_page_count = 0;
        }
        item_count_page3( 3, on_page_count);
      }
      else if(item_active==4){
        on_page_count = on_page_count - 1;
        if(on_page_count<0){
          on_page_count = 0;
        }
        item_count_page3( 4, on_page_count);
      }
    }
   }

   else if(get_data_from_screen=='q'){
    if(customer1.active){
      if(item_active==1){
        customer1.unit_item1 = on_page_count;
        item_page2(customer1.ID, customer1.unit_item1, customer1.unit_item2, customer1.unit_item3, customer1.unit_item4);
        on_page_count = 0;
      }
      else if(item_active==2){
        customer1.unit_item2 = on_page_count;
        item_page2(customer1.ID, customer1.unit_item1, customer1.unit_item2, customer1.unit_item3, customer1.unit_item4);
        on_page_count = 0;
      }
      else if(item_active==3){
        customer1.unit_item3 = on_page_count;
        item_page2(customer1.ID, customer1.unit_item1, customer1.unit_item2, customer1.unit_item3, customer1.unit_item4);
        on_page_count = 0;
      }
      else if(item_active==4){
        customer1.unit_item4 = on_page_count;
        item_page2(customer1.ID, customer1.unit_item1, customer1.unit_item2, customer1.unit_item3, customer1.unit_item4);
        on_page_count = 0;
      }
    }

    else if(customer2.active){
      if(item_active==1){
        customer2.unit_item1 = on_page_count;
        item_page2(customer2.ID, customer2.unit_item1, customer2.unit_item2, customer2.unit_item3, customer2.unit_item4);
        on_page_count = 0;
      }
      else if(item_active==2){
        customer2.unit_item2 = on_page_count;
        item_page2(customer2.ID, customer2.unit_item1, customer2.unit_item2, customer2.unit_item3, customer2.unit_item4);
        on_page_count = 0;
      }
      else if(item_active==3){
        customer2.unit_item3 = on_page_count;
        item_page2(customer2.ID, customer2.unit_item1, customer2.unit_item2, customer2.unit_item3, customer2.unit_item4);
        on_page_count = 0;
      }
      else if(item_active==4){
        customer2.unit_item4 = on_page_count;
        item_page2(customer2.ID, customer2.unit_item1, customer2.unit_item2, customer2.unit_item3, customer2.unit_item4);
        on_page_count = 0;
      }
    }

    else if(customer3.active){
      if(item_active==1){
        customer3.unit_item1 = on_page_count;
        item_page2(customer3.ID, customer3.unit_item1, customer3.unit_item2, customer3.unit_item3, customer3.unit_item4);
        on_page_count = 0;
      }
      else if(item_active==2){
        customer3.unit_item2 = on_page_count;
        item_page2(customer3.ID, customer3.unit_item1, customer3.unit_item2, customer3.unit_item3, customer3.unit_item4);
        on_page_count = 0;
      }
      else if(item_active==3){
        customer3.unit_item3 = on_page_count;
        item_page2(customer3.ID, customer3.unit_item1, customer3.unit_item2, customer3.unit_item3, customer3.unit_item4);
        on_page_count = 0;
      }
      else if(item_active==4){
        customer3.unit_item4 = on_page_count;
        item_page2(customer3.ID, customer3.unit_item1, customer3.unit_item2, customer3.unit_item3, customer3.unit_item4);
        on_page_count = 0;
      }
    }

    else if(customer4.active){
      if(item_active==1){
        customer4.unit_item1 = on_page_count;
        item_page2(customer4.ID, customer4.unit_item1, customer4.unit_item2, customer4.unit_item3, customer4.unit_item4);
        on_page_count = 0;
      }
      else if(item_active==2){
        customer4.unit_item2 = on_page_count;
        item_page2(customer4.ID, customer4.unit_item1, customer4.unit_item2, customer4.unit_item3, customer4.unit_item4);
        on_page_count = 0;
      }
      else if(item_active==3){
        customer4.unit_item3 = on_page_count;
        item_page2(customer4.ID, customer4.unit_item1, customer4.unit_item2, customer4.unit_item3, customer4.unit_item4);
        on_page_count = 0;
      }
      else if(item_active==4){
        customer4.unit_item4 = on_page_count;
        item_page2(customer4.ID, customer4.unit_item1, customer4.unit_item2, customer4.unit_item3, customer4.unit_item4);
        on_page_count = 0;
      }
    }
    
   }

   else if(get_data_from_screen=='p'){
      if(customer1.active){
        item_page2(customer1.ID, customer1.unit_item1, customer1.unit_item2, customer1.unit_item3, customer1.unit_item4);
        on_page_count = 0;
      }
      else if(customer2.active){
        item_page2(customer2.ID, customer2.unit_item1, customer2.unit_item2, customer2.unit_item3, customer2.unit_item4);
        on_page_count = 0;
      }
      else if(customer3.active){
        item_page2(customer3.ID, customer3.unit_item1, customer3.unit_item2, customer3.unit_item3, customer3.unit_item4);
        on_page_count = 0;
      }
      else if(customer4.active){
        item_page2(customer4.ID, customer4.unit_item1, customer4.unit_item2, customer4.unit_item3, customer4.unit_item4);
        on_page_count = 0;
      }
   }

    else if(get_data_from_screen=='r'){
      if(customer1.active){
        item_page2(customer1.ID, customer1.unit_item1, customer1.unit_item2, customer1.unit_item3, customer1.unit_item4);
      }
      else if(customer2.active){
        item_page2(customer2.ID, customer2.unit_item1, customer2.unit_item2, customer2.unit_item3, customer2.unit_item4);
      }
      else if(customer3.active){
        item_page2(customer3.ID, customer3.unit_item1, customer3.unit_item2, customer3.unit_item3, customer3.unit_item4);
      }
      else if(customer4.active){
        item_page2(customer4.ID, customer4.unit_item1, customer4.unit_item2, customer4.unit_item3, customer4.unit_item4);
      }
   }
	
	// Get s from pressing Done
   else if(get_data_from_screen=='s'){
      if(customer1.active){
        customer1.active = false;
        customer1.busy_ = true;
        if(priority_count<4){
          priority_count +=1;
        }else{
          priority_count = 0;
        }
        customer1.priority = priority_count;
        thank_page5(customer1.ID);
      }
      else if(customer2.active){
        customer2.active = false;
        customer2.busy_ = true;
        if(priority_count<4){
          priority_count +=1;
        }else{
          priority_count = 0;
        }
        customer2.priority = priority_count;
        thank_page5(customer2.ID);
      }
      else if(customer3.active){
        customer3.active = false;
        customer3.busy_ = true;
        if(priority_count<4){
          priority_count +=1;
        }else{
          priority_count = 0;
        }
        customer3.priority = priority_count;
        thank_page5(customer3.ID);
      }
      else if(customer4.active){
        customer4.active = false;
        customer4.busy_ = true;
        if(priority_count<4){
          priority_count +=1;
        }else{
          priority_count = 0;
        }
        customer4.priority = priority_count;
        thank_page5(customer4.ID);
      }
   }

   // CANCEL EVERYTHING
   else if(get_data_from_screen=='t'){
    if(customer1.active){
        customer1.active = false;
        customer_page1( customer1.busy_, customer2.busy_, customer3.busy_, customer3.busy_);
      }
      else if(customer2.active){
        customer2.active = false;
        customer_page1( customer1.busy_, customer2.busy_, customer3.busy_, customer3.busy_);
      }
      else if(customer3.active){
        customer3.active = false;
        customer_page1( customer1.busy_, customer2.busy_, customer3.busy_, customer3.busy_);
      }
      else if(customer4.active){
        customer4.active = false;
        customer_page1( customer1.busy_, customer2.busy_, customer3.busy_, customer3.busy_);
      }
   }
   
  }
  else{
    get_data_from_screen=' ';
  }
}

void initializing_page0(){
  Serial1.print("page 0");
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);

  screen_update_status = false;
}

void customer_page1(bool c1, bool c2, bool c3, bool c4){
  Serial1.print("page 1");
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);

  if(c1){
    Serial1.print("vis p0,1");
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);
  }else{
    Serial1.print("vis p0,0");
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);
  }
  
  if(c2){
    Serial1.print("vis p1,1");
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);
  }else{
    Serial1.print("vis p1,0");
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);
  }

  if(c3){
    Serial1.print("vis p2,1");
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);
  }else{
    Serial1.print("vis p2,0");
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);
  }

  if(c4){
    Serial1.print("vis p3,1");
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);
  }else{
    Serial1.print("vis p3,0");
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);
  }

  screen_update_status = false;
}

void item_page2(int ID, int item1, int item2, int item3, int item4){
  Serial1.print("page 2");
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);

  String send0 = "t0.txt=\"" + String(ID);
  send0 = send0 + "\"";
  Serial1.print(send0);
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.print("vis t0, 1");
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);

  send0 = "t1.txt=\"" + String(item1);
  send0 = send0 + "\"";
  Serial1.print(send0);
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.print("vis t1, 1");
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);

  send0 = "t2.txt=\"" + String(item3);
  send0 = send0 + "\"";
  Serial1.print(send0);
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.print("vis t2, 1");
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);

  send0 = "t3.txt=\"" + String(item4);
  send0 = send0 + "\"";
  Serial1.print(send0);
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.print("vis t3, 1");
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);

  send0 = "t4.txt=\"" + String(item2);
  send0 = send0 + "\"";
  Serial1.print(send0);
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.print("vis t4, 1");
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);

  screen_update_status = false;
}


void item_count_page3(int item_ID, int item_count){
  Serial1.print("page 3");
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);

  String send0 = "t0.txt=\"" + String(item_ID);
  send0 = send0 + "\"";
  Serial1.print(send0);
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.print("vis t0, 1");
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);

  send0 = "t1.txt=\"" + String(item_count);
  send0 = send0 + "\"";
  Serial1.print(send0);
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.print("vis t1, 1");
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);
  
  screen_update_status = false;
}

void done_page4(int item1, int item2, int item3, int item4){
  Serial1.print("page 4");
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);

  Serial1.print("n0.val=");
  Serial1.print(item1);
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);

  Serial1.print("n1.val=");
  Serial1.print(item2);
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);

  Serial1.print("n2.val=");
  Serial1.print(item3);
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);
 
  Serial1.print("n3.val=");
  Serial1.print(item4);
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);

  screen_update_status = false;
}

void thank_page5(int ID){
  Serial1.print("page 5");
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);

  Serial1.print("n0.val=");
  Serial1.print(ID);
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);

  screen_update_status = false;
}