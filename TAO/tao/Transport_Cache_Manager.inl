/* -*- C++ -*- */
//$Id$

ACE_INLINE int
TAO_Transport_Cache_Manager::bind (TAO_Cache_ExtId &ext_id,
                                    TAO_Cache_IntId &int_id)
{
#if !defined (TAO_HAS_COLLOCATION)
  ACE_MT (ACE_GUARD_RETURN (ACE_Lock,
                            guard,
                            *this->cache_lock_,
                            -1));

  return this->bind_i (ext_id,
                       int_id);
#else
  return 0;
#endif
}


ACE_INLINE int
TAO_Transport_Cache_Manager::cache_transport (
    TAO_Transport_Descriptor_Interface *prop,
    TAO_Transport *transport)
{

#if !defined (TAO_HAS_COLLOCATION)
  // Compose the ExternId & Intid
  TAO_Cache_ExtId ext_id (prop);
  TAO_Cache_IntId int_id (transport);

  int retval = 0;
  {
    ACE_MT (ACE_GUARD_RETURN (ACE_Lock,
                              guard,
                              *this->cache_lock_,
                              -1));

    // Do as the semantics of this method dictates
    int_id.recycle_state (ACE_RECYCLABLE_BUSY);

    retval = this->bind_i (ext_id,
                           int_id);
  }

  return retval;
#else
  return 0;
#endif
}

ACE_INLINE int
TAO_Transport_Cache_Manager::cache_idle_transport (
    TAO_Transport_Descriptor_Interface *prop,
    TAO_Transport *transport)
{

#if !defined (TAO_HAS_COLLOCATION)
  // Compose the ExternId & Intid
  TAO_Cache_ExtId ext_id (prop);
  TAO_Cache_IntId int_id (transport);

  int retval = 0;
  {
    ACE_MT (ACE_GUARD_RETURN (ACE_Lock,
                              guard,
                              *this->cache_lock_,
                              -1));

    // Do as the semantics of this method dictates
    int_id.recycle_state (ACE_RECYCLABLE_IDLE_AND_PURGABLE);
    retval = this->bind_i (ext_id,
                           int_id);


  }

  return retval;
#else
  return 0;
#endif
}

ACE_INLINE int
TAO_Transport_Cache_Manager::purge_entry (HASH_MAP_ENTRY *&entry)
{

#if !defined (TAO_HAS_COLLOCATION)
  // Double checked locking
  if(entry == 0)
    return 0;

  ACE_MT (ACE_GUARD_RETURN (ACE_Lock, guard, *this->cache_lock_, -1));

  return this->purge_entry_i (entry);
#else
  return 0;
#endif
}

ACE_INLINE void
TAO_Transport_Cache_Manager::mark_invalid (HASH_MAP_ENTRY *&entry)
{
#if !defined (TAO_HAS_COLLOCATION)
  if(entry == 0)
    return;

  // Double checked locking
  ACE_MT (ACE_GUARD (ACE_Lock, guard, *this->cache_lock_));

  this->mark_invalid_i (entry);
#endif
}



ACE_INLINE int
TAO_Transport_Cache_Manager::make_idle (HASH_MAP_ENTRY *&entry)
{
#if !defined (TAO_HAS_COLLOCATION)
  if(entry == 0)
    return -1;

  ACE_MT (ACE_GUARD_RETURN (ACE_Lock, guard, *this->cache_lock_, -1));
  return this->make_idle_i (entry);
#else
  return 0;
#endif

}




ACE_INLINE int
TAO_Transport_Cache_Manager::close (TAO_Connection_Handler_Set &handlers)
{

#if !defined (TAO_HAS_COLLOCATION)
  // The cache lock pointer should only be zero if
  // Transport_Cache_Manager::open() was never called.  Note that
  // only one thread opens the Transport_Cache_Manager at any given
  // time, so it is safe to check for a non-zero lock pointer.
  if (this->cache_lock_ == 0)
    return -1;

  ACE_MT (ACE_GUARD_RETURN (ACE_Lock,
                            guard,
                            *this->cache_lock_,
                            -1));

  return this->close_i (handlers);
#else
  return 0;
#endif
}


ACE_INLINE size_t
TAO_Transport_Cache_Manager::current_size (void) const
{
#if !defined (TAO_HAS_COLLOCATION)
  return this->cache_map_.current_size ();
#else
  return 0;
#endif
}

ACE_INLINE size_t
TAO_Transport_Cache_Manager::total_size (void) const
{
#if !defined (TAO_HAS_COLLOCATION)
  return this->cache_map_.total_size ();
#else
  return 0;
#endif
}
