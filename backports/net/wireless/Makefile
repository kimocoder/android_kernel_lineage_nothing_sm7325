# SPDX-License-Identifier: GPL-2.0
# Backports cfg80211 Makefile

obj-$(CPTCFG_CFG80211) += cfg80211.o

cfg80211-y += core.o sysfs.o radiotap.o util.o reg.o scan.o nl80211.o
cfg80211-y += mlme.o ibss.o sme.o chan.o ethtool.o mesh.o ap.o trace.o ocb.o
cfg80211-$(CPTCFG_CFG80211_DEBUGFS) += debugfs.o
cfg80211-$(CPTCFG_CFG80211_WEXT) += wext-compat.o wext-sme.o
cfg80211-$(CPTCFG_CFG80211_INTERNAL_REGDB) += regdb.o

ccflags-y += -DDEBUG
