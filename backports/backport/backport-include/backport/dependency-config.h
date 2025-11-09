#ifndef __BACKPORT_DEPENDENCY_CONFIG_H
#define __BACKPORT_DEPENDENCY_CONFIG_H

/*
 * Backports Dependency Configuration
 * 
 * This header manages conditional compilation of dependencies (QRTR, MHI, QMI)
 * based on compatibility with the native kernel implementation.
 * 
 * The build system sets these flags based on build.config:
 * - BACKPORTS_USE_NATIVE_QRTR: Use native kernel QRTR if compatible
 * - BACKPORTS_USE_NATIVE_MHI: Use native kernel MHI if compatible
 * - BACKPORTS_QMI_HELPERS: Always compile backported QMI helpers for ath11k
 */

/* ========================================================================
 * QRTR (Qualcomm IPC Router) Configuration
 * ======================================================================== */

#ifdef BACKPORTS_QRTR
/* Using backported QRTR implementation */
#define BACKPORT_QRTR_NAMESPACE bp_qrtr
#define BACKPORT_QRTR_PREFIX "bp_"

/* Symbol renaming macros to prevent conflicts */
#define qrtr_endpoint_register		bp_qrtr_endpoint_register
#define qrtr_endpoint_unregister	bp_qrtr_endpoint_unregister
#define qrtr_endpoint_post		bp_qrtr_endpoint_post
#define qrtr_ns_init			bp_qrtr_ns_init
#define qrtr_ns_remove			bp_qrtr_ns_remove

/* Include backported QRTR headers */
#include <backport/linux/qrtr.h>

#else
/* Using native kernel QRTR implementation */
#include <linux/qrtr.h>
#endif /* BACKPORTS_QRTR */


/* ========================================================================
 * MHI (Modem Host Interface) Configuration
 * ======================================================================== */

#ifdef BACKPORTS_MHI
/* Using backported MHI implementation */
#define BACKPORT_MHI_NAMESPACE bp_mhi
#define BACKPORT_MHI_PREFIX "bp_"

/* Symbol renaming macros to prevent conflicts */
#define mhi_alloc_controller		bp_mhi_alloc_controller
#define mhi_free_controller		bp_mhi_free_controller
#define mhi_register_controller		bp_mhi_register_controller
#define mhi_unregister_controller	bp_mhi_unregister_controller
#define of_register_mhi_controller	bp_of_register_mhi_controller
#define mhi_prepare_for_power_up	bp_mhi_prepare_for_power_up
#define mhi_async_power_up		bp_mhi_async_power_up
#define mhi_sync_power_up		bp_mhi_sync_power_up
#define mhi_power_down			bp_mhi_power_down
#define mhi_unprepare_after_power_down	bp_mhi_unprepare_after_power_down
#define mhi_queue_buf			bp_mhi_queue_buf
#define mhi_queue_dma			bp_mhi_queue_dma
#define mhi_queue_skb			bp_mhi_queue_skb
#define mhi_queue_is_full		bp_mhi_queue_is_full
#define mhi_get_free_desc_count		bp_mhi_get_free_desc_count
#define mhi_device_get			bp_mhi_device_get
#define mhi_device_put			bp_mhi_device_put
#define mhi_prepare_for_transfer	bp_mhi_prepare_for_transfer
#define mhi_unprepare_from_transfer	bp_mhi_unprepare_from_transfer
#define mhi_download_rddm_image		bp_mhi_download_rddm_image
#define mhi_force_rddm_mode		bp_mhi_force_rddm_mode

/* Include backported MHI headers */
#include <backport/linux/mhi.h>

#else
/* Using native kernel MHI implementation */
#include <linux/mhi.h>
#endif /* BACKPORTS_MHI */


/* ========================================================================
 * QMI (Qualcomm MSM Interface) Configuration
 * ======================================================================== */

#ifdef BACKPORTS_QMI_HELPERS
/* Using backported QMI helpers for ath11k-specific functionality */

/*
 * Note: We use native kernel QMI base infrastructure but backport
 * ath11k-specific QMI message definitions and helpers.
 * 
 * This approach minimizes conflicts while ensuring ath11k has the
 * exact QMI interface it expects from kernel 5.15.
 */

/* Include native QMI base headers */
#include <linux/soc/qcom/qmi.h>

/* Include backported ath11k-specific QMI helpers */
#include <backport/linux/soc/qcom/qmi_ath11k.h>

#else
/* Using native kernel QMI implementation entirely */
#include <linux/soc/qcom/qmi.h>
#endif /* BACKPORTS_QMI_HELPERS */


/* ========================================================================
 * Dependency Verification
 * ======================================================================== */

/*
 * Compile-time checks to ensure dependencies are properly configured.
 * These will cause build errors if the configuration is inconsistent.
 */

#if defined(BACKPORTS_ATH11K_AHB) && !defined(BACKPORTS_ATH11K)
#error "BACKPORTS_ATH11K_AHB requires BACKPORTS_ATH11K to be enabled"
#endif

#if defined(BACKPORTS_ATH11K) && !defined(BACKPORTS_QMI_HELPERS)
#warning "BACKPORTS_ATH11K should use BACKPORTS_QMI_HELPERS for best compatibility"
#endif


/* ========================================================================
 * Module Namespace Declarations
 * ======================================================================== */

/*
 * If using backported dependencies, declare module namespaces to prevent
 * symbol conflicts with native kernel implementations.
 */

#ifdef BACKPORTS_QRTR
#define BACKPORT_QRTR_MODULE_NAMESPACE "BP_QRTR"
#endif

#ifdef BACKPORTS_MHI
#define BACKPORT_MHI_MODULE_NAMESPACE "BP_MHI"
#endif


/* ========================================================================
 * Debug and Logging
 * ======================================================================== */

#ifdef BACKPORTS_DEBUG
#define backport_dbg(fmt, ...) \
	pr_debug("backports: " fmt, ##__VA_ARGS__)
#else
#define backport_dbg(fmt, ...) \
	do { } while (0)
#endif

/* Log which implementations are being used at module load time */
static inline void backport_log_dependencies(void)
{
#ifdef BACKPORTS_QRTR
	pr_info("backports: Using backported QRTR implementation\n");
#else
	pr_info("backports: Using native kernel QRTR implementation\n");
#endif

#ifdef BACKPORTS_MHI
	pr_info("backports: Using backported MHI implementation\n");
#else
	pr_info("backports: Using native kernel MHI implementation\n");
#endif

#ifdef BACKPORTS_QMI_HELPERS
	pr_info("backports: Using backported QMI helpers for ath11k\n");
#else
	pr_info("backports: Using native kernel QMI implementation\n");
#endif
}


#endif /* __BACKPORT_DEPENDENCY_CONFIG_H */
