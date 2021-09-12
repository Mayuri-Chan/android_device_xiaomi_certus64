/*
 * Driver interaction with Linux nl80211/cfg80211
 * Copyright (c) 2002-2010, Jouni Malinen <j@w1.fi>
 * Copyright (c) 2003-2004, Instant802 Networks, Inc.
 * Copyright (c) 2005-2006, Devicescape Software, Inc.
 * Copyright (c) 2007, Johannes Berg <johannes@sipsolutions.net>
 * Copyright (c) 2009-2010, Atheros Communications
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Alternatively, this software may be distributed under the terms of BSD
 * license.
 *
 * See README and COPYING for more details.
 */

#ifndef _MTK_DRIVER_NL80211_H_
#define _MTK_DRIVER_NL80211_H_

#include <linux/wireless.h>

#ifndef BITS
#define BITS(m,n) (~(BIT(m)-1) & ((BIT(n) - 1) | BIT(n)))
#endif

enum nl80211_testmode_sta_link_statistics_attr {
    __NL80211_TESTMODE_STA_STATISTICS_INVALID = 0,
    NL80211_TESTMODE_STA_STATISTICS_VERSION,
    NL80211_TESTMODE_STA_STATISTICS_MAC,
    NL80211_TESTMODE_STA_STATISTICS_LINK_SCORE,
    NL80211_TESTMODE_STA_STATISTICS_FLAG,
    NL80211_TESTMODE_STA_STATISTICS_PER,
    NL80211_TESTMODE_STA_STATISTICS_RSSI,
    NL80211_TESTMODE_STA_STATISTICS_PHY_MODE,
    NL80211_TESTMODE_STA_STATISTICS_TX_RATE,
    NL80211_TESTMODE_STA_STATISTICS_TOTAL_CNT,
    NL80211_TESTMODE_STA_STATISTICS_THRESHOLD_CNT,
    NL80211_TESTMODE_STA_STATISTICS_AVG_PROCESS_TIME,
    NL80211_TESTMODE_STA_STATISTICS_MAX_PROCESS_TIME,
    NL80211_TESTMODE_STA_STATISTICS_AVG_HIF_PROCESS_TIME,
    NL80211_TESTMODE_STA_STATISTICS_MAX_HIF_PROCESS_TIME,
    NL80211_TESTMODE_STA_STATISTICS_FAIL_CNT,
    NL80211_TESTMODE_STA_STATISTICS_TIMEOUT_CNT,
    NL80211_TESTMODE_STA_STATISTICS_AVG_AIR_TIME,
    NL80211_TESTMODE_STA_STATISTICS_TC_EMPTY_CNT_ARRAY,
    NL80211_TESTMODE_STA_STATISTICS_TC_QUE_LEN_ARRAY,
    NL80211_TESTMODE_STA_STATISTICS_TC_AVG_QUE_LEN_ARRAY,
    NL80211_TESTMODE_STA_STATISTICS_TC_CUR_QUE_LEN_ARRAY,
    NL80211_TESTMODE_STA_STATISTICS_ENQUEUE,
    NL80211_TESTMODE_STA_STATISTICS_STA_ENQUEUE,
    NL80211_TESTMODE_STA_STATISTICS_DEQUEUE,
    NL80211_TESTMODE_STA_STATISTICS_STA_DEQUEUE,
    NL80211_TESTMODE_STA_STATISTICS_RB_ARRAY,
    NL80211_TESTMODE_STA_STATISTICS_NO_TC_ARRAY,
    NL80211_TESTMODE_STA_STATISTICS_TC_USED_ARRAY,
    NL80211_TESTMODE_STA_STATISTICS_TC_WANTED_ARRAY,
    NL80211_TESTMODE_STA_STATISTICS_IRQ_ISR_CNT,
    NL80211_TESTMODE_STA_STATISTICS_IRQ_ISR_PASS_CNT,
    NL80211_TESTMODE_STA_STATISTICS_IRQ_TASK_CNT,
    NL80211_TESTMODE_STA_STATISTICS_IRQ_AB_CNT,
    NL80211_TESTMODE_STA_STATISTICS_IRQ_SW_CNT,
    NL80211_TESTMODE_STA_STATISTICS_IRQ_TX_CNT,
    NL80211_TESTMODE_STA_STATISTICS_IRQ_RX_CNT,
    NL80211_TESTMODE_STA_STATISTICS_RESERVED_ARRAY,
    NL80211_TESTMODE_STA_STATISTICS_NUM,
    NL80211_TESTMODE_STA_STATISTICS_MAX = NL80211_TESTMODE_STA_STATISTICS_NUM - 1
};

