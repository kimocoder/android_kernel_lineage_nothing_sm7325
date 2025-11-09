/*
 * QRTR Backport Wrapper
 * 
 * This file provides symbol renaming wrappers for backported QRTR
 * implementation to prevent conflicts with native kernel QRTR.
 * 
 * When BACKPORTS_USE_NATIVE_QRTR=no, QRTR symbols are renamed with
 * bp_ prefix to allow coexistence with native implementation.
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/qrtr.h>

/* Only compile this wrapper if using backported QRTR */
#ifdef BACKPORTS_QRTR

/*
 * Symbol Renaming Strategy:
 * 
 * Original Symbol              Backported Symbol
 * ---------------              -----------------
 * qrtr_endpoint_register    -> bp_qrtr_endpoint_register
 * qrtr_endpoint_unregister  -> bp_qrtr_endpoint_unregister
 * qrtr_endpoint_post        -> bp_qrtr_endpoint_post
 * 
 * The actual implementation is in the backported qrtr.c file.
 * This wrapper just ensures proper symbol exports with bp_ prefix.
 */

/* Forward declarations of backported functions */
extern int bp_qrtr_endpoint_register(struct qrtr_endpoint *ep, unsigned int net_id);
extern void bp_qrtr_endpoint_unregister(struct qrtr_endpoint *ep);
extern int bp_qrtr_endpoint_post(struct qrtr_endpoint *ep, const void *data, size_t len);

/* Export backported symbols */
EXPORT_SYMBOL_GPL(bp_qrtr_endpoint_register);
EXPORT_SYMBOL_GPL(bp_qrtr_endpoint_unregister);
EXPORT_SYMBOL_GPL(bp_qrtr_endpoint_post);

/* Module namespace for conflict prevention */
#ifdef CONFIG_MODULE_NAMESPACE
MODULE_IMPORT_NS(BP_QRTR);
#endif

MODULE_DESCRIPTION("QRTR Backport Symbol Wrapper");
MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("Backports Project");
MODULE_VERSION("1.0");

/*
 * Usage Notes:
 * 
 * 1. ath11k code includes <backport/dependency-config.h> which defines:
 *    #define qrtr_endpoint_register bp_qrtr_endpoint_register
 * 
 * 2. When ath11k calls qrtr_endpoint_register(), it actually calls
 *    bp_qrtr_endpoint_register() due to the preprocessor macro.
 * 
 * 3. The backported QRTR implementation exports bp_qrtr_endpoint_register()
 *    instead of qrtr_endpoint_register().
 * 
 * 4. This prevents conflicts with native kernel QRTR which exports
 *    qrtr_endpoint_register() without the bp_ prefix.
 * 
 * 5. Both implementations can coexist in the same kernel, and the
 *    choice is made at compile time based on build.config.
 */

#endif /* BACKPORTS_QRTR */
