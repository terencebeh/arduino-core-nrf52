/*
  Copyright (c) 2016 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
  
*/

#ifndef __BLECHARACTERISTIC_H
#define __BLECHARACTERISTIC_H

#include <stdint.h>
#include "BLEUuid.h"
#include "BLEProperties.h"
#include "BLEDescriptor.h"

typedef void (*BLECharacteristicEventHandlerType)(void);

typedef enum {SET, NOTIFICATION, INDICATION} BLESetType;

class BLECharacteristic {
	public:
		BLECharacteristic(BLEUuid uuid, BLEProperties properties, uint8_t *data, uint16_t dataLength, bool variableLength);
		void addDescriptor(BLEDescriptor &descriptor);
		void setEventHandler(BLECharacteristicEventHandlerType eventHandler);
		void setValue(uint8_t *data_ptr, uint16_t length, BLESetType setType = NOTIFICATION);
	
	private:
		BLEAttribute characteristicValue;
	    uint16_t cccdHandle;
		BLEProperties properties;
		BLECharacteristic *nextCharacteristic;
		BLEDescriptor *firstDescriptor;
};

#endif
