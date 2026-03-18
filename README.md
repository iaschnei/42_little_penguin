## Takeaways from each assignment :

### Assignment 00 :

To build / rebuild the kernel, run the following commands : 
```
make olddefconfig
make
make modules_install
KREL="$(make -s kernelrelease)"
echo "$KREL"
cp -v arch/x86/boot/bzImage /boot/vmlinuz-"$KREL"
cp -v System.map           /boot/System.map-"$KREL"
cp -v .config              /boot/config-"$KREL"
grub-mkconfig -o /boot/grub/grub.cfg
reboot
```
### Assignment 01 :

Modules are simply C files with some specifications to be readable by the kernel :

main.c
```C
// The "__init" keyword tells the kernel that this function is only used once at initiation
// and does not need to be saved in memory. Same thing with "__exit".
static int __init main_init(void)

// Used to call a function by the kernel.
module_init(main_init);
```

Makefile
```Makefile
# Specifies where to find the directory of our kernel's module builder with uname
KDIR ?= /lib/modules/$(shell uname -r)/build

```

### Assignment 02 :

To create a patch, commit the files with a clear description then run :
```
git format-patch -1 --stdout > <PATCH_NAME>.patch
```

And in our case since we work in the kernel source tree we can also check that our patch follows recommendations this way :
```
./scripts/checkpatch.pl --strict <PATCH_NAME>.patch
```

### Assigment 03 :

Coding style documentation is in the kernel source tree at ./Documentation/process/coding-style.rst
