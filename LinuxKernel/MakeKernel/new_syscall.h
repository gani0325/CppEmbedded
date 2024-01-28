// arch/x86/entry/syscalls/syscall_64.c

SYSCALL_DEFINE1(enqueue, int, value) {
    return sys_enqueue(value);
}

SYSCALL_DEFINE0(dequeue) {
    return sys_dequeue();
}
