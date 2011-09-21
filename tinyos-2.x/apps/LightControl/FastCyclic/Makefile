COMPONENT=EstimatorC
BUILD_EXTRA_DEPS = UserEventMsg.py
CLEAN_EXTRA = UserEventMsg.py

CFLAGS += -I. -I$(MYTOSDIR)/lib/net
CFLAGS += -I$(MYTOSDIR)/lib/net/zonedip -I$(MYTOSDIR)/lib/net/zonedip/interfaces
CFLAGS += -I$(MYTOSDIR)/lib/net/neighbors -I$(MYTOSDIR)/lib/net/neighbors/interfaces
CFLAGS += -I$(MYTOSDIR)/lib/actuator/zone -I$(MYTOSDIR)/lib/actuator/zone/interfaces
CFLAGS += -I$(MYTOSROOT)/apps/LightControl/Sensor
CFLAGS += -I$(TOSDIR)/lib/T2Hack

#CFLAGS += -DTOSH_DATA_LENGTH=216
CFLAGS += -DTOSH_DATA_LENGTH=96

PFLAGS = -DCC2420_DEF_CHANNEL=20

UserEventMsg.py: $(MYTOSROOT)/apps/LightControl/Sensor/user_events.h
	mig python -target=$(PLATFORM) $(CFLAGS) -python-classname=UserEventMsg $< user_event_msg -o $@

include $(MAKERULES)

