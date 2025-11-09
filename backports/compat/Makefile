# Compatibility layer Makefile
# This builds the compat.ko module required for backports

ccflags-y += -I$(src)/../backport/compat -Wframe-larger-than=1280

ifeq ($(CONFIG_BACKPORT_INTEGRATE),)
obj-m += compat.o
else
obj-$(CONFIG_BACKPORT_COMPAT) += compat.o
endif

compat-y += ../backport/compat/main.o

# Kernel backport compatibility code
compat-$(CPTCFG_KERNEL_3_0) += ../backport/compat/compat-3.0.o
compat-$(CPTCFG_KERNEL_3_1) += ../backport/compat/compat-3.1.o
compat-$(CPTCFG_KERNEL_3_2) += ../backport/compat/backport-3.2.o
compat-$(CPTCFG_KERNEL_3_3) += ../backport/compat/compat-3.3.o
compat-$(CPTCFG_KERNEL_3_4) += ../backport/compat/compat-3.4.o
compat-$(CPTCFG_KERNEL_3_5) += ../backport/compat/compat-3.5.o ../backport/compat/user_namespace.o
compat-$(CPTCFG_KERNEL_3_6) += ../backport/compat/compat-3.6.o
compat-$(CPTCFG_KERNEL_3_7) += ../backport/compat/compat-3.7.o
compat-$(CPTCFG_KERNEL_3_8) += ../backport/compat/compat-3.8.o
compat-$(CPTCFG_KERNEL_3_9) += ../backport/compat/compat-3.9.o
compat-$(CPTCFG_KERNEL_3_10) += ../backport/compat/backport-3.10.o
compat-$(CPTCFG_KERNEL_3_11) += ../backport/compat/backport-3.11.o
compat-$(CPTCFG_KERNEL_3_12) += ../backport/compat/backport-3.12.o
compat-$(CPTCFG_KERNEL_3_13) += ../backport/compat/backport-3.13.o ../backport/compat/memneq.o
compat-$(CPTCFG_KERNEL_3_14) += ../backport/compat/backport-3.14.o
compat-$(CPTCFG_KERNEL_3_15) += ../backport/compat/backport-3.15.o
compat-$(CPTCFG_KERNEL_3_17) += ../backport/compat/backport-3.17.o
compat-$(CPTCFG_KERNEL_3_18) += ../backport/compat/backport-3.18.o
compat-$(CPTCFG_KERNEL_3_19) += ../backport/compat/backport-3.19.o
compat-$(CPTCFG_KERNEL_4_0) += ../backport/compat/backport-4.0.o
compat-$(CPTCFG_KERNEL_4_1) += ../backport/compat/backport-4.1.o
compat-$(CPTCFG_KERNEL_4_2) += ../backport/compat/backport-4.2.o
compat-$(CPTCFG_KERNEL_4_3) += ../backport/compat/backport-4.3.o
compat-$(CPTCFG_KERNEL_4_4) += ../backport/compat/backport-4.4.o
compat-$(CPTCFG_KERNEL_4_5) += ../backport/compat/backport-4.5.o
compat-$(CPTCFG_KERNEL_4_6) += ../backport/compat/backport-4.6.o
compat-$(CPTCFG_KERNEL_4_7) += ../backport/compat/backport-4.7.o
compat-$(CPTCFG_KERNEL_4_8) += ../backport/compat/backport-4.8.o
compat-$(CPTCFG_KERNEL_4_10) += ../backport/compat/backport-4.10.o
compat-$(CPTCFG_KERNEL_4_12) += ../backport/compat/backport-4.12.o
compat-$(CPTCFG_KERNEL_4_18) += ../backport/compat/backport-4.18.o
compat-$(CPTCFG_KERNEL_5_2) += ../backport/compat/backport-5.2.o ../backport/compat/backport-genetlink.o
compat-$(CPTCFG_KERNEL_5_3) += ../backport/compat/backport-5.3.o
compat-$(CPTCFG_KERNEL_5_5) += ../backport/compat/backport-5.5.o
compat-$(CPTCFG_KERNEL_5_10) += ../backport/compat/backport-5.10.o
