# HeathOS
An operating system specifically for my needs, will be renamed when the kernel is actually useful. As it stands consider this a research project.

## Philosophy
The founding thought of this operating system is that all changes to the operating system should be a ledger of sorts. Imagine the operating system as being version controlled, at any point you should be able to roll back changes.

## Licensing
As it stands right now, the software will pick the most flexible open source license. This software is not intended to be proprietary now or ever.

## Todo
- Driver support (keyboard first)
- Implement some form of std::cout
- Implement a terminal
- Implement a distributed package manager
- Implement version control for tracking all "transactions" of changes to state
- Implement a Kernel API
- Attempt to install third party software like `git`.

## Next Steps
- Document and create scripts for the following:
  - All steps outlined here: https://wiki.osdev.org/Bare_Bones#Building_a_Cross-Compiler
  - Creating custom `binutils` binaries
  - Creating custom build-gcc binaries
  - Creating custom build for Grub 2
    - Documented here: https://wiki.osdev.org/GRUB_2#Installing_GRUB_2_on_OS_X
  - Exporting environmental variables for $TARGET and $PREFIX
