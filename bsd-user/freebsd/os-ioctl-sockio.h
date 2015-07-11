/*
 *  FreeBSD sockio.h definitions for ioctl(2) emulation
 *
 *  Copyright (c) 2015 Stacey D. Son
 *  All rights reserved.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _OS_IOCTL_SOCKIO_H_
#define _OS_IOCTL_SOCKIO_H_

/* See sys/sockio.h */
#define TARGET_SIOCSHIWAT       TARGET_IOW('s',  0, int32_t)
#define TARGET_SIOCGHIWAT       TARGET_IOR('s',  1, int32_t)
#define TARGET_SIOCSLOWAT       TARGET_IOW('s',  2, int32_t)
#define TARGET_SIOCGLOWAT       TARGET_IOR('s',  3, int32_t)
#define TARGET_SIOCATMARK       TARGET_IOR('s',  7, int32_t)
#define TARGET_SIOCSPGRP        TARGET_IOW('s',  8, int32_t)
#define TARGET_SIOCGPGRP        TARGET_IOR('s',  9, int32_t)

/* See net/if.h */
struct target_ifreq_buffer {
    abi_ulong  length;
    abi_ulong  buffer;
};

#define TARGET_IFNAMSIZ 16

struct target_ifreq {
    char    ifr_name[TARGET_IFNAMSIZ];
    union {
        struct  target_sockaddr ifru_addr;
        struct  target_sockaddr ifru_dstaddr;
        struct  target_sockaddr ifru_broadaddr;
        struct  target_ifreq_buffer ifru_buffer;
        int16_t   ifru_flags[2];
        int16_t   ifru_index;
        int32_t     ifru_jid;
        int32_t     ifru_metric;
        int32_t     ifru_mtu;
        int32_t     ifru_phys;
        int32_t     ifru_media;
        abi_ulong ifru_data;
        int32_t     ifru_cap[2];
        uint32_t   ifru_fib;
    } ifr_ifru;
};


#define TARGET_SIOCSIFADDR      TARGET_IOW('i', 12, struct target_ifreq)
#define TARGET_SIOCGIFADDR      TARGET_IOWR('i', 33, struct target_ifreq)
#define TARGET_SIOCSIFDSTADDR   TARGET_IOW('i', 14, struct target_ifreq)
#define TARGET_SIOCGIFDSTADDR   TARGET_IOWR('i', 34, struct target_ifreq)
#define TARGET_SIOCSIFFLAGS     TARGET_IOW('i', 16, struct target_ifreq)
#define TARGET_SIOCGIFFLAGS     TARGET_IOWR('i', 17, struct target_ifreq)
#define TARGET_SIOCGIFBRDADDR   TARGET_IOWR('i', 35, struct target_ifreq)
#define TARGET_SIOCSIFBRDADDR   TARGET_IOW('i', 19, struct target_ifreq)
#define TARGET_SIOCGIFNETMASK   TARGET_IOWR('i', 37, struct target_ifreq)
#define TARGET_SIOCSIFNETMASK   TARGET_IOW('i', 22, struct target_ifreq)
#define TARGET_SIOCGIFMETRIC    TARGET_IOWR('i', 23, struct target_ifreq)
#define TARGET_SIOCSIFMETRIC    TARGET_IOW('i', 24, struct target_ifreq)
#define TARGET_SIOCDIFADDR      TARGET_IOW('i', 25, struct target_ifreq)
#define TARGET_SIOCSIFCAP       TARGET_IOW('i', 30, struct target_ifreq)
#define TARGET_SIOCGIFCAP       TARGET_IOWR('i', 31, struct target_ifreq)
#define TARGET_SIOCGIFINDEX     TARGET_IOWR('i', 32, struct target_ifreq)
#define TARGET_SIOCGIFMAC       TARGET_IOWR('i', 38, struct target_ifreq)
#define TARGET_SIOCSIFMAC       TARGET_IOW('i', 39, struct target_ifreq)
#define TARGET_SIOCSIFNAME      TARGET_IOW('i', 40, struct target_ifreq)
#define TARGET_SIOCSIFDESCR     TARGET_IOW('i', 41, struct target_ifreq)
#define TARGET_SIOCGIFDESCR     TARGET_IOWR('i', 42, struct target_ifreq)
#define TARGET_SIOCADDMULTI     TARGET_IOW('i', 49, struct target_ifreq)
#define TARGET_SIOCDELMULTI     TARGET_IOW('i', 50, struct target_ifreq)
#define TARGET_SIOCGIFMTU       TARGET_IOWR('i', 51, struct target_ifreq)
#define TARGET_SIOCSIFMTU       TARGET_IOW('i', 52, struct target_ifreq)
#define TARGET_SIOCGIFPHYS      TARGET_IOWR('i', 53, struct target_ifreq)
#define TARGET_SIOCSIFPHYS      TARGET_IOW('i', 54, struct target_ifreq)
#define TARGET_SIOCSIFMEDIA     TARGET_IOWR('i', 55, struct target_ifreq)
#define TARGET_SIOCSIFGENERIC   TARGET_IOW('i', 57, struct target_ifreq)
#define TARGET_SIOCGIFGENERIC   TARGET_IOWR('i', 58, struct target_ifreq)
#define TARGET_SIOCSIFLLADDR    TARGET_IOW('i', 60, struct target_ifreq)
#define TARGET_SIOCGIFPSRCADDR  TARGET_IOWR('i', 71, struct target_ifreq)
#define TARGET_SIOCGIFPDSTADDR  TARGET_IOWR('i', 72, struct target_ifreq)
#define TARGET_SIOCDIFPHYADDR   TARGET_IOW('i', 73, struct target_ifreq)
#define TARGET_SIOCGPRIVATE_0   TARGET_IOWR('i', 80, struct target_ifreq)
#define TARGET_SIOCGPRIVATE_1   TARGET_IOWR('i', 81, struct target_ifreq)
#define TARGET_SIOCSIFVNET      TARGET_IOWR('i', 90, struct target_ifreq)
#define TARGET_SIOCSIFRVNET     TARGET_IOWR('i', 91, struct target_ifreq)
#define TARGET_SIOCGIFFIB       TARGET_IOWR('i', 92, struct target_ifreq)
#define TARGET_SIOCSIFFIB       TARGET_IOW('i', 93, struct target_ifreq)
#define TARGET_SIOCIFCREATE     TARGET_IOWR('i', 122, struct target_ifreq)
#define TARGET_SIOCIFCREATE2    TARGET_IOWR('i', 124, struct target_ifreq)
#define TARGET_SIOCIFDESTROY    TARGET_IOW('i', 121, struct target_ifreq)

