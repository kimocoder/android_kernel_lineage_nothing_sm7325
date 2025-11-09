# SPDX-License-Identifier: GPL-2.0
# Backports Atheros wireless drivers Makefile

obj-$(CPTCFG_ATH_COMMON)	+= ath.o
obj-$(CPTCFG_ATH11K)		+= ath11k/

ath-objs :=	main.o \
		regd.o \
		hw.o \
		key.o \
		dfs_pattern_detector.o \
		dfs_pri_detector.o

ath-$(CPTCFG_ATH_DEBUG) += debug.o
ath-$(CPTCFG_ATH_TRACEPOINTS) += trace.o

ccflags-y += -DDEBUG

CFLAGS_trace.o := -I$(src)
