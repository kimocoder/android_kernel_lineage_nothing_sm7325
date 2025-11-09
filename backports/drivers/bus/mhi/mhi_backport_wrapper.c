/*
 * MHI Backport Wrapper
 * 
 * This file provides symbol renaming wrappers for backported MHI
 * implementation to prevent conflicts with native kernel MHI.
 * 
 * When BACKPORTS_USE_NATIVE_MHI=no, MHI symbols are renamed with
 * bp_ prefix to allow coexistence with native implementation.
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/mhi.h>

/* Only compile this wrapper if using backported MHI */
#ifdef BACKPORTS_MHI

/*
 * Symbol Renaming Strategy:
 * 
 * Original Symbol                  Backported Symbol
 * ---------------                  -----------------
 * mhi_alloc_controller          -> bp_mhi_alloc_controller
 * mhi_free_controller           -> bp_mhi_free_controller
 * mhi_register_controller       -> bp_mhi_register_controller
 * mhi_unregister_controller     -> bp_mhi_unregister_controller
 * of_register_mhi_controller    -> bp_of_register_mhi_controller
 * mhi_prepare_for_power_up      -> bp_mhi_prepare_for_power_up
 * mhi_async_power_up            -> bp_mhi_async_power_up
 * mhi_sync_power_up             -> bp_mhi_sync_power_up
 * mhi_power_down                -> bp_mhi_power_down
 * mhi_unprepare_after_power_down -> bp_mhi_unprepare_after_power_down
 * 
 * The actual implementation is in the backported MHI core files.
 * This wrapper just ensures proper symbol exports with bp_ prefix.
 */

/* Forward declarations of backported functions */
extern struct mhi_controller *bp_mhi_alloc_controller(size_t size);
extern void bp_mhi_free_controller(struct mhi_controller *mhi_cntrl);
extern int bp_mhi_register_controller(struct mhi_controller *mhi_cntrl,
				       const struct mhi_controller_config *config);
extern void bp_mhi_unregister_controller(struct mhi_controller *mhi_cntrl);
extern int bp_of_register_mhi_controller(struct mhi_controller *mhi_cntrl);
extern int bp_mhi_prepare_for_power_up(struct mhi_controller *mhi_cntrl);
extern int bp_mhi_async_power_up(struct mhi_controller *mhi_cntrl);
extern int bp_mhi_sync_power_up(struct mhi_controller *mhi_cntrl);
extern void bp_mhi_power_down(struct mhi_controller *mhi_cntrl, bool graceful);
extern void bp_mhi_unprepare_after_power_down(struct mhi_controller *mhi_cntrl);

/* Export backported symbols */
EXPORT_SYMBOL_GPL(bp_mhi_alloc_controller);
EXPORT_SYMBOL_GPL(bp_mhi_free_controller);
EXPORT_SYMBOL_GPL(bp_mhi_register_controller);
EXPORT_SYMBOL_GPL(bp_mhi_unregister_controller);
EXPORT_SYMBOL_GPL(bp_of_register_mhi_controller);
EXPORT_SYMBOL_GPL(bp_mhi_prepare_for_power_up);
EXPORT_SYMBOL_GPL(bp_mhi_async_power_up);
EXPORT_SYMBOL_GPL(bp_mhi_sync_power_up);
EXPORT_SYMBOL_GPL(bp_mhi_power_down);
EXPORT_SYMBOL_GPL(bp_mhi_unprepare_after_power_down);

/* Module namespace for conflict prevention */
#ifdef CONFIG_MODULE_NAMESPACE
MODULE_IMPORT_NS(BP_MHI);
#endif

MODULE_DESCRIPTION("MHI Backport Symbol Wrapper");
MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("Backports Project");
MODULE_VERSION("1.0");

/*
 * Usage Notes:
 * 
 * 1. ath11k code includes <backport/dependency-config.h> which defines:
 *    #define mhi_alloc_controller bp_mhi_alloc_controller
 *    #define mhi_register_controller bp_mhi_register_controller
 *    ... (and so on for all MHI functions)
 * 
 * 2. When ath11k calls mhi_alloc_controller(), it actually calls
 *    bp_mhi_alloc_controller() due to the preprocessor macro.
 * 
 * 3. The backported MHI implementation exports bp_mhi_alloc_controller()
 *    instead of mhi_alloc_controller().
 * 
 * 4. This prevents conflicts with native kernel MHI which exports
 *    mhi_alloc_controller() without the bp_ prefix.
 * 
 * 5. Both implementations can coexist in the same kernel, and the
 *    choice is made at compile time based on build.config.
 * 
 * 6. For ath11k_ahb on SM7325, native MHI is compatible and recommended,
 *    so this wrapper is typically not used (BACKPORTS_USE_NATIVE_MHI=yes).
 */

#endif /* BACKPORTS_MHI */