/* See net/if.h */
struct target_ifconf {
    int32_t ifc_len;
    union {
        abi_ulong   ifcu_buf;
        abi_ulong   ifcu_reg;
    } ifc_ifcu;
};

#define TARGET_SIOCGIFCONF     	TARGET_IOWR('i', 36, struct target_ifconf)

/* See net/if.h */
struct  target_ifdrv {
    char            ifd_name[TARGET_IFNAMSIZ];
    abi_ulong       ifd_cmd;
    abi_ulong       ifd_len;
    abi_ulong       ifd_data;
};

#define TARGET_SIOCSDRVSPEC    TARGET_IOW('i', 123, struct target_ifdrv)
#define TARGET_SIOCGDRVSPEC    TARGET_IOWR('i', 123, struct target_ifdrv)

/* See net/if.h */
struct target_ifg_req {
    union {
        char        ifgrqu_group[TARGET_IFNAMSIZ];
        char        ifgrqu_member[TARGET_IFNAMSIZ];
    } ifgrq_ifgrqu;
};

struct target_ifgroupreq {
    char            ifgr_name[TARGET_IFNAMSIZ];
    uint32_t        ifgr_len;
    union {
        char        ifgru_group[TARGET_IFNAMSIZ];
        struct target_ifg_req *ifgru_groups;
    } ifgr_ifgru;
};

#define TARGET_SIOCGIFGROUP    TARGET_IOWR('i', 136, struct target_ifgroupreq)

struct target_ifmediareq {
    char        ifm_name[TARGET_IFNAMSIZ];
    int32_t     ifm_current;
    int32_t     ifm_mask;
    int32_t     ifm_status;
    int32_t     ifm_active;
    int32_t     ifm_count;
    abi_ulong   ifm_ulist;
};

#define TARGET_SIOCGIFMEDIA  TARGET_IOWR('i', 56, struct target_ifmediareq)


#endif /* _OS_IOCTL_SOCKIO_H_ */