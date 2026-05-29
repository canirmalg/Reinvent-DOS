; Reinvent DOS: Ring 0 Syscall Gatekeeper
; This stub handles the transition from user mode to the secure kernel.

global syscall_entry_stub
extern handle_syscall_rust

syscall_entry_stub:
    swapgs                      ; Switch to Kernel GS
    mov [gs:USER_RSP], rsp      ; Save User Stack
    mov rsp, [gs:KERNEL_RSP]    ; Load Kernel Stack

    ; Security: Push arguments for the Rust Kernel
    push r15                    ; Capability Token (Must match TCB)
    push rdi                    ; Syscall Arg 1
    
    call handle_syscall_rust    ; Jump to Rust Kernel logic

    ; Restore and Return to Ring 3
    add rsp, 16
    mov rsp, [gs:USER_RSP]
    swapgs
    sysretq
