#include <cpsw_api_user.h>


class IAxiVersionUser;
typedef shared_ptr<IAXIVersionUser> AXIVersionUser;
i


AxiVersionUser IAxiVersionUser::create(Path p)
{
/*ScalVal_Adapt rval = check_interface<ScalVal_Adapt, IntEntryImpl>( p );
        if ( rval ) {
                if ( rval->getMode() != IIntField::RW )
                        throw InterfaceNotImplementedError( p );
        }
        return rval;
*/
  try {
    masterReset_ = IScalVal::create( p->findByName("MasterReset") );
    fpgaReload_  = IScalVal::create( p->findByName("FpgaReload") );
    counter_     = IScalVal::create( p->findByName("Counter") );
  } catch ( CPSWError &e ) {

  }
  return v; 
}

void IAxiVersionUser::masterReset()
{
  
}
