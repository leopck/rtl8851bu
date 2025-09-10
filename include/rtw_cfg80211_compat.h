/* include/rtw_cfg80211_compat.h */
#pragma once
#include <linux/version.h>
#include <net/cfg80211.h>

/* Some trees don’t define an explicit reason value. Fall back to 0. */
#ifndef NL80211_TIMEOUT_UNSPECIFIED
#define NL80211_TIMEOUT_UNSPECIFIED 0
#endif

/* Unifying wrapper for cfg80211_cac_event() across kernels */
static inline void cfg80211_cac_event_compat(struct net_device *ndev,
                                             const struct cfg80211_chan_def *chdef,
                                             enum nl80211_radar_event event,
                                             gfp_t gfp)
{
#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 12, 0)
/* Newer kernels: (ndev, chdef, event, reason, gfp) */
    cfg80211_cac_event(ndev, chdef, event, NL80211_TIMEOUT_UNSPECIFIED, gfp);
#else
/* Older kernels: (ndev, chdef, event, gfp) */
    cfg80211_cac_event(ndev, chdef, event, gfp);
#endif
}

#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 12, 0)
#define RTW_CAC_RUNNING(iface) ((iface)->cac_running)
#else
#define RTW_CAC_RUNNING(iface) ((iface)->rtw_wdev->cac_started)
#endif

