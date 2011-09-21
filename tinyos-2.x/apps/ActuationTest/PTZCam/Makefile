COMPONENT=PtzCameraAppC
BUILD_EXTRA_DEPS += PrintfStore.class
CLEAN_EXTRA = *.class

#CFLAGS += -I$(TOSDIR)/lib/printf
#CFLAGS += -I$(TOSROOT)/apps/BlinkM

CFLAGS += -I$(TOSDIR)/lib/net
CFLAGS += -I$(TOSDIR)/lib/net/zonedip -I$(TOSDIR)/lib/net/zonedip/interfaces
CFLAGS += -I$(TOSDIR)/lib/net/neighbors -I$(TOSDIR)/lib/net/neighbors/interfaces
CFLAGS += -I$(TOSDIR)/lib/actuator -I$(TOSDIR)/lib/actuator/interfaces
CFLAGS += -I$(TOSDIR)/lib/actuator/zone -I$(TOSDIR)/lib/actuator/zone/interfaces

CONSTANTS += -DTOSH_DATA_LENGTH=48
#CFLAGS += $(CONSTANTS)

PFLAGS = -DCC2420_DEF_CHANNEL=12

PrintfStore.class: PrintfStore.java
	javac PrintfStore.java

include $(MAKERULES)

