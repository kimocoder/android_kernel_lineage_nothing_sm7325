#ifndef __BACKPORT_QMI_ATH11K_H
#define __BACKPORT_QMI_ATH11K_H

/*
 * ath11k-Specific QMI Definitions
 * 
 * This header provides ath11k-specific QMI message definitions and helpers
 * backported from kernel 5.15.
 * 
 * Include this header in ath11k/qmi.c when BACKPORTS_QMI_HELPERS is enabled.
 */

#include <linux/soc/qcom/qmi.h>

#ifdef BACKPORTS_QMI_HELPERS

/*
 * QMI Service Identifiers for ath11k
 */
#define ATH11K_QMI_WLFW_SERVICE_ID_V01		0x45
#define ATH11K_QMI_WLFW_SERVICE_VERS_V01	0x01
#define ATH11K_QMI_WLFW_SERVICE_INS_ID_V01	0x02

/*
 * QMI Message IDs for ath11k
 */
#define ATH11K_QMI_WLANFW_REQUEST_MEM_IND_V01		0x0035
#define ATH11K_QMI_WLANFW_FW_MEM_READY_IND_V01		0x0037
#define ATH11K_QMI_WLANFW_COLD_BOOT_CAL_DONE_IND_V01	0x0021
#define ATH11K_QMI_WLANFW_FW_READY_IND_V01		0x0038
#define ATH11K_QMI_WLANFW_CAP_REQ_V01			0x0024
#define ATH11K_QMI_WLANFW_CAP_RESP_V01			0x0024
#define ATH11K_QMI_WLANFW_BDF_DOWNLOAD_REQ_V01		0x0025
#define ATH11K_QMI_WLANFW_BDF_DOWNLOAD_RESP_V01		0x0025
#define ATH11K_QMI_WLANFW_M3_INFO_REQ_V01		0x003C
#define ATH11K_QMI_WLANFW_M3_INFO_RESP_V01		0x003C
#define ATH11K_QMI_WLANFW_WLAN_MODE_REQ_V01		0x0022
#define ATH11K_QMI_WLANFW_WLAN_MODE_RESP_V01		0x0022
#define ATH11K_QMI_WLANFW_WLAN_CFG_REQ_V01		0x0023
#define ATH11K_QMI_WLANFW_WLAN_CFG_RESP_V01		0x0023

/*
 * QMI Message Structures
 * 
 * These structures define the format of QMI messages exchanged between
 * the ath11k driver and the wireless firmware.
 */

/* Forward declarations */
struct ath11k_qmi_wlanfw_cap_req_msg_v01;
struct ath11k_qmi_wlanfw_cap_resp_msg_v01;
struct ath11k_qmi_wlanfw_bdf_download_req_msg_v01;
struct ath11k_qmi_wlanfw_bdf_download_resp_msg_v01;
struct ath11k_qmi_wlanfw_m3_info_req_msg_v01;
struct ath11k_qmi_wlanfw_m3_info_resp_msg_v01;
struct ath11k_qmi_wlanfw_wlan_mode_req_msg_v01;
struct ath11k_qmi_wlanfw_wlan_mode_resp_msg_v01;
struct ath11k_qmi_wlanfw_wlan_cfg_req_msg_v01;
struct ath11k_qmi_wlanfw_wlan_cfg_resp_msg_v01;

/*
 * QMI Message Encoders/Decoders
 * 
 * These element info arrays are used by the QMI infrastructure to
 * encode/decode messages for transmission.
 */

extern struct qmi_elem_info ath11k_qmi_wlanfw_cap_req_msg_v01_ei[];
extern struct qmi_elem_info ath11k_qmi_wlanfw_cap_resp_msg_v01_ei[];
extern struct qmi_elem_info ath11k_qmi_wlanfw_bdf_download_req_msg_v01_ei[];
extern struct qmi_elem_info ath11k_qmi_wlanfw_bdf_download_resp_msg_v01_ei[];
extern struct qmi_elem_info ath11k_qmi_wlanfw_m3_info_req_msg_v01_ei[];
extern struct qmi_elem_info ath11k_qmi_wlanfw_m3_info_resp_msg_v01_ei[];
extern struct qmi_elem_info ath11k_qmi_wlanfw_wlan_mode_req_msg_v01_ei[];
extern struct qmi_elem_info ath11k_qmi_wlanfw_wlan_mode_resp_msg_v01_ei[];
extern struct qmi_elem_info ath11k_qmi_wlanfw_wlan_cfg_req_msg_v01_ei[];
extern struct qmi_elem_info ath11k_qmi_wlanfw_wlan_cfg_resp_msg_v01_ei[];

#endif /* BACKPORTS_QMI_HELPERS */

#endif /* __BACKPORT_QMI_ATH11K_H */
