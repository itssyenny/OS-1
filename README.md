# OS-1
It is all about Linux Kernel Building and System Call Implementation 

Kernel is a fundamental part of a modern compuer's operating system (OS).
The kernel's primary functions are to :
  1. Manage the computer's hardware and resources, such as CPU, main memory, I/O devices.
  2. Allow applications to run and use these resources.
  
On this project, I use Oracle VM VirtualBox to implement all my additional system calls. You can directly download it at https://www.virtualbox.org/wiki/Downloads and don't forget to download the Ubuntu 12.04.5 32 bits LTS here at http://tw.archive.ubuntu.com/ubuntu-cd/12.04.5/ubuntu-12.04.5-desktop-i386.iso .

Steps to build Linux Kernel :
  1. You need to login first to your VM VirtualBOX and open the terminal
  2. $ sudo apt-get install vim fakeroot build-essential kernel-package libncurses5 libncurses5-dev
  3. $ cd/tmp
  4. $ wget https://www.kernel.org/pub/linux/kernel/v2.6/longterm/v2.6.32/linux-2.6.32.60.tar.xz
  5. $ sudo tar xvf linux-2.6.32.60.tar.xz -C /usr/src
  6. $ cd/usr/src/linux-2.6.32.60
  7. make mrproper
  8. $ sudo make menuconfig , and then exit and save it
  9. $ sudo make bzImage 
      You can use make -j# (# : the numbe rof your physical cores) to create multiple threads to speed up the kernel building
  10. $ sudo make modules
  11. $ sudo make modules_install
  12. $ sudo make install
  13. $ sudo vim /etc/default/grub
       Add "#" to comment the following 2 lines :
        #GRUB_HIDDEN_TIMEOUT=0
        #GRUB_HIDDEN_TIMEOUT_QUIET=true
  14. $ sudo update-grub2
  15. $ sudo shutdown -r now
  


# WHAT IS SYSTEM CALL?

Initially you must be so curious what system call is right? System call is how a program requests services from the kernel of an operating system. It provides an essential interface between processes(user) and the operating system(kernel).
System Calls can be grouped into 5 major categories :
  1. Process control
  2. File management
  3. Device management
  4. Information maintenance
  5. Communication
  
# ONCE A SYSTEM CALL OCCURS

When you call the system call, the processor is switched automatically to the system execution mode(privileged execution mode). And, the key parts of the current thread context (e.g. the program counter and the stack pointer) are SAVED.
Then, there are changes in the thread context, such as :
  1. Program counter is set to a fixed memory address (within the kernel's address space) by the hardware.
  2. Stack pointer is pointed at the top of a stack in the kernel's address space.
  
Calling thread will be executing a system call handler (part of kernel) in system mode. This system call handler determines which service the calling process wants and then performs that service. When the kernel finishes, it returns from the system call and restore the key parts of the thread context and switch the processor status back to the user execution mode(unprivileged execution mode). Finally, the thread is executing the calling-process program again and picks up where it left when it made the system call.
