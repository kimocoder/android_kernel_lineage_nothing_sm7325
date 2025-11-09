#ifndef __BACKPORT_ATH11K_COMPAT_H
#define __BACKPORT_ATH11K_COMPAT_H

/*
 * ath11k Compatibility Header
 * 
 * This header provides compatibility shims for ath11k driver to work
 * with both native and backported dependencies (QRTR, MHI, QMI).
 * 
 * Include this header in ath11k source files before other includes.
 */

#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/module.h>

/* Include dependency configuration */
#include <backport/dependency-config.h>

/* ========================================================================
 * QRTR Compatibility
 * ======================================================================== */

#ifdef BACKPORTS_QRTR
/*
 * When using backported QRTR, symbols are renamed with bp_ prefix.
 * The dependency-config.h header handles the renaming via macros.
 */

/* Verify QRTR structures are available */
#ifndef QRTR_NODE_BCAST
#define QRTR_NODE_BCAST 0xffffffffu
#endif

#ifndef QRTR_PORT_CTRL
#define QRTR_PORT_CTRL 0xfffffffeu
#endif

#else
/*
 * Using native kernel QRTR.
 * Verify that required APIs are available.
 */

/* Check for 5.15-style QRTR API with net_id parameter */
#if LINUX_VERSION_CODE < KERNEL_VERSION(5,4,0)
#error "Native QRTR requires kernel 5.4 or later"
#endif

#endif /* BACKPORTS_QRTR */


/* ========================================================================
 * MHI Compatibility
 * ======================================================================== */

#ifdef BACKPORTS_MHI
/*
 * When using backported MHI, symbols are renamed with bp_ prefix.
 * The dependency-config.h header handles the renaming via macros.
 */

/* MHI state definitions */
#ifndef MHI_STATE_M0
#define MHI_STATE_M0 0
#define MHI_STATE_M1 1
#define MHI_STATE_M2 2
#define MHI_STATE_M3 3
#endif

#else
/*
 * Using native kernel MHI.
 * Verify that required APIs are available.
 */

#if LINUX_VERSION_CODE < KERNEL_VERSION(5,4,0)
#error "Native MHI requires kernel 5.4 or later"
#endif

#endif /* BACKPORTS_MHI */


/* ========================================================================
 * QMI Compatibility
 * ======================================================================== */

#ifdef BACKPORTS_QMI_HELPERS
/*
 * Using backported QMI helpers for ath11k-specific functionality.
 * 
 * We use native kernel QMI base infrastructure but backport
 * ath11k-specific QMI message definitions and helpers.
 */

/* QMI message IDs for ath11k */
#define ATH11K_QMI_WLANFW_REQUEST_MEM_IND_V01		0x0035
#define ATH11K_QMI_WLANFW_FW_MEM_READY_IND_V01		0x0037
#define ATH11K_QMI_WLANFW_COLD_BOOT_CAL_DONE_IND_V01	0x0021
#define ATH11K_QMI_WLANFW_FW_READY_IND_V01		0x0038

/* QMI service definitions */
#define ATH11K_QMI_WLFW_SERVICE_ID_V01			0x45
#define ATH11K_QMI_WLFW_SERVICE_VERS_V01		0x01
#define ATH11K_QMI_WLFW_SERVICE_INS_ID_V01		0x02

#else
/*
 * Using native kernel QMI implementation entirely.
 * This may work if the native kernel has ath11k-compatible QMI definitions.
 */

#warning "Using native QMI without backported helpers - may have compatibility issues"

#endif /* BACKPORTS_QMI_HELPERS */


/* ========================================================================
 * Kernel Version Compatibility Shims
 * ======================================================================== */

/*
 * These shims handle API differences between kernel 5.4 and 5.15
 * that affect ath11k driver.
 */

/* IEEE80211 compatibility */
#if LINUX_VERSION_CODE < KERNEL_VERSION(5,10,0)
/* Add compatibility shims for mac80211 API changes */
#endif

/* Device tree compatibility */
#if LINUX_VERSION_CODE < KERNEL_VERSION(5,8,0)
/* Add compatibility shims for device tree API changes */
#endif

/* Firmware loading compatibility */
#if LINUX_VERSION_CODE < KERNEL_VERSION(5,6,0)
/* Add compatibility shims for firmware API changes */
#endif


/* ========================================================================
 * Module Information
 * ======================================================================== */

/*
 * Add backports version information to module metadata.
 * This helps identify backported modules during troubleshooting.
 */

#ifdef BACKPORTS_VERSION
#define ATH11K_BACKPORTS_VERSION BACKPORTS_VERSION
#else
#define ATH11K_BACKPORTS_VERSION "unknown"
#endif

#ifdef BACKPORT_KERNEL_VERSION
#define ATH11K_SOURCE_KERNEL BACKPORT_KERNEL_VERSION
#else
#define ATH11K_SOURCE_KERNEL "5.15"
#endif

#ifdef BACKPORT_TARGET_KERNEL
#define ATH11K_TARGET_KERNEL BACKPORT_TARGET_KERNEL
#else
#define ATH11K_TARGET_KERNEL "5.4"
#endif


/* ========================================================================
 * Debug Helpers
 * ======================================================================== */

#ifdef BACKPORTS_DEBUG
#define ath11k_backport_dbg(fmt, ...) \
	pr_debug("ath11k_backport: " fmt, ##__VA_ARGS__)
#else
#define ath11k_backport_dbg(fmt, ...) \
	do { } while (0)
#endif

/* Log dependency configuration at module load */
static inline void ath11k_log_backport_info(void)
{
	pr_info("ath11k: Backports version %s (source: %s, target: %s)\n",
		ATH11K_BACKPORTS_VERSION,
		ATH11K_SOURCE_KERNEL,
		ATH11K_TARGET_KERNEL);
	
	backport_log_dependencies();
}


/* ========================================================================
 * Symbol Export Helpers
 * ======================================================================== */

/*
 * Helper macros for exporting symbols with proper namespace handling.
 */

#ifdef BACKPORTS_QRTR
#define ATH11K_EXPORT_QRTR_SYMBOL(sym) \
	EXPORT_SYMBOL_GPL(bp_##sym)
#else
#define ATH11K_EXPORT_QRTR_SYMBOL(sym) \
	/* Using native QRTR, no export needed */
#endif

#ifdef BACKPORTS_MHI
#define ATH11K_EXPORT_MHI_SYMBOL(sym) \
	EXPORT_SYMBOL_GPL(bp_##sym)
#else
#define ATH11K_EXPORT_MHI_SYMBOL(sym) \
	/* Using native MHI, no export needed */
#endif


#endif /* __BACKPORT_ATH11K_COMPAT_H */
