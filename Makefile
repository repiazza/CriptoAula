# Makefile for CrptVowels

CCOPT =
LDOPT =
ADDON_LIBS = 

CC     = gcc

ifdef   DEBUG
CCOPT += -O2 -Wall -g -DDEBUG=$(DEBUG)
LDOPT += -g
else
CCOPT += -O2 -Wall
endif

ifdef   FAKE
CCOPT += -DFAKE
endif

LIBS= 

CHESS-SRVEXEC=crptvowels

OBJS += \
  CrptVowels.o 


crptvowels: $(OBJS)
	$(CC) $(LDOPT) -o $(CHESS-SRVEXEC) $(OBJS) $(LIBS)

all: clean $(CHESS-SRVEXEC)

fake: $(CHESS-SRVEXEC)

clean:
	rm -f $(OBJS) $(CHESS-SRVEXEC)


%.o: %.c
	$(CC) -c $(CCOPT) $< -o $@

########################################################### Dependencias


# DO NOT DELETE THIS LINE -- make depend depends on it.
