COMPONENT=EstimatorC

CFLAGS += -I. -I$(TOSDIR)/lib/net
CFLAGS += -I$(TOSDIR)/lib/net/zonedip -I$(TOSDIR)/lib/net/zonedip/interfaces
CFLAGS += -I$(TOSDIR)/lib/net/neighbors -I$(TOSDIR)/lib/net/neighbors/interfaces
CFLAGS += -I$(TOSDIR)/lib/actuator/zone -I$(TOSDIR)/lib/actuator/zone/interfaces
CFLAGS += -I$(TOSROOT)/apps/LightControl/Sensor
CFLAGS += -I$(TOSDIR)/lib/T2Hack

#CFLAGS += -D_FORTIFY_SOURCE=0
CFLAGS += -DTOSH_DATA_LENGTH=96
#CFLAGS += -DTOSH_DATA_LENGTH=216

PFLAGS = -DCC2420_DEF_CHANNEL=20

include $(MAKERULES)

