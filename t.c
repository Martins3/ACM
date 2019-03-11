#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
int main() {
    long int shoutout = syscall(329);
    printf("System call sys_hello returned %ld\n", shoutout);
    return 0;
}
