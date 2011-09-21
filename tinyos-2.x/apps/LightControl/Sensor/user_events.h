#ifndef _USER_EVENTS_H_
#define _USER_EVENTS_H_

typedef nx_struct user_event_msg {
      nx_uint16_t value;
} user_event_msg_t;

enum {
      AM_USER_EVENT_MSG = 6,
};

#endif

