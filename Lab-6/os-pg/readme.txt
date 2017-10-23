!!!!!!!!!!!!!!!---Abhishek Yadav---!!!!!!!!!!!!!!!!!!
to run my code type:
---------
pintos run hello
...........
 QUE: First thread will print its thread name ?
 void print_thread_name(void)
 {
         printf("starting of Thread number :3\n");
         printf("thread_name = %s\n",thread_name());
         printf("ending of Thread number :3\n\n");
         thread_exit();
 }

    In above function thread_name will print thread name.
----------------------!!!!!!!!!!!!------------------------------
 QUE: Second thread will print its thread Id ?
 void print_tid(void)
 {
         printf("starting of Thread number :2\n");
         printf("thread_id = %d\n",thread_tid());
         printf("ending of Thread number :2\n");
         thread_exit();
 }

  In above function thread_tid will print thread Id.
  ------------------------!!!!!!!!!!!-------------------------------------
 QUE: Third thread will print its thread priority ?

    `printf("thread_priority = %d\n",thread_get_priority());``

    This function thread_get_priority will print thread priority of this thread.

----------------------!!!!!!!!!!!!!!---------------------------------------------------------
    `If we generate a using priority default the its priority will print any number not correct according to your system`

 To create graph:------
 at X axis: time slice
 at Y axis:no. of iteration

 When we will change value of time slice in thread.c file we will get a no of iteration (variable name : num_sticks in my code) w.r.t time slice.
 we can see that value(number of iteration) every time is decreaseing.
 values :-
 X axix :2  4   8   16  32  64  128 256 512 1024
 Y axis :24 18  14  12  11  10  9   8   8   8
