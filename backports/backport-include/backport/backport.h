/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __BACKPORT_H
#define __BACKPORT_H

/*
 * Minimal backport header for kernel integration mode
 * This allows in-tree drivers to build when backports is enabled
 */

/* Include the auto-generated configuration if it exists */
#ifdef CONFIG_BACKPORT_INTEGRATE
#include <backport/autoconf.h>
#endif

#endif /* __BACKPORT_H */
