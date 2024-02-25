/* ----------------------------------------------------------------------------*
  Copyright 2022 MILTEKSAN

  Use of this software is restricted to MILTEKSAN
  Provides context to visitor pattern implementation such that variable/function
  names and values can be passed alongside within the correct scope

  Written by Melina Aero, Istanbul, Turkey
  Written by BCD Teknik, Istanbul, Turkey
  Contact onur.tuncer@melina-aero.com
  Contact ahmet.ihsan@bcdteknik.com
  Contact beyza.yuksel@bites.com.tr
-------------------------------------------------------------------------------*/

#ifndef OBJECT_DICTIONARY_401_H
#define OBJECT_DICTIONARY_401_H

#include <cstdint>
#include <vector>

// #define OD_INDEX_RX_PDO_ASSIGNMENT uint16_t(0x1c12)
// #define OD_INDEX_TX_PDO_ASSIGNMENT uint16_t(0x1c13)

// #define OD_INDEX_ERROR_CODE (0x603F)
// #define OD_INDEX_CONTROLWORD (0x6040)

#define OD_INDEX_DEVICE_TYPE (0x1000)
 
// 1001 - Error register unsigned8 RO yes -
// 1002 - Manufacturer status register unsigned32 RO yes -
// 1003 --- Pre-defined error field array --- --- ---
// 1005 - COB-ID SYNC message unsigned32 RW - com
// 1006 - Communication cycle period unsigned32 RW - com
// 1007 - Synchronous window length unsigned32 RW - com
// 1008 - Manufacturer device name
// 1009 - Manufacturer hardware version
// 100A - Manufacturer software version
// 100С - Guard time unsigned16 RW - com
// 100D - Life time factor unsigned8 RW - com
// 1010 --- Store parameters array --- --- ---
// 1011 --- Restore default parameters array --- --- ---
// 1017 - Producer heartbeat time unsigned16 RW - com

#define OD_INDEX_IDENTITY_OBJECT (0x1018)
#define OD_INDEX_SYNCHRONOUS_COUNTER_OVERFLOW_VALUE (0x1019)
// #define OD_INDEX_
// #define OD_INDEX_
// #define OD_INDEX_

// 1029 --- Error behavior object array

// 1200 --- SDO server parameter record --- --- ----
// 1400 --- RPDO 1 communication parameter record
// 1401 --- RPDO 2 communication parameter record
// 1402 --- RPDO 3 communication parameter record
// 1403 --- RPDO 4 communication parameter record
// 1600 --- RPDO 1 mapping parameter_RECORD
// 1601 --- RPDO 2 mapping parameter_RECORD
// 1602 --- RPDO 3 mapping parameter_RECORD
// 1603 --- RPDO 4 mapping parameter_RECORD
// 1800 --- TPDO 1 communication parameter_RECORD
// 1801 --- TPDO 2 communication parameter_RECORD
// 1802 --- TPDO 3 communication parameter_RECORD
// 1803 --- TPDO 4 communication parameter_RECORD
// 1A00 --- TPDO 1 mapping parameter_RECORD
// 1A01 --- TPDO 2 mapping parameter_RECORD
// 1A02 --- TPDO 3 mapping parameter_RECORD
// 1A03 --- TPDO 4 mapping parameter_RECORD
// 2000 --- IO Remote hardware configuration array --- --- ---
// 2001 --- Analog inputs or analog outputs range index array --- --- ---
// 2002 --- Analog inputs rate (SpS) index array --- --- ---
// 2010 --- Status output 8-bit array --- --- ---
// 2011 - Inhibit time EMCY for digital output lines short circuit unsigned16 RW - com
// 2012 --- Short circuit emergency mask output 8-bit array --- --- ---
// 2018 - Analog outputs status unsigned8 RO
// 2019 - Inhibit time EMCY for the analog outputs short circuit or load dump unsigned16 RW - com
// 201A --- Short circuit emergency mask for the analog outputs unsigned8 RW - com
// 201B --- Load dump emergency mask for the analog outputs unsigned8 RW - com
// 2020 --- Mapping of the physical and logical counters array --- --- ---
// 2021 --- Read logical counter 32-bit array --- --- ---
// 2022 - Physical counters reset mask unsigned16 WO yes -
// 2030 --- Slew rate update clock index array --- --- ---
// 2031 --- Slew rate step size index array --- --- ---
// 2402 --- Read or set physical counter 32-bit array --- --- ---
// 2421 --- Physical counter interrupt trigger selection array --- --- ---
// 2422 --- Physical counter interrupt source array --- --- ---
// 2423 - Counters global interrupt enable boolean RW - com
// 2424 --- Physical counter interrupt upper limit array --- --- ---
// 2426 --- Physical counter interrupt delta array --- --- ---
// 6000 --- Read input 8-bit array
// 6002 --- Polarity input 8-bit array
// 6005 - Global interrupt enable digital input boolean RW - com
// 6006 --- Interrupt mask any change 8-bit array
// 6007 --- Interrupt mask low-to-high 8-bit array
// 6008 --- Interrupt mask high-to-low 8-bit array
// 6200 --- Write output 8-bit array
// 6202 --- Change polarity output 8-bit array
// 6206 --- Error mode output
// 6207 --- Error value output
// 6208 --- Filter mask output
// 6401 --- Read analog input
// 6403 --- Read analog input
// 6411 --- Write analog output 16-bit array --- --- ---
// 6421 --- Analog input interrupt trigger selection array --- --- ---
// 6422 --- Analog input interrupt source array --- --- ---
// 6423 - Analog input global interrupt enable boolean RW - com
// 6424 --- Analog input interrupt upper limit integer array
// 6425 --- Analog input interrupt lower limit integer array
// 6426 --- Analog input interrupt delta unsigned array --- --- ---
// 642E --- Analog input offset float array --- --- ---
// 642F --- Analog input pre-scaling float array --- --- ---
// 6443 --- Analog output error mode array
// 6444 --- Analog output error value integer array

#endif // OBJECT_DICTIONARY_401_H
