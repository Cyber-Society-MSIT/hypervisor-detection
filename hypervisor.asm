global _start          ; Entry point for the program

section .text          ; Code section begins
_start:
    xor rax, rax       ; Clear RAX register (set to 0)
    xor rdx, rdx       ; Clear RDX register (set to 0)
    xor rcx, rcx       ; Clear RCX register (set to 0)
    xor rbx, rbx       ; Clear RBX register (set to 0)

    mov eax, 0x40000000 ; Load the hypervisor information leaf into EAX
    cpuid              ; Execute CPUID instruction to get hypervisor information

    ; Exit the program
    mov rax, 60        ; sys_exit system call number
    mov rsi, 11        ; Exit code (optional)
    syscall            ; Invoke the system call

section .data          ; Data section (empty here)
