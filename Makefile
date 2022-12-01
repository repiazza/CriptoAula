# Makefile for cryptvowels.c

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

CRPTVOWELS-EXEC=crptvowels

OBJS += \
  cryptvowels.o 

crptvowels: $(OBJS)
	$(CC) $(LDOPT) -o $(CRPTVOWELS-EXEC) $(OBJS) $(LIBS)

all: clean $(CRPTVOWELS-EXEC)

fake: $(CRPTVOWELS-EXEC)

clean:
	rm -f $(OBJS) $(CRPTVOWELS-EXEC)


%.o: %.c
	$(CC) -c $(CCOPT) $< -o $@

########################################################### Dependencias


# DO NOT DELETE THIS LINE -- make depend depends on it.
