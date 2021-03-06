/* RS-485 structures */

/* RS-485 support */
/* Used with ioctl() TIOCSERSETRS485 */
struct rs485_control {
        unsigned short rts_on_send;
        unsigned short rts_after_sent;
        __u32 delay_rts_before_send;
        unsigned short enabled;
#ifdef __KERNEL__
        int disable_serial_loopback;
#endif
};

/* Used with ioctl() TIOCSERWRRS485 */
struct rs485_write {
        __u16 outc_size;
        unsigned char *outc;
};

