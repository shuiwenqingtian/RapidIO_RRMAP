#----------------------------------------------------------------------------*
#Copyright (c) 2015, Integrated Device Technology Inc.
#Copyright (c) 2015, RapidIO Trade Association
#All rights reserved.
#
#Redistribution and use in source and binary forms, with or without modification,
#are permitted provided that the following conditions are met:
#
#1. Redistributions of source code must retain the above copyright notice, this
#list of conditions and the following disclaimer.
#
#2. Redistributions in binary form must reproduce the above copyright notice,
#this list of conditions and the following disclaimer in the documentation
#and/or other materials provided with the distribution.
#
#3. Neither the name of the copyright holder nor the names of its contributors
#may be used to endorse or promote products derived from this software without
#specific prior written permission.
#
#THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
#ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
#WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
#DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
#FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
#DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
#SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
#CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
#OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
#OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#--------------------------------------------------------------------------***

TOPDIR?=$(shell pwd)/../..
include $(TOPDIR)/rules.mk

NAME:=cfg
TARGETS:=lib$(NAME).a
TEST_TARGET:=$(NAME)_test

OBJECTS:=$(patsubst src/%.c,src/%.o,$(wildcard src/*.c))
TEST_OBJECTS:=$(patsubst test/%.c,test/%.o,$(wildcard test/*.c))

HEADERS:=inc/lib$(NAME).h

CROSS_COMPILE?=/usr/bin/

CC:=$(CROSS_COMPILE)g++
AR:=$(CROSS_COMPILE)ar

CFLAGS=$(CXXFLAGS)
CFLAGS+=-D$(DEBUG_CTL) -DRDMA_LL=$(LOG_LEVEL)
CFLAGS+=-I../inc -Isrc
CFLAGS+=-I../libriocp_pe/inc
CFLAGS+=-I../librio_switch/inc
CFLAGS+=-I../libct/inc
CFLAGS+=-I../libdid/inc
LDFLAGS+=-L. -l$(NAME)


.PHONY: all clean

ifdef TEST
all: $(TARGETS) $(TEST_TARGET)
else
all: $(TARGETS)
endif

%.a: $(OBJECTS)
	@echo ---------- Building $@
	$(AR) rcs $@ $^

src/%.o: src/%.c $(HEADERS)
	@echo ---------- Building $@
	$(CC) -c $(CFLAGS) $< -o $@

test/%.o: test/%.c
	@echo ---------- Building $@
	$(CC) -c $(CFLAGS) $(TST_INCS) $< -o $@

test/%: test/%.o
	@echo ---------- Building $@
	$(CC) -o $@ $< $(LDFLAGS) \
	$(TST_LIBS)

$(TEST_TARGET): $(TEST_TARGETS)

clean:
	@echo ---------- Cleaning lib$(NAME)...
	rm -f $(TARGETS) $(OBJECTS) \
	$(TEST_TARGETS) $(TEST_OBJECTS)\
	inc/*~ src/*~ test/*~ *~ *.a

