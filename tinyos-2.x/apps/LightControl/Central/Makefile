COMPONENT=EstimatorC

CFLAGS += -I$(TOSDIR)/lib/net \
          -I$(TOSDIR)/lib/net/4bitle \
          -I$(TOSDIR)/lib/net/ctp
CFLAGS += -I$(TOSROOT)/apps/LightControl/Sensor

#CFLAGS += -I$(TOSDIR)/lib/printf

CFLAGS += -DTOSH_DATA_LENGTH=48

PFLAGS = -DCC2420_DEF_CHANNEL=20

include $(MAKERULES)

