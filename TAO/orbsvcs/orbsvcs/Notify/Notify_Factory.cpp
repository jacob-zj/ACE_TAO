// $Id$

#include "ace/Dynamic_Service.h"
#include "Notify_Factory.h"
#include "Notify_Default_CO_Factory.h"
#include "Notify_Default_POA_Factory.h"
#include "Notify_Default_Collection_Factory.h"
#include "Notify_Default_EMO_Factory.h"
#include "Notify_Event.h"

ACE_RCSID(Notify, Notify_Factory, "$Id$")

TAO_Notify_CO_Factory* TAO_Notify_Factory::co_factory_ = 0;
TAO_Notify_POA_Factory* TAO_Notify_Factory::poa_factory_ = 0;
TAO_Notify_Collection_Factory* TAO_Notify_Factory::collection_factory_ = 0;
TAO_Notify_EMO_Factory* TAO_Notify_Factory::emo_factory_ = 0;

void
TAO_Notify_Factory::init (CORBA::Environment &ACE_TRY_ENV)
{
  co_factory_ =
    ACE_Dynamic_Service <TAO_Notify_CO_Factory>::instance (TAO_NOTIFY_DEF_CO_FACTORY_NAME);

  if (co_factory_ == 0)
    {
      ACE_NEW_THROW_EX (co_factory_,
                        TAO_Notify_Default_CO_Factory (),
                        CORBA::NO_MEMORY ());
    }

  poa_factory_ =
    ACE_Dynamic_Service <TAO_Notify_POA_Factory>::instance (TAO_NOTIFY_DEF_POA_FACTORY_NAME);

  if (poa_factory_ == 0)
    {
      ACE_NEW_THROW_EX (poa_factory_,
                        TAO_Notify_Default_POA_Factory (),
                        CORBA::NO_MEMORY ());
    }

  collection_factory_ =
    ACE_Dynamic_Service <TAO_Notify_Collection_Factory>::instance (TAO_NOTIFY_DEF_COLLECTION_FACTORY_NAME);

  if (collection_factory_ == 0)
    {
      ACE_NEW_THROW_EX (collection_factory_,
                        TAO_Notify_Default_Collection_Factory (),
                        CORBA::NO_MEMORY ());
    }

  emo_factory_ =
    ACE_Dynamic_Service <TAO_Notify_EMO_Factory>::instance (TAO_NOTIFY_DEF_EMO_FACTORY_NAME);

  if (emo_factory_ == 0)
    {
      ACE_NEW_THROW_EX (emo_factory_,
                        TAO_Notify_Default_EMO_Factory (),
                        CORBA::NO_MEMORY ());
    }
}

void
TAO_Notify_Factory::shutdown (void)
{
  // @@
}

TAO_Notify_CO_Factory*
TAO_Notify_Factory::get_channel_objects_factory (void)
{
  return TAO_Notify_Factory::co_factory_;
}

TAO_Notify_POA_Factory*
TAO_Notify_Factory::get_poa_factory (void)
{
  return TAO_Notify_Factory::poa_factory_;
}

TAO_Notify_Collection_Factory*
TAO_Notify_Factory::get_collection_factory (void)
{
  return TAO_Notify_Factory::collection_factory_;
}

TAO_Notify_EMO_Factory*
TAO_Notify_Factory::get_event_manager_objects_factory (void)
{
  return TAO_Notify_Factory::emo_factory_;
}

// ****************************************************************

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

template class ACE_Dynamic_Service<TAO_Notify_CO_Factory>;
template class ACE_Dynamic_Service<TAO_Notify_POA_Factory>;
template class ACE_Dynamic_Service<TAO_Notify_Collection_Factory>;
template class ACE_Dynamic_Service<TAO_Notify_EMO_Factory>;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#pragma instantiate ACE_Dynamic_Service<TAO_Notify_Resource_Factory>

#endif /*ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
