# Reinvent-DOS
Strip computing back to the metal. Build it right
Reinvent DOS is an ambitious, collaborative microkernel operating system project targeting modern x86-64 hardware. Our goal is to synthesize the minimalist, efficient architecture of classic 16-bit systems with the ironclad security and performance of 2026-era hardware primitives.

The Core Philosophy
We are moving away from monolithic, bloated OS architectures. Instead, we are building a capability-based, event-driven microkernel that treats security as a fundamental property of the file system, not an afterthought.

Key Innovations
1. NeoFAT (Atomic Tagged Metadata)
We’ve extended the legacy FAT32/exFAT specification using "Shadow Directory Entries." By repurposing the 0x0F attribute byte, we allow for:
Atomic Tagging: Metadata lives inside the file system, not in sidecar files.
Legacy Compatibility: Drives remain 100% readable on standard OSs.
Instant Discovery: Search by tags at the hardware-index level rather than crawling directory paths.

2.Capability-Based Security (The "Zero-Trust" Kernel)
Traditional OSs rely on "Who is the user?"—NeoDOS relies on "What is your Capability?"
Every process is issued a cryptographically secure 64-bit token at runtime.
System calls (SYSCALL) are gated by the Kernel (Ring 0). Without the correct capability token passed in R15, the Kernel refuses execution, preventing rogue processes from touching memory or disk sectors.

3. Tiered Integrity (Virus Immunity)
Tier A (Corporate/System): Digital Signature validation ensures that OS binaries and drivers are never tampered with.
Tier B (Home/User): Automatic hash-based consistency checking prevents silent file corruption and file-infector malware without requiring the user to manage complex certificates.

Technical Specifications
Architecture: x86-64 Long Mode (Bare Metal).
Language: Rust (Kernel Logic) & NASM Assembly (Gatekeeper/Interrupts).
Memory Model: Higher-Half Kernel, Ring 0/3 isolation via MMU/Paging.
Syscall Interface: Optimized SYSCALL/SYSRET ABI.


Roadmap & Current Status
[x] Phase 0: Architectural Design & Specifications (Completed).
[ ] Phase 1: NeoFAT Specification & CLI Utility (In Progress).
[ ] Phase 2: Ring 0 Syscall Gatekeeper & Task Scheduler.
[ ] Phase 3: Hardware Integrity / Hash-verification layer.


Getting Started
If you are a systems engineer or a low-level hacker, you can view our current architectural header files in include/neofat.h. We are currently looking for contributors to help with the Ring 0 Context Switching implementation.


Contributing
We welcome all contributors. If you have experience with:
Rust (no-std environment)
x86-64 Assembly
Operating System Design
...please check our CONTRIBUTING.md and join the conversation in the [Discussions] tab.


Acknowledgements
This project is built on the vision of a system that is secure by design and transparent by nature. Reinvent DOS will be maintained by a community of architects and engineers dedicated to the future of minimalist computing.

License: MIT/GPL-3.0
