// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// be/be_codegen.cpp:150

#ifndef _TAO_IDL_ORIG_TAOC_H_
#define _TAO_IDL_ORIG_TAOC_H_

#include /**/ "ace/pre.h"

#include "PolicyC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "TimeBaseC.h"
#include "Messaging_SyncScopeC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Export

#if defined (TAO_EXPORT_NESTED_CLASSES)
#  if defined (TAO_EXPORT_NESTED_MACRO)
#    undef TAO_EXPORT_NESTED_MACRO
#  endif /* defined (TAO_EXPORT_NESTED_MACRO) */
#  define TAO_EXPORT_NESTED_MACRO TAO_Export
#endif /* TAO_EXPORT_NESTED_CLASSES */

#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from 
// be/be_visitor_root/root_ch.cpp:63

namespace TAO
{
  class Collocation_Proxy_Broker;
  
  template<typename T> class Narrow_Utils;
  template<typename T> class AbstractBase_Narrow_Utils;
}

// TAO_IDL - Generated from
// be/be_visitor_module/module_ch.cpp:48

namespace TAO
{
  
  // TAO_IDL - Generated from
  // be/be_visitor_typedef/typedef_ch.cpp:342
  
  typedef CORBA::UShort BufferingConstraintMode;
  typedef CORBA::UShort_out BufferingConstraintMode_out;
  
  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_BufferingConstraintMode;
  
  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52
  
  const TAO::BufferingConstraintMode BUFFER_FLUSH = 0U;
  
  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52
  
  const TAO::BufferingConstraintMode BUFFER_TIMEOUT = 1U;
  
  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52
  
  const TAO::BufferingConstraintMode BUFFER_MESSAGE_COUNT = 2U;
  
  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52
  
  const TAO::BufferingConstraintMode BUFFER_MESSAGE_BYTES = 4U;
  
  // TAO_IDL - Generated from
  // be/be_type.cpp:258
  
  struct BufferingConstraint;
  
  typedef
    TAO_Fixed_Var_T<
        BufferingConstraint
      >
    BufferingConstraint_var;
  
  typedef
    BufferingConstraint &
    BufferingConstraint_out;
  
  // TAO_IDL - Generated from
  // be/be_visitor_structure/structure_ch.cpp:52
  
  struct TAO_Export BufferingConstraint
  {
    typedef BufferingConstraint_var _var_type;
    
    static void _tao_any_destructor (void *);
    TAO::BufferingConstraintMode mode;
    TimeBase::TimeT timeout;
    CORBA::ULong message_count;
    CORBA::ULong message_bytes;
  };
  
  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_BufferingConstraint;
  
  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52
  
  const CORBA::PolicyType BUFFERING_CONSTRAINT_POLICY_TYPE = 1413545985U;
  
  // TAO_IDL - Generated from
  // be/be_interface.cpp:612

#if !defined (_TAO_BUFFERINGCONSTRAINTPOLICY__VAR_OUT_CH_)
#define _TAO_BUFFERINGCONSTRAINTPOLICY__VAR_OUT_CH_
  
  class BufferingConstraintPolicy;
  typedef BufferingConstraintPolicy *BufferingConstraintPolicy_ptr;
  
  typedef
    TAO_Objref_Var_T<
        BufferingConstraintPolicy
      >
    BufferingConstraintPolicy_var;
  
  typedef
    TAO_Objref_Out_T<
        BufferingConstraintPolicy
      >
    BufferingConstraintPolicy_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be/be_visitor_interface/interface_ch.cpp:54

#if !defined (_TAO_BUFFERINGCONSTRAINTPOLICY_CH_)
#define _TAO_BUFFERINGCONSTRAINTPOLICY_CH_
  
  class TAO_Export BufferingConstraintPolicy
    : public virtual CORBA::Policy
  {
  public:
    typedef BufferingConstraintPolicy_ptr _ptr_type;
    typedef BufferingConstraintPolicy_var _var_type;
    
    // The static operations.
    static BufferingConstraintPolicy_ptr _duplicate (BufferingConstraintPolicy_ptr obj);
    
    static BufferingConstraintPolicy_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static BufferingConstraintPolicy_ptr _nil (void)
    {
      return (BufferingConstraintPolicy_ptr)0;
    }
    
    static void _tao_any_destructor (void *);
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    virtual ::TAO::BufferingConstraint buffering_constraint (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be/be_visitor_interface/interface_ch.cpp:192
    
    virtual CORBA::Boolean _is_a (
        const char *type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    BufferingConstraintPolicy (void);
    
    virtual ~BufferingConstraintPolicy (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    BufferingConstraintPolicy (const BufferingConstraintPolicy &);
    
    void operator= (const BufferingConstraintPolicy &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_BufferingConstraintPolicy;
  
  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52
  
  const Messaging::SyncScope SYNC_EAGER_BUFFERING = 0;
  
  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52
  
  const Messaging::SyncScope SYNC_DELAYED_BUFFERING = -2;

// TAO_IDL - Generated from
// be/be_visitor_module/module_ch.cpp:66

} // module TAO

// TAO_IDL - Generated from
// be/be_visitor_traits.cpp:50

// Traits specializations.
namespace TAO
{

#if !defined (_TAO_BUFFERINGCONSTRAINTPOLICY__TRAITS_CH_)
#define _TAO_BUFFERINGCONSTRAINTPOLICY__TRAITS_CH_
  
  ACE_TEMPLATE_SPECIALIZATION
  struct TAO_Export Objref_Traits<TAO::BufferingConstraintPolicy>
  {
    static TAO::BufferingConstraintPolicy_ptr tao_duplicate (
        TAO::BufferingConstraintPolicy_ptr
      );
    static void tao_release (
        TAO::BufferingConstraintPolicy_ptr
      );
    static TAO::BufferingConstraintPolicy_ptr tao_nil (void);
    static CORBA::Boolean tao_marshal (
        TAO::BufferingConstraintPolicy_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */
};

// TAO_IDL - Generated from
// be/be_visitor_structure/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, const TAO::BufferingConstraint &); // copying version
TAO_Export void operator<<= (CORBA::Any &, TAO::BufferingConstraint*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, TAO::BufferingConstraint *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const TAO::BufferingConstraint *&);

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, TAO::BufferingConstraintPolicy_ptr); // copying
TAO_Export void operator<<= (CORBA::Any &, TAO::BufferingConstraintPolicy_ptr *); // non-copying
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, TAO::BufferingConstraintPolicy_ptr &);

// TAO_IDL - Generated from
// be/be_visitor_root/cdr_op.cpp:48

#ifndef __ACE_INLINE__

// TAO_IDL - Generated from
// be/be_visitor_structure/cdr_op_ch.cpp:53

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const TAO::BufferingConstraint &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, TAO::BufferingConstraint &);

// TAO_IDL - Generated from
// be/be_visitor_root/cdr_op.cpp:64

#endif /* __ACE_INLINE__ */

// TAO_IDL - Generated from
// be/be_codegen.cpp:911

#if defined (__ACE_INLINE__)
#include "TAOC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"

#endif /* ifndef */

