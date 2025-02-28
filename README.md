# Hypervisor Detection using CPUID Instruction

## Overview
This project demonstrates how to detect the presence of a hypervisor using the CPUID instruction. It includes both an assembly program and a C implementation to retrieve hypervisor vendor information.

## Features
- Uses the CPUID instruction to check if a hypervisor is present.
- Retrieves the hypervisor vendor signature from the CPUID leaf 0x40000000.
- Implements both assembly and C versions for detection.

## Files
- `hypervisor.asm` - Assembly implementation that executes CPUID and exits.
- `hypervisor.c` - C implementation that prints the hypervisor vendor signature.

## Assembly Implementation
### Instructions
- Clears registers (RAX, RBX, RCX, RDX) using XOR.
- Sets `EAX = 0x40000000` to query hypervisor information.
- Executes `CPUID` and then exits.

### Compilation & Execution
```sh
nasm -f elf64 hypervisor.asm -o hypervisor.o
ld hypervisor.o -o hypervisor
./hypervisor
```

## C Implementation
### Instructions
- Sets `EAX = 0x40000000`.
- Executes `CPUID` and stores results in EBX, ECX, and EDX.
- Prints the hypervisor vendor signature.

### Compilation & Execution
```sh
gcc hypervisor.c -o hypervisor
./hypervisor
```

## Expected Output
If running on a hypervisor, the program should print the hypervisor vendor signature, such as:
```
EBX: KVMK
ECX: VMVM
EDX: ware
```
If no hypervisor is detected, output may be empty or contain non-hypervisor-related values.

## License
This project is open-source and can be modified or distributed under the MIT License.


