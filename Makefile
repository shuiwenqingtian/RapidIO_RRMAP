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

TOPDIR=$(shell pwd)
include $(TOPDIR)/rules.mk

LOG_LEVEL?=7
export LOG_LEVEL

DEBUG?=DEBUG
export DEBUG

# TODO This must go away
TOP_LEVEL = $(shell pwd)

TARGETS = common fabric_management rrmapcli goodput file_transfer 

all: $(TARGETS)

fabric_management: common FORCE
	$(MAKE) all -C fabric_management
		
common: FORCE
	$(MAKE) all -C common 
	
rrmapcli: common FORCE	
	$(MAKE) all -C utils/rrmapcli

goodput: common FORCE	
	$(MAKE) all -C utils/goodput

file_transfer: common FORCE
	$(MAKE) all -C utils/file_transfer

FORCE:

clean: FORCE
	$(MAKE) clean -C common
	$(MAKE) clean -C fabric_management
	$(MAKE) clean -C utils/rrmapcli
	$(MAKE) clean -C utils/goodput
	$(MAKE) clean -C utils/file_transfer
	rm -rf include/libs_a/*
