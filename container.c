#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mount.h>
#include "container.h"

#define STACK_SIZE 1024 * 1024
static char stack[STACK_SIZE];

int child_func(void *arg) {
    char **args = (char **)arg;

    printf("Inside container! PID = %d\n", getpid());

    // 🔒 Filesystem isolation
    if (chroot("/mnt/e/projects/os/rootfs") != 0) {
        perror("chroot failed");
        exit(1);
    }

    if (chdir("/") != 0) {
        perror("chdir failed");
        exit(1);
    }

    printf("Changed root successfully!\n");

    // Mount /proc (ignore error if fails)
    mount("proc", "/proc", "proc", 0, NULL);

    execvp(args[0], args);
    perror("exec failed");
    return 1;
}

int run_container(char *program, char **args) {
    int flags = CLONE_NEWPID | CLONE_NEWUTS | CLONE_NEWNS | SIGCHLD;

    pid_t pid = clone(child_func, stack + STACK_SIZE, flags, args);

    if (pid == -1) {
        perror("clone failed");
        exit(1);
    }

    printf("Container PID (host): %d\n", pid);
    sleep(30); // gives you time to attach cgroup
    waitpid(pid, NULL, 0);
    return 0;
}