# Producer-Consumer Problem (Kernel Space)
The producer-consumer problem is a classic synchronization problem in which two processes - producer and consumer are involved.

## Modifying the kernel
* Add the system calls ```reader``` and ```writer``` in ```syscall_64.tbl```.
* Added the appropriate header files (semaphore.h) and use kmalloc to allocate space for the queue (size = 5) in linux kernel.
* A circular queue has been implemented for the sake of convenience.
* Reader and Writer system calls have been implemented for enqueueing and dequeuing the 8 byte number into the queue in ```sys.c```.

## Random Value generator
8 byte numbers are taken in unsigned char array from ```/dev/urandom``` and then converted into unsigned long long number which is passed to kernel space for enqueuing through write and, read which returns the enqueued number to user space.

## Reader and Writer calls
We implement system calls for enqueueing and dequeuing (writer and reader respectively) which make use of 3 semaphores (2 counting and one binary) taking into consideration the number of remaining spaces in queue and the number of spaces filled. <br>
The binary semaphore is used to provide mutual exclusion enabling them to gain access to the queue while other process is waiting to acquire the control.

## Commands to run (Testing)

    make
    ./p and ./c (in two separate terminals for clarity)

## References
1. https://www.programiz.com/dsa/circular-queue
2. https://stackoverflow.com/questions/30720546/converting-8-byte-char-array-into-long
3. https://shivammitra.com/c/producer-consumer-problem-in-c/
4. http://manpages.ubuntu.com/manpages/bionic/man9/sema.9freebsd.html
