#ifndef _RINGBUFFER_H
#define _RINGBUFFER_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>

//AxiVersion
class   IRingBuffer;
typedef shared_ptr<IRingBuffer> RingBuffer;

class CRingBufferImpl;
typedef shared_ptr<CRingBufferImpl> RingBufferImpl;

class IRingBuffer : public virtual IMMIODev {
public:
        static RingBuffer create(const char *name);
};

class CRingBufferImpl : public CMMIODevImpl, public virtual IRingBuffer {
public:
        CRingBufferImpl(Key &key, const char* name);
};
#endif