typedef enum _ENUM_TRAFFIC_CLASS_INDEX_T {
    TC0_INDEX = 0,
    TC1_INDEX,
    TC2_INDEX,
    TC3_INDEX,
    TC_DATA_NUM,
    TC4_INDEX = TC_DATA_NUM,
    TC5_INDEX,
    TC_NUM
} ENUM_TRAFFIC_CLASS_INDEX_T;

struct wpa_driver_sta_statistics_s {
    u8      version;
    u8      addr[ETH_ALEN];
    u32     flag;

    u32     link_score;
    u8      per;
    int     rssi;
    u32     phy_mode;
    double  tx_rate;

    u32     tx_total_cnt;
    u32     enqueue_total_cnt;
    u32     dequeue_total_cnt;
    u32     enqueue_sta_total_cnt;
    u32     dequeue_sta_total_cnt;
    u32     tx_exc_threshold_cnt;

    u32     tx_avg_process_time;
    u32     tx_max_process_time;
    u32     tx_avg_hif_process_time;
    u32     tx_max_hif_process_time;

    u32     tx_fail_cnt;
    u32     tx_timeout_cnt;
    u32     tx_avg_air_time;

    u32     tc_buf_full_cnt[TC_DATA_NUM];
    u32     tc_que_len[TC_DATA_NUM];

    u32     tc_back_count[TC_DATA_NUM];

    u32     dequeue_no_tc_res[TC_DATA_NUM];
    u32     tc_wanted_res[TC_DATA_NUM];
    u32     tc_used_res[TC_DATA_NUM];

    u32     isr_cnt;
    u32     isr_pass_cnt;
    u32     isr_task_cnt;
    u32     isr_ab_cnt;
    u32     isr_sw_cnt;
    u32     isr_tx_cnt;
    u32     isr_rx_cnt;

    u32     tc_avg_que_len[TC_DATA_NUM];
    u32     tc_cur_que_len[TC_DATA_NUM];

    u8      reserved[32];
};

struct wpa_driver_test_mode_info {
    u32  index;
    u32  buflen;
};

struct wpa_driver_testmode_params {
    struct wpa_driver_test_mode_info hdr;
    u8  *buf;
};

struct wpa_driver_get_sta_statistics_params {
    struct wpa_driver_test_mode_info hdr;
    u32 version;
    u32 flag;
    u8  addr[ETH_ALEN];
    u8  *buf;
};

struct wpa_driver_p2p_sigma_params {
    struct wpa_driver_test_mode_info hdr;
    u32 idx;
    u32 value;
};

struct wpa_driver_sw_cmd_params {
    struct wpa_driver_test_mode_info hdr;
    u8  set;
    u32 adr;
    u32 data;
};

struct wpa_driver_suspendmode_params {
    struct wpa_driver_test_mode_info hdr;
    u8  suspend;
};

struct wpa_driver_rx_filter_params {
    struct wpa_driver_test_mode_info hdr;
    u32 Ipv4FilterHigh;
    u32 Ipv4FilterLow;
    u32 Ipv6FilterHigh;
    u32 Ipv6FilterLow;
    u32 SnapFilterHigh;
    u32 SnapFilterLow;
};

enum nl80211_testmode_params {
    NL80211_TESTMODE_SW_CMD = 1,
    NL80211_TESTMODE_WAPI = 2,
    NL80211_TESTMODE_HS20 = 3,
    NL80211_TESTMODE_POORLINK = 4,
    NL80211_TESTMODE_STATISTICS = 0x10,
    NL80211_TESTMODE_LINK_DETECT = 0x20,
    NL80211_TESTMODE_HS_SET_CONFIG = 51,
    NL80211_TESTMODE_NEW_BEGIN = 100,
    NL80211_TESTMODE_SUSPEND = 101,
    NL80211_TESTMODE_STR_CMD = 102,
    NL80211_TESTMODE_RXFILTER = 103
};

#endif
