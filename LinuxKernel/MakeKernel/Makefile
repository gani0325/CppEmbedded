# Makefile
.PHONY: kernel-download kernel-config kernel-add-systemcall kernel-build program-build clean
all: buildroot kernel

kernel-download:
	wget https://cdn.kernel.org/pub/linux/kernel/v6.x/linux-6.25.tar.xz; tar xvf linux-6.2.5.tar.xz; rm linux-6.2.5.tar.xz; mv linux-6.2.5 kernel; \
	fi

kernel-config: kernel-download
	cd kernel && make menuconfig

kernel-add-systemcall: kernel-config

kernel-build: kernel-add-systemcall
	cd kernel && make

program-build: kernel-build