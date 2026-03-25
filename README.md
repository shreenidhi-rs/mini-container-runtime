id="readme1"
#  Mini Container Runtime (C, Linux)

##  Overview
This project implements a lightweight container runtime from scratch using core Linux primitives like namespaces, chroot, and cgroups.

It demonstrates how modern container technologies like Docker work internally.

---

##  Features
- Process isolation using `clone()` and PID namespaces
- Filesystem isolation using `chroot()`
- Minimal Linux environment setup (manual dependency handling)
- Resource limiting using cgroups (v2)
- Execution of isolated processes

---

##  Key Concepts
- Linux Namespaces
- Process Isolation
- Filesystem Isolation
- Binary Dependency Management (`ldd`)
- Control Groups (cgroups)

---

##  Tech Stack
- C (GCC)
- Linux System Calls
- WSL / Ubuntu

---

##  How to Run

### 1. Compile
```bash
make