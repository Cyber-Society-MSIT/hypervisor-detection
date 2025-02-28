#include <stdio.h>

void check_hypervisor() {
    unsigned int eax, ebx, ecx, edx;

    // Set EAX to 0x40000000 (Hypervisor information leaf)
    eax = 0x40000000;

    // Execute CPUID instruction
    __asm__ __volatile__ (
        "cpuid"
        : "=b"(ebx), "=c"(ecx), "=d"(edx) // Outputs: EBX, ECX, and EDX
        : "a"(eax)                        // Input: EAX
    );

    // Print the result
    printf("EBX: %.4s\n", (char*)&ebx); // Vendor signature from EBX
    printf("ECX: %.4s\n", (char*)&ecx); // Vendor signature from ECX
    printf("EDX: %.4s\n", (char*)&edx); // Vendor signature from EDX
}

int main() {
    check_hypervisor();
    return 0;
}
