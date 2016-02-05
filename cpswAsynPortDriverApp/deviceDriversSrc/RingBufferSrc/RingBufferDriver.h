#ifndef RINGBUFFER_DRIVER_H
#define RINGBUFFER_DRIVER_H

#include "asynPortDriver.h"
#include "cpswAsynPortDriver.h"
#include <cpsw_api_user.h>

/* Registers */
#define WaveformSizeString "WaveformSize"
#define RAM_ADDR_WIDTH_GString "RAM_ADDR_WIDTH_G"
#define ExtdataLogClrString "ExtdataLogClr"
#define ExtDataLogEnString "ExtDataLogEn"
#define IntdataLogClrString "IntdataLogClr"
#define IntDataLogEnString "IntDataLogEn"
#define Reg0x0000String "Reg0x0000"
#define RingBufferString "RingBuffer"

/* Commands */


 /* This class implements the AxiVersion driver. */
class RingBufferDriver : public cpswAsynDriver {
public:
    RingBufferDriver(const char *portName, Path p, int nelms);



protected:
/* Registers */
    int p_WaveformSize;
    #define FIRST_RINGBUFFER_PARAM p_WaveformSize
    int p_RAM_ADDR_WIDTH_G;
    int p_ExtdataLogClr;
    int p_ExtDataLogEn;
    int p_IntdataLogClr;
    int p_IntDataLogEn;
    int p_Reg0x0000;
    int p_RingBuffer;
    #define LAST_RINGBUFFER_PARAM p_RingBuffer


    #define NUM_RINGBUFFER_PARAMS (&LAST_RINGBUFFER_PARAM - &FIRST_RINGBUFFER_PARAM + 1)

private:

};

#endif

