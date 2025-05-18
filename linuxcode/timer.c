#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "mytimer.h"
 
void time_handler1(size_t timer_id, void * user_data)
{
    printf("\n%s",(char*)user_data);
    fflush(stdout);
    system("gnome-terminal -e vyshnav/ipc/./send");
}
 
void time_handler2(size_t timer_id, void * user_data)
{
    printf("\n%s",(char*)user_data);
    fflush(stdout);
    system("gnome-terminal -e sl");
}
 
void time_handler3(size_t timer_id, void * user_data)
{
//    system("gnome-terminal -e vyshnav/python game.py ");
}

void time_handler4(size_t timer_id, void * user_data)
{
    printf("\n%s",(char*)user_data);
    fflush(stdout);
    system("gnome-terminal -e vyshnav/./matchstick");
}

void time_handler5(size_t timer_id, void * user_data)
{
    printf("\n%s",(char*)user_data);
    fflush(stdout);
    system("gnome-terminal -e vyshnav/./number");
}
 
void main()
{
    size_t timer1, timer2, timer3 ,timer4 ,timer5;
 
    initialize();
      
      timer1 = start_timer(5, time_handler1, TIMER_SINGLE_SHOT, "timer1 terminated");
      timer2 = start_timer(15, time_handler2, TIMER_SINGLE_SHOT,"timer2 terminated");
      timer3 = start_timer(20, time_handler3,TIMER_SINGLE_SHOT, "timer3");
      timer4 = start_timer(25, time_handler4,TIMER_SINGLE_SHOT, "timer4");
      timer5 = start_timer(30, time_handler5,TIMER_SINGLE_SHOT, "timer5");
 
    sleep(60);
 
    stop_timer(timer1);
    stop_timer(timer2);
    stop_timer(timer3);
    stop_timer(timer4);
    stop_timer(timer5);
 
    finalize();
}
